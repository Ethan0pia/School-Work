# Ethan Dunham
# Cloud Only Final Assignment
# CS 496
# 2/19/18
# Sources pythontips.com/2013/07/28/generating-a-random-string/
#		  github.com/joneric/CS-496
#	      developers.google.com/api-client-library/java/google-api-java-client/oauth2

from google.appengine.ext.webapp import template
from google.appengine.api import urlfetch
from google.appengine.ext import ndb
from random import randint
import webapp2
import urllib
import random
import string
import json
import os

#Global variables to easily change Oauth info between users/programs
CLIENT_ID = '715972069292-u1t11gbjl4u3prefg17phai60acmqcan.apps.googleusercontent.com'
CLIENT_SECRET = '3kbPBBC0YL4GZxsQjhkY05Y4'
REDIRECT_URI = 'https://cloud-only-final-2.appspot.com/oauth'


class Vehicle(ndb.Model):
    id = ndb.StringProperty()
    vin = ndb.StringProperty()
    owner_id = ndb.StringProperty()
    vehicle_make = ndb.StringProperty()
    vehicle_model = ndb.StringProperty()
    purchase_price = ndb.StringProperty()


class UserAccount(ndb.Model):
    id = ndb.StringProperty()
    user_id = ndb.StringProperty()
    fname = ndb.StringProperty()
    lname = ndb.StringProperty()
    email = ndb.StringProperty()


class MainPage(webapp2.RequestHandler):
    def get(self):
        #create a random string for the secret to pass to Google for auth
        random_string = ''.join([random.choice(string.ascii_letters + string.digits) for n in xrange(32)])
        #create the url to be called to redirect for login
        url = "https://accounts.google.com/o/oauth2/v2/auth?scope=email&access_type=offline&include_granted_scopes=true&state=" + random_string
        url = url + "&redirect_uri=" + REDIRECT_URI + "&response_type=code&client_id=" + CLIENT_ID
        #create value to inject into html page
        page_values = {'url': url}
        #display the html page
        path = os.path.join(os.path.dirname(__file__), 'pages/mainPage.html')
        #inject the url into the url variable in the html
        self.response.out.write(template.render(path, page_values))


class OAuthHandler(webapp2.RequestHandler):
    def get(self):
        #save the returned authorization code
        auth_code = self.request.GET['code']
        #save the returned state
        state = self.request.GET['state']
        #create the post info to get the token
        post_body = {
            'code': auth_code,
            'client_id': CLIENT_ID,
            'client_secret': CLIENT_SECRET,
            'redirect_uri': REDIRECT_URI,
            'grant_type': 'authorization_code'
            }

        payload = urllib.urlencode(post_body)
        headers = {'Content-Type':'application/x-www-form-urlencoded'}
        #send the data to get the info
        result = urlfetch.fetch(
            url="https://www.googleapis.com/oauth2/v4/token",
            payload = payload,
            method = urlfetch.POST,
            headers = headers)

        json_result = json.loads(result.content)
        #save the token
        headers = {'Authorization': 'Bearer ' + json_result['access_token']}
        token = json_result['access_token']
        #get the user's information
        result = urlfetch.fetch(
            url="https://www.googleapis.com/plus/v1/people/me",
            method = urlfetch.GET,
            headers=headers)

        json_result = json.loads(result.content)
        #save data to inject into html
        user_id = json_result['id']
        fname = json_result['name']['givenName']
        lname = json_result['name']['familyName']
        email = json_result['emails'][0]['value']

        template_values = {'fname': fname,
                           'lname': lname,
                           'user_id': token}
        
        user_exists = False
        for user in UserAccount.query():
            if user.user_id == user_id:
                user_exists = True

        if not user_exists:
            new_user = UserAccount()
            new_user.user_id = user_id
            new_user.fname = fname
            new_user.lname = lname
            new_user.email = email
            new_user.put()
            new_user.id = str(new_user.key.urlsafe())
            new_user.put()
        #display correct html page
        path = os.path.join(os.path.dirname(__file__), 'pages/oauthPage.html')
        #inject values into html
        self.response.out.write(template.render(path, template_values))


