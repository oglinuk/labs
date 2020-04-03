var http = require('http');
var url = require('url');
var port = '9001';

http.createServer(function(req, resp) {
    resp.writeHead(200, {'Content-Type': 'text/plain'});
    var qs = url.parse(req.url, true).query;
    resp.end(`Hello ${qs.first} ${qs.last} from hw_querystring_splitting.js!`);
}).listen(port);

console.log(`Goto 0.0.0.0:${port}/?first=Alan&last=Turing`);
