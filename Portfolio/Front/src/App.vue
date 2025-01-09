<template>
  <div>
    <AppHeader></AppHeader>
    <div class="blank"></div>
    <!-- <HelloWorld msg="Welcome to Your Vue.js App"/> -->
    <AppMain class="tester"></AppMain>
    <!-- <ScreenCategory></ScreenCategory> -->
    <AppFooter></AppFooter>
  </div>
</template>

<script>
import './assets/main.css'

import AppHeader from './common/AppHeader.vue'
import AppFooter from './common/AppFooter.vue'
import AppMain from './common/AppMain.vue'

export default {
  name: 'App',
  components: {
    AppHeader,
    AppFooter,
    AppMain,
  }
}
</script>

<style>
@font-face {
  font-family: 'SCoreDream';
  src: url('assets/fonts/SCDream/SCDream1.otf') format('opentype');
  font-weight: 100; /* Thin */
  font-style: normal;
}

@font-face {
  font-family: 'SCoreDream';
  src: url('assets/fonts/SCDream/SCDream2.otf') format('opentype');
  font-weight: 200; /* Extra Light */
  font-style: normal;
}

@font-face {
  font-family: 'SCoreDream';
  src: url('assets/fonts/SCDream/SCDream3.otf') format('opentype');
  font-weight: 300; /* Light */
  font-style: normal;
}

@font-face {
  font-family: 'SCoreDream';
  src: url('assets/fonts/SCDream/SCDream4.otf') format('opentype');
  font-weight: 400; /* Regular */
  font-style: normal;
}

@font-face {
  font-family: 'SCoreDream';
  src: url('assets/fonts/SCDream/SCDream5.otf') format('opentype');
  font-weight: 500; /* Medium */
  font-style: normal;
}

@font-face {
  font-family: 'SCoreDream';
  src: url('assets/fonts/SCDream/SCDream6.otf') format('opentype');
  font-weight: 600; /* Semi Bold */
  font-style: normal;
}

@font-face {
  font-family: 'SCoreDream';
  src: url('assets/fonts/SCDream/SCDream7.otf') format('opentype');
  font-weight: 700; /* Bold */
  font-style: normal;
}

@font-face {
  font-family: 'SCoreDream';
  src: url('assets/fonts/SCDream/SCDream8.otf') format('opentype');
  font-weight: 800; /* Extra Bold */
  font-style: normal;
}

@font-face {
  font-family: 'SCoreDream';
  src: url('assets/fonts/SCDream/SCDream9.otf') format('opentype');
  font-weight: 900; /* Black */
  font-style: normal;
}


#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  margin: 0;
  padding: 0;
}

* {
  margin: 0;
}

.blank {
  height: 140px;
}

@import url('https://fonts.googleapis.com/css2?family=Nanum+Gothic&display=swap');

/* 전체 폰트 설정 */
* {
    font-family: 'Nanum Gothic', sans-serif;
}
</style>
