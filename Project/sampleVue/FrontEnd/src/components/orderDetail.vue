<script setup>
import { ItemStore, sysImgStore, adminMode, basketStore, baseURL } from "@/common/store";
import { ref } from "vue";
import { api } from "@/utils/axios";

const itemStore = ItemStore();

const props = defineProps(["targetID"]);

const cntBox = ref({});
let sumItem = 0;
const tempDesc = ref(props.targetID.desc);

props.targetID.items.forEach((e)=>{
  cntBox.value[e.menus_id] = e.quantity;
  sumItem += e.quantity;
});

const countDown = (id)=>{
  if(cntBox.value[id] > 0){
    cntBox.value[id]--;
    sumItem--;
  }
}
const countUp = (id)=>{
  cntBox.value[id]++;
  sumItem++;
}
const emit=defineEmits(["emitToggle"]);

async function deleteOrder(){
  const data = await api.orders.delete(props.targetID.id);
  emit("emitToggle");
}

async function updateOrder(){
  if (sumItem==0){
    deleteOrder();
  }else{
    for(const itemID in cntBox.value){
      await api.orders.modifyItem(props.targetID.id, itemID, cntBox.value[itemID]);
    }
    await api.orders.modifyDesc(props.targetID.id, tempDesc.value);
    emit("emitToggle");
  }
  
}
  //const data = await api.orders.addKart(requestText.value);
  //console.log(data);
  //const data = await api.orders.delete(20);
  //console.log(data);
  //const result = await api.orders.findAll();
  //const result = await api.orders.findOne(3);
  //const result = await api.orders.modifyItem(3, 2, 5);
  //console.log(result);
</script>

<template>
  <div class="titleID">
    <h1 style="margin: 3px;">주문 번호 : {{ props.targetID.id }}</h1>
  </div>
  <div class="itemListBox" style="border:0.3px solid gold; height: 60%;">
    <ul v-for="item of props.targetID.items" style="height: 30%; display: flex; align-items: center; border-bottom: 0.2px solid blanchedalmond;">
      <div class="thumbnail"
        :style="`background-image:url(${itemStore.menuPack[itemStore.menuIDPack[item.menus_id].index].image})`"></div>
      <div class="itemName" style="margin-left:10% ;width:50%">{{
      itemStore.menuPack[itemStore.menuIDPack[item.menus_id].index].name }}</div>
      <div class="countBox" style="">
        <button class="downButton countBt" @click="countDown(item.menus_id)"><span
            style="position: relative; top:-9px">-</span></button>
        <div class="countNumber"><span>{{ cntBox[item.menus_id] }}</span></div>
        <button class="upButton countBt" @click="countUp(item.menus_id)"><span style="position: relative; top:-5px">+</span></button>
      </div>
    </ul>
  </div>
  <div class="baseBox" style="height: 25%; display: flex;">
    <textarea v-model="tempDesc" style="width:60%; height:100%; border-radius: 10px; resize: none; margin:5px;"></textarea>
    <div class="btBox" style="margin-top:5px; height:100%; width:35% ; border:0.2px solid black"> 
      <button @click="deleteOrder">주문 취소</button>
      <button @click="updateOrder">주문 수정</button>
    </div>
  </div>
  
</template>


<style scoped>
.btBox>button{
  border-radius: 50px;
  margin-left: 10px;
  margin-top: 5px;
  height: 44%;
  width: 80%;
}
.countBox {
  display: flex;
  border-radius: 50px;
  overflow: hidden;
  align-items: center;
  border: 0.3px solid black;
  height: 50%;
  width: 35%
}

.countNumber {
  display: flex;
  font-size: 25px;
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

.itemListBox::-webkit-scrollbar {
  border-radius: 10px;
  background-color: rgb(187, 245, 245);
}

.itemListBox::-webkit-scrollbar-thumb {
  background-color: rgb(57, 157, 197);
  border-radius: 10px;
  box-shadow: inset 0px 0px 5px white;
}

.itemListBox::-webkit-scrollbar-track {
  border-radius: 10px;
  box-shadow: inset 0px 0px 5px white;
}

.itemListBox {
  overflow-y: scroll;
}

.itemListBox>ul {
  padding-left: 0;
  margin: 0;
}

.thumbnail {
  height: 90%;
  aspect-ratio: 1/1;
  background-repeat: no-repeat;
  background-size: cover;
}
</style>