# Ethan Dunham
# Oauth implementation
# CS 496
# 1/19/18
# Sources pythontips.com/2013/07/28/generating-a-random-string/
#		  github.com/joneric/CS-496
#	      developers.google.com/api-client-library/java/google-api-java-client/oauth2

from google.appengine.ext.webapp import template
from google.appengine.api import urlfetch
import webapp2
import urllib
import random
import string
import json
import os

#Global variables to easily change Oauth info between users/programs
CLIENT_ID = '861808281824-3oddqr87b7lpqk6jjru8qo96vm4g3o4m.apps.googleusercontent.com'
CLIENT_SECRET = '8g6njuwTBX9bdgt2XKkLmn0n'
REDIRECT_URI = 'https://oauth-implementation-192621.appspot.com/oauth'

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
		#get the user's information
        result = urlfetch.fetch(
            url="https://www.googleapis.com/plus/v1/people/me",
            method = urlfetch.GET,
            headers=headers)

        json_result = json.loads(result.content)
        # self.response.write(json.dumps(json_result['name']['givenName']))
        name_check = False
        gplink_check = False
		#check response for name and gplink
        for item in json_result:
            if item == 'name':
                if item[0]:
                    name_check = True
            if item == 'url':
                gplink_check = True
		#if data was found
        if name_check and gplink_check:
			#save data to inject into html
            fname = json_result['name']['givenName']
            lname = json_result['name']['familyName']
            gplink = str(json_result['url'])
            template_values = {'fname': fname,
                               'lname': lname,
                               'gplink': gplink,
                               'state': state}
		#missing some data
        else:
            template_values = {'noAccount': "NOTE: No Google+ account found", 'state': state}
		#display correct html page
        path = os.path.join(os.path.dirname(__file__), 'pages/oauthPage.html')
		#inject values into html
        self.response.out.write(template.render(path, template_values))

#page handling info
app = webapp2.WSGIApplication([
    ('/', MainPage),
    ('/oauth',OAuthHandler)
], debug=True)
