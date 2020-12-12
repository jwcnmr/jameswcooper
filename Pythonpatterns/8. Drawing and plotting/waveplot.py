import matplotlib.pyplot as plt
import math
import numpy

waves=[]
ASIZE=16384
#create wave array
for x in range(0, ASIZE):
    waves.append(math.exp((ASIZE-x)/ASIZE)*(math.cos(x/100.0)+math.cos(x/5.0)))
#create frequency array
#freqdata=numpy.fft.fft(waves, ASIZE)
#real=[]

#for x in range(0, int(ASIZE/2)):
#    real.append(freqdata[x].real)

fig, ax= plt.subplots()
ax.plot(waves)
#print(fig, ax)
#ax.plot(real)
#plt.show()



plt.show()