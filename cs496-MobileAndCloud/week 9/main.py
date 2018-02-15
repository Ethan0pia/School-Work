# Ethan Dunham
# Cloud Only Final Assignment
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
CLIENT_ID = '527379074383-n8prs1s8c6pkl9ntadickctps9uutk7p.apps.googleusercontent.com'
CLIENT_SECRET = 'TNb6u0XRp-TpTGQ9njTxOn4E'
REDIRECT_URI = 'https://cloud-only-final.appspot.com/oauth'

class UserAccount(ndb.Model):
    id = ndb.StringProperty()
	user_id = ndb.StringProperty()
    fname = ndb.StringProperty()
    lname = ndb.StringProperty()
    email = ndb.StringProperty()
	car = ndb.StringProperty()



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

#page handling info
app = webapp2.WSGIApplication([
    ('/', MainPage),
    ('/oauth',OAuthHandler)
], debug=True)
