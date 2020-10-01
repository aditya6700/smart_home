const mqtt = require('mqtt');
let Bedroom1Data = [
  {
      id: 1,
      type: "Applaince",
      device: "Fan 1",
      status: "OFF",
      readings : null,
  },
  {
      id: 2,
      type: "Applaince",
      device: "Fan 2",
      status: "OFF",
      readings: null,
  },
  {
      id: 3,
      type: "Applaince",
      device: "Light 1",
      status: "ON",
      readings : null,
  },
 
];


var client = mqtt.connect('mqtt://192.168.0.125:1883');

console.log('Client publishing.. ');

client.publish('/leds/pi', JSON.stringify(Bedroom1Data));

client.publish('/leds/esp8266', 'TOGGLE' );

client.subscribe('/leds/esp8266', ()=>{
  client.on('message',   (topic,message) => {
      context = message.toString();
      console.log(topic,"message is", context)
    })
})
