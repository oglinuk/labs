var fs = require('fs');
var filename = 'hw_deletefile.txt';

fs.open(filename, 'w', function(err) {
    if(err) console.log(`Error: ${err}`);
    console.log(`Successfully created ${filename} for deletion ...`);
});

fs.unlink(filename, function(err) {
    if(err) console.log(`Error: ${err}`);
    console.log(`Successfully deleted ${filename} using fs.unlink ...`);
});