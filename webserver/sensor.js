var http = require('http');

var fs = require('fs');



function handle_incoming_request (req, res) {

    console.log("INCOMING REQUEST: " + req.method + " " + req.url);

    load_sensor_data(function(err, readings){

    if (err) { 

       console.log("Couldn't read file");

    }

    console.log(readings);

   res.writeHead(200, { "Content-Type": "application/json"});

var s= readings.split(',');	
res.write(JSON.stringify({"sensor":{Temperature:s[0],Humidity:s[1],WindSpeed:s[2],Time:s[3],Location:s[4]}},null,'\t'));
   res.end();
               
   });

}

function load_sensor_data(callback) {

   fs.readFile(

   "sensorlog.txt",'utf8',

   function (err, readings) {

   if (err) {

   callback(err);

return;



}

callback(null, readings);

}

);

}

var s = http.createServer(handle_incoming_request);


s.listen(8080);