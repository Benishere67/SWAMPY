import pyaudio
import wave
import numpy as np


filename = 'TalkinAll.wav'

# Set chunk size of 1024 samples per data frame
chunk = 1024  

# Open the sound file 
wf = wave.open(filename, 'rb')


def print_sound(indata):
    volume_norm = np.linalg.norm(indata)*0.7
    #wtfis = volume_norm
    print ("|" * int(volume_norm))

# Create an interface to PortAudio
p = pyaudio.PyAudio()

# Open a .Stream object to write the WAV file to
# 'output = True' indicates that the sound will be played rather than recorded
stream = p.open(format = p.get_format_from_width(wf.getsampwidth()),
                channels = wf.getnchannels(),
                rate = wf.getframerate(),
                output = True)

# Read data in chunks
data = wf.readframes(chunk)
dataK = wf.readframes(1)

# Play the sound by writing the audio data to the stream
while data != '':
    stream.write(data)
    signnal_gm = np.frombuffer(dataK, dtype=np.uint8, count = 2)
    print_sound(signnal_gm)
    #print(signnal_gm)
    data = wf.readframes(chunk)
    dataK = wf.readframes(1)


# Close and terminate the stream
stream.close()
p.terminate()