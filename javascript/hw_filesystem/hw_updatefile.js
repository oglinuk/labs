var fs = require('fs');
var filename = 'hw_updatefile.txt';

// method 1 ~ writeFile()
fs.writeFile(filename, 'Hello world from writeFile in hw_updatefile.js!', function(err) {
        if(err) console.log(`Error: ${err}`);

    console.log(`Successfully updated ${filename} using fs.writeFile ...`);
});

// method 2 ~ appendFile()
fs.appendFile(filename, '\n\nHello world from appendFile in hw_updatefile.js!', function(err) {
        if(err) console.log(`Error: ${err}`);

    console.log(`Successfully updated ${filename} using fs.appendFile ...`);
});