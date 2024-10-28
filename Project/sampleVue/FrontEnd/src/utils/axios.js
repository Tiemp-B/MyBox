import axios from "axios";
import { baseURL } from "@/common/store";

//나는 현재 AWS를 구동하여 menus와 orders 두 테이블이 생성되어 있는 상태이다.
//그리고 BACK을 vscode로 구동하여 localhost:8080을 통해 AWS의 데이터와 연결된다.
//이미지는 localhost로 들어가면 BACK 폴더의 public으로 연결되고
// AWS ip:port/public/파일명으로 들어가면 AWS 서버에 존재하는 항목을 불러온다.
const DOMAIN = baseURL;

const request = axios.create({
  baseURL: `${DOMAIN}/api`,
});

export const api = {
  sys: {
    getImage: () => request.get("/image"),
  },
  menus: {
    findAll: () => request.get("/menus"),
    findOne: (id) => request.get("/menus/:id"),

    create: (name, description, file) => {
      const formData = new FormData();
      formData.append("name", name);
      formData.append("description", description);
      formData.append("file", file);
      return request.post("/menus", formData, {
        headers: {
          "Content-Type": "multipart/form-data"
        }
      });
    },

    update: (id, name, description) => {
      console.log(id);
      return request.patch(`/menus/${id}`, {
        name: name,
        description: description,
      })
    },

    updateImg: async (id, newFile, originalFile) => {
      const formData = new FormData();
      formData.append("file", newFile);
      const upRes = await request.post(`/menus/${id}/image`, formData, {
        headers: {
          "Content-Type": "multipart/form-data",
        },
      });
      if (!upRes.data.success) {
        console.log("새 이미지 등록 실패");
        return;
      }
      const imgDel = await request.get(`image/delete/${originalFile}`);
      console.log("THIS2: ", imgDel);
      if (imgDel.data.success) console.log("이미지 삭제 성공");
      else console.log("이미지 삭제 실패");
      return;
    },

    delete: (id) => request.delete(`/menus/${id}`),
    deleteImg: (originalFile) => request.delete("api/menus/image", {
      originalFile: originalFile
    }),

  },
  orders: {
    findAll: () => {
      return request.get("/orders");
    },
    findOne: (id) => {
      return request.get(`/orders/${id}`);
    },
    addKart: (desc) => request.post("/orders", {
      desc: desc,
    }),

    addItem: (id, itemID, itemQuantity) => request.post(`/orders/karts/${id}`, {
      kart_id: id,
      itemID: itemID,
      itemQuantity: itemQuantity,
    }),


    modifyItem: (id, itemID, Quantity) => request.patch(`/orders/karts/${id}`, {
      itemID: itemID,
      Quantity: Quantity,
    }),
    modifyDesc: (id, desc)=>{
      return request.patch(`/karts/desc/${id}`,{
        desc: desc,
      });
    },

    delete: (id) => request.delete(`/orders/delete/${id}`),
  },
  login: (username, password) => {
    console.log("this: ", password);
    const res = request.post("/user", {
      id: username,
      pw: password,
    });
    return res;
  }
};

