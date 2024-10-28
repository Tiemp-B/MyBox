<script setup>
//import { RouterLink, RouterView, useRouter } from "./node_modules/vue-router/dist/vue-router";
import { RouterLink, RouterView, useRouter } from "vue-router";
import { loadImage } from "@/utils/src2img.js";
import { api } from "@/utils/axios";
//import { ref } from "./node_modules/vue/dist/vue";
import { ref } from "vue"
import { sysImgStore, adminMode, basketStore, ItemStore, baseURL } from "@/common/store";


const items = ItemStore();
const admin = adminMode();

const popOn = ref(false);
const inpID = ref("");
const inpPW = ref("");

function togglePop() {
  popOn.value = !popOn.value;
}

async function checkAdmin() {
  const res = await api.login(inpID.value, inpPW.value);
  if (res.data.success) {
    alert("접속 성공!")
    admin.admin = true;
    popOn.value = false;
    inpID.value = "";
    inpPW.value = "";
  } else {
    alert("접속 실패!")
  }
}

async function getMenu() {
  items.menuPack = [{
    id: 0,
    name: "",
    desc: "",
    image: "",
  }];
  const menuList = ref([]);
  const result = await api.menus.findAll();
  menuList.value = result.data;
  let cnt = 1;
  try {
    result.data.forEach((e) => {
      if (e.description !== "DELETED" && e.name !== "") {
        items.menuPack.push({
          id: e.id,
          name: e.name,
          desc: e.description,
          image: baseURL + "/" + e.image_src,
          index: cnt,
        });
        items.menuIDPack[e.id] = {
          id: e.id,
          name: e.name,
          desc: e.description,
          index: cnt,
        };
        cnt++;
      }
    })
  } catch (error) {
    console.log(error)
  }

}
getMenu()
</script>

<template>
  <div class="appPage">
    <header class="appHeader">
      <h2>SSAFY CAFE</h2>
    </header>
    <div class="appBody">
      <RouterView />
    </div>
    <footer class="appFooter">
      <span>All right reserved</span>
      <nav>
        <RouterLink to="/" @click="admin.admin = false">home</RouterLink> |
        <a v-if="!admin.admin" href="#" @click="togglePop">admin</a>
        <!-- <RouterLink v-if="!admin.admin" to="/" @click="changeMode">admin</RouterLink> -->
        <RouterLink v-else to="/" @click="admin.admin = false">user</RouterLink>
      </nav>
    </footer>
  </div>

  <div class="popDisplay1" v-if="popOn">
    <div class="popBack1" @click="togglePop"></div>
    <div class="popCase1">
      <div class="inputBox1"
        style="padding: 5px; display: flex; flex-direction: column; height: 60%; width: 70%; align-items: center; justify-content: space-around;">
        <p>ID: <input v-model="inpID" type="text" placeholder="아이디"></p>
        <p>PW: <input v-model="inpPW" type="password" placeholder="비밀번호"></p>
      </div>
      <button @click="checkAdmin" style="width:60px; height: 30px; position: absolute; left:70%; top: 75%">로그인</button>
    </div>
  </div>
</template>

<style scoped>
body {
  display: flex;
  justify-content: center;
}

.appPage {
  display: flex;
  flex-direction: column;
  border: 1px solid black;
  width: 600px;
  height: 95vh;
}

.appHeader {
  padding: 3px;
  border: 1px solid black;
  height: auto;
  align-items: center;
  text-align: center;
}

.appBody {
  flex: 1;
  border: 1px solid black;
  height: 500px;
}

.appFooter {
  position: relative;
  bottom: 0%;
  border: 1px solid black;
  text-align: center;
}

.inputBox1>p {
  margin-bottom: 5px;
}

.popDisplay1 {
  transform: translate(0%, -100%);
  width: 100%;
  height: 100%;
}

.popBack1 {
  position: relative;
  width: 100%;
  height: 100%;
  background-color: black;
  opacity: 0.5;
}

.popCase1 {
  padding: 5%;
  transform: translate(-50%, -50%);
  position: absolute;
  left: 50%;
  top: 50%;
  width: 40%;
  height: 20%;
  background-color: whitesmoke;
  border-radius: 10px;
  display: flex;
  justify-content: center;
}
</style>
