/*exported addcar editcarH editcarP editcarProf gocarP gohome goreg gocar remove remove_all comments  backPprof backHprof addRoom editRoom addPost commets_off commets_on hideHprof goPP editinfoH editinfoP editcar loadPost sendPost addcarprof loadPostProf*/
/*eslint-env browser*/

var img;
var hotelname;
var roomnumber;
var score;
var Din;
var Dout;
var adults;
var childen;
var loc;
var price;

var roomid = 1;
var profid = 1;
var cartid = 1;
var Bname;

// Create JSON data form elements into 
function createJSON(formElements){
    var dat = {};
    console.log(formElements);
    var i;
    for(i = 0; i <formElements.length; i++){   
        dat[formElements[i].name] = formElements[i].value;
    }
    return(dat)
}

function updateCustomers() {
    var form = document.getElementById('frm1');
    var dat = createJSON(form.getElementsByClassName('formElement'));

    console.log(dat);

    // Create new AJAX request
    var xhttp = new XMLHttpRequest();
            
    xhttp.onreadystatechange = function(){
        if(this.readyState == 4 && this.status == 200){
        var response = JSON.parse(xhttp.responseText);
        console.log(response);
        }
    }
    
    // Initiate connection
    xhttp.open("POST", "/updateCustomers", true);
            
    xhttp.setRequestHeader("Content-type","application/json");
            
    // Send request
    xhttp.send(JSON.stringify(dat));
} 


function editcarH(obj){
    document.getElementById("Hprofile").style.display = 'none'; 
    document.getElementById("editarea").style.display = 'block';
    document.getElementById("noedit").style.display = 'none'; 
    document.getElementById("edit").style.display = 'block';
    ID = obj.id;
    Bname = "B" + ID;     
}

function editinfoP(){
    var x = document.getElementById(Bname);
    var y = document.getElementById("frm3");
    hotelname = y.elements[0].value;
    roomnumber = y.elements[1].value;
    score = y.elements[2].value;
    Din = y.elements[3].value;
    Dout = y.elements[4].value;
    adults = y.elements[5].value;
    childen = y.elements[6].value;
    loc = y.elements[7].value;
    price = y.elements[8].value;
    
    x.getElementsByClassName("hotel")[0].innerHTML = hotelname; 
    x.getElementsByClassName("number")[0].innerHTML = roomnumber;
    x.getElementsByClassName("score")[0].innerHTML = score;   x.getElementsByClassName("info1")[0].innerHTML = Din;
    x.getElementsByClassName("info2")[0].innerHTML = Dout;
    x.getElementsByClassName("info3")[0].innerHTML = adults;
    x.getElementsByClassName("info4")[0].innerHTML = childen;
    x.getElementsByClassName("info5")[0].innerHTML = loc;
    x.getElementsByClassName("price")[0].innerHTML = price;
    document.getElementById("booking_sec").style.display = 'block'; 
    document.getElementById("editareaP").style.display = 'none';
}


function editcarProf(obj){
    document.getElementById("booking_sec").style.display = 'none'; 
    document.getElementById("editareaP").style.display = 'block'; 
    ID = obj.id;
    Bname = "P" + ID; 
}



