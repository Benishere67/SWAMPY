# Print out realtime audio volume as ascii bars

import sounddevice as sd
import numpy as np


def print_sound(indata, outdata, frames, time, status):
    volume_norm = np.linalg.norm(indata)*10
    wtfis = volume_norm
    print ("|" * int(volume_norm))

with sd.Stream(callback=print_sound):
    sd.sleep(20000)