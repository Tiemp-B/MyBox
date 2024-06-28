import time
import datetime
import pyaudio
import wave
import speech_recognition as sr
from gtts import gTTS
import pygame
from GPT import GPT_TALK

# 녹음할 오디오 파일 경로
output_path = 'recorded_audio.wav'

# 녹음 설정
chunk = 1024  # 버퍼 크기
sample_format = pyaudio.paInt16  # 비트 수
channels = 2  # 스테레오
sample_rate = 44100  # 샘플링 속도
record_seconds = 5  # 녹음 시간 (초)

# PyAudio 인스턴스 생성
audio_recorder = pyaudio.PyAudio()
device_index = 0

def mic_set():  # 입력 장치 목록 출력
    print("Available audio input devices:")
    for i in range(audio_recorder.get_device_count()):
        info = audio_recorder.get_device_info_by_index(i)
        if info['maxInputChannels'] > 0:
            print(f"{i}: {info['name']}")

    # 사용하려는 입력 장치 인덱스 설정
    return int(input("Enter the device index you want to use: "))


def recognize_speech_from_file(lang, filename=output_path):
    recognizer = sr.Recognizer()
    with sr.AudioFile(filename) as source:
        audio_data = recognizer.record(source)
        try:
            if lang == 1:
                text = recognizer.recognize_google(audio_data, language='en-US')
            elif lang == 2:
                text = recognizer.recognize_google(audio_data, language='ko-KR')
            print("Recognized Text:", text)
            return text
        except sr.UnknownValueError:
            print("Google Speech Recognition could not understand audio")
            return ""
        except sr.RequestError as e:
            print(f"Could not request results from Google Speech Recognition service; {e}")
            return ""


def record_save():
    timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    output_path = f"rec_{timestamp}.wav"
    stream = audio_recorder.open(format=sample_format,
                                 channels=channels,
                                 rate=sample_rate,
                                 frames_per_buffer=chunk,
                                 input=True,
                                 input_device_index=device_index)
    # 오디오 데이터 저장을 위한 wave 라이브러리 인스턴스 생성
    wave_file = wave.open(output_path, 'wb')
    wave_file.setnchannels(channels)
    wave_file.setsampwidth(audio_recorder.get_sample_size(sample_format))
    wave_file.setframerate(sample_rate)

    # 오디오 녹음
    print("녹음을 시작합니다. 5초 동안 녹음합니다.")
    frames = []

    start_time = time.time()
    while time.time() - start_time < record_seconds:
        data = stream.read(chunk)
        frames.append(data)

    # 녹음 데이터 저장
    stream.stop_stream()
    stream.close()

    wave_file.writeframes(b''.join(frames))
    wave_file.close()
    print("녹음이 완료되었습니다.")
    return output_path


def text2wav(text, lang):
    timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    tts_path = f"tts_{timestamp}.mp3"

    if lang == 1:
        eng_wav = gTTS(text)
        eng_wav.save(tts_path)
    elif lang == 2:
        kor_wav = gTTS(text, lang="ko")
        kor_wav.save(tts_path)

    print("TTS start")
    time.sleep(0.3)
    pygame.mixer.init()
    pygame.mixer.music.load(tts_path)
    pygame.mixer.music.play()
    while pygame.mixer.music.get_busy():
        time.sleep(1)
    print("TTS end")


if __name__ == "__main__":
    device_index = mic_set()
    text = ""
    mode = int(input("Enter 1 to voice to TTS, 2 for talk with GPT: "))
    while text != "종료":
        lang = int(input("Enter 1 to record eng, 2 for kor: "))
        rec_path = record_save()
        text = recognize_speech_from_file(lang=lang,filename=rec_path)
        if(text == "종료"): break
        if(mode == 1):
            if text != "":
                text2wav(text, lang)
        elif(mode == 2):
            if text == "": continue
            out = GPT_TALK(text)
            print(out)
            text2wav(out, lang)
    audio_recorder.terminate()
