var cron = require('node-cron');
var dataProcess = require('child_process');

console.log("Started CronJob to update the Database every x Minute...");

cron.schedule('*/1 * * * *', function(){
  console.log("Attempting to call dataretriever.js");

  returnValue = dataProcess.spawn('node', ['dataretriever.js']);
  returnValue.stdout.on('data', (data) => {
    console.log(`${data}`);
  });
  returnValue.stderr.on('data', (data) => {
    console.log(`${data}`);
  });
  returnValue.on('close', (code) => {
    console.log(`child process exited with code ${code}`);
  });
});