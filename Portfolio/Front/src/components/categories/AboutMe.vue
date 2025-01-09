<script setup>

</script>

<template>
    <div class="main" id="AboutMe">
        <div class="body">
            <div class="title">
                <img src="../../assets/images/Profile.png" alt="Profile icon">
                <h1>PROFILE</h1>
            </div>
            <div class="contents">
                <div class="left">
                    <div class="circle">
                        <img src="../../assets/images/MyFace.jpg" alt="my face">
                    </div>
                </div>
                <div class="middle">
                    <div class="item">
                        <img class="icon" src="../../assets/images/Name.png" alt="Name Icon">
                        <div class="info">
                            <div class="label">이름</div>
                            <div class="value">변재혁</div>
                        </div>
                    </div>
                    <div class="item">
                        <img class="icon" src="../../assets/images/Locate.png" alt="Location Icon">
                        <div class="info">
                            <div class="label">위치</div>
                            <div class="value">대한민국 서울시 송파구</div>
                        </div>
                    </div>
                    <div class="item">
                        <img class="icon" src="../../assets/images/Email.png" alt="Email Icon">
                        <div class="info">
                            <div class="label">이메일</div>
                            <div class="value">bjh819819@naver.com</div>
                        </div>
                    </div>
                </div>
                <div class="right">
                    <div class="item">
                        <img class="icon" src="../../assets/images/Calender.png" alt="Birthday Icon">
                        <div class="info">
                            <div class="label">생년월일</div>
                            <div class="value">1996-08-19</div>
                        </div>
                    </div>
                    <div class="item">
                        <img class="icon" src="../../assets/images/Phone.png" alt="Phone Icon">
                        <div class="info">
                            <div class="label">연락처</div>
                            <div class="value">010-2575-3466</div>
                        </div>
                    </div>
                    <div class="item">
                        <img class="icon" src="../../assets/images/University.png" alt="Education Icon">
                        <div class="info">
                            <div class="label">학력</div>
                            <div class="value">서강대학교 - 전자공학과</div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</template>


<style scoped>
#AboutMe {
    background-color: white;
    justify-self: center;
    align-self: center;
    width: 100%;
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

h1{
    display: flex; /* 플렉스 컨테이너 */
    justify-content: center; /* 수평 중앙 정렬 (선택 사항) */
    align-items: center; /* 수직 중앙 정렬 */
    text-align: center; /* 텍스트 정렬 */
}

.contents {
    width: 100%;
    height: 50%;
    display: flex; /* 가로로 배치 */
    justify-content: space-between; /* 섹션 간 간격 균등 */
    gap: 20px; /* 섹션 간 간격 */
}

.left {
    flex: 1; /* 이미지 영역 */
    display: flex;
    justify-content: center;
    align-items: flex-start;
}

.middle, .right {
    flex: 2; /* 중간과 오른쪽은 동일한 크기로 분할 */
    display: flex;
    flex-direction: column; /* 세로로 배치 */
    gap: 15px; /* 항목 간 간격 */
    justify-content: end;
    margin-left: 10px;
    margin-right: 10px;
}

.item {
    display: flex; /* 아이콘과 정보 영역을 가로로 배치 */
    align-items: center;
    gap: 15px; /* 아이콘과 정보 간 간격 */
}

.icon {
    width: 40px; /* 아이콘 크기 */
    height: 40px;
    flex-shrink: 0; /* 아이콘 크기를 고정 */
}

.info {
    display: flex;
    flex-direction: column; /* 항목명과 내용 세로 정렬 */
}

.label {
    font-weight: bold; /* 항목명은 굵게 */
    font-size: 1rem;
    text-align: left;
    color: #333;
}
.value {
    font-size: 0.9rem; /* 내용은 조금 작게 */
    color: #666;
}

.circle {
    border: 3px solid mediumseagreen;
    width: 20vh;
    height: 20vh;
    border-radius: 50%;
    overflow: hidden;
    display: flex;
    justify-content: center;
    align-items: center;
    background-color: #f0f0f0;
}

.circle img {
    width: 100%;
    height: 100%;
    object-fit: cover;
}

/**
사이트 자체가 업데이트 된 후 -> API 동작 -> 데이터 수신 ->  

*/

</style>