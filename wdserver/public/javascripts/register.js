function sign_in(){
    document.getElementById("signup").style.display="none";
    document.getElementById("signin").style.display="block";
    document.getElementById("sin").style.backgroundColor="#ccc";
    document.getElementById("sup").style.backgroundColor="#ddd";
}
function sign_up(){
    document.getElementById("signin").style.display="none";
    document.getElementById("signup").style.display="block";
    document.getElementById("sup").style.backgroundColor="#ccc";
    document.getElementById("sin").style.backgroundColor="#ddd";
}
function register(){
    document.getElementById("rtab").style.display="block";
    document.getElementById("reg").style.display="block";
    document.getElementById("Tab").style.display="none";
    document.getElementById("signup").style.display="none";
}
function submit(){
    document.getElementById("rtab").style.display="none";
    document.getElementById("reg").style.display="none";
}
function cancel(){
    
    document.getElementById("rtab").style.display="none";
    document.getElementById("reg").style.display="none";
    document.getElementById("Tab").style.display="block"; 
    sign_in();
}
function facebook(){
    alert("Facebook login will implement in soon future. . . !");
}
function googleplus(){
    alert("Google Plus login will implement in soon future. . . !");
}
function twitter(){
    alert("Twitter login will implement in soon future. . . !");
}
    var myInput = document.getElementById("psw");
    var letter = document.getElementById("letter");
    var capital = document.getElementById("capital");
    var number = document.getElementById("number");
    var length = document.getElementById("length");

    // When the user clicks on the password field, show the message box
    myInput.onfocus = function () {
        document.getElementById("message").style.display = "block";
    }

    // When the user clicks outside of the password field, hide the message box
    myInput.onblur = function() {
        document.getElementById("message").style.display = "none";
    }

    // When the user starts to type something inside the password field
    myInput.onkeyup = function() {
        // Validate lowercase letters
        var lowerCaseLetters = /[a-z]/g;
        if(myInput.value.match(lowerCaseLetters)) {  
            letter.classList.remove("invalid");
            letter.classList.add("valid");
        } else {
            letter.classList.remove("valid");
            letter.classList.add("invalid");
    }
  
    // Validate capital letters
    var upperCaseLetters = /[A-Z]/g;
    if(myInput.value.match(upperCaseLetters)) {  
        capital.classList.remove("invalid");
        capital.classList.add("valid");
    } else {
        capital.classList.remove("valid");
        capital.classList.add("invalid");
    }

    // Validate numbers
    var numbers = /[0-9]/g;
    if(myInput.value.match(numbers)) {  
        number.classList.remove("invalid");
        number.classList.add("valid");
    } else {
        number.classList.remove("valid");
        number.classList.add("invalid");
    }
  
    // Validate length
    if(myInput.value.length >= 8) {
        length.classList.remove("invalid");
        length.classList.add("valid");
    } else {
        length.classList.remove("valid");
        length.classList.add("invalid");
    }
        
}


function resetPassword(){
    var x = document.getElementById("email").value;
    if(x!=""){
        alert("A reset password link has sent to your Email address!");
    }
    else{
        alert("Enter your email address first!");
    }
}
function checkPassword(){
    var a = document.getElementById("psw").value;
    var b = document.getElementById("cpsw").value;
    if(a != b){
        alert("Passwords are not match, Try again please !");
        sign_up();
    }
}