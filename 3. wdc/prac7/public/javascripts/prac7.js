var user = [];

function FindUser() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) { 
        user = JSON.parse(xhttp.responseText);
        xhttp.open("GET", "user.json", true);
        res.redirect('account.html');
    }
  }
};

        