<script setup>
import cat1 from "@/components/categories/MyTitle.vue"
import cat2 from "@/components/categories/AboutMe.vue"
import cat3 from "@/components/categories/MyStack.vue"
import cat4 from "@/components/categories/MyArchive.vue"
import cat5 from "@/components/categories/MyLicense.vue"
import cat6 from "@/components/categories/MyProject.vue"
import cat7 from "@/components/categories/MyCareer.vue"

</script>

<template>
    <cat1 class="category" v-if="true" style="z-index: 7"></cat1>
    <cat2 class="category" v-if="true" style="z-index: 6"></cat2>
    <cat3 class="category" v-if="true" style="z-index: 5"></cat3>
    <cat4 class="category" v-if="false" style="z-index: 4"></cat4>
    <cat5 class="category" v-if="false" style="z-index: 3"></cat5>
    <cat6 class="category" v-if="true" style="z-index: 2"></cat6>
    <cat7 class="category" v-if="true" style="z-index: 1"></cat7>
</template>

<style>
.category {
    position: relative;
    height: 55vh;
    margin-top: -70px;
    padding-top: 70px;
}
</style>
