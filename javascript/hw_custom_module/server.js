var custom = require('./custom_module');
var http = require('http');
var port = '9001';

http.createServer(function(req, resp) {
    resp.writeHead(200, {'Content-Type': 'text/plain'});
    resp.end('Hello world ' + custom.hw_custom_module());
}).listen(port);

console.log(`Serving at 0.0.0.0:${port} ...`);