function editinfoH(){
    var x = document.getElementById(Bname);
    var y = document.getElementById("frm1");
    
    img = y.elements[0].value;
    hotelname = y.elements[1].value;
    roomnumber = y.elements[2].value;
    score = y.elements[3].value;
    adults = y.elements[4].value;
    childen = y.elements[5].value;
    loc = y.elements[6].value;
    price = y.elements[7].value;
    
    var datos = [{"formImage" : img, "formhotel_name" : hotelname,  "formRoomNumber" : roomnumber, "formReviewScore" : score, "formAdults" : adults, "formkids" : childen,  "formLocation" : loc, "formPrice" : price, "ID " : ID}]; 
    
    updateCustomers(datos);
    
    x.getElementsByClassName("image")[0].innerHTML = img;
    x.getElementsByClassName("hotel")[0].innerHTML = "Hotel Name: " + hotelname; 
    x.getElementsByClassName("number")[0].innerHTML = " - Room Number: " + roomnumber;
    x.getElementsByClassName("score")[0].innerHTML = " - Review Score: " + score;
    x.getElementsByClassName("info3")[0].innerHTML = " - # Adults: " + adults;
    x.getElementsByClassName("info4")[0].innerHTML = " - #Childen: " + childen;
    x.getElementsByClassName("info5")[0].innerHTML = " - Location: " + loc;
    x.getElementsByClassName("price")[0].innerHTML = "AUD $" + price;
    
    document.getElementById("Hprofile").style.display = 'block'; 
    document.getElementById("editarea").style.display = 'none';
}



function remove(obj){
    ID = obj.id;
    Bname = "C" + ID; 
    var y = document.getElementById(Bname);
    y.style.display = 'none';
    deleteCart();
}

function addProfile() {
    
    var datos = {"ID" : ID};
    console.log(datos);
    // Create new AJAX request
    var xhttp = new XMLHttpRequest();            
    xhttp.onreadystatechange = function(){
        if(this.readyState == 4 && this.status == 200){
        var response = JSON.parse(xhttp.responseText);
        console.log(response);
        }
    }
    // Initiate connection
    xhttp.open("POST", "/addProfile", true);            
    xhttp.setRequestHeader("Content-type","application/json");      
    // Send request
    xhttp.send(JSON.stringify(datos));
}


function deleteCart() {
    
    var datos = {"ID " : ID};
    
    console.log(datos);
     
    // Create new AJAX request
    var xhttp = new XMLHttpRequest();            
    xhttp.onreadystatechange = function(){
        if(this.readyState == 4 && this.status == 200){
        var response = JSON.parse(xhttp.responseText);
        console.log(response);
        }
    }
    // Initiate connection
    xhttp.open("POST", "/deleteCart", true);            
    xhttp.setRequestHeader("Content-type","application/json");     
    // Send request
    xhttp.send(JSON.stringify(datos));
}


function remove_all(){
    var i;
    for (i = cartid-1; i > 0; i--){
        Bname = "C" + i; 
        ID = document.getElementById(Bname);
        ID.style.display = 'none';
    }
}

function getCart(){
    // Create new AJAX request
    var xhttp = new XMLHttpRequest();

    // Define behaviour for a response
    xhttp.onreadystatechange = function() {        
        if (this.readyState == 4 && this.status == 200) {
            var customers = JSON.parse(xhttp.responseText);
            var select = document.getElementById('Scart');
            select.innerHTML = "";
            var i;        
            for(i=0; i<customers.length ; i++){
                img = customers[i].Image;
                hotelname = customers[i].hotel_name;
                roomnumber = customers[i].RoomNumber;
                score = customers[i].ReviewScore;
                Din = customers[i].Check_in_Date;
                Dout = customers[i].Check_in_Out;
                adults = customers[i].Adults;
                childen = customers[i].kids;
                loc = customers[i].Location;
                price = customers[i].Price;
                addcar();
            }
        }
    };

    // Initiate connection
    xhttp.open("GET", "/getCart", true);
    xhttp.send();
}  

function getProfile(){
    getReview();
    // Create new AJAX request
    var xhttp = new XMLHttpRequest();

    // Define behaviour for a response
    xhttp.onreadystatechange = function() {        
        if (this.readyState == 4 && this.status == 200) {
            var customers = JSON.parse(xhttp.responseText);
            var select = document.getElementById('booking_sec');
            select.innerHTML = "";
            var i;        
            for(i=0; i<customers.length ; i++){
                img = customers[i].Image;
                hotelname = customers[i].hotel_name;
                roomnumber = customers[i].RoomNumber;
                score = customers[i].ReviewScore;
                Din = customers[i].Check_in_Date;
                Dout = customers[i].Check_in_Out;
                adults = customers[i].Adults;
                childen = customers[i].kids;
                loc = customers[i].Location;
                price = customers[i].Price;
                addcarprof();
            }
        }
    };

    // Initiate connection
    xhttp.open("GET", "/getProfile", true);
    xhttp.send();
}  

