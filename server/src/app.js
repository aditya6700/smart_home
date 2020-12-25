const express = require('express');
const cors = require('cors');
const router = require('./routers//routes');
require('./db/connect');

const app = express();
const port = process.env.PORT || 1432;

app.use(cors());
app.use(express.json());
app.use(express.urlencoded({extended: false}));

app.use(router)

app.listen(port, () => {
    console.log(`you're listening on port ${port}`);
});