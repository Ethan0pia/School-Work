# Ethan Dunham
# REST Planning and Implementation
# 01/16/2018
# Sources: media.oregonstate.edu/media/t/0_nph1lmls
#		   github.com/joneric/CS-496
from google.appengine.ext import ndb
import webapp2
import json

#boat object
class Boat(ndb.Model):
    id = ndb.StringProperty()
    name = ndb.StringProperty(required=True)
    type = ndb.StringProperty(required=True)
    length = ndb.IntegerProperty(required=True)
    at_sea = ndb.BooleanProperty()

#slip object
class Slip(ndb.Model):
    id = ndb.StringProperty()
    number = ndb.IntegerProperty(required=True)
    current_boat = ndb.StringProperty(required=True)
    arrival_date = ndb.StringProperty(required=True)

#main page handler
class MainPage(webapp2.RequestHandler):
    def get(self):
        self.response.write("Welcome to the marina! This is a wake free area!")

#boat handler
class BoatHandler(webapp2.RequestHandler):
	#add boat
    def post(self):
		#load boat info
        received_data = json.loads(self.request.body)
		#set required field checks
        has_name = False
        has_type = False
        has_length = False
		#loop through items in the JSON
        for value in received_data:
            if value == "name":
                has_name = True
            elif value == "type":
                has_type = True
            elif value == "length":
                has_length = True
		#Make boat if we received all the required information
        if has_name and has_type and has_length:
            new_boat = Boat(name=received_data['name'], type=received_data['type'], length=received_data['length'])
            new_boat.at_sea = True
            new_boat.put()
			#create reference id that is URL safe
            new_boat.id = str(new_boat.key.urlsafe())
            new_boat.put()
			#create response JSON
            new_boat_dict = new_boat.to_dict()
            new_boat_dict['self'] = '/boats/' + new_boat.key.urlsafe()
            self.response.write(json.dumps(new_boat_dict))
        else:
			#Missing some input that is required to make a boat
            self.response.status = 400
            self.response.write("ERROR: the expected format is {\"name\": \"str\", \"length\": int, \"type\": \"str\"}.")

	#get boat by ID
    def get(self, id=None):
		#if ID is not null
        if id:
            has_boat = False
			#check for boat
            for boat in Boat.query():
                if boat.id == id:
                    has_boat = True
            if has_boat:
				#create return JSON
                this_boat = ndb.Key(urlsafe=id).get()
                this_boat_dict = this_boat.to_dict()
                this_boat_dict['self'] = "/boats/" + id
                self.response.write(json.dumps(this_boat_dict))
            else:
				#The id was not found
                self.response.status = 401
                self.response.write("ERROR: a boat with that id does not exist.")
        else:
			#no id, return all boats
            boats_query_results = [boat_query.to_dict()
                                      for boat_query in Boat.query()]
            for boat in boats_query_results:
                boat['self'] = "/boats/" + str(boat['id'])
            self.response.write(json.dumps(boats_query_results))

	#remove a boat by ID
    def delete(self, id=None):
		#if ID is not null
        if id:
            has_boat = False
			#check boats for ID
            for boat in Boat.query():
                if boat.id == id:
                    has_boat = True
            if has_boat:
                reset_slip = False
				#find slip that boat is in
                for slip in Slip.query(Slip.current_boat == id):
					#reset slip to be available
                    if slip.current_boat and slip.arrival_date:
                        slip.current_boat = ""
                        slip.arrival_date = ""
                        slip.put()
                        reset_slip = True
				#return if the boat was in a slip
                if reset_slip:
                    ndb.Key(urlsafe=id).delete()
                    self.response.write("SUCCESS: the boat was deleted and the slip emptied.")
				#return if boat was not in a slip
                else:
                    ndb.Key(urlsafe=id).delete()
                    self.response.write("SUCCESS: the boat was deleted and was not in a slip.")
			#boat was not found to delete
            else:
                self.response.status = 401
                self.response.write("ERROR: a boat with that ID does not exist.")

	#edit a boat
    def patch(self, id=None):
        if id:
            boat_data = json.loads(self.request.body)
            has_boat = False
			#search for boat
            for boat in Boat.query():
                if boat.id == id:
                    has_boat = True
			#if boat is found
            if has_boat:
				#get the boat object to edit
                patch_boat = ndb.Key(urlsafe=id).get()
				#check to verify that only 1 field is being edited by request.
                if len(boat_data) > 1:
                    self.response.status = 400
                    self.response.write("ERROR: the expected format is {\"name\": \"str\"} or {\"length\": int} or {\"type\": \"str\"}.")
                else:
					#change the pertinent info in the boat object
                    for key in boat_data:
                        if key == "name":
                            patch_boat.name = boat_data['name']
                            patch_boat.put()
                            self.response.write("SUCCESS: the boat's 'name' was updated.")
                        elif key == "type":
                            patch_boat.type = boat_data['type']
                            patch_boat.put()
                            self.response.write("SUCCESS: the boat's 'type' was updated.")
                        elif key == "length":
                            patch_boat.length = boat_data['length']
                            patch_boat.put()
                            self.response.write("SUCCESS: the boat's 'length' was updated.")
						#info sent is not one of the 3 things that can be patched
                        else:
                            self.response.status = 400
                            self.response.write("ERROR: the expected format is {\"name\": \"str\"} or {\"length\": int} or {\"type\": \"str\"}.")
			#boat not found
            else:
                self.response.status = 401
                self.response.write("ERROR: a boat with that ID does not exist.")

	#edits all the boat's info
    def put(self, id=None):
        if id:
            put_boat_data = json.loads(self.request.body)
            has_boat = False
			#find boat
            for boat in Boat.query():
                if boat.id == id:
                    has_boat = True
            if has_boat:
				#get boat object
                put_boat = ndb.Key(urlsafe=id).get()
                input_name = False
                input_type = False
                input_length = False
				#check data for the 3 fields
                for item in put_boat_data:
                    if item == "name":
                        input_name = True
                    elif item == "type":
                        input_type = True
                    elif item == "length":
                        input_length = True
				#update boat if all fields were sent
                if input_name and input_type and input_length:
                    put_boat.name = put_boat_data['name']
                    put_boat.type = put_boat_data['type']
                    put_boat.length = put_boat_data['length']
                    put_boat.put()
                    self.response.write("SUCCESS: the boat's 'name', 'type', and 'length' were updated.")
                else:
					#missing at least 1 field
                    self.response.status = 400
                    self.response.write("ERROR: the expected format is {\"name\": \"str\", \"length\": int, \"type\": \"str\"}.")
            else:
				#boat not found
                self.response.status = 401
                self.response.write("ERROR: a boat with that ID does not exist.")

