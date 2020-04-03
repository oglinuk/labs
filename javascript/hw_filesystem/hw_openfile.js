var fs = require('fs');
var filename = 'hw_createfile.txt';

fs.open(filename, 'r', function(err, f) {
    if(err) throw err;
    console.log(`Hello world from hw_openfile.js! Contents of ${filename}:\n\n${f.toString()}`)
});