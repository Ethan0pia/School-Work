import webapp2
from datetime import datetime
#Adapted from https://github.com/GoogleCloudPlatform/python-docs-samples/blob/master/appengine/standard/hello_world/main.py

class MainPage(webapp2.RequestHandler):
    def get(self):
        now = datetime.now()
        self.response.headers['Content-Type'] = 'text/plain'
        self.response.write(now)


app = webapp2.WSGIApplication([
    ('/', MainPage),
], debug=True)
