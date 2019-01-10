var mysql = require('mysql');
var async = require("async");

var connection = mysql.createConnection({
    host: 'localhost',
    user: 'pi',
    password: 'test1234',
    database: 'iotdatabase',
    insecureAuth: true
});

exports.connect = function () {
    connection.connect(function (err) {
        if (err) {
            return console.error('error: ' + err.message);
        }

        console.log('Connected to the MySQL server.');
    });
}

exports.close = function () {
    connection.end(function (err) {
        if (err) {
            return console.log('error:' + err.message);
        }
        console.log('Close the database connection.');
    });
}

exports.insert = function (object) {
    let insertStmt = `INSERT INTO gps_data(longitude,latitude, time, device_id)
            VALUES(?,?,?,?)`;
    //let queryStmt = 'SELECT time FROM gps_data WHERE time = ?';
    let time = object.time.slice(0, 19).replace('T', ' ');
    let values = [object.lon, object.lat, time, 1];
    console.log(values);
    // execute the insert statment
    connection.query(insertStmt, values, (err, results, fields) => {
        if (err) {
            return console.error(err.message);
        }
        // get inserted id
        console.log('Todo Id:' + results.insertId);
    });
}

exports.getLatestPostition = async function (device_name) {
    let queryStmt = `SELECT gps.longitude, gps.latitude FROM iotdatabase.gps_data as gps, iotdatabase.devices as dev
    WHERE (SELECT max(time) FROM iotdatabase.gps_data) = gps.time AND dev.name = ?`;

    await connection.query(queryStmt, device_name, (err, result, fields) => {
        let returnObject = {
            longitude: result[0].longitude,
            latitude: result[0].latitude
        }
        //console.log(returnObject);
        return returnObject;
    })
}