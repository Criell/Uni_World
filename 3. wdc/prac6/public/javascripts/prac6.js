var posts = [];
var tl;
var txt;

function loadmorePost() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) { 
     posts = JSON.parse(xhttp.responseText);
     document.getElementById("container").innerHTML = this.responseText;
    }
  };
    
  // Initiate connection
  xhttp.open("GET", "posts.json", true);
            
  // Send request
  xhttp.send();
}

function loadPost() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) { 
     posts = JSON.parse(xhttp.responseText);
     document.getElementById("container").innerHTML = posts[0];
    }
  };
    
  // Initiate connection
  xhttp.open("GET", "posts.json", true);
            
  // Send request
  xhttp.send();
}

function morePost() {
    tl = document.getElementById('newPostTitle').value;
    txt = document.getElementById('newPostText').value;
    
    // Create new AJAX request
    var xhttp = new XMLHttpRequest();
    
    // Initiate connection
    xhttp.open("POST", "addPost.json", true);
            
    xhttp.setRequestHeader("Content-type","application/json");
    
    // Send request
    xhttp.send(JSON.stringify({"title": tl, "text":txt}));
    
    document.getElementById("container").innerHTML = tl + " " + txt;
}

        