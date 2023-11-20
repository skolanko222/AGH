import numpy as np
import matplotlib.pyplot as plt
import re
import math

f = open("data.txt", "r") 

V11 = []
V12 = []
E11 = []
E12 = []
S11 = [float(s) for s in re.findall(r'-?\d+\.?\d*', f.readline())]
for i in range(0, 100):
    V11.append([float(s) for s in re.findall(r'-?\d+\.?\d*', f.readline())])
for i in range(0, 100):
    E11.append([float(s) for s in re.findall(r'-?\d+\.?\d*', f.readline())])
S12 = [float(s) for s in re.findall(r'-?\d+\.?\d*', f.readline())]
for i in range(0, 100):
    V12.append([float(s) for s in re.findall(r'-?\d+\.?\d*', f.readline())])
for i in range(0, 100):
    E12.append([float(s) for s in re.findall(r'-?\d+\.?\d*', f.readline())])
x11 = []
x12 = []
for i in range(1, len(S11)+1):
    x11.append(i)
for i in range(1, len(S12)+1):
    x12.append(i)

S21 = [float(s) for s in re.findall(r'-?\d+\.?\d*', f.readline())]
S22 = [float(s) for s in re.findall(r'-?\d+\.?\d*', f.readline())]
S23 = [float(s) for s in re.findall(r'-?\d+\.?\d*', f.readline())]
S24 = [float(s) for s in re.findall(r'-?\d+\.?\d*', f.readline())]
x21 = []
x22 = []
x23 = []
x24 = []
for i in range(1, len(S21)+1):
    x21.append(i)
for i in range(1, len(S22)+1):
    x22.append(i)
for i in range(1, len(S23)+1):
    x23.append(i)
for i in range(1, len(S24)+1):
    x24.append(i)

figure, (ax1, ax2) = plt.subplots(1, 2, figsize=(13, 5))
ax1.plot(x11, S11, label='w=0.6, it=' + str(len(x11)))
ax1.plot(x12, S12, label='w=1.0, it=' + str(len(x12)))
ax1.set_xlim([2,100000])
ax1.set_ylim([0,5000])
ax1.set_xlabel('nr iteracji')
ax1.set_ylabel('S')
ax1.title.set_text('Relaksacja Globalna')
ax1.legend(loc='upper right')
ax1.set_xscale('log')
ax2.plot(x21, S21, label='w=1.0, it=' + str(len(x21)))
ax2.plot(x22, S22, label='w=1.4, it=' + str(len(x22)))
ax2.plot(x23, S23, label='w=.1.8, it=' + str(len(x23)))
ax2.plot(x24, S24, label='w=1.9, it=' + str(len(x24)))
ax2.set_xlim([2,100000])
ax2.set_ylim([0,3000])
ax2.set_xlabel('nr iteracji')
ax2.set_ylabel('S')
ax2.title.set_text('Relaksacja Lokalna')
ax2.legend(loc='upper right')
ax2.set_xscale('log')
plt.savefig("Relaksacja_S.png",bbox_inches='tight',transparent=False)

figure, ((ax3, ax4), (ax5, ax6)) = plt.subplots(2, 2, figsize=(13, 10))
ax3.imshow(V11, cmap='jet')
#ax3.colorbar()
ax4.imshow(V12, cmap='jet')
#ax4.colorbar()
ax5.imshow(E11, cmap='jet')
#ax5.colorbar()
ax6.imshow(E12, cmap='jet')
#ax6.colorbar()
plt.savefig("Potencjal_Blad.png",bbox_inches='tight',transparent=False)

#figure, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(13, 10))
#ax4.plot(x11, v11, label='TOL 10^(-2)')
#ax4.plot(x12, v12, label='TOL 10^(-5)')
#ax4.set_xlim([-2.5,2.5])
#ax4.set_ylim([-8,8])
#ax4.title.set_text('Metoda Trapezow')
#ax4.set_xlabel('x')
#ax4.set_ylabel('v(x)')
#ax4.legend(loc='upper right')
#plt.savefig("Metoda_trapezow.png",bbox_inches='tight',transparent=False)





