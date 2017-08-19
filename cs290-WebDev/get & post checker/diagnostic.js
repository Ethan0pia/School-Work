/***********************************************************************************************************************************
*** Author: Ethan Dunham/ CS290 lectures http://eecs.oregonstate.edu/ecampus-video/CS290/core-content/hello-node/express-forms.html
*** date: 5/19/17
*** This is a get and post checker for a server
************************************************************************************************************************************/

var express = require('express');

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', process.argv[2]);


var bodyParser = require('body-parser');
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

//get info; from lecture http://eecs.oregonstate.edu/ecampus-video/CS290/core-content/hello-node/express-forms.html
app.get('/', function (req, res) {
    var params = [];
    for (var p in req.query) {
        params.push({ 'name': p, 'data': req.query[p] })
    }
    var context = {};
    context.dataList = params;
    res.render('get', context);
});

//get access to info sent ; from lecture http://eecs.oregonstate.edu/ecampus-video/CS290/core-content/hello-node/express-forms.html
app.post('/', function (req, res) {
    var params = [];
    for (var p in req.body) {
        params.push({ 'name': p, 'data': req.body[p] })
    }
    var context = {};
    context.dataList = params;
    res.render('post', context);
});

app.use(function (req, res) {
    res.status(404);
    res.render('404');
});

app.use(function (err, req, res, next) {
    console.log(err.stack);
    res.status(500);
    res.render('500');
});

app.listen(app.get('port'), function () {
    console.log('Express started on port 43492');
});
