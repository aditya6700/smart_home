const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');
const mysql = require('mysql')

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
        if(err) throw err;
        res.send(result);
    })

});

app.listen(1432, () => {
    console.log("you're listening on port 1432");
});