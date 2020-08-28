var fs = require('fs')
var path = require('path')

var inputFile = "input.dat"
var outputFile = "output.dat"


fs.readFile('.vscode/settings.json', 'utf8', function(err, data) {
    if (err) {
        return console.log(err);
    }
    const viewPath = (path.join(__dirname)).replace(/\\/g, '/')
    var result = data.replace(/\"cpp\" :.*/, `"cpp" : "cd $dir && g++ -DLOCAL_OUTPUT=\\\\\\\"${viewPath}/IO/${outputFile}\\\\\\\" -DLOCAL_INPUT=\\\\\\\"${viewPath}/IO/${inputFile}\\\\\\\" $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",`);

    fs.writeFile('.vscode/settings.json', result, 'utf8', function(err) {
        if (err) return console.log(err);
    });
});