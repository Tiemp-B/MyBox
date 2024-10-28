<script setup>
import {ItemStore} from "@/common/store.js"

const itemStore = ItemStore();
const props = defineProps(["order"]);

</script>


<template>
  <div class="box">
    <div class="idBox">
      {{ props.order.id }}
    </div>
    <div class="itemBox">
      <ul v-for="item of props.order.items">
        {{ itemStore.menuIDPack[item.menus_id].name }}
      </ul>
    </div>
  </div>
</template>


<style scoped>
.box>.itemBox{
  margin-left: 10%;
}
.box>.idBox{
  margin-left: 10%;
  height: 70%;
  aspect-ratio: 1/1;
  display: flex;
  align-items: center;
}
.box {
  align-items: center;
  height: 100%;
  width: 95%;
  overflow: hidden;
  display: flex;
}

/* 
.box:after {
  position: absolute;
  bottom: 0;
  height: 100%;
  width: 100%;
  content: "";
  background: linear-gradient(to top,
      rgba(255, 255, 255, 1) 20%,
      rgba(255, 255, 255, 0) 80%);
  pointer-events: none;
} */
</style>