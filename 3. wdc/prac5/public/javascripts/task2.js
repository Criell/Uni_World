var currcenter, map;


function initMap() {
    currcenter = {lat: -34.920603, lng: 138.60622769999998};
    map = new google.maps.Map(document.getElementById('map'), {
    zoom: 20,
    center: currcenter
    });
}

    
function showKI() {
    currcenter = {lat: -35.7752426, lng: 137.2142417};
    map = new google.maps.Map(document.getElementById('map'), {
    zoom: 10,
    center: currcenter
    });
}

function addMarker() {
    
    var marker = new google.maps.Marker({
    position: currcenter,
    map: map
    });
}
