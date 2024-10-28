const express = require("express");
const { pool } = require("./db");
const path = require("path");

const app = express();
const PORT = 3000;

const cors = require("cors");
app.use(cors());

const morgan = require("morgan");
app.use(morgan("dev"));

const multer = require("multer");

app.use(express.json());
app.use("/public", express.static("public"));

const upload = multer({
  storage: multer.diskStorage({
    destination: (req, file, done) => {
      done(null, "public/");
    },
    filename: (req, file, done) => {
      const ext = path.extname(file.originalname);
      console.log("ext: ", ext);
      const fileNameExeptExt = path.basename(file.originalname, ext);
      console.log("fileNameExeptExt: ", fileNameExeptExt);
      const saveFileName = fileNameExeptExt + Date.now() + ext;
      console.log("saveFileName: ", saveFileName);
      done(null, saveFileName);
    },
  }),
  limits: { filesize: 5 * 1024 * 1024 },
});

var fs = require("fs");
app.get("/api/image", async (req, res) => {
  fs.readdir("./public/sys", (error, filelist) => {
    if (error) {
      return res.json({
        success: false,
        message: "시스템 이미지 가져오기 실패",
      });
    } else {
      data = filelist;
      return res.json(data);
    }
  });
});

//menus get  전체 메뉴, 특정 메뉴

app.get("/api/menus", async (req, res) => {
  try {
    const data = await pool.query("SELECT * FROM menus");
    return res.json(data[0]);
  } catch (error) {
    console.log("getMenus error: ", error);
    return res.json({
      success: false,
      message: "메뉴 조회 실패",
    });
  }
});

app.get("/api/menus/:id", async (req, res) => {
  try {
    const data = await pool.query("SELECT * FROM menus WHERE ?", [
      req.params.id,
    ]);
    return res.json(data[0][0]);
  } catch (error) {
    console.log("getIdMenu error:", error);
    return res.json({
      success: false,
      message: "메뉴 세부정보 조회 실패",
    });
  }
});

//이미지 get

//menus post

app.post("/api/menus/", upload.single("file"), async (req, res) => {
  try {
    console.log(req.body);
    console.log(req.file);
    const imgPath = req.file.destination + req.file.filename;
    const data = await pool.query(
      "INSERT INTO menus (name, description, image_src) VALUES (?, ?, ?)",
      [req.body.name, req.body.description, imgPath]
    );
    return res.json({
      success: true,
      message: "메뉴 등록 성공",
    });
  } catch (error) {
    console.log("postMenu error:", error);
    return res.json({
      success: false,
      message: "메뉴 등록 실패",
    });
  }
});

//menus patch

app.patch("/api/menus/:id", async (req, res) => {
  console.log(req.params);
  try {
    const data = await pool.query(
      "UPDATE menus SET name=?, description=? WHERE id=?",
      [req.body.name, req.body.description, req.params.id]
    );
    return res.json({
      success: true,
      message: "정보 변경 성공",
    });
  } catch (error) {
    console.log("dataUpdate error: ", error);
    return res.json({
      success: false,
      message: "정보 변경 실패",
    });
  }
});

app.post("/api/menus/:id/image", upload.single("file"), async (req, res) => {
  try {
    const imgPath = req.file.destination + req.file.filename;
    const data = await pool.query("UPDATE menus SET image_src=? WHERE id=?", [
      imgPath, req.params.id,]);
    console.log("이미지 변경 성공");
    return res.json({
      success: true,
      message: "이미지 변경 성공",
    });
  } catch (error) {
    console.log("imageUpdate error: ", error);
    return res.json({
      success: false,
      message: "이미지 변경 실패",
    });
  }
});

// menus delete

app.delete("/api/menus/:id", async (req, res) => {
  try {
    const data = await pool.query("DELETE FROM menus WHERE id=?", [
      req.params.id,
    ]);
    return res.json({
      success: true,
      message: "데이터 삭제 성공",
    });
  } catch (error) {
    console.log("delete error: ", error);
    return res.json({
      success: false,
      message: "데이터 삭제 실패",
    });
  }
});

