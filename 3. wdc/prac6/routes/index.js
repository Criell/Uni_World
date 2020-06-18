var express = require('express');
var router = express.Router();

var text_date = ' ';

router.get('/log.html', function(req, res, next) {
    text_date = text_date + '<li>' + new Date() + '</li>'; 
    res.send('<!DOCTYPE html> \
<html> \
    <head> \
    <title>My Page</title> \
    </head> \
    <body> \
        <ul>'+text_date+'</ul> \
    </body> \
</html>');
});

var fs = require('fs');

var posts = [];

fs.readFile('data/posts.json', 'utf8', function(err, data) { 
    posts = JSON.parse(data);
});

router.get('/posts.json', function(req, res) {
    res.send(JSON.stringify(posts));
});

router.post('/addPost.json', function(req, res) {
    console.log(req.body);
    res.send({title:req.body.title, text :req.body.text});
});

router.post('/ajax.html', function(req, res, next) {
    res.send (req.body);
});

module.exports = router;
