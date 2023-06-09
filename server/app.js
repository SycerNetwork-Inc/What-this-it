const express = require('express');
const app = express();
// json 
app.use(express.json());
// http://192.168.1.35/log

// show ip connection and user agent
app.use((req, res, next) => {
    console.log(req.ip, req.headers['user-agent']);
    next();
});

app.post('/log', (req, res) => {
    console.log(req.body);
    res.send('ok');
});

app.get('/', (req, res) => {
    res.send('Hello World');
});

app.listen(80, () => console.log('Server started at port 80'));