app.get("/api/image/delete/:name", async (req, res) => {
  console.log("here!", req.params.name);
  const file_name = "./public/" + req.params.name;

  fs.stat(file_name, (error, stats) => {
    if (error) {
      return res.json({
        success: false,
        message: "해당 이미지가 없습니다!",
      })
    } else {
      fs.unlink(file_name, error => {
        if (error) {
          return res.json({
            success: false,
            message: "이미지 삭제중 에러가 발생했습니다!",
          })
        } else {
          return res.json({
            success: true,
            message: "이미지를 삭제하였습니다.",
          })
        }
      })
    }
  })
});

// 주문목록

app.get("/api/orders", async (req, res) => {
  try {
    const data = await pool.query(`
      SELECT * FROM karts;
      `);
    return res.json(data[0]);
  } catch (error) {
    return res.json({
      success: false,
      message: "주문내역 수신 실패"
    })
  }
})

app.get("/api/orders/:id", async (req, res) => {
  try {
    const data = await pool.query(`
      SELECT orders.menus_id, orders.quantity
      FROM karts
      JOIN orders ON
      orders.kart_id = karts.id
      WHERE karts.id = ?;
  `, [req.params.id]);
    //console.log(req.params.id, ":", data);
    return res.json(data[0]);
  } catch (error) {
    console.log("getOrders error: ", error);
    return res.json({
      success: false,
      message: "주문 조회 실패",
    });
  }
});

app.get("/api/karts", async (req, res) => {
  try {
    const data = await pool.query(`
      SELECT * FROM orders
    `);
    return res.json(data[0]);
  } catch (error) {
    return res.json({
      success: false,
      message: "주문 상품 조회 실패",
    })
  }
})

app.post("/api/orders", async (req, res) => {
  try {
    const data = await pool.query(`
      INSERT INTO karts (kart_desc) VALUES (?)
    `, [req.body.desc]);
    return res.json({
      success: true,
      message: "주문 생성!",
      kartID: data[0].insertId,
    })
  } catch (error) {
    console.log("주문 생성 실패!", error);
    return res.json({
      success: false,
      message: "주문 생성 실패",
    })
  }
});

app.post("/api/orders/karts/:id", async (req, res) => {
  try {
    const data = await pool.query(`
      INSERT INTO orders (kart_id, menus_id, quantity) VALUES (?, ?, ?)
    `, [req.body.kart_id, req.body.itemID, req.body.itemQuantity]);
    return res.json({
      success: true,
      message: "주문 상품 등록!",
    })
  } catch (error) {
    console.log("주문 상품 등록 실패!", error);
    return res.json({
      success: false,
      message: "주문 상품 등록 실패",
    })
  }
})

app.patch("/api/orders/karts/:id", async (req, res) => {
  try {
    const data = await pool.query(`
      UPDATE orders SET quantity=? 
      WHERE kart_id=? AND menus_id=?
    `, [req.body.Quantity, req.params.id, req.body.itemID]);
    return res.json({
      success: true,
      message: "상품 수량 변경 성공",
    });
  } catch (error) {
    return res.json({
      success: false,
      message: "상품 수량 변경 실패"
    });
  };
});


app.patch("/api/karts/desc/:id", async(req, res)=>{
  try{
    console.log("!!!");
    const data = await pool.query(`
      UPDATE karts SET kart_desc=?
      WHERE id=? 
    `,[req.body.desc, req.params.id]);
    return res.json({
      success: true,
      message: "주문 요청 수정 성공",
    });
  }catch(error){
    return res.json({
      success: false,
      message: "주문 요청 수정 실패"
    });
  };
});

app.delete("/api/orders/delete/:id", async (req, res) => {
  try {
    console.log(req.body);
    const data = await pool.query(`
      DELETE FROM karts WHERE id=?
    `, [req.params.id]);
    return res.json({
      success: true,
      message: "주문 삭제 성공",
    })
  } catch (error) {
    //console.log("주문 삭제 실패!", error);
    return res.json({
      success: false,
      message: "주문 삭제 실패"
    })
  }
});

app.post("/api/user", async (req, res) => {
  try {
    const data = await pool.query(`
      SELECT * FROM ADMIN_USER WHERE username=?
    `,[req.body.id]);
    if (req.body.pw == data[0][0].password) {
      return res.json({
        success: true,
        message: "접속 성공!"
      });
    } else {
      return res.json({
        success: false,
        message: "wrong password!"
      });
    }
  } catch (error) {
    return res.json({
      success: false,
      message: "유저명 수신 실패!"
    });
  }
});


app.listen(PORT, () => console.log(`this server listening on ${PORT}`));
