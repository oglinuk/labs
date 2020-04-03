var fs = require('fs');

fs.appendFile('hw_createfile.txt', 'Hello world from hw_createfile.js!', function(err) {
    if(err) throw err;
    console.log('Success!')
});