const mqtt = require('mqtt');
 
var client = mqtt.connect('mqtt://192.168.0.193:1883');

// console.log('Client publishing.. ');

// client.publish('/leds/pi', JSON.stringify(Bedroom1Data));
let Bedroom1Data = [
  {
      room: "bedroom1",
      type: "Applaince",
      device: "Fan 1",
      status: "OFF",
      readings : null,
  },
  {
      room: "bedroom1",
      type: "Applaince",
      device: "Fan 2",
      status: "OFF",
      readings: null,
  },
  {
      room: "bedroom1",
      type: "Applaince",
      device: "Light 1",
      status: "ON",
      readings : null,
  },
  {
      room: "bedroom1",
      type: "Applaince",
      device: "Light 2",
      status: "OFF",
      readings: null,
  },
  {
      room: "bedroom1",
      type: "Applaince",
      device: "Air Conditoner",
      status: "OFF",
      readings:  null,
  },
  {
      room: "bedroom1",
      type: "Sensor",
      device: "Temperature",
      status: "ON",
      readings:  28.6,
  },
  {
      room: "bedroom1",
      type: "Sensor",
      device: "Humidity",
      status: "OFF",
      readings:  52.3,
  },
  {
      room: "bedroom1",
      type: "Sensor",
      device: "Gas",
      status: "ON",
      readings:  400,
  },
]

const pubdata = () => {
	if(client.publish('/pi/bedroom1', JSON.stringify(Bedroom1Data)))
      console.log("pulblished")
}

setInterval(pubdata,3000);
  


client.subscribe('/leds/pi', ()=>{
  client.on('message',   (topic,message) => {
      context = message.toString();
      console.log(topic,"message is", context)
    })
})
