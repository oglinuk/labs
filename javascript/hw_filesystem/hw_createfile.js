var fs = require('fs');
var filename = 'hw_createfile.txt';

// method 1 ~ appendFile()
fs.appendFile(filename, 'Hello world from hw_createfile.js with appendFile!', function(err) {
        if(err) console.log(`Error: ${err}`);

    console.log(`Successfully used fs.appendFile to create ${filename} ...`)
});

// method 2 ~ open()
fs.open(filename, 'w', function(err, f) {
        if(err) console.log(`Error: ${err}`);

    console.log(`Successfully used fs.open to create ${filename} ...`);
});

// method 3 ~ writeFile()
fs.writeFile(filename, 'Hello world from hw_createfile.js with writeFile!', function(err) {
        if(err) console.log(`Error: ${err}`);

    console.log(`Successfully used fs.writeFile to create ${filename} ...`);
});