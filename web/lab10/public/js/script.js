var geocoder;
var map;
var markers = Array();
var infos = Array();

function initialize() {
    // prepare Geocoder
    geocoder = new google.maps.Geocoder();

    // set initial position (New York)
    var myLatlng = new google.maps.LatLng(37.61005,126.99719);

    var myOptions = { // default map options
        zoom: 14,
        center: myLatlng,
        mapTypeId: google.maps.MapTypeId.ROADMAP
    };
    map = new google.maps.Map(document.getElementById('gmap_canvas'), myOptions);
}

// clear overlays function
function clearOverlays() {
    if (markers) {
        for (i in markers) {
            markers[i].setMap(null);
        }
        markers = [];
        infos = [];
    }
}

// clear infos function
function clearInfos() {
    if (infos) {
        for (i in infos) {
            if (infos[i].getMap()) {
                infos[i].close();
            }
        }
    }
}

// set coordinate function
function setCoord()
{
    var address_lat = document.getElementById("gmap_coord_lat").value;
    var address_long = document.getElementById("gmap_coord_long").value;

    // script uses our 'geocoder' in order to find location by address name
//    geocoder.geocode( { 'address': address}, function(results, status) {
//        if (status == google.maps.GeocoderStatus.OK) { // and, if everything is ok

            // we will center map
            var geolocate = new google.maps.LatLng(address_lat, address_long);
            //var geolocate2 = new google.maps.LatLng(parseFloat(address_lat)+0.01, parseFloat(address_long)+0.01);

            var myOptions =
            { // default map options
                zoom: 18,
                center: geolocate,
                mapTypeId: google.maps.MapTypeId.ROADMAP
            };

            map = new google.maps.Map(document.getElementById('gmap_canvas'), myOptions);


      //      alert(addrLocation.lat());
            map.setCenter(geolocate);

            // store current coordinates into hidden variables
            document.getElementById('lat').value = address_lat;
            document.getElementById('lng').value = address_long;

            // and then - add new custom marker
            var addrMarker = new google.maps.Marker({
                position: geolocate,
                map: map,
                title: address_lat + ', ' + address_long,
                icon: 'marker.png'
            });
//            marker.setMap(map);
//            marker2.setMap(map);
//        } else {
//            alert('Geocode was not successful for the following reason: ' + status);
//        }
//    });
}

function setmulticordi(cordiarray, namearray)
{
    markingtarget = [];
    avgx = [];
    avgy = [];

    for(let i = 0; i < cordiarray.length; i++)
    {
        var address_long = cordiarray[i].X;
        avgx.push(address_long);
        var address_lat = cordiarray[i].Y;
        avgy.push(address_lat);

        var geolocate = new google.maps.LatLng(address_lat, address_long);

        markingtarget.push(new google.maps.Marker({position: geolocate, title: namearray[i], icon: 'marker.png'}));
    }

    var midfinder = new google.maps.LatLngBounds();

    for(let j = 0; j < avgx.length; j++)
    {
        midfinder.extend(new google.maps.LatLng(avgy[j], avgx[j]));
    }
    var center = midfinder.getCenter();
    document.getElementById('lat').value = center.lat();
    document.getElementById('lng').value = center.lng();

    var myOptions =
    { // default map options
        zoom: 14,
        center: midfinder.getCenter(),
        mapTypeId: google.maps.MapTypeId.ROADMAP
    };

    map = new google.maps.Map(document.getElementById('gmap_canvas'), myOptions);
    console.log(map.getBounds());
    //console.log(map.getBounds().getNorthEast());
    for(let k = 0; k < markingtarget.length; k++)
    {
        markingtarget[k].setMap(map);
    }
    map.fitBounds(midfinder);
    map.setZoom(map.getZoom());
    if(markingtarget.length == 1 && map.getZoom() > 17)
    {
        map.setZoom(17);
    }
    else if(markingtarget.length == 3 && map.getZoom() > 18)
    {
        map.setZoom(map.getZoom() - 1);
    }
    else if(markingtarget.length == 2 && map.getZoom() > 20)
    {
        map.setZoom(20);
    }
    else if(markingtarget.length >= 4 && map.getZoom() > 11 && map.getZoom() < 16)
    {
        map.setZoom(map.getZoom() - 1);
    }
    else if(markingtarget.length > 4 && map.getZoom() > 16)
    {
        map.setZoom(map.getZoom() - 1);
    }

    console.log(map.getZoom());
}

// find address function
function findAddress()
{
    var address = document.getElementById("gmap_where").value;

    // script uses our 'geocoder' in order to find location by address name
    geocoder.geocode( { 'address': address}, function(results, status) {
        if (status == google.maps.GeocoderStatus.OK) { // and, if everything is ok

            // we will center map
            var addrLocation = results[0].geometry.location;
      //      alert(addrLocation.lat());
            map.setCenter(addrLocation);

            // store current coordinates into hidden variables
            document.getElementById('lat').value = results[0].geometry.location.lat();
            document.getElementById('lng').value = results[0].geometry.location.lng();

            // and then - add new custom marker
            var addrMarker = new google.maps.Marker({
                position: addrLocation,
                map: map,
                title: results[0].formatted_address,
                icon: 'marker.png'
            });
        } else {
            alert('Geocode was not successful for the following reason: ' + status);
        }
    });
}

// find custom places function
function findPlaces() {

    // prepare variables (filter)
    var type = document.getElementById('gmap_type').value;
//    type = 'restaurant';
    var radius = document.getElementById('gmap_radius').value;
    var keyword = document.getElementById('gmap_keyword').value;

    var lat = document.getElementById('lat').value;
    var lng = document.getElementById('lng').value;
//    alert(lat, lng);
    var cur_location = new google.maps.LatLng(lat, lng);

    // prepare request to Places
    var request = {
        location: cur_location,
        radius: radius,
        types: [type]
    };
    if (keyword) {
        request.keyword = [keyword];
    }

    // send request
    service = new google.maps.places.PlacesService(map);
    service.search(request, createMarkers);
}

// create markers (from 'findPlaces' function)
function createMarkers(results, status) {
    if (status == google.maps.places.PlacesServiceStatus.OK) {

        // if we have found something - clear map (overlays)
        clearOverlays();

        // and create new markers by search result
        for (var i = 0; i < results.length; i++) {
            createMarker(results[i]);
        }
    } else if (status == google.maps.places.PlacesServiceStatus.ZERO_RESULTS) {
        alert('Sorry, nothing is found');
    }
}

// creare single marker function
function createMarker(obj) {

    // prepare new Marker object
    var mark = new google.maps.Marker({
        position: obj.geometry.location,
        map: map,
        title: obj.name
    });
    markers.push(mark);

    // prepare info window
    var infowindow = new google.maps.InfoWindow({
        content: '<img src="' + obj.icon + '" /><font style="color:#000;">' + obj.name +
        '<br />Rating: ' + obj.rating + '<br />Vicinity: ' + obj.vicinity + '</font>'
    });

    // add event handler to current marker
    google.maps.event.addListener(mark, 'click', function() {
        clearInfos();
        infowindow.open(map,mark);
    });
    infos.push(infowindow);
}

// initialization
google.maps.event.addDomListener(window, 'load', initialize);
