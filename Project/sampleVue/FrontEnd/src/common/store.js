import { ref, computed } from "vue";
import { defineStore } from "pinia";

// export const baseURL = "http://52.79.239.16:8080"
export const baseURL = "http://127.0.0.1:3000"

const sysImgStore = defineStore("sysStore", () => {
  const mainPack = ref({
    mainIcon: baseURL + "/public/sys/main_icon.png",
    mainBack: baseURL + "/public/sys/main_background.jpg",
    mainBanner: "",
    shoppingKart: baseURL + "/public/sys/shopping-kart.png",
    emptyImg: baseURL + "/public/sys/empty_img.png",
  });

  return { mainPack };
});

const ItemStore = defineStore("itemStore", () => {
  const menuPack = ref([
    {
      id: 0,
      name: "",
      desc: "",
      image: "",
      index:"",
    },
  ]);
  const menuIDPack = ref({});
  return { menuPack, menuIDPack };
});

const adminMode = defineStore("sysMode", ()=>{
	const admin = ref(false);
})

const basketStore = defineStore("basketStore", ()=>{
  const basket = ref({
    "견본":{
      "id" : 0,
      "cnt" : 0,
      "name" : "",
    }
  });
  const sumItem = ref(0);
  return {basket, sumItem};
})

export { sysImgStore, ItemStore, adminMode, basketStore};
