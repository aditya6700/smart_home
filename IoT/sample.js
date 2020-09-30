 const mqtt = require('mqtt');

client = mqtt.connect('mqtt://192.168.0.125:1883');

console.log('Client publishing.. ');
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
  {
      id: 4,
      type: "Applaince",
      device: "Light 2",
      status: "OFF",
      readings: null,
  },
  {
      id: 5,
      type: "Applaince",
      device: "Air Conditoner",
      status: "OFF",
      readings:  null,
  },
  {
      id: 6,
      type: "Sensor",
      device: "Temparature",
      status: "ON",
      readings:  28.6 + " celcius" ,
  },
  {
      id: 7,
      type: "Sensor",
      device: "Humidity",
      status: "OFF",
      readings:  52.3,
  },
  {
      id: 8,
      type: "Sensor",
      device: "Gas Level",
      status: "ON",
      readings:  400 + "imp",
  },
  {
      id: 9,
      type: null,
      device: null,
      status: null,
      readings:  null,
  },
];


client.publish('/leds/pi', JSON.stringify(Bedroom1Data));

client.publish('/leds/esp8266', 'TOGGLE' );

client.subscribe('/leds/esp8266', ()=>{
  client.on('message',   (topic,message) => {
      context = message.toString();
      console.log(topic,"message is", context)
    })
})
