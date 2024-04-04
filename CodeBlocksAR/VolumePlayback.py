import sounddevice as sd
import soundfile as sf

data, fs = sf.read('Wooock.mp3')
sd.play(data, fs)
sd.wait()