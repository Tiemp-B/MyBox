<template>
    <div>
      <video
        id="my-video"
        class="video-js"
        controls
        preload="auto"
        width="640"
        height="360"
        data-setup="{}"
      >
        <source :src="videoSrc" type="application/x-mpegURL" />
        Your browser does not support HTML5 video.
      </video>
    </div>
  </template>
  
  <script>
  import videojs from 'video.js';
  import 'video.js/dist/video-js.css';
  
  export default {
    data() {
      return {
        //videoSrc: 'http://localhost:8000/output.m3u8' // HLS URL
        videoSrc: 'http://192.168.0.18:8000/output.m3u8' // HLS URL
      };
    },
    mounted() {
      this.player = videojs(this.$refs.videoPlayer);
    },
    beforeDestroy() {
      if (this.player) {
        this.player.dispose();
      }
    }
  };
  </script>
  
  <style scoped>
  .video-js {
    width: 100%;
    height: auto;
  }
  </style>
  