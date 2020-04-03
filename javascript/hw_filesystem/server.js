var http = require('http');
var fs = require('fs')
var port = '9001';

http.createServer(function(req, resp) {
    fs.readFile('index.html', function(err, data) {
        if(err) console.log(`Error: ${err}`);
        resp.writeHead(200, {'Content-Type': 'text/html'});
        resp.end(data);
    });
}).listen(port);

console.log(`Serving at 0.0.0.0:${port} ...`);