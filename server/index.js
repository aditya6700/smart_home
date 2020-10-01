const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');
const mysql = require('mysql')
const mqtt = require('mqtt');

var client = mqtt.connect('mqtt://192.168.0.125:1883');

const app = express();
app.use(cors());
app.use(express.json());
app.use(bodyParser.urlencoded({extended: true}));

const db = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'masteroot',
    database: 'iot',
    timezone: 'ist',
});

app.get('/api/get/:room/:date', (req,res) => {
    let {room, date} = req.params
    let [start_hour, end_hour, table_name] =[`${date} 00:00:00`, `${date} 23:00:00`, room]
    console.log(room,date,start_hour,end_hour)

    // let sqlSelect = `select * from ${table_name} where Time between "${start_hour}" and "${end_hour}"`
    let sqlSelect = `select * from ${table_name} where Time Like "${date}%";`
    db.query(sqlSelect, (err,result) => {
        
        (err) ? console.log(err) : res.send(result); 
        console.log(typeof result)
    })

});


app.post('/api/esp8266/on',(req,res) => {
    let {selectedRoom, selectedDevice} = req.body;
    console.log(selectedRoom,selectedDevice,' Client publishing.. ON');
    var onData = {
        device: selectedDevice,
        status: "HIGH",
    }
    client.publish(`/esp8266/${selectedRoom}`, JSON.stringify(onData) );
    return res.json(`done processing ${selectedRoom} on ${selectedDevice}`);
})
app.post('/api/esp8266/off',(req,res) => {
    let {selectedRoom, selectedDevice} = req.body;
    console.log(selectedRoom,selectedDevice,' Client publishing.. OFF');
    var offData = {
        device: selectedDevice,
        status: "LOW",
    }
    client.publish(`/esp8266/${selectedRoom}`, JSON.stringify(offData) );
    return res.json(`done processing ${selectedRoom} on ${selectedDevice}`);
})


app.listen(1432, () => {
    console.log("you're listening on port 1432");
});