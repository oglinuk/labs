var fs = require('fs');
var filename = 'hw_renamefile.txt';
var newname = 'hw_renamed.txt'

fs.open(filename, 'w', function(err) {
    if(err) console.log(`Error: ${err}`);
    console.log(`Successfully created ${filename} to be renamed ...`);
});

fs.rename(filename, newname, function(err) {
    if(err) console.log(`Error: ${err}`);
    console.log(`Successfully renamed ${filename} to ${newname} using fs.rename ...`)
})