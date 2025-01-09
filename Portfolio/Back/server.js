const express = require("express");
const { pool } = require("./db");
const path = require("path");
const fs = require("fs");

const app = express();
const PORT = 3308;

const cors = require("cors");
app.use(cors());

const morgan = require("morgan");
app.use(morgan('combined'));

const multer = require("multer");



const upload = multer({
    storage: multer.diskStorage({
        destination: (req, file, done) => {
            done(null, "public/");
        },
        filename: (req, file, done) => {
            const ext = Path2D.extname(file.originalname);
            const fileNameExeptExt = path.basename(file.originalname, ext);
            const saveFileName = fileNameExeptExt + Date.now() + ext;
            done(null, saveFileName);
        },
    }),
    limits: { filesize: 5 * 1024 * 1024 },
});

// //get1
// app.get('/', async (req, res) => {
//     try {
//         const data = await pool.query("SELECT * FROM menus");
//         return res.json({
//             success: true,
//             message: "get1 success",
//             data: data[0],
//         });
//     } catch (error) {
//         console.log("Error get1: ", error);
//         return res.json({
//             success: false,
//             message: "get1 failed",
//         });
//     }
// });

//post1
app.post("/", upload.single("file"), async (req, res) => {
    try {

        return res.json({
            success: true,
            message: "post1 success",
        })
    } catch (error) {
        return res.json({
            success: false,
            message: "post1 failed",
        });
    }
});

//patch1
app.patch("/:id", async (req, res) => {
    try {
        const data = await pool.query(
            "UPDATE menus SET name=?, description=?, WHERE id=?",
            [req.body.name, req.body.description, req.params.id]
        );
        return res.json({
            success: true,
            message: "patch1 success",
        });
    } catch (error) {
        return res.json({
            success: false,
            message: "patch1 failed",
        });
    }
});

//delete1
app.delete("/:id", async (req, res) => {
    try {
        const data = await pool.query("DELETE FROM menus WHERE id=?",
            [req.params.id,]
        );
        return res.json({
            success: true,
            message: "delete1 success",
        });
    } catch (error) {
        return res.json({
            success: false,
            message: "delete failed",
        })
    }
})

//


app.listen(PORT, () => {
    console.log(`Server is running on ${PORT}`);
})

