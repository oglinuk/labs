var http = require('http');
var port = '9001';

http.createServer(function(req, resp) {
    resp.writeHead(200, {'Content-Type': 'text/plain'});
    resp.end('Hello world from hello_world.js!')
}).listen(port);

console.log(`Serving at 0.0.0.0:${port} ...`);