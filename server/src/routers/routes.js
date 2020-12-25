const express = require('express');
const mqtt = require('mqtt');
const {livingRoom_DB, bedRoom1_DB, bedRoom2_DB} = require('../model/collection');

const mqttUri = 'mqtt://192.168.29.245:1883';
const client = mqtt.connect(mqttUri);

const router = new express.Router();

router.get('/api/get/:room/:date', async (req,res) => {
    try {
        const {room, date} = req.params;
        res.status(201).send(room);
    } catch (err) {
        res.status(400).send(err);
    }
    
});


router.post('/api/esp8266/on',(req,res) => {
    let {selectedRoom, selectedDevice} = req.body;
    console.log(selectedRoom,selectedDevice,' Client publishing.. ON');
    var onData = {
        device: selectedDevice,
        status: 1,
    }
    client.publish(`/esp8266/${selectedRoom}`, JSON.stringify(onData) );
    return res.json(`done processing ${selectedRoom} on ${selectedDevice}`);
});


router.post('/api/esp8266/off',(req,res) => {
    let {selectedRoom, selectedDevice} = req.body;
    console.log(selectedRoom,selectedDevice,' Client publishing.. OFF');
    var offData = {
        device: selectedDevice,
        status: 0,
    }
    client.publish(`/esp8266/${selectedRoom}`, JSON.stringify(offData) );
    return res.json(`done processing ${selectedRoom} on ${selectedDevice}`);
});

module.exports = router;