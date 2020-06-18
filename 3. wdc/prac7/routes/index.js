var express = require('express');
var router = express.Router();

var path = require('path');

/* GET home page. */
router.get('/', function(req, res, next) {
  res.status(200).sendFile('login.html', { root: path.join(__dirname, '../public/') });
});

module.exports = router;
