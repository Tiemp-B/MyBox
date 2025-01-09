const mysql = require("mysql2/promise");

const pool = mysql.createPool({
    host: "127.0.0.1",
    user: "root",
    password: "qwerty119",
    waitForConnections: true,
    connectionLimit: 10,
    queueLimit: 0,
});

// const pool = mysql.createPool({
//     host: "127.0.0.1",
//     user: "root",
//     password: "ssafy",
//     database: "order_system",
//     waitForConnections: true,
//     connectionLimit: 10,
//     queueLimit: 0,
// });

module.exports = {pool};
