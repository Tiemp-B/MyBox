<script setup>

</script>

<template>
    <div class="main" id="MyTitle">
        <div class="body overlay">
            <h1 class="msg">
                변재혁
                <br>
                임베디드 개발자 포트폴리오
            </h1>
            <hr style="width:3.5rem; justify-self: center; align-self: center; border-top: 5px orange; opacity: 1;" />
            <h3>
                안녕하세요.<br>
                어떻게든 구현해내는 개발자<br>
                변재혁입니다.
            </h3>
        </div>
    </div>
</template>

<style scoped>
.main {
    background-image: url('../../assets/images/TopImage.png');
    background-position: center;
    background-size: cover;
    position: relative;
    padding-top: 80px;
}

.overlay {
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background: radial-gradient(circle,
            rgba(60, 179, 113, 0.2) 10%,
            rgba(60, 179, 113, 0.7) 70%,
            rgba(60, 179, 113, 1) 92%);
    pointer-events: none;
    display: flex;
    justify-content: center;
    flex-direction: column;
}

.overlay * {
    margin: 1%;
}

.overlay h1 {
    font-family: 'SCoreDream', sans-serif;
    font-size: 3rem;
    color: whitesmoke;
    font-weight: 700;

    /* offset(x, y), blur-radius, color */
    text-shadow: 2px 3px 5px black;

}


.overlay h3 {
    align-self: center;
    width: 50%;
    border-radius: 15px;
    background-color: rgba(0, 0, 0, 0.5);
    font-size: 1.3rem;
    color: whitesmoke;
    text-shadow: 2px 3px 5px black;
}
</style>