<script setup>
import { ItemStore, sysImgStore, adminMode, basketStore, baseURL } from "@/common/store";
// import { ref } from "./node_modules/vue/dist/vue";
import { ref } from "vue";
import orderSimple from "@/components/orderSimple.vue";
import orderDetail from "@/components/orderDetail.vue";

import popPage from "@/components/popPage.vue";


const admin = adminMode();
const basket = basketStore();
const items = ItemStore();
const itemStore = ItemStore();
const sysImg = sysImgStore();



const popOn = ref(false);
const selected = ref(0);
const selectedIdx = ref(0);
const modifyThis = ref(0);

const orderList= ref([]);

async function getOrders(){
  const data = await api.orders.findAll();
  for(var item of data.data){
    const res = await api.orders.findOne(item.id);
    orderList.value.push({
      id: item.id,
      desc: item.kart_desc,
      items: res.data,
    });
  }
}

getOrders();

const togglePop =async ()=>{
  if(popOn.value ){
    orderList.value=[];
    getOrders();
  }
  popOn.value = !popOn.value;
}
const openDetail = (order)=>{
  togglePop();
  selected.value = order;
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


<template style="overflow: scroll; width: 500px; height: 150px">
  <div class="listCol" style="overflow: hidden; padding-left: 10%; height: 5%; border-bottom: 0.3px solid blanchedalmond;"><span style="position: relative; top:15%">주문번호</span><span style="position: relative; left:20%; top:15%">상품명</span></div>
  <div class="appCase" >
    <ul v-for="order in orderList" >
      <div class="orderSlate" @click="openDetail(order)">
        <orderSimple :order="order"/>
     </div>
    </ul>
  </div>

  
  <div class="popDisplay2" v-if="popOn">
    <div class="popBack2" @click="togglePop"></div>
    <div class="popCase2" :targetID="selected">
      <div @click="togglePop" style="position: relative; width:10px; height: 10px; left: 47%; top:-7%"><h1>X</h1></div>
      <div  style="position:absolute; left:50%; top:50%; transform: translate(-50%, -50%); border: 0.3px solid black; width: 80%; height:80%">
        <orderDetail :targetID="selected" @emitToggle="togglePop"/>
      </div>
    </div>
  </div>
</template>

<style scoped>
.popDisplay2 {
  transform: translate(0%, -100%);
  width: 100%;
  height: 100%;
}
.popBack2{
  position: relative;
  width: 100%;
  height: 100%;
  background-color: black;
  opacity: 0.5;
}
.popCase2 {
  padding: 5%;
  transform: translate(-50%, -50%);
  position: absolute;
  left: 50%;
  top: 50%;
  width: 70%;
  height: 70%;
  background-color: whitesmoke;
  border-radius: 10px;
  display: flex;
  justify-content: center;
}

.orderSlate{
  height: 80%;
  width: 95%;
  display: flex;
  flex-direction: row;
  align-items: center;
  justify-content: space-around;
}

.appCase>ul{
  display: flex;
  align-items: center;
  justify-content: center;
  padding: 0px; 
  margin: 0px; 
  width: 100%; 
  height: 14%; 
  border-bottom: 0.3px solid rgb(202, 202, 202);
}

.appCase {
  overflow-y: scroll;
  height: 95%;
  width: 100%;
}

.appCase::-webkit-scrollbar {
  border-radius: 10px;
  background-color: rgb(187, 245, 245);
}

.appCase::-webkit-scrollbar-thumb {
  background-color: rgb(57, 157, 197);
  border-radius: 10px;
  box-shadow: inset 0px 0px 5px white;
}

.appCase::-webkit-scrollbar-track {
  border-radius: 10px;
  box-shadow: inset 0px 0px 5px white;
}
</style>