#deals with slips
class SlipHandler(webapp2.RequestHandler):
	#create a new slip
    def post(self):
        post_slip_data = json.loads(self.request.body)
		#get list of existing slips
        post_slip_query_results = [post_slip_query.to_dict() for post_slip_query in Slip.query()]
        input_number = False
		#make sure a slip number was sent
        for item in post_slip_data:
            if item == "number":
                input_number = True
        if input_number:
            in_use = False
			#verify that slip number is available
            for slip in post_slip_query_results:
                if slip['number'] == post_slip_data['number']:
                    in_use = True
                    self.response.status = 403
                    self.response.write("ERROR: that slip number is already in use.")
            if not in_use:
				#create new slip object
                post_slip = Slip(number=post_slip_data['number'])
                post_slip.current_boat = ""
                post_slip.arrival_date = ""
                post_slip.put()
				#create url save id
                post_slip.id = str(post_slip.key.urlsafe())
                post_slip.put()
				#create return JSON
                post_slip_dict = post_slip.to_dict()
                post_slip_dict['self'] = '/slips/' + post_slip.key.urlsafe()
                self.response.write(json.dumps(post_slip_dict))
		#incorrect format to create slip
        else:
            self.response.status = 400
            self.response.write("ERROR: the expected format is {\"number\": int}.")

	#get slip(s)
    def get(self, id=None):
        if id:
            has_slip = False
			#search for slip id
            for slip in Slip.query():
                if slip.id == id:
                    has_slip = True
            if has_slip:
				#get slip object
                get_slip = ndb.Key(urlsafe=id).get()
				#create retirn JSON
                get_slip_dict = get_slip.to_dict()
                get_slip_dict['self'] = "/slips/" + id
                self.response.write(json.dumps(get_slip_dict))
			#slip doesn't exist
            else:
                self.response.status = 401
                self.response.write("ERROR: a slip with that ID does not exist")
		#return all slips
        else:
			#create return JSON of all slips
            get_slip_query_results = [get_slip_query.to_dict() for get_slip_query in Slip.query()]
            for slip in get_slip_query_results:
                slip['self'] = "/slips/" + str(slip['id'])
            self.response.write(json.dumps(get_slip_query_results))

	#delete slip
    def delete(self, id=None):
        if id:
            has_slip = False
			#check if slip exists
            for slip in Slip.query():
                if slip.id == id:
                    has_slip = True
            if has_slip:
				#get the slip object
                delete_slip = ndb.Key(urlsafe=id).get()
				#check if it has a boat
                if delete_slip.current_boat:
					#get boat object and set to at sea
                    boat_in_the_slip = ndb.Key(urlsafe=delete_slip.current_boat).get()
                    boat_in_the_slip.at_sea = True;
                    boat_in_the_slip.put()
                    delete_slip.key.delete()
                    self.response.write("SUCCESS: the slip was deleted and the boat was sent out to sea.")
                else:
					#no boat in slip
                    delete_slip.key.delete()
                    self.response.write("SUCCESS: there was no boat in the slip and the slip was deleted.")
			#no slip with the sent ID
            else:
                self.response.status = 401
                self.response.write("ERROR: a slip with that ID does not exist.")

	#patch a slip
    def patch(self, id=None):
        if id:
            patch_slip_data = json.loads(self.request.body)
            has_slip = False
			#check if slip exists
            for slip in Slip.query():
                if slip.id == id:
                    has_slip = True
            if has_slip:
                patch_slip = ndb.Key(urlsafe=id).get()
				#verify only 1 value was sent to change
                if len(patch_slip_data) > 1:
                    self.response.status = 400
                    self.response.write("ERROR: the expected format is {\"number\": int}.")
                else:
					#find the slip object
                    for key in patch_slip_data:
                        if key == "number":
                            patch_slip_query_results = [patch_slip_query.to_dict() for patch_slip_query in Slip.query()]
                            found_it = False
							#make sure the new slip number is valid
                            for slip in patch_slip_query_results:
                                if slip['number'] == patch_slip_data['number']:
                                    found_it = True
                                    self.response.status = 403
                                    self.response.write("ERROR: that slip number is already in use.")
							#patch the slip with the new number
                            if not found_it:
                                patch_slip.number = patch_slip_data['number']
                                patch_slip.put()
                                self.response.write("SUCCESS: the slip 'number' was updated.")
						#a number was not sent in the patch
                        else:
                            self.response.status = 400
                            self.response.write("ERROR: the expected format is {\"number\": int}.")
			#could not find slip
            else:
                self.response.status = 401
                self.response.write("ERROR: a slip with that ID does not exist.")