function addReview() {
    var hotel = document.getElementById("txt_hotel").value;
    var rev = document.getElementById("txt_post").value;
    var dat = {"formHotel": hotel, "formPost": rev};
    
    console.log(dat);
    // Create new AJAX request
    var xhttp = new XMLHttpRequest();            
    xhttp.onreadystatechange = function(){
        if(this.readyState == 4 && this.status == 200){
        var response = JSON.parse(xhttp.responseText);
        console.log(response);
        }
    }
    // Initiate connection
    xhttp.open("POST", "/addReview", true);            
    xhttp.setRequestHeader("Content-type","application/json");      
    // Send request
    xhttp.send(JSON.stringify(dat));
    
    getReview();
}

function getReview(){
    // Create new AJAX request
    var xhttp = new XMLHttpRequest();

    // Define behaviour for a response
    xhttp.onreadystatechange = function() {        
        if (this.readyState == 4 && this.status == 200) {
            var customers = JSON.parse(xhttp.responseText);
            var select = document.getElementById('posts');
            select.innerHTML = "";
            var i;        
            for(i=0; i < customers.length ; i++){
                select.innerHTML += "<div><span>"+customers[i].hotel_name+"</span><span>'-'"+customers[i].rev_text+"</span></div>";
            }
        }
    };

    // Initiate connection
    xhttp.open("GET", "/getReview", true);
    xhttp.send();
}  


function addCustomers() {
    addRoom();
    var form = document.getElementById('frm1');
    var dat = createJSON(form.getElementsByClassName('formElement'));
    console.log(dat);
    // Create new AJAX request
    var xhttp = new XMLHttpRequest();            
    xhttp.onreadystatechange = function(){
        if(this.readyState == 4 && this.status == 200){
        var response = JSON.parse(xhttp.responseText);
        console.log(response);
        }
    }
    // Initiate connection
    xhttp.open("POST", "/addCustomers", true);            
    xhttp.setRequestHeader("Content-type","application/json");
    // Send request
    xhttp.send(JSON.stringify(dat));
}


function getCustomer(){
    // Create new AJAX request
    var xhttp = new XMLHttpRequest();

    // Define behaviour for a response
    xhttp.onreadystatechange = function() {        
        if (this.readyState == 4 && this.status == 200) {
            var customers = JSON.parse(xhttp.responseText);
            var select = document.getElementById('Hprofile');
            select.innerHTML = "";
            var i;        
            for(i=0; i<customers.length ; i++){
                img = customers[i].Image;
                hotelname = customers[i].hotel_name;
                roomnumber = customers[i].RoomNumber;
                score = customers[i].ReviewScore;
                adults = customers[i].Adults;
                childen = customers[i].kids;
                loc = customers[i].Location;
                price = customers[i].Price;
                createRoom();
            }
        }
    };

    // Initiate connection
    xhttp.open("GET", "/getCustomer", true);
    xhttp.send();
}    

