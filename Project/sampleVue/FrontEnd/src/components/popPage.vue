<script setup>
import { sysImgStore, adminMode, ItemStore, baseURL, basketStore} from '@/common/store';
import {ref} from "vue";
import {useRouter} from "vue-router";
import {api} from "@/utils/axios";

const basket = basketStore();
const sysImg = sysImgStore();
const popImg = ref("");
const admin = adminMode();
const items = ItemStore();
const router = useRouter();

const name = ref("");
const desc = ref("");
const file = ref("");
const requestText = ref("");
const orderDone = ref(false);
const kartID = ref(0);

const emit = defineEmits(["popChange"]);
const props = defineProps(["modifyTarget"]);

function fileUp(e){
  file.value =e.target.files[0];
  popImg.value = URL.createObjectURL(e.target.files[0]);
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


async function createMenu(){
  if(!name.value || !desc.value||!file.value){
    alert("빈 값이 있습니다! 정확한 기재 부탁합니다!");
    return ;
  }
  console.log(file.value);
  const result = await api.menus.create(
    name.value,
    desc.value,
    file.value,
  );
  if(result.data.success){
    alert("메뉴가 등록되었습니다!");
  }else{
    alert("메뉴 등록에 실패하였습니다!");
  }
  getMenu();
  admin.admin = true;
  emit("popChange");
}

//props.modifyTarget
async function modifyMenu(){
  if(file.value){
    const imgFile = items.menuPack[props.modifyTarget].image.split("public/")[1];
    api.menus.updateImg(items.menuPack[props.modifyTarget].id, file.value, imgFile);
  }
  await api.menus.update(items.menuPack[props.modifyTarget].id, name.value, desc.value);
  getMenu();
}

if(props.modifyTarget>0){
  popImg.value = items.menuPack[props.modifyTarget].image;
  name.value = items.menuPack[props.modifyTarget].name;
  desc.value = items.menuPack[props.modifyTarget].desc;
}

function upBasket(key){
  basket.basket[key].cnt++;
  basket.sumItem++;
}
function downBasket(key){
  basket.basket[key].cnt--;
  basket.sumItem--;
}
async function sendOrder(){
  if(basket.sumItem<1){
    return ;
  }
  const data = await api.orders.addKart(requestText.value);
  kartID.value = data.data.kartID;
  for(const item in basket.basket){
    if(basket.basket[item].cnt>0){
      api.orders.addItem(kartID.value, basket.basket[item].id, basket.basket[item].cnt);
    }
  }
  orderDone.value = true;
}

</script>

<template>
  <div v-if="orderDone" class="bigBox" style="display: flex; flex-direction: column; align-items: center;">
    <h2>주문이 완료되었습니다!</h2>
    <div class="circle" style="height:60%; aspect-ratio: 1/1; background-color: plum; border-radius: 50%; text-align: center; box-shadow: 1px 1px 1px 1px;">
      <div style="transform: translate(-50%, -50%); margin-left:50%; margin-top:45%; font-size: 10em;">{{ kartID }}</div>
    </div>
    <div style="margin-top: 10%; height: 30%; width:100%; display: flex; justify-content: center;">
      <button @click="router.push({ path: '/' })" style="height: 50%; width: 50%; border-radius: 50px; font-size: 2.5em;">홈으로</button>
    </div>
  </div>
  
  <div v-else-if="admin.admin" class="bigBox">
    <div class="upBox tempBox">
      <div class="imgBox">
        <img v-if="popImg" class="newImg" :src="popImg" alt="..."/>
        <img v-else class="nowImg" :src="sysImg.mainPack.emptyImg" alt="..."/>
      </div>
      <div class="fileUp">
        <input type="file" @change="fileUp">
      </div>
    </div>
    <div class="downBox tempBox">
      <div class="titleInput">
        상품명 : <br>
        <textarea v-model="name" spellcheck="false" type="text"></textarea>
      </div>
      <br>
      <div class="descInput">
        상품설명 : <br>
        <textarea v-model="desc" spellcheck="false" type="text"></textarea>
      </div>
      <div class="submitButton">
        <button v-if="props.modifyTarget>0" @click="modifyMenu">메뉴 수정</button>
        <button v-else @click="createMenu">메뉴 추가</button>
      </div>
    </div>
  </div>

  <div v-else class="bigBox">
    <div class="basketBox">
      <ul v-for="item in basket.basket" >
        <div v-if="item.cnt > 0" class="itemSlate">
          <div class="imgBox" :style="`background-image: url(${items.menuPack[item.index].image})`"></div>
          <div class="itemName"><p>{{ item.name }}</p></div>
          <div class="countCase">
            <button class="downButton countBt" @click="downBasket(item.name)">-</button>
            <div class="countNumber"><span>{{item.cnt}}</span></div>
            <button class="upButton countBt" @click="upBasket(item.name)">+</button>
          </div>
        </div>
      </ul>
      <ul v-if="basket.sumItem==0">
        <div class="itemSlate">
          <h2>상품이 없습니다!</h2>
        </div>
      </ul>
    </div>
    <div class="confirmBox">
      <textarea placeholder="요청 사항을 적어주세요!" v-model="requestText"></textarea>
      <button @click="sendOrder" class="sendBt">주 문</button>
    </div>
  </div>

</template>

<style scoped>



.confirmBox>textarea{
  width: 50%;
}
.confirmBox>.sendBt{
  font-size: larger;
  font-weight: 700;
  border-radius: 55px;
  height: 60%;
  aspect-ratio: 2/1;
}
.confirmBox{
  display: flex;
  justify-content: space-around;
  align-items: center;
}
.countCase>.upButton {
  background-color: red;
}
.countCase>.downButton {
  background-color: blue;
}
.countCase>.countBt {
  font-size: 40px;
  border: none;
  width: 40%;
  height: 103%;
}
.countCase>.countNumber {
  display: flex;
  font-size: 20px;
  width: 50%;
  height: 100%;
  align-items: center;
  text-align: center;
  justify-content: center;
}
.countCase>.countBox {
  position: relative;
  height: 105%;
  width: 105%;
  display: flex;
  justify-content: space-between;
  transform: translate(-2%, -5%);
}

.itemSlate>.countCase{
  border-radius: 50px;
  overflow: hidden;
  display: flex;
  align-items: center;
  justify-content: center;
  flex-direction: row;
  border: 0.5px solid black;
  width: 25%;
  height: 50%;
}

.itemSlate>.itemName{
  font-size: x-large;
  width: 40%;
}
.itemSlate>.imgBox{
  background-repeat: no-repeat;
  background-size: cover;
  background-position: center;
}
.itemSlate{
  display: flex;
  flex-direction: row;
  align-items: center;
  justify-content: space-around;
  border-bottom: 0.3px solid rgb(202, 202, 202);
  height: 100px;
}

.basketBox::-webkit-scrollbar {
  border-radius: 10px;
  background-color: rgb(187, 245, 245);
}

.basketBox::-webkit-scrollbar-thumb {
  background-color: rgb(57, 157, 197);
  border-radius: 10px;
  box-shadow: inset 0px 0px 5px white;
}

.basketBox::-webkit-scrollbar-track {
  border-radius: 10px;
  box-shadow: inset 0px 0px 5px white;
}
.basketBox{
  border:0.5px solid green;
  height: 80%;
  overflow-y: scroll;
}
.confirmBox{
  height: 20%;
  border: 0.5px solid greenyellow;
}
textarea{
  font-size: 1.3em;
  padding-top: 5px;
  resize: none;
  top:  0px;
  border-radius: 5px;
  width: 90%;
  height: 50%;
}
.descInput{
  height: 65%;
}
.titleInput{
  height: 15%;
}
.imgBox{
  border: 0.5px solid rgb(163, 158, 158);
  height: 90%;
  aspect-ratio: 1/1;
  overflow: hidden;
}
.newImg{ 
  position: relative;
  transform: translate(-50%, -50%);
  left: 50%;
  top: 50%;
  height: 100%;
  width: auto;
}
.nowImg{
  position: relative;
  transform: translate(-50%, -50%);
  left: 50%;
  top: 50%;
  height: 40%;
  width: auto;
  opacity: 0.5;
}
.tempBox{
  width: 100%;
  height: 50%;
}

.bigBox{
  width: 100%;
  height: 100%; 
}

</style>