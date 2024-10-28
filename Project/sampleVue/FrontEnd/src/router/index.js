import { createRouter, createWebHistory } from 'vue-router';


const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: "main",
      component: ()=>import("../views/mainPage.vue"),
    },
    {
      path: '/admin',
      name: "admin",
      component: ()=>import("../views/Admin.vue"),
    },
    {
      path: '/menus',
      name: 'menus',
      component: ()=>import("../views/Menus.vue"),
    },
    {
      path: '/order',
      name: 'order',
      component: ()=>import("../views/OrderList.vue"),
    }

  ]
})

export default router;
