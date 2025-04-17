<script>

export default {
    data() {
        return {
            showDetail: true,
        };
    },
    methods: {
        detailPop(){
            console.log("pop!");
            this.showDetail = !this.showDetail;
        }
    }
};

</script>

<template>
    <div class="pjtCard" @click="detailPop">
        <h1>tester box</h1>
    </div>
    <Teleport to="body">
        <div :class="['box', { dimmed: showDetail }]">
            <div  class="overlay" @click.self="showDetail = true">
                <div class="detailPage">
                    <!--
                    <iframe src="https://magic-chili-c75.notion.site/ebd/106c9007947f80d58774ef7183d4dc8c" width="100%" height="600" frameborder="0" allowfullscreen />
                    -->
                    <iframe class="notionif" src="https://magic-chili-c75.notion.site/ebd/fffc9007947f816cbdaff9ff46b2910d" width="100%" height="600" frameborder="0" allowfullscreen />
                    <!-- <iframe src="https://magic-chili-c75.notion.site/ebd/15ac9007947f80db9e62d71606ca2111" width="100%" height="600" frameborder="0" allowfullscreen /> -->
                </div>
            </div>
        </div>
    </Teleport>
</template>

<style>

.pjtCard{
    border : solid 1px black;
}
<<<<<<< HEAD
</style>
=======

.pjtCard:hover{
    transform: scale(1.3); /* 1.1배 확대 */
    transition: transform 0.3s ease; /* 부드럽게 확대 */
    transform-origin: center center;
}

.detailPage{
  top: 50px;
  left: 50px;
  width: 85%;
  height: 85%;
  background-color: white;
  border-radius: 20px; /* 둥근 꼭짓점 */
  box-shadow: 0 0 10px rgba(0, 0, 0, 0.3);
  padding: 20px;
  overflow: auto;
  position: fixed;
  z-index: 10000;
}

.notionif{
    width:  100%;
    height: 99%;
}

.overlay {
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  background-color: rgba(0, 0, 0, 0.6); /* 반투명 어두운 배경 */
  display: flex;
  justify-content: center;
  align-items: center;
  z-index: 1000;
}

.dimmed{
    opacity: 0;
}

</style>
>>>>>>> 5ede7c5ea88678b46ccc5d44c44dc21578bd9e81
