var https = require('https');
var connection = require('./connect.js')

var headers = {
    'Content-Type': 'application/json',
    'Authorization': 'key ttn-account-v2.RyirGD384KbG2Z8Pa9cXQvelvnkwdZyXWaNaf0XLMqs'
};

var options = {
    host: 'pytrackpallettracker.data.thethingsnetwork.org',
    path: '/api/v2/query/track1?last=1h',
    port: 443,
    headers: headers
};

https.request(options, function (res) {
    //console.log('STATUS: ' + res.statusCode);
    //console.log('HEADERS: ' + JSON.stringify(res.headers));
    res.setEncoding('utf8');

    connection.connect();
    res.on('data', function (chunk) {
        var jsonBody = JSON.parse(chunk);
        for (var i = 0; i < jsonBody.length; i++) {
            connection.insert(jsonBody[i]);
            if (i === jsonBody.length - 1) {
                connection.close();
            }
        }
    });
}).end();