class UserHandler(webapp2.RequestHandler):
    def get(self, user_id):
        user_id = verifyUser(user_id)
        if user_id != "0":
            user_exists = False
            user_account = ""
            #find user account
            for user in UserAccount.query():
                if user.user_id == user_id:
                    user_exists = True
                    user_account = user
            if user_exists:
                #write return json with only info the user knows. This keeps the id of the user secret for security purposes
                self.response.write(json.dumps({'user_id': user_account.user_id, 'fname': user_account.fname, 'lname': user_account.lname, 'email': user_account.email}))
            else:
                self.response.status = 401
                self.response.write("ERROR: User does not exist")
        else:
            self.response.status = 425
            self.response.write("That token has expired or is invalid. Please log back into the API to get a new token.")


    #edit a user
    def patch(self, user_id):
        user_id = verifyUser(user_id)
        if user_id != "0":
            user_data = json.loads(self.request.body)
            user_exists = False
            user_account = ""
            #find user account
            for user in UserAccount.query():
                if user.user_id == user_id:
                    user_exists = True
                    user_account = user
            if user_exists:
                    #check to verify that only 1 field is being edited by request.
                    if len(user_data) != 1:
                        self.response.status = 402
                        self.response.write("ERROR: the expected format is {\"fname\": \"str\"} or {\"lname\": \"str\"} or {\"email\": \"str\"}.")
                    else:
                        #change the pertinent info in the user object
                        for key in user_data:
                            if key == "fname":
                                user_account.fname = user_data['fname']
                                user_account.put()
                                user_dict = user_account.to_dict()
                                user_dict.pop('id', None)
                                self.response.write(json.dumps(user_dict))
                            elif key == "lname":
                                user_account.lname = user_data['lname']
                                user_account.put()
                                user_dict = user_account.to_dict()
                                user_dict.pop('id', None)
                                self.response.write(json.dumps(user_dict))
                            elif key == "email":
                                user_account.email = user_data['email']
                                user_account.put()
                                user_dict = user_account.to_dict()
                                user_dict.pop('id', None)
                                self.response.write(json.dumps(user_dict))
                            #info sent is not one of the 3 things that can be patched
                            else:
                                self.response.status = 402
                                self.response.write("ERROR: the expected format is {\"fname\": \"str\"} or {\"lname\": \"str\"} or {\"email\": \"str\"}.")
            #user not found
            else:
                self.response.status = 401
                self.response.write("ERROR: User does not exist")
        else:
            self.response.status = 425
            self.response.write("That token has expired or is invalid. Please log back into the API to get a new token.")


    #edit a user
    def put(self, user_id):
        user_id = verifyUser(user_id)
        if user_id != "0":
            user_data = json.loads(self.request.body)
            user_exists = False
            user_account = ""
            #find user account
            for user in UserAccount.query():
                if user.user_id == user_id:
                    user_exists = True
                    user_account = user
            if user_exists:
                    #check to verify that only 1 field is being edited by request.
                    if len(user_data) != 3:
                        self.response.status = 402
                        self.response.write("ERROR: the expected format is {\"fname\": \"str\", \"lname\": \"str\", \"email\": \"str\"}.")
                    else:
                        #change the pertinent info in the user object
                        fname_check = False
                        lname_check = False
                        email_check = False
                        for key in user_data:
                            if key == "fname":
                                fname_check = True
                            elif key == "lname":
                                lname_check = True
                            elif key == "email":
                                email_check = True
                            #info sent is not one of the 3 things that can be put
                            else:
                                self.response.status = 402
                                self.response.write("ERROR: the expected format is {\"fname\": \"str\", \"lname\": \"str\", \"email\": \"str\"}.")
                        if fname_check and lname_check and email_check:
                            user_account.fname = user_data['fname']
                            user_account.lname = user_data['lname']
                            user_account.email = user_data['email']
                            user_account.put()
                            user_dict = user_account.to_dict()
                            user_dict.pop('id', None)
                            self.response.write(json.dumps(user_dict))
            #user not found
            else:
                self.response.status = 401
                self.response.write("ERROR: User does not exist")
        else:
            self.response.status = 425
            self.response.write("That token has expired or is invalid. Please log back into the API to get a new token.")


    #delete a user
    def delete(self, user_id):
        user_id = verifyUser(user_id)
        if user_id != "0":
            user_exists = False
            user_account = ""
            user_key = ""
            #find user account
            for user in UserAccount.query():
                if user.user_id == user_id:
                    user_exists = True
                    user_account = user
                    user_key = user.id
            if user_exists:
                for vehicle in Vehicle.query():
                    if vehicle.owner_id == user_key:
                        vehicle.owner_id = "none"
                        vehicle.put()
                ndb.Key(urlsafe=user_key).delete()
                user_exists = False
                user_account = ""
                user_key = ""
                #find user account
                for user in UserAccount.query():
                    if user.user_id == user_id:
                        user_exists = True
                if not user_exists:
                    self.response.write("User was deleted successfully")
                else:
                    self.response.status = 403
                    self.response.write("ERROR: failed to delete user")
            #user not found
            else:
                self.response.status = 401
                self.response.write("ERROR: User does not exist")
        else:
            self.response.status = 425
            self.response.write("That token has expired or is invalid. Please log back into the API to get a new token.")


