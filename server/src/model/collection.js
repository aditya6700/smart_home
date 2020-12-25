const mongoose = require('mongoose');

mongoose.pluralize(null);

const noSchema = new mongoose.Schema({},{ strict: false })

const livingRoom_DB = mongoose.model('livingroom', noSchema);
const bedRoom1_DB   = mongoose.model('bedroom1', noSchema);
const bedRoom2_DB   = mongoose.model('bedroom2', noSchema);

module.exports = {livingRoom_DB, bedRoom1_DB, bedRoom2_DB};