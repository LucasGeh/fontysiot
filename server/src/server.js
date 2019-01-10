var express = require('express');
var app = express();
var fs = require("fs");
var mysql = require('mysql');

var connection = mysql.createConnection({
    host: 'localhost',
    user: 'pi',
    password: 'test1234',
    database: 'iotdatabase',
    insecureAuth: true
});

app.get('/api/v2/query', function (req, res) {
    let queryStmt = `SELECT gps.longitude, gps.latitude FROM iotdatabase.gps_data as gps, iotdatabase.devices as dev
    WHERE (SELECT max(time) FROM iotdatabase.gps_data) = gps.time AND dev.name = ?`;

    connection.query(queryStmt, req.query.device, (err, result, fields) => {
        let returnObject = {
            longitude: result[0].longitude,
            latitude: result[0].latitude
        }
        console.log(returnObject);
        res.writeHead(200, { "Content-Type": "application/json"});
        res.write(JSON.stringify(returnObject));
        res.end();
    })
})

app.get('/api/v2/devices', function (req, res) {
    let queryStmt = `SELECT name FROM iotdatabase.devices`;
    connection.query(queryStmt, (err, result, fields) => {
        //console.log(result);
        let returnObject = {};
        for (let i = 0; i < result.length; i++) {
            //console.log(result[i].name);
            returnObject["device-" + i] = result[i].name;
        }
        console.log(returnObject);
        res.writeHead(200, { "Content-Type": "application/json"});
        res.write(JSON.stringify(returnObject));
        res.end();
    })
})

var server = app.listen(8081, function () {
    var host = server.address().address
    var port = server.address().port
    connection.connect();
    console.log("Node Server listening at http://%s:%s", host, port)
})