function addcarprof() {    
    var carnode01 = document.createElement('section');
    var name = profid;
    profid++;
    carnode01.id = ("P" + name);
    carnode01.className = "ck_cart_info";
    var carnode02 = document.createElement('div'); 
    carnode02.className = "ck_product";
    var carnode03 = document.createElement("IMG");
    carnode03.className="ck_img bookElement";
    carnode03.id = "image";
    carnode03.setAttribute("src", img);
    var carnode04 = document.createElement('p'); 
    var carnode05 = document.createElement('h3'); 
    var carnode05text = document.createTextNode("AUD " + price);
    carnode05.className = "price bookElement";
    carnode05.appendChild(carnode05text);
    var carnode06 = document.createElement('div');
    carnode06.className ="ck_product";
    var carnode07 = document.createElement('h4'); 
    carnode07.className = "info0";    
    var carnode08 = document.createElement('span');
    var carnode08text = document.createTextNode("Hotel Name: " + hotelname);
    carnode08.className = "hotel bookElement";
    carnode08.appendChild(carnode08text);
    var carnode09 = document.createElement('span');
    carnode09.className = "number bookElement";
    var carnode09text = document.createTextNode(" - Room Number: " + roomnumber);
    carnode09.appendChild(carnode09text);
    var carnode10 = document.createElement('span');
    carnode10.className = "score bookElement";
    var carnode10text = document.createTextNode(" - Review Score: " + score);
    carnode10.appendChild(carnode10text);
    var carnode12 = document.createElement('span');
    var carnode12text = document.createTextNode("Check-in Date: "+Din);
    carnode12.appendChild(carnode12text);
    carnode12.className = "info1 bookElement";     
    var carnode13 = document.createElement('span');
    var carnode13text = document.createTextNode(" - Check-out Date: " + Dout);
    carnode13.appendChild(carnode13text);
    carnode13.className = "info2 bookElement";
    var carnode14 = document.createElement('span');
    var carnode14text = document.createTextNode(" - # Adults: " + adults);
    carnode14.appendChild(carnode14text);
    carnode14.className = "info3 bookElement";
    var carnode15 = document.createElement('span');
    var carnode15text = document.createTextNode(" - # Childen: " + childen);
    carnode15.appendChild(carnode15text);
    carnode15.className = "info4 bookElement";
    var carnode16 = document.createElement('span');
    var carnode16text = document.createTextNode(" - Location: " + loc);
    carnode16.appendChild(carnode16text);
    carnode16.className = "info5 bookElement";
    var carnode17 = document.createElement('div');
    carnode17.className = "ck_info"; 
    var carnode18 = document.createElement('button');
    carnode18.className = "ck_button";
    carnode18.id = name;
    carnode18.setAttribute( "onClick", "javascript: editcarProf(this);");
    var carnode18text = document.createTextNode("Edit");
    carnode18.appendChild(carnode18text);
   
    carnode01.appendChild(carnode02);
    carnode02.appendChild(carnode03);
    carnode02.appendChild(carnode04);
    carnode02.appendChild(carnode05);
    carnode01.appendChild(carnode06);
    carnode06.appendChild(carnode07);
    carnode07.appendChild(carnode08);
    carnode07.appendChild(carnode09);
    carnode07.appendChild(carnode10);
    carnode06.appendChild(carnode12);
    carnode06.appendChild(carnode13);
    carnode06.appendChild(carnode14);
    carnode06.appendChild(carnode15);
    carnode06.appendChild(carnode16);
    carnode01.appendChild(carnode17);
    carnode17.appendChild(carnode18); 
    
 document.getElementById("booking_sec").appendChild(carnode01);
}


