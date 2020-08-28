var fs = require('fs')
var path = require('path')
fs.readFile('.vscode/settings.json', 'utf8', function(err, data) {
    if (err) {
        return console.log(err);
    }
    const viewPath = (path.join(__dirname)).replace(/\\/g, '/')
    var result = data.replace(/\"cpp\":.*/, `"cpp" : "cd $dir && g++ -DLOCAL_OUTPUT=\\\\\\\"${viewPath}/output.dat\\\\\\\" -DLOCAL_INPUT=\\\\\\\"${viewPath}/input.dat\\\\\\\" $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",`);

    fs.writeFile('.vscode/settings.json', result, 'utf8', function(err) {
        if (err) return console.log(err);
    });
});