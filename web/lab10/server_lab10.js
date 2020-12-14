var bodyParser = require('body-parser');
var jsonParser = bodyParser.json();
var express = require('express');
var app = express();
var cors = require('cors');
var proj4 = require('proj4');
var fs = require('fs');
var rline = require('readline');
var entrc = [];
var end = false;

function ReadEntrc(fn)
{
  var stream = fs.createReadStream(fn, "utf8");
  var rd = rline.createInterface({input: stream});
  var ln;

  rd.on('line', function(data) {
    var token = data.split('|');
      ln = {
              name: token[0],
              type: token[1],
              address: token[2],
              gaddr: token[3],
              x: parseFloat(token[4]),
              y: parseFloat(token[5])
           };
      entrc.push(ln);
  });

  rd.on('close', function() {end = true;});

}

ReadEntrc('entrc_seoul_filter_sorted_utf8.txt');

app.use(cors());
app.use(express.static('public'));
// request 이벤트 리스너를 설정합니다.

app.get('/hello', (request, response) => {response.send('<h1> Hello World!!!</h1>');});

app.get('/proj4_client.html', (request, response) =>
{
    response.addHeader('Access-Control-Allow-Origin', 'http://maps.googleapis.com');
    response.redirect('http://naver.com');
});

app.get('/hong.html', (request, response) => {response.redirect('http://naver.com');});

app.use(bodyParser.json());

app.post('/convertGsrToUtmK', function (req, res)
{
    console.log('\n/convertGsrToUtmK');
    //console.log('body: ' + req.body);

    var coordinates = req.body; // 받아온 XY좌표
    // point array 1
    var point1 = [parseFloat(coordinates.x1), parseFloat(coordinates.y1)]

    // point array 2
    var point2 = [parseFloat(coordinates.x2), parseFloat(coordinates.y2)]

    var firstProjection = "+proj=tmerc +lat_0=38 +lon_0=127.5 +k=0.9996 +x_0=1000000 +y_0=2000000 +ellps=GRS80 +units=m +no_defs"; // from
    var secondProjection = "+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs"; // to

    // #1. 변환한 위도 경도 값 저장
    var lonAndLat1 = proj4(firstProjection, secondProjection, point1);// from 경위도
    var lonAndLat2 = proj4(firstProjection, secondProjection, point2); // to 경위도

    // #2. 하나의 JSON ARRAY로 데이터 저장
    var retPoints ={
        X1: lonAndLat1[0],
        Y1: lonAndLat1[1],
        X2: lonAndLat2[0],
        Y2: lonAndLat2[1]
    };

    // #3. json stringify → response send
    res.send(JSON.stringify(retPoints));
});

app.post('/entrcToUtmK', function (req, res) {
    console.log('\n/EntrcToUtmK');
    //console.log('body: ' + req.body);

    var name = req.body.name;

    if(!end) {res.send('DB not ready error'); return;}

    var x, y;
    var cordis = [];
    var nametarget = [];


    for(let i = 0; i < entrc.length; i++)
    {
        keys = name.split(" ");
        //enchaned find
        var justtarget = entrc[i].name + " " + entrc[i].type + " " + entrc[i].address + " " + entrc[i].gaddr;
// 이를 위하여 데이터베이스의 처음 4개 필드값을 append하여 하나의 문자열로 만들고 해당 검색
//  문자열에 있는 각 단어가 모두 존재하는 건물들을 화면에 출력하도록 하면 된다.
//  예를 들어, "신현빌딩 강서"의 경우, "신현빌딩"과 "강서" 두 단어로 split()한 후에
//  각 단어가 4개 필드 연합문자열에 모두 존재하는 건물만 출력한다.

        istrue = true;
        for(let x = 0; x < keys.length; x++)
        {
            if(justtarget.indexOf(keys[x]) != -1)
            {
                continue;
            }
            else
            {
                istrue = false;
                break;
            }
        }

        //if((justtarget.indexOf(keys[0]) != -1 && justtarget.indexOf(keys[1]) != -1) || justtarget.indexOf(name) != -1)
        if(istrue === true)
        {
          x = entrc[i].x;
          y = entrc[i].y;
          names = entrc[i].name + " " + entrc[i].type + " " + entrc[i].address;
          cordis.push([x, y]);
          nametarget.push(names);
        }
    }//발견한 모든 좌표를 저장

    if(cordis.length == 0) {res.send('name not found error'); return;}

    var firstProjection = "+proj=tmerc +lat_0=38 +lon_0=127.5 +k=0.9996 +x_0=1000000 +y_0=2000000 +ellps=GRS80 +units=m +no_defs"; // from
    var secondProjection = "+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs"; // to

    var lonAndLat;
    var retPoints = [];
    var pointsstring = '';


    for(let i = 0; i < cordis.length; i++)
    {
        // #1. 변환한 위도 경도 값 저장
        // #2. 하나의 JSON ARRAY로 데이터 저장
        lonAndLat = proj4(firstProjection, secondProjection, cordis[i]);// from 경위도
        tempcord = {X: lonAndLat[0], Y: lonAndLat[1]};
        console.log(tempcord);
        pointsstring += JSON.stringify(tempcord) + '|' + nametarget[i] +'?'; //delimeter is ?
        retPoints.push({X: lonAndLat[0], Y: lonAndLat[1]});
    }
    pointsstring += name;

    // #3. json stringify → response send
    //res.send(JSON.stringify(pointsstring));

    res.send(pointsstring);
});

console.log('URL address:  http://localhost:3020');
app.listen(process.env.PORT || 3020);
