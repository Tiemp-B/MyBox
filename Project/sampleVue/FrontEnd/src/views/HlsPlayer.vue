<template>
    <div>
      <video ref="video" controls autoplay></video>
    </div>
  </template>
  
  <script>
  import Hls from 'hls.js';
  
  export default {
    name: 'HlsPlayer',
    mounted() {
      const video = this.$refs.video;
      const videoSrc = 'http://localhost:8888/stream.m3u8'; // HLS 스트림 URL
  
      if (Hls.isSupported()) {
        const hls = new Hls();
        hls.loadSource(videoSrc);
        hls.attachMedia(video);
        hls.on(Hls.Events.MANIFEST_PARSED, () => {
          video.play();
        });
      } else if (video.canPlayType('application/vnd.apple.mpegurl')) {
        // HLS를 지원하는 Safari 브라우저
        video.src = videoSrc;
        video.addEventListener('loadedmetadata', () => {
          video.play();
        });
      }
    },
  };
  </script>
  
  <style scoped>
  video {
    width: 100%;
    height: auto;
  }
  </style>
  