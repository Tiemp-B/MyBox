<script setuh3>

</script>

<template>
    <div class="main" id="MyStack">
        <div class="body">
            <div class="title">
                <img src="" alt="Stack icon">
                <h1>STACKS</h1>
            </div>
            <div class="contents">
                <div class="card Language">
                    <div class="label">
                        <img src="../../assets/images/language.png" alt="language icon" class="icon">
                        <h3>Language</h3>
                    </div>
                    <div class="items">
                        <div class="item">C</div>
                    </div>
                </div>
                <div class="card OS">
                    <div class="label">
                        <img src="../../assets/images/OS.png" alt="OS icon" class="icon">
                        <h3>OS</h3>
                    </div>
                    <div class="items">
                        <div class="item">Linux</div>
                    </div>
                </div>
                <div class="card Frontend">
                    <div class="label">
                        <img src="../../assets/images/Frontend.png" alt="Frontend icon" class="icon">
                        <h3>Front-end</h3>
                    </div>
                    <div class="items">
                        <div class="item">VueJS</div>
                    </div>
                </div>
                <div class="card Backend">
                    <div class="label">
                        <img src="../../assets/images/Backend.png" alt="Backend icon" class="icon">
                        <h3>Back-end</h3>
                    </div>
                    <div class="items">
                        <div class="item">MySQL</div>
                    </div>
                </div>
                <div class="card DevOps">
                    <div class="label">
                        <img src="../../assets/images/DevOps.png" alt="Devops icon" class="icon">
                        <h3>DevOps</h3>
                    </div>
                    <div class="items">
                        <div class="item">AWS</div>
                        <div class="item">Docker</div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</template>

<style scoped>
.title {
    display: flex;
    align-items: center;
    justify-content: center;
    height: 30%;
}

.title img {
    width: 40px;
    /* 아이콘 크기 */
    height: 40px;
    flex-shrink: 0;
    /* 아이콘 크기를 고정 */
    margin-right: 10px;
}

.main {
    background-color: rgb(214, 230, 245);
}

.card {
    display: flex;
    flex-direction: row;
}

.card img {
    width: 40px;
    /* 아이콘 크기 */
    height: 40px;
    flex-shrink: 0;
    /* 아이콘 크기를 고정 */
}

.card h3 {
    width: 100px;
    text-align: left;
}

.contents {
    background-color: gold;
    padding: 3%;
    border-radius: 10px;
    display: flex;
    flex-direction: column;
    gap: 5px;
    
    box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.2);
}

.label{
    flex:2;
    display: flex;
    align-items: center;
    justify-content: center;
    flex-direction: row;
}

.icon {
    margin: 2px;
    margin-right: 8px;
}

.items{
    flex: 8;
    display: flex;
    align-items: center;
}

.item {
    margin-left: 3px;
    margin-right: 3px;
    padding: 3px 5px 3px 5px;
    border-radius: 5px;
    background-color: orange;
}


</style>