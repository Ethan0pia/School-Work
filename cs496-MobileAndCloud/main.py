import webapp2
from datetime import datetime
#Adapted from https://github.com/GoogleCloudPlatform/python-docs-samples/blob/master/appengine/standard/hello_world/main.py

now = datetime.now()
time = now.hour+":"+ now.minute+":"+ now.second
class MainPage(webapp2.RequestHandler):
    def get(self):
        self.response.headers['Content-Type'] = 'text/plain'
        self.response.write(time)


app = webapp2.WSGIApplication([
    ('/', MainPage),
], debug=True)