class VehicleHandler(webapp2.RequestHandler):
    def get(self, user_id):
        user_id = verifyUser(user_id)
        if user_id != "0":
            user_exists = False
            user_key = ""
            #find user account
            for user in UserAccount.query():
                if user.user_id == user_id:
                    user_exists = True
                    user_key = user.id
            if user_exists:
                #write return json with only info the user knows. This keeps the id of the user secret for security purposes
                owned_vehicles = []
                for vehicle in Vehicle.query():
                    if vehicle.owner_id == user_key:
                        vehicle_dict = vehicle.to_dict()
                        vehicle_dict.pop('owner_id', None)
                        vehicle_dict.pop('id', None)
                        owned_vehicles.append(vehicle_dict)
                self.response.write(json.dumps(owned_vehicles))
            else:
                self.response.status = 401
                self.response.write("ERROR: User does not exist")
        else:
            self.response.status = 425
            self.response.write("That token has expired or is invalid. Please log back into the API to get a new token.")


    #add a vehicle
    def post(self, user_id):
        user_id = verifyUser(user_id)
        if user_id != "0":
            vehicle_data = json.loads(self.request.body)
            user_exists = False
            user_key = ""
            #find user account
            for user in UserAccount.query():
                if user.user_id == user_id:
                    user_exists = True
                    user_key = user.id
            if user_exists:
                    #check to verify that all 4 fields are being sent by request.
                    if len(vehicle_data) != 4:
                        self.response.status = 402
                        self.response.write("ERROR: the expected format is {\"vin\": \"str\", \"vehicle_make\": \"str\", \"vehicle_model\": \"str\", \"purchase_price\": \"str\"}.")
                    else:
                        #change the pertinent info in the user object
                        vin_check = False
                        make_check = False
                        model_check = False
                        price_check = False
                        for key in vehicle_data:
                            if key == "vin":
                                vin_check = True
                            elif key == "vehicle_make":
                                make_check = True
                            elif key == "vehicle_model":
                                model_check = True
                            elif key == "purchase_price":
                                price_check = True
                            #info sent is not one of the 4 values of a vehicle
                            else:
                                self.response.status = 402
                                self.response.write("ERROR: the expected format is {\"vin\": \"str\", \"vehicle_make\": \"str\", \"vehicle_model\": \"str\", \"purchase_price\": \"str\"}.")
                        if vin_check and make_check and model_check and price_check:
                            vehicle_exists = False
                            for vehicle in Vehicle.query():
                                if vehicle.vin == vehicle_data['vin']:
                                    vehicle_exists = True
                            if not vehicle_exists:
                                #create new vehicle object
                                new_vehicle = Vehicle()
                                new_vehicle.vin = vehicle_data['vin']
                                new_vehicle.vehicle_make = vehicle_data['vehicle_make']
                                new_vehicle.vehicle_model = vehicle_data['vehicle_model']
                                new_vehicle.purchase_price = vehicle_data['purchase_price']
                                new_vehicle.owner_id = user_key
                                new_vehicle.put()
                                new_vehicle.id = str(new_vehicle.key.urlsafe())
                                new_vehicle.put()
                                vehicle_dict = new_vehicle.to_dict()
                                vehicle_dict.pop('owner_id', None)
                                vehicle_dict.pop('id', None)
                                self.response.write(json.dumps(vehicle_dict))
                            else:
                                self.response.status = 405
                                self.response.write("ERROR: That vin is already owned by someone")
            #user not found
            else:
                self.response.status = 401
                self.response.write("ERROR: User does not exist")
        else:
            self.response.status = 425
            self.response.write("That token has expired or is invalid. Please log back into the API to get a new token.")


    #add a vehicle
    def delete(self, user_id):
        user_id = verifyUser(user_id)
        if user_id != "0":
            vehicle_data = json.loads(self.request.body)
            user_exists = False
            user_key = ""
            #find user account
            for user in UserAccount.query():
                if user.user_id == user_id:
                    user_exists = True
                    user_key = user.id
            if user_exists:
                    #check to verify that only the vin is sent by request.
                    if len(vehicle_data) != 1:
                        self.response.status = 402
                        self.response.write("ERROR: the expected format is {\"vin\": \"str\"}.")
                    else:
                        #change the pertinent info in the user object
                        vin_check = False
                        for key in vehicle_data:
                            if key == "vin":
                                vin_check = True
                            #info sent is not one of the 4 values of a vehicle
                            else:
                                self.response.status = 402
                                self.response.write("ERROR: the expected format is {\"vin\": \"str\"}.")
                        if vin_check:
                            vehicle_exists = False
                            vehicle_id = ""
                            for vehicle in Vehicle.query():
                                if vehicle.vin == vehicle_data['vin']:
                                    vehicle_exists = True
                                    vehicle_id = vehicle.id
                            if vehicle_exists:
                                ndb.Key(urlsafe=vehicle_id).delete()
                                vehicle_exists = False
                                #find vehicle to verify it was deleted correctly
                                for vehicle in Vehicle.query():
                                    if vehicle.vin == vehicle_data['vin']:
                                        vehicle_exists = True
                                if not vehicle_exists:
                                    self.response.write("Vehicle was deleted successfully")
                                else:
                                    self.response.status = 403
                                    self.response.write("ERROR: failed to delete vehicle")
                            else:
                                self.response.status = 405
                                self.response.write("ERROR: That vehicle does not exist")
            #user not found
            else:
                self.response.status = 401
                self.response.write("ERROR: User does not exist")
        else:
            self.response.status = 425
            self.response.write("That token has expired or is invalid. Please log back into the API to get a new token.")


