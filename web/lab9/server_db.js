// 모듈을 추출합니다.
var http = require('http');
var express = require('express');
var _ = require('underscore');
var mysql = require('mysql');

// 데이터베이스와 연결합니다.
var client = mysql.createConnection({
    user: 'root',
    password: 'fenexter3874',
    database: 'myinfo'
});

// 변수를 선언합니다.
var schedules;

// 웹 서버를 생성합니다.
var app = express();
const bodyParser = require('body-parser');
app.use(bodyParser.urlencoded({extended: false}));
app.use(bodyParser.json());
app.use(express.static('public'));

// 라우트합니다.
app.get('/schedule', function (request, response) {
    // 데이터베이스 요청을 수행합니다.
    client.query('SELECT * FROM schedule', function (error, data) {
        response.send(data);
    });
});

app.all('/schedule/get', function (request, response) {
    // 변수를 선언합니다.
    var output = null;

    client.query('SELECT * FROM schedule', function (error, data) {
      console.log(data);
      data = JSON.parse(JSON.stringify(data));
        schedules = data;
        console.log(schedules);
        console.log(schedules.length);

    // 요청 매개 변수 sidx를 처리합니다.
    var sidx = request.param('sidx');
    console.log(sidx);
    if (sidx == '') { sidx = 'id'; } else { sidx = sidx.replace('grid_', ''); }

    // 요청 매개 변수 sord를 처리합니다.
    var sord = request.param('sord');
    output = _.sortBy(schedules, function (item) {
        return item[sidx];
    });
    if (sord == 'desc') { output = output.reverse(); }

    // 요청 매개 변수 _search를 처리합니다.
    var _search = request.param('_search');
    if (_search == 'true') {
        var searchField = request.param('searchField');
        var searchString = request.param('searchString');
        var condition = request.param('searchOper');
        output = _.filter(output, function (item) {

            if(condition == 'eq')
            {
                if (searchField == 'id')
                {
                    return item.id == Number(searchString);
                }
                else
                {
                    return item[searchField] == searchString;
                }
            }
            else if(condition == 'ne')
            {
                if (searchField == 'id')
                {
                    return item.id == Number(searchString);
                }
                else
                {
                    return item[searchField].indexOf(searchString) == -1;
                }
            }
            else if (condition == 'bw')
            {
                let seed = searchString.length;

                if (searchField == 'id')
                {
                    return item.id == Number(searchString);
                }
                else
                {
                    let justsub = item[searchField].substring(0, seed);

                    return justsub == searchString;
                }
            }
            else if (condition == 'ew')
            {
                let seed = searchString.length;

                if (searchField == 'id')
                {
                    return item.id == Number(searchString);
                }
                else
                {
                    let ender = item[searchField].split("").reverse().join("").substring(0, seed).split("").reverse().join("");

                    return ender == searchString;
                }
            }
            else if (condition == 'en')
            {
                let seed = searchString.length;

                if (searchField == 'id')
                {
                    return item.id == Number(searchString);
                }
                else
                {
                    let ender = item[searchField].split("").reverse().join("").substring(0, seed).split("").reverse().join("");

                    return ender != searchString;
                }
            }
            else if(condition == 'cn' || condition =='in')
            {
                if (searchField == 'id')
                {
                    return item.id == Number(searchString);
                }
                else
                {
                    return item[searchField].indexOf(searchString) != -1;
                }
            }
            else if(condition == 'nc' || condition == 'ni')
            {
                if (searchField == 'id')
                {
                    return item.id == Number(searchString);
                }
                else
                {
                    return item[searchField].indexOf(searchString) == -1;
                }
            }
            else if(condition == 'lt')
            {
                let seed = searchString.length;

                if (searchField == 'id')
                {
                    return item.id == Number(searchString);
                }
                else
                {
                    return (seed - item[searchField].length) > 0;
                }
            }
            else if(condition == 'gt')
            {
                let seed = searchString.length;

                if (searchField == 'id')
                {
                    return item.id == Number(searchString);
                }
                else
                {
                    return (seed - item[searchField].length) < 0;
                }
            }
        });
    }

    // 요청 매개 변수 page와 rows를 처리합니다.
    var page = Number(request.param('page'));
    var rows = Number(request.param('rows'));
    var totalRecords = schedules.length;
    var totalPages = Math.ceil(totalRecords / rows);
    var start = rows * page - rows;

    // 응답합니다.
    output = output.slice(start, start + rows);
    response.send({
        page: page,
        total: totalPages,
        records: totalRecords,
        rows: _.map(output, function (item) {
            return {
                id: item.id,
                cell: _.toArray(item)
            };
        })
    });
  });
});

app.post('/schedule/edit', function (request, response) {
    // 요청 매개 변수 oper를 처리합니다.
console.log('oper' + request.body.oper);
      switch (request.body.oper) {
        case 'add':
            // 데이터베이스 요청을 수행합니다.
            console.log(request.body, ' string');
            client.query('INSERT INTO schedule (value, date, time, place, contact) VALUES(?,?,?,?,?)', [
                request.body.value, request.body.date, request.body.time, request.body.place, request.body.contact
            ], function (error, data) {
//                response.send(data);
            });
            break;
        case 'del':
            var id = Number(request.body.id);
            console.log('del: ' + id);
            client.query('DELETE FROM schedule WHERE id=?', [
                id
            ], function (error, data) {
              console.log(error);
//                response.send(data);
            });
            break;
        case 'edit':
            var id = Number(request.body.id);
            var query = 'UPDATE schedule SET ';
            // 쿼리를 생성합니다.
            if (request.body.value) query += "value='" + request.body.value + "', ";
            if (request.body.date) query += "date='" + request.body.date + "', ";
            if (request.body.time) query += "time='" + request.body.time + "', ";
            if (request.body.place) query += "place='" + request.body.place + "', ";
            if (request.body.contact) query += "contact='" + request.body.contact + "' ";
            query += "WHERE id = '" + id + "'";
console.log(query);
            // 데이터베이스 요청을 수행합니다.
            client.query(query, function (error, data) {
              console.log(error);
//                response.send(data);
            });

            break;
    }

    // 응답합니다.
    response.send();
});

// 웹 서버를 실행합니다.
http.createServer(app).listen(52275, function () {
    console.log('Server Running at http://127.0.0.1:52275');
});
