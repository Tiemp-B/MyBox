<script setup>
import {ref} from "vue";
const props = defineProps(["itemData"]);


</script>

<template>
  <div class="itemBox">
    <div class="imgBox" :style="`background-image: url(${props.itemData.image})`"></div>
    <div class="itemText">
        <h1>{{ props.itemData.name }}</h1>
    </div>
  </div>  
</template>

<style scoped>
.imgBox{
    border: 1px solid blanchedalmond;
    height: 80%;
    aspect-ratio: 1/1;
    background-position: center;
    background-size: cover;
    background-repeat: no-repeat;
}
.itemText{
    border: 1px solid brown;
    height: 80%;
    width: 60%;
    position: relative;
}
.itemBox{
    display: flex;
    justify-content: space-evenly;
    align-items: center;
    border: 1px solid gold;
    height: 150px;
}
</style>