function addcar() {    
    var carnode01 = document.createElement('section');
    var name = cartid;
    cartid++;
    carnode01.id = ("C" + name);
    carnode01.className = "ck_cart_info";
    var carnode02 = document.createElement('div'); 
    carnode02.className = "ck_product";
    var carnode03 = document.createElement("IMG");
    carnode03.className="ck_img bookElement";
    carnode03.id = "image";
    carnode03.setAttribute("src", img);
    var carnode04 = document.createElement('p'); 
    var carnode05 = document.createElement('h3'); 
    var carnode05text = document.createTextNode("AUD " + price);
    carnode05.className = "price bookElement";
    carnode05.appendChild(carnode05text);
    var carnode06 = document.createElement('div');
    carnode06.className ="ck_product";
    var carnode07 = document.createElement('h4'); 
    carnode07.className = "info0";    
    var carnode08 = document.createElement('span');
    var carnode08text = document.createTextNode("Hotel Name: " + hotelname);
    carnode08.className = "hotel bookElement";
    carnode08.appendChild(carnode08text);
    var carnode09 = document.createElement('span');
    carnode09.className = "number bookElement";
    var carnode09text = document.createTextNode(" - Room Number: " + roomnumber);
    carnode09.appendChild(carnode09text);
    var carnode10 = document.createElement('span');
    carnode10.className = "score bookElement";
    var carnode10text = document.createTextNode(" - Review Score: " + score);
    carnode10.appendChild(carnode10text);
    var carnode12 = document.createElement('span');
    var carnode12text = document.createTextNode("Check-in Date: "+Din);
    carnode12.appendChild(carnode12text);
    carnode12.className = "info1 bookElement";     
    var carnode13 = document.createElement('span');
    var carnode13text = document.createTextNode(" - Check-out Date: " + Dout);
    carnode13.appendChild(carnode13text);
    carnode13.className = "info2 bookElement";
    var carnode14 = document.createElement('span');
    var carnode14text = document.createTextNode(" - # Adults: " + adults);
    carnode14.appendChild(carnode14text);
    carnode14.className = "info3 bookElement";
    var carnode15 = document.createElement('span');
    var carnode15text = document.createTextNode(" - # Childen: " + childen);
    carnode15.appendChild(carnode15text);
    carnode15.className = "info4 bookElement";
    var carnode16 = document.createElement('span');
    var carnode16text = document.createTextNode(" - Location: " + loc);
    carnode16.appendChild(carnode16text);
    carnode16.className = "info5 bookElement";
    var carnode17 = document.createElement('div');
    carnode17.className = "ck_info"; 
    var carnode18 = document.createElement('button');
    carnode18.className = "ck_button";
    carnode18.id = name;
    carnode18.setAttribute( "onClick", "javascript: remove(this);");
    var carnode18text = document.createTextNode("Checkout");
    carnode18.appendChild(carnode18text);
   
    carnode01.appendChild(carnode02);
    carnode02.appendChild(carnode03);
    carnode02.appendChild(carnode04);
    carnode02.appendChild(carnode05);
    carnode01.appendChild(carnode06);
    carnode06.appendChild(carnode07);
    carnode07.appendChild(carnode08);
    carnode07.appendChild(carnode09);
    carnode07.appendChild(carnode10);
    carnode06.appendChild(carnode12);
    carnode06.appendChild(carnode13);
    carnode06.appendChild(carnode14);
    carnode06.appendChild(carnode15);
    carnode06.appendChild(carnode16);
    carnode01.appendChild(carnode17);
    carnode17.appendChild(carnode18); 
    
    document.getElementById("Scart").appendChild(carnode01);
}



function backPprof() {
    document.getElementById("booking_sec").style.display = 'block'; 
    document.getElementById("editareaP").style.display = 'none';
}


function commets_on(){
    document.getElementById("comments_sec").style.display = 'block'; 
    document.getElementById("booking_sec").style.display = 'none';
}

function commets_off(){
    document.getElementById("booking_sec").style.display = 'block'; 
    document.getElementById("comments_sec").style.display = 'none';
}

function addRoom(){
    document.getElementById("noedit").style.display = 'block'; 
    document.getElementById("edit").style.display = 'none';
    document.getElementById("Hprofile").style.display = 'block'; 
    document.getElementById("editarea").style.display = 'none';
    
    var x = document.getElementById("frm1");
    img  = x.elements[0].value;
    hotelname = x.elements[1].value;
    roomnumber = x.elements[2].value;
    score =  x.elements[3].value;
    adults = x.elements[4].value;
    childen = x.elements[5].value;
    loc = x.elements[6].value;
    price = x.elements[7].value;
    createRoom();
}
    
