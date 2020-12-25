const mongoose = require('mongoose');

const monogoUri = 'mongodb://localhost:27017/smartHome';

mongoose.connect(monogoUri,{
    useCreateIndex: true,
    useUnifiedTopology: true,
    useNewUrlParser: true,
    useFindAndModify: false
}).then(() =>{
    console.log("connection established with database");
}).catch((err) => {
    console.log("database connection failed"+ err);
});