#handles boats inside a slip
class BoatInSlipHandler(webapp2.RequestHandler):
	#returns a boat in a slip
    def get(self, id=None):
        if id:
            has_slip = False
			#find the requested slip by ID
            for slip in Slip.query():
                if slip.id == id:
                    has_slip = True
            if has_slip:
				#get slip object
                get_slip = ndb.Key(urlsafe=id).get()
				#empty slip
                if get_slip.current_boat == "":
                    self.response.write("SUCCESS: there is no boat in slip")
                else:
					#get boat object
                    get_boat = ndb.Key(urlsafe=get_slip.current_boat).get()
					#build return JSON
                    boat_dict = get_boat.to_dict()
                    boat_dict['self'] = "/boats/" + get_slip.current_boat
                    self.response.write(json.dumps(boat_dict))
			#no slip with that id
            else:
                self.response.status = 401
                self.response.write("ERROR: a slip with that ID does not exist.")

	#put a boat in a slip
    def put(self, id=None):
        if id:
            put_data = json.loads(self.request.body)
            has_slip = False
			#check if slip with that id exists
            for slip in Slip.query():
                if slip.id == id:
                    has_slip = True
            if has_slip:
				#get slip object
                put_slip = ndb.Key(urlsafe=id).get()
                input_current_boat = False
                input_arrival_date = False
                for item in put_data:
                    if item == "current_boat":
                        input_current_boat = True
                    elif item == "arrival_date":
                        input_arrival_date = True
				#verify required info was given
                if input_current_boat and input_arrival_date:
                    boat_exists = False
					#check if boat exists
                    for boat in Boat.query():
                        if boat.id == put_data['current_boat']:
                            boat_exists = True
                    if boat_exists:
						#get boat object
                        put_boat = ndb.Key(urlsafe=put_data['current_boat']).get()
                        if put_boat.at_sea:
							#add boat info to slip
                            if put_slip.current_boat == "":
                                put_slip.current_boat = put_data['current_boat']
                                put_slip.arrival_date = put_data['arrival_date']
                                put_slip.put()
                                put_boat.at_sea = False
                                put_boat.put()
                                self.response.write("SUCCESS: the boat was brought in from the sea and added to the slip.")
                            else:
                                self.response.status = 403
                                self.response.write("ERROR: that slip is already taken.")
                        else:
                            self.response.status = 403
                            self.response.write("ERROR: that boat is already assigned a slip. There is no reason to move it.")
                    else:
                        self.response.status = 401
                        self.response.write("ERROR: a boat with that ID does not exist.")
                else:
                    self.response.status = 400
                    self.response.write("ERROR: the expected format is {\"current_boat\": \"boat_id\", \"arrival_date\": \"YYYY-MM-DD\"}.")
            else:
                self.response.status = 401
                self.response.write("ERROR: a slip with that ID does not exist.")

	#remove a slip
    def delete(self, id=None):
        if id:
            has_slip = False
			#check if slip exists
            for slip in Slip.query():
                if slip.id == id:
                    has_slip = True
            if has_slip:
				#get slip object
                slip = ndb.Key(urlsafe=id).get()
                if slip.current_boat:
					#get boat object and set to at sea
                    boat_in_slip = ndb.Key(urlsafe=slip.current_boat).get()
                    boat_in_slip.at_sea = True
                    boat_in_slip.put()
                    slip.current_boat = ""
                    slip.arrival_date = ""
                    slip.put()
                    self.response.write("SUCCESS: the boat was removed from the slip and sent to sea.")
                else:
                    self.response.status = 403
                    self.response.write("ERROR: there is no boat in that slip.")
            else:
                self.response.status = 401
                self.response.write("ERROR: a slip with that ID does not exist.")

#allow patching
allowed_methods = webapp2.WSGIApplication.allowed_methods
new_allowed_methods = allowed_methods.union(('PATCH',))
webapp2.WSGIApplication.allowed_methods = new_allowed_methods
#initialize page handling
app = webapp2.WSGIApplication([
    ('/', MainPage),
    ('/boats',BoatHandler),
    ('/boats/(.*)',BoatHandler),
    ('/slips',SlipHandler),
    ('/slips/(.*)/boat',BoatInSlipHandler),
    ('/slips/(.*)',SlipHandler)
], debug=True)
