var express = require('express');
var router = express.Router();

router.post('/updateCustomers', function(req, res) {
    console.log(req.body);
    req.pool.getConnection(function(err, connection){
    	if(err) throw err;
    	var sql = "UPDATE room SET Image=?, hotel_name=?, RoomNumber=?, ReviewScore=?, Adults=?, kids=?, Location=?, Price=? WHERE RNumber=?";
    	connection.query(sql, [req.body.formImage, req.body.formhotel_name, req.body.formRoomNumber, req.body.formReviewScore, req.body.formAdults, req.body.formkids, req.body.formLocation, req.body.formPrice, req.body.ID], function(err, results){
    		console.log(results);
            connection.release();
    	});
    })
});

router.post('/addProfile', function(req, res) {
    console.log(req.body);
    req.pool.getConnection(function(err, connection){
    	if(err) throw err;
    	var sql = "INSERT INTO booking_pay (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) SELECT Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price FROM user_booking WHERE PNumber=+req.body.formID+;";
    	connection.query(sql, function(err, results){
    		console.log(results);
            connection.release();
            res.send({"PNumber":results.insertId});
    	});
    })
});


router.post('/deleteCart', function(req, res) {
    console.log(req.body);
    req.pool.getConnection(function(err, connection){
    	if(err) throw err;
    	var sql = "DELETE FROM user_booking WHERE BNumber='"+req.body.formID+"';";
    	connection.query(sql, function(err, results){
    		console.log(results);
            connection.release();
    	});
    })
});
router.post('/updateProfile', function(req, res) {
    console.log(req.body);
    req.pool.getConnection(function(err, connection){
    	if(err) throw err;
    	var sql = "UPDATE room SET Image=?, hotel_name=?, RoomNumber=?, ReviewScore=?, Check_in_Date=?, Check_in_Out=?, Adults=?, kids=?, Location=?, Price=? WHERE PNumber=?";
    	connection.query(sql, [req.body.formhotel_name, req.body.formRoomNumber, req.body.formReviewScore,req.body.formCheck_in_Date,req.body.formCheck_in_Out, req.body.formAdults, req.body.formkids, req.body.formLocation, req.body.formPrice, req.body.ID], function(err, results){
    		console.log(results);
            connection.release();
    	});
    })
});

router.post('/addCart', function(req, res) {
    console.log(req.body);
    req.pool.getConnection(function(err, connection){
    	if(err) throw err;
    	var sql = "INSERT INTO user_booking (hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUES ('"+req.body.formhotel_name+"', '"+req.body.formRoomNumber+"', '"+req.body.formReviewScore+"', '"+req.body.formCheck_in_Date+"', '"+req.body.formCheck_in_Out+"',  '"+req.body.formAdults+"', '"+req.body.formkids+"', '"+req.body.formLocation+"', '"+req.body.formPrice+"');";
    	connection.query(sql, function(err, results){
    		console.log(results);
            connection.release();
            res.send({"BNumber":results.insertId});
    	});
    })
});


router.get('/getCart', function(req, res){
	req.pool.getConnection(function(err, connection){
		if(err) throw err;
		var sql = "SELECT Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price FROM user_booking";
		connection.query(sql, function(err, results){
			connection.release();
			console.log(results);
			res.send(results);
		});
	});
});

router.get('/getProfile', function(req, res){
	req.pool.getConnection(function(err, connection){
		if(err) throw err;
		var sql = "SELECT Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price FROM booking_pay";
		connection.query(sql, function(err, results){
			connection.release();
			console.log(results);
			res.send(results);
		});
	});
});

router.post('/addReview', function(req, res) {
    console.log(req.body);
    req.pool.getConnection(function(err, connection){
    	if(err) throw err;
    	var sql = "INSERT INTO reviews (hotel_name, rev_text) VALUES ('"+req.body.formHotel+"','"+req.body.formPost+"');";
    	connection.query(sql, function(err, results){
    		console.log(results);
            connection.release();
            res.send({"RevNumber":results.insertId});
    	});
    })
});


