<script setup>
// import { ref } from "./node_modules/vue/dist/vue";
import { ref } from "vue";
import { sysImgStore, adminMode, basketStore, ItemStore, baseURL } from "@/common/store";
// import { useRouter } from "./node_modules/vue-router/dist/vue-router";
import { useRouter } from "vue-router";

const sysImg = sysImgStore();
const admin = adminMode();
const props = defineProps(['updateNow']);
const router = useRouter();
const basket = basketStore();
const items = ItemStore();

const newFile = ref(null);

function fileChange(e) {
  newFile.value = e.target.files[0];
}

function setURL(file) {
  const imageURL = URL.createObjectURL(file);
  return imageURL;
}

function toMenu() {
  router.push({ path: "/menus" });
}

function toOrder() {
  router.push({ path: "/order" });
}

//초기화
basket.basket = {
    "견본":{
      "id" : 0,
      "cnt" : 0,
      "name" : "",
      "index": 0,
    }
  };
basket.sumItem = 0;
</script>

<template>
  <div class="selectPageBox" :style="`background-image: url(${sysImg.mainPack.mainBack})`">
    <img class="mainIcon" :src="sysImg.mainPack.mainIcon" alt="이미지">
    <div class="buttonBox">
      <p><button class="customButton" @click="toMenu"><span v-if="admin.admin">상품 목록</span>
        <span v-else>주문하기</span></button></p>
      <p><button class="customButton" @click="toOrder">주문내역확인</button></p>
    </div>
  </div>
</template>

<style>
.mainIcon {
  position: absolute;
  bottom: 300px;
  width: 100px;
}

.selectPageBox {
  height: 100%;
  display: flex;
  flex-direction: column;
  align-items: center;
  background-repeat: no-repeat;
  background-size: cover;
  background-position: center;
}

.customButton {
  font-size: 15px;
  height: 50px;
  width: 150px;
  border-radius: 50px;
}

.buttonBox {
  margin-top: 10%;
  text-align: center;
  align-items: center;
  justify-content: center;
  position: absolute;
  bottom: 100px;
}
</style>
