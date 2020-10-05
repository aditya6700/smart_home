const mqtt = require('mqtt');
 
var client = mqtt.connect('mqtt://192.168.0.136:1883');

// console.log('Client publishing.. ');

// client.publish('/leds/pi', JSON.stringify(Bedroom1Data));

if(client.publish('/leds/esp8266', 'TOGGLE' ))
    console.log("pulblished")

client.subscribe('/leds/pi', ()=>{
  client.on('message',   (topic,message) => {
      context = message.toString();
      console.log(topic,"message is", context)
    })
})