router.get('/getReview', function(req, res){
	req.pool.getConnection(function(err, connection){
		if(err) throw err;
		var sql = "SELECT hotel_name, rev_text FROM reviews";
		connection.query(sql, function(err, results){
			connection.release();
			console.log(results);
			res.send(results);
		});
	});
});

router.post('/addCustomers', function(req, res) {
    console.log(req.body);
    req.pool.getConnection(function(err, connection){
    	if(err) throw err;
    	var sql = "INSERT INTO room (Image, hotel_name, RoomNumber, ReviewScore, Adults, kids, Location, Price) VALUES ('"+req.body.formImage+"', '"+req.body.formhotel_name+"', '"+req.body.formRoomNumber+"', '"+req.body.formReviewScore+"', '"+req.body.formAdults+"', '"+req.body.formkids+"', '"+req.body.formLocation+"', '"+req.body.formPrice+"');";
    	connection.query(sql, function(err, results){
    		console.log(results);
            connection.release();
            res.send({"RNumber":results.insertId});
    	});
    })
});

router.get('/getCustomer', function(req, res){
	req.pool.getConnection(function(err, connection){
		if(err) throw err;
		var sql = "SELECT Image, hotel_name, RoomNumber, ReviewScore, Adults, kids, Location, Price FROM room";
		connection.query(sql, function(err, results){
			connection.release();
			console.log(results);
			res.send(results);
		});
	});
});

var CLIENT_ID = "1065638520314-kn571dtifa0uhbt20vh0ckf3e2ebg0tm.apps.googleusercontent.com";
var {OAuth2Client} = require('google-auth-library');
var client = new OAuth2Client(CLIENT_ID);

// upload user.jason into users
var fs=require('fs');
var data=fs.readFileSync('data/user.json');
var users=JSON.parse(data);

// global variables to store user information
var username;
var password;
var googleID;

// session object
var sessions = {};

router.post('/user.json', function(req, res) {

    var user = null;

//Some output just for test
    console.log(JSON.stringify(req.body));
    if(req.body.username && req.body.password){
    username=req.body.username;
    password=req.body.password;

    console.log(username);
    console.log(password);
  }

// If login details present, attempt login
    if(req.body.username && req.body.password){
        console.log("Username + Password received");

        if(username && password && googleID){
            users.push({"username":username,"password":password,"google":googleID});
            var newData = JSON.stringify(users);
            fs.writeFile('data/user.json',newData,added);

            function added(err){
                console.log('New user added to user.json');
                console.log(err);
                console.log(users);
            }
        }

        for (var i=0; i<users.length; i++){
            if(users[i].username === req.body.username && users[i].password === req.body.password){
                sessions[req.session.id] = req.body.username;
                user = req.body.username;
            }
        }
        res.json({username:user});

    }
// If google login token present
    else if(req.body.idtoken !== undefined) {
        console.log("Google Token Recieved");
        async function verify() {
            // Verify google ID token
            const ticket = await client.verifyIdToken({
                idToken: req.body.idtoken,
                audience: CLIENT_ID
            });

            // Get user data from token
            const payload = ticket.getPayload();

            // Get user's Google ID
            const userid = payload['sub'];
            googleID=userid;

            for (var i=0; i<users.length; i++){
                /*
                 * If google ID matches a user
                 * save the session
                 * send that username
                 * (otherwise user will remain null)
                 */
                if(users[i].google === userid){
                    sessions[req.session.id] = users[i].username;
                    user = users[i].username;
                }
            }
            res.json({username:user});
        }
        verify().catch(console.error);


    }
    // If no login details, but valid session
    else if(sessions[req.session.id] !== undefined) {
        console.log("Valid session");
        user = sessions[req.session.id];
        res.json({username:user});
    }
    else if(user === null)
        res.json({username:null});
});

module.exports = router;