function createRoom(){
    var roomnode01 = document.createElement('section');
    var name = roomid;
    roomid++;
    roomnode01.id= ("B" + name);
    roomnode01.className = "ck_cart_info"
    var roomnode02 = document.createElement('div'); 
    roomnode02.className = "ck_product"
    var roomnode03 = document.createElement("IMG");
    roomnode03.className="ck_img image bookElement";
    roomnode03.id="image";
    roomnode03.setAttribute("src", img);
    var roomnode04 = document.createElement('p'); 
    var roomnode05 = document.createElement('h3'); 
    var roomnode05text = document.createTextNode("AUD $" + price);
    roomnode05.appendChild(roomnode05text);
    roomnode05.className = "price bookElement";
    var roomnode06 = document.createElement('div');
    roomnode06.className ="ck_product";
    var roomnode07 = document.createElement('h3'); 
    roomnode07.className = "info0";
    var roomnode08 = document.createElement('span');
    var roomnode08text = document.createTextNode("Hotel Name: " + hotelname);
    roomnode08.appendChild(roomnode08text);
    roomnode08.className = "hotel bookElement";
    var roomnode09 = document.createElement('span');
    var roomnode09text = document.createTextNode(" - Room Number: " + roomnumber);
    roomnode09.appendChild(roomnode09text);
    roomnode09.className = "number bookElement";
    var roomnode10 = document.createElement('span');
    var roomnode10text = document.createTextNode(" - Review Score: " + score);
    roomnode10.appendChild(roomnode10text);
    roomnode10.className = "score bookElement";
    var roomnode14 = document.createElement('span');
    var roomnode14text = document.createTextNode(" - # Adults: " + adults);
    roomnode14.appendChild(roomnode14text);
    roomnode14.className = "info3 bookElement";
    var roomnode15 = document.createElement('span');
    var roomnode15text = document.createTextNode(" - #Childen: " + childen);
    roomnode15.appendChild(roomnode15text);
    roomnode15.className = "info4 bookElement";
    var roomnode16 = document.createElement('span');
    var roomnode16text = document.createTextNode(" - Location: " + loc);
    roomnode16.appendChild(roomnode16text);
    roomnode16.className = "info5 bookElement";
    var roomnode17 = document.createElement('div');
    roomnode17.className = "ck_info"; 
    var roomnode18 = document.createElement('button');
    roomnode18.className = "ck_button";
    roomnode18.id = name;
    roomnode18.setAttribute( "onClick", "javascript: editcarH(this);");
    var roomnode18text = document.createTextNode("Edit");
    roomnode18.appendChild(roomnode18text);
    roomnode01.appendChild(roomnode02);
    roomnode02.appendChild(roomnode03);
    roomnode02.appendChild(roomnode04);
    roomnode02.appendChild(roomnode05);
    roomnode01.appendChild(roomnode06);
    roomnode06.appendChild(roomnode07);
    roomnode07.appendChild(roomnode08);
    roomnode07.appendChild(roomnode09);
    roomnode07.appendChild(roomnode10);
    roomnode06.appendChild(roomnode14);
    roomnode06.appendChild(roomnode15);
    roomnode06.appendChild(roomnode16);
    roomnode01.appendChild(roomnode17);
    roomnode17.appendChild(roomnode18);     document.getElementById("Hprofile").appendChild(roomnode01);
}

function hideHprof(){
    document.getElementById("Hprofile").style.display = 'none'; 
    document.getElementById("editarea").style.display = 'block';
    document.getElementById("noedit").style.display = 'block'; 
    document.getElementById("edit").style.display = 'none';   
}



function backHprof() {
    document.getElementById("Hprofile").style.display = 'block'; 
    document.getElementById("editarea").style.display = 'none';
}

function gocar(){location.href = 'cart.html';}
function gohome(){location.href = 'index.html';}
function goreg(){location.href = 'register.html';}
function goPP() {location.href = 'Person_Profile.html';}
function goHP() {location.href = 'Hotel_Profile.html';}