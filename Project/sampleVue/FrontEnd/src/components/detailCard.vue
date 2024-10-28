<script setup>
// import { ref } from "./node_module/vue/dist/vue";
import { ref } from "vue";
import { basketStore, adminMode, ItemStore, baseURL } from "@/common/store";
import { api } from "@/utils/axios";

const props = defineProps(["itemData"]);

const image_src = props.itemData.image;
const countItem = ref(1);
const basket = basketStore();
const admin = adminMode();
const items = ItemStore();

const countUp = ()=>countItem.value++;
const countDown = ()=>{
  if(countItem.value>0) countItem.value--;
}

const emit = defineEmits(["itemAdd", "modifyOn"]);

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
  result.data.forEach((e) => {
    if (e.description !== "DELETED") {
      items.menuPack.push({
        id: e.id,
        name: e.name,
        desc: e.description,
        image: baseURL + "/" + e.image_src,
        index: cnt,
      })
      cnt++;
    }
  })
}

function addFunc() {
  emit("itemAdd");
  if(basket.basket[props.itemData.name]) {
    basket.sumItem += -basket.basket[props.itemData.name]["cnt"]+countItem.value;
    basket.basket[props.itemData.name]["cnt"]=countItem.value;
  }
  else{
    basket.basket[props.itemData.name] = {
      "id": props.itemData.id,
      "cnt": countItem.value,
      "name" : props.itemData.name,
      "index" : props.itemData.index,
    };
    basket.sumItem += countItem.value;
  }
}
function modifyStart(){
  emit("modifyOn");
}

async function deleteMenu(){
  await api.menus.update(props.itemData.id, props.itemData.name, "DELETED");
  getMenu();
}

</script>

<template>
  <div class="detailBox">
    <div class="dataBox" @click="$emit('itemAdd')">
      <div class="imgBox" :style="`background-image: url(${image_src})`"></div>
      <div class="textBox">
        <div class="itemTitle">
          <p>{{ props.itemData.name }}</p>
        </div>
        <div class="itemDesc">
          <span>{{ props.itemData.desc }}</span>
        </div>
      </div>
    </div>
    <!-- 항목 주문 // user의 경우 -->
    <div v-if="!admin.admin" class="upBox">
      <div class="countCase">
        <div class="countBox">
          <button class="downButton countBt" @click="countDown">-</button>
          <div class="countNumber"><span>{{countItem}}</span></div>
          <button class="upButton countBt" @click="countUp">+</button>
        </div>
      </div>
      <div class="addCase">
        <button class="addButton" @click="addFunc">추 가</button>
      </div>
    </div>
    <!-- 항목 수정 // admin일 경우만 -->
    <div v-else class="modifyBox">
      <button @click="modifyStart">수정</button>
      <button @click="deleteMenu">삭제</button>
    </div>
  </div>
</template>

<style scoped>
.detailBox {
  border: 1px solid gold;
  height: 450px;
  padding: 20px;
}

.dataBox {
  display: flex;
  border: 1px solid brown;
  height: 70%;
}

.dataBox>.imgBox {
  border: 1px solid red;
  width: 55%;
  aspect-ratio: 1/1;
  background-position: center;
  background-size: cover;
  background-repeat: no-repeat;
}

.dataBox>.textBox {
  display: flex;
  flex-direction: column;
  align-items: center;
  border: 1px solid green;
  width: 45%;
}

.dataBox>.textBox>.itemTitle>p {
  margin: 10px;
  font-size: 33px;
}

.dataBox>.textBox>.itemDesc {
  padding: 5px;
  border: 0.5px solid rgb(224, 224, 224);
  background-color: rgb(224, 224, 224);
  border-radius: 10px;
  width: 80%;
  aspect-ratio: 1/1;
}

.upBox {
  display: flex;
  align-items: center;
  border: 1px solid brown;
  height: 30%;
  justify-content: space-between;
}
.countCase{
  height: 60px;
  width: 280px;
  overflow: hidden;
  border: 1px solid black;
  border-radius: 50px;
}
.countBox {
  position: relative;
  height: 105%;
  width: 105%;
  display: flex;
  justify-content: space-between;
  transform: translate(-2%, -5%);
}

.countNumber {
  display: flex;
  font-size: 35px;
  width: 60%;
  height: 100%;
  align-items: center;
  text-align: center;
  justify-content: center;
}

.upButton {
  background-color: red;
}

.downButton {
  background-color: blue;
}

.countBt {
  font-size: 40px;
  border: none;
  width: 40%;
  height: 103%;
}
.addCase{
  width: 40%;
  height: 60px;
}
.addButton{
  width: 90%;
  height: 100%;
  border-radius: 50px;
  font-size: 30px;
}
</style>
