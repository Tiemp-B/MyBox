<script setup>
  import { ItemStore, sysImgStore, adminMode, basketStore, baseURL } from "@/common/store";
  // import { ref } from "./node_modules/vue/dist/vue";
  import { ref } from "vue";
  import itemCard from "@/components/itemCard.vue";
  import detailCard from "@/components/detailCard.vue";
  import popPage from "@/components/popPage.vue";

  const admin = adminMode();
  const basket = basketStore();
  const itemStore = ItemStore();
  const sysImg = sysImgStore();

  const popOn = ref(false);
  const selectedID = ref(0);
  const selectedIdx = ref(0);
  const modifyThis = ref(0);

  function selectMenu(id, idx) {
    selectedID.value = id;
    selectedIdx.value = idx;
  }
  function deSelect() {
    selectedID.value = 0;
  }
  function popPageToggle() {
    if (popOn.value) modifyThis.value = 0;
    popOn.value = !popOn.value;
  }
  function modifyStart() {
    popPageToggle();
    modifyThis.value = selectedIdx.value;
  }


</script>

<template class="appCase" style="overflow: scroll; width: 500px; height: 150px">
  <div class="appCase">
    <ul v-for="item in itemStore.menuPack">
      <itemCard v-if="(item.id > 0) && (selectedID != item.id)" :itemData="item"
        @click="selectMenu(item.id, item.index)" />
      <detailCard v-if="(item.id > 0) && item.id == selectedID" :itemData="item" @item-add="deSelect"
        @modifyOn="modifyStart" />
    </ul>
    <ul v-if="admin.admin" class="addBox" @click="popPageToggle">
      <div>+</div>
    </ul>
  </div>

  <div v-if="!admin.admin && !popOn" class="basketIcon"
    :style="`background-image: url(${sysImg.mainPack.shoppingKart})`" @click="popPageToggle">
    <div v-if="basket.sumItem > 0" class="filled"></div>
  </div>

  <div class="popDisplay" v-if="popOn">
    <div class="popCase" @click="popPageToggle"></div>
    <div class="smallView">
      <popPage @popChange="popPageToggle" :modifyTarget="modifyThis" />
    </div>
  </div>
</template>

<style>
.smallView {
  padding: 5%;
  border-radius: 10px;
  transform: translate(5%, -110%);
  width: 80%;
  height: 80%;
  background-color: white;
}

.popDisplay {
  transform: translate(0%, -100%);
  width: 100%;
  height: 100%;

}

.popCase {
  position: relative;
  width: 100%;
  height: 100%;
  background-color: black;
  opacity: 0.5;
}

.addBox {
  background-color: rgb(233, 231, 231);
  display: flex;
  justify-content: center;
  text-align: center;
  align-items: end;
  opacity: 50%;
  font-size: 100px;
  height: 100px;
  border: 1px solid gray;
}

.filled {
  border-radius: 50px;
  height: 15px;
  width: 15px;
  background-color: red;
  position: absolute;
  right: 0px;
}

template {
  padding: 0px;
  margin: 0px;
  display: flex;
  height: 100%;
}

ul {
  padding: 0px;
  margin: 0px;
}

.appCase {
  overflow-y: scroll;
  height: 100%;
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

.basketIcon {
  border-radius: 50px;
  background-size: 80%;
  background-color: skyblue;
  background-position: center;
  background-repeat: no-repeat;
  width: 50px;
  height: 50px;
  position: absolute;
  border: 1px solid greenyellow;
  transform: translate(1000%, -150%);
  box-shadow: 1px 1px 1px 1px gray;
}
</style>
