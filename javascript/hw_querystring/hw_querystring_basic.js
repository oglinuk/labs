var http = require('http');
var port = '9001';

http.createServer(function(req, resp) {
    resp.writeHead(200, {'Content-Type': 'text/plain'});
    resp.end(req.url);
}).listen(port);

console.log(`Goto 0.0.0.0:${port}/hw_querystring`);
