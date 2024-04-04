import sounddevice as sd
import soundfile as sf
import numpy as np


#duration = 5.5  seconds

sd.default.channels = 2

data, fs = sf.read('Wooock.mp3')




def print_sound(indata, outdata, frames, time, status):
    volume_norm = np.linalg.norm(indata)*10
    wtfis = volume_norm
    print ("|" * int(volume_norm))


sd.play(data, fs)
with sd.Stream(channels=2, callback=print_sound):
    sd.wait()