class UsersVehicleHandler(webapp2.RequestHandler):
    def get(self, user_id, vin_number):
        user_id = verifyUser(user_id)
        if user_id != "0":
            user_exists = False
            user_key = ""
            #find user account
            for user in UserAccount.query():
                if user.user_id == user_id:
                    user_exists = True
                    user_key = user.id
            if user_exists:
                #write return json with only info the user knows. This keeps the id of the user secret for security purposes
                vehicle_found = False
                vehicle_dict = ""
                for vehicle in Vehicle.query():
                    if vehicle.vin == vin_number:
                        if vehicle.owner_id == user_key:
                            vehicle_found = True
                            vehicle_dict = vehicle.to_dict()
                            vehicle_dict.pop('owner_id', None)
                            vehicle_dict.pop('id', None)
                        elif vehicle.owner_id == "none":
                            vehicle_found = True
                            vehicle_dict = vehicle.to_dict()
                            vehicle_dict.pop('id', None)
                if vehicle_found:
                    self.response.write(json.dumps(vehicle_dict))
                else:
                    self.response.status = 401
                    self.response.write("ERROR: Vehicle does not exist")
            else:
                self.response.status = 401
                self.response.write("ERROR: User does not exist")
        else:
            self.response.status = 425
            self.response.write("That token has expired or is invalid. Please log back into the API to get a new token.")


    #claim a vehicle
    def post(self, user_id, vin_number):
        user_id = verifyUser(user_id)
        if user_id != "0":
            user_exists = False
            user_key = ""
            #find user account
            for user in UserAccount.query():
                if user.user_id == user_id:
                    user_exists = True
                    user_key = user.id
            if user_exists:
                #change the pertinent info in the user object
                vehicle_exists = False
                vehicle_owned = False
                vehicle_obj = ""
                for vehicle in Vehicle.query():
                    if vehicle.vin == vin_number:
                        if vehicle.owner_id == "none":
                            vehicle_exists = True
                            vehicle_obj = vehicle
                        else:
                            vehicle_owned = True
                if vehicle_exists:
                    #create new vehicle object
                    vehicle_obj.owner_id = user_key
                    vehicle_obj.put()
                    self.response.write("Vehicle owner updated successfully")
                elif vehicle_owned:
                    self.response.status = 410
                    self.response.write("ERROR: That vehicle is already owned by someone")
                else:
                    self.response.status = 401
                    self.response.write("ERROR: Vehicle does not exist")
            #user not found
            else:
                self.response.status = 401
                self.response.write("ERROR: User does not exist")
        else:
            self.response.status = 425
            self.response.write("That token has expired or is invalid. Please log back into the API to get a new token.")


    #edit a vehicle
    def put(self, user_id, vehicle_vin):
        user_id = verifyUser(user_id)
        if user_id != "0":
            user_data = json.loads(self.request.body)
            user_exists = False
            user_account = ""
            #find user account
            for user in UserAccount.query():
                if user.user_id == user_id:
                    user_exists = True
                    user_account = user
            if user_exists:
                #check to verify that all fields are being edited by request.
                if len(user_data) != 4:
                    self.response.status = 402
                    self.response.write("ERROR: the expected format is {\"vin\": \"str\", \"vehicle_make\": \"str\", \"vehicle_model\": \"str\", \"purchase_price\": \"str\"}.")
                else:
                    vehicle_exists = False
                    vehicle_obj = ""
                    for vehicle in Vehicle.query():
                        if vehicle.vin == vehicle_vin and vehicle.owner_id == user_account.id:
                            vehicle_exists = True
                            vehicle_obj = vehicle
                    if vehicle_exists:
                        #change the pertinent info in the user object
                        vin_check = False
                        make_check = False
                        model_check = False
                        price_check = False
                        vin_used = False
                        for key in user_data:
                            if key == "vin":
                                for vehicle in Vehicle.query():
                                    if vehicle.vin == user_data['vin']:
                                        vin_used = True
                                vin_check = True
                            elif key == "vehicle_make":
                                make_check = True
                            elif key == "vehicle_model":
                                model_check = True
                            elif key == "purchase_price":
                                price_check = True
                            #info sent is not one of the 4 things that can be edited
                            else:
                                self.response.status = 402
                                self.response.write("ERROR: the expected format is {\"vin\": \"str\", \"vehicle_make\": \"str\", \"vehicle_model\": \"str\", \"purchase_price\": \"str\"}")
                        if vin_used:
                            self.response.status = 405
                            self.response.write("ERROR: that vin is already in use")
                        elif vin_check and make_check and model_check and price_check:
                            vehicle_obj.vin = user_data['vin']
                            vehicle_obj.vehicle_make = user_data['vehicle_make']
                            vehicle_obj.vehicle_model = user_data['vehicle_model']
                            vehicle_obj.purchase_price = user_data['purchase_price']
                            vehicle_obj.put()
                            vehicle_dict = vehicle_obj.to_dict()
                            vehicle_dict.pop('owner_id', None)
                            vehicle_dict.pop('id', None)
                            self.response.write(json.dumps(vehicle_dict))
                    else:
                        self.response.status = 405
                        self.response.write("ERROR: That vehicle does not exist")
            #user not found
            else:
                self.response.status = 401
                self.response.write("ERROR: User does not exist")
        else:
            self.response.status = 425
            self.response.write("That token has expired or is invalid. Please log back into the API to get a new token.")


    #edit a vehicle
    def patch(self, user_id, vehicle_vin):
        user_id = verifyUser(user_id)
        if user_id != "0":
            user_data = json.loads(self.request.body)
            user_exists = False
            user_account = ""
            #find user account
            for user in UserAccount.query():
                if user.user_id == user_id:
                    user_exists = True
                    user_account = user
            if user_exists:
                #check to verify that only 1 field is being edited by request.
                if len(user_data) != 1:
                    self.response.status = 402
                    self.response.write("ERROR: the expected format is {\"vin\": \"str\"} or {\"vehicle_make\": \"str\"} or {\"vehicle_model\": \"str\"} or {\"purchase_price\": \"str\"}")
                else:
                    vehicle_exists = False
                    vehicle_obj = ""
                    for vehicle in Vehicle.query():
                        if vehicle.vin == vehicle_vin and vehicle.owner_id == user_account.id:
                            vehicle_exists = True
                            vehicle_obj = vehicle
                    if vehicle_exists:
                        #change the pertinent info in the user object
                        for key in user_data:
                            if key == "vin":
                                vin_used = False
                                for vehicle in Vehicle.query():
                                    if vehicle.vin == user_data['vin']:
                                        vin_used = True
                                if not vin_used:
                                    vehicle_obj.vin = user_data['vin']
                                    vehicle_obj.put()
                                    vehicle_dict = vehicle_obj.to_dict()
                                    vehicle_dict.pop('owner_id', None)
                                    vehicle_dict.pop('id', None)
                                    self.response.write(json.dumps(vehicle_dict))
                                else:
                                    self.response.status = 405
                                    self.response.write("ERROR: that vin is already in use")
                            elif key == "vehicle_make":
                                vehicle_obj.vehicle_make = user_data['vehicle_make']
                                vehicle_obj.put()
                                vehicle_dict = vehicle_obj.to_dict()
                                vehicle_dict.pop('owner_id', None)
                                vehicle_dict.pop('id', None)
                                self.response.write(json.dumps(vehicle_dict))
                            elif key == "vehicle_model":
                                vehicle_obj.vehicle_model = user_data['vehicle_model']
                                vehicle_obj.put()
                                vehicle_dict = vehicle_obj.to_dict()
                                vehicle_dict.pop('owner_id', None)
                                vehicle_dict.pop('id', None)
                                self.response.write(json.dumps(vehicle_dict))
                            elif key == "purchase_price":
                                vehicle_obj.purchase_price = user_data['purchase_price']
                                vehicle_obj.put()
                                vehicle_dict = vehicle_obj.to_dict()
                                vehicle_dict.pop('owner_id', None)
                                vehicle_dict.pop('id', None)
                                self.response.write(json.dumps(vehicle_dict))
                            #info sent is not one of the 3 things that can be patched
                            else:
                                self.response.status = 402
                                self.response.write("ERROR: the expected format is {\"vin\": \"str\"} or {\"vehicle_make\": \"str\"} or {\"vehicle_model\": \"str\"} or {\"purchase_price\": \"str\"}")
                    else:
                        self.response.status = 405
                        self.response.write("ERROR: That vehicle does not exist")
            #user not found
            else:
                self.response.status = 401
                self.response.write("ERROR: User does not exist")
        else:
            self.response.status = 425
            self.response.write("That token has expired or is invalid. Please log back into the API to get a new token.")


    #sell a vehicle
    def delete(self, user_id, vin_number):
        user_id = verifyUser(user_id)
        if user_id != "0":
            user_exists = False
            user_key = ""
            #find user account
            for user in UserAccount.query():
                if user.user_id == user_id:
                    user_exists = True
                    user_key = user.id
            if user_exists:
                #change the pertinent info in the user object
                vehicle_exists = False
                vehicle_obj = ""
                for vehicle in Vehicle.query():
                    if vehicle.vin == vin_number:
                        if vehicle.owner_id == user_key:
                            vehicle_exists = True
                            vehicle_obj = vehicle
                if vehicle_exists:
                    #find vehicle to verify it was deleted correctly
                    vehicle_obj.owner_id = "none"
                    vehicle_obj.put()
                    self.response.write("Vehicle was set to unowned")
                else:
                    self.response.status = 405
                    self.response.write("ERROR: That vehicle does not exist or is owned by someone else")
            #user not found
            else:
                self.response.status = 401
                self.response.write("ERROR: User does not exist")
        else:
            self.response.status = 425
            self.response.write("That token has expired or is invalid. Please log back into the API to get a new token.")


def verifyUser(access_token):
    headers = {'Authorization': 'Bearer ' + access_token}
    #get the user's information
    result = urlfetch.fetch(
        url="https://www.googleapis.com/plus/v1/people/me",
        method = urlfetch.GET,
        headers=headers)
    user_id = 0
    json_result = json.loads(result)
    if 'error' not in json_result
        json_result = json.loads(result.content)
        user_id = json_result['id']
    #save data to inject into html
    return user_id


#allow patching
allowed_methods = webapp2.WSGIApplication.allowed_methods
new_allowed_methods = allowed_methods.union(('PATCH',))
webapp2.WSGIApplication.allowed_methods = new_allowed_methods
#page handling info
app = webapp2.WSGIApplication([
    ('/', MainPage),
    ('/oauth', OAuthHandler),
    ('/users/(.*)', UserHandler),
    ('/vehicles/(.*)', VehicleHandler),
    ('/user/(.*)/vin/(.*)', UsersVehicleHandler)
], debug=True)