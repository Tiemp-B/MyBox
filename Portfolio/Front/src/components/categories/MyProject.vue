<script setup>
import pjtBox from "@/components/SimpleProjectCard.vue"
</script>

<template>  
    <div class="main" id="MyProject">
        <div class="body">
            <div class="title">
                <img src="" alt="project icon">
                <h1>PROJECTS</h1>
            </div>
            <div class="contents">
                <pjtBox></pjtBox>
                <pjtBox></pjtBox>
                <pjtBox></pjtBox>
            </div>
        </div>
    </div>
</template>

<style>

#MyProject{
    background-color: #a3cca2;
}

.title {
    display: flex;
    align-items: center;
    justify-content: center;
    height: 30%;
}

.title img{
    width: 40px; /* 아이콘 크기 */
    height: 40px;
    flex-shrink: 0; /* 아이콘 크기를 고정 */
    margin-right: 10px;
}

.contents{
    width: 100%;
    height: 50%;
    display: flex; /* 가로로 배치 */
    justify-content: space-between; /* 섹션 간 간격 균등 */
    gap: 20px; /* 섹션 간 간격 */
    border: solid 1px black;
}

.item{

}
.list{
    
}
</style>