import numpy as np
infile = open('earthwjupiter10.txt')


N = 3 # number of celestial bodies

hmm = 13000

x_sun = np.zeros(hmm-1)
y_sun = np.zeros(hmm-1)
z_sun = np.zeros(hmm-1)
x_earth = np.zeros(hmm-1)
y_earth = np.zeros(hmm-1)
z_earth = np.zeros(hmm-1)
x_jupiter = np.zeros(hmm-1)
y_jupiter = np.zeros(hmm-1)
z_jupiter = np.zeros(hmm-1)
numbers = []



#count = 0
for line in infile:
    if not line.startswith("T"):
	numbers.append([float(i) for i in line.split()])

for i in range(hmm-1):
	x_sun[i] = numbers[3*i][1]
	y_sun[i] = numbers[3*i][2]
	z_sun[i] = numbers[3*i][3]
	x_earth[i] = numbers[3*i+1][1]
	y_earth[i] = numbers[3*i+1][2]
	z_earth[i] = numbers[3*i+1][3]
	x_jupiter[i] = numbers[3*i+2][1]
	y_jupiter[i] = numbers[3*i+2][2]
	z_jupiter[i] = numbers[3*i+2][3]

# -------------------------------------------------------------------------------

infile = open('earthwjupiter.txt')


hmm2 = 13000

x_sun2 = np.zeros(hmm2-1)
y_sun2 = np.zeros(hmm2-1)
z_sun2 = np.zeros(hmm2-1)
x_earth2 = np.zeros(hmm2-1)
y_earth2 = np.zeros(hmm2-1)
z_earth2 = np.zeros(hmm2-1)
#x_jupiter2 = np.zeros(hmm2-1)
#y_jupiter2 = np.zeros(hmm2-1)
#z_jupiter2 = np.zeros(hmm2-1)
numbers2 = []



#count = 0
for line in infile:
    if not line.startswith("T"):
	numbers2.append([float(i) for i in line.split()])

for i in range(hmm-1):
	x_sun2[i] = numbers2[3*i][1]
	y_sun2[i] = numbers2[3*i][2]
	z_sun2[i] = numbers2[3*i][3]
	x_earth2[i] = numbers2[3*i+1][1]
	y_earth2[i] = numbers2[3*i+1][2]
	z_earth2[i] = numbers2[3*i+1][3]
#	x_jupiter2[i] = numbers2[3*i+2][1]
#	y_jupiter2[i] = numbers2[3*i+2][2]
#	z_jupiter2[i] = numbers2[3*i+2][3]

# ----------------------------------------------------------------------------

# for plotting two in one...
#for i in range(hmm-1):
#	x_sun[i] = numbers[2*i][1]
#	y_sun[i] = numbers[2*i][2]
#	z_sun[i] = numbers[2*i][3]
#	x_earth[i] = numbers[2*i+1][1]
#	y_earth[i] = numbers[2*i+1][2]
#	z_earth[i] = numbers[2*i+1][3]

#infile2 = open('test2.txt')
#hmm2 = 1500
#x_earth2 = np.zeros(hmm2-1)
#y_earth2 = np.zeros(hmm2-1)
#z_earth2 = np.zeros(hmm2-1)

#numbers2 = []
#for line in infile2:
#    if not line.startswith("T"):
#	numbers2.append([float(i) for i in line.split()])

#for i in range(hmm2-1):
#	x_earth2[i] = numbers2[2*i+1][1]
#	y_earth2[i] = numbers2[2*i+1][2]
#	z_earth2[i] = numbers2[2*i+1][3]

# ----------------------------------------------------------------------------------



import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import seaborn as sns
from scipy.misc import imread

# create 2D plot
#plt.plot(x_sun,y_sun,'y')
plt.plot([0.0],[0.0],markerfacecolor='y',
	markeredgecolor='y',marker='o',markersize=25,
	label = 'Sun')

#plt.plot([x_earth[-1]],[y_earth[-1]],markerfacecolor='b',
#	markeredgecolor='b',marker='o',markersize=15,
#	label = 'Earth')
plt.plot(x_earth[0:1500],y_earth[0:1500],'b', label='w/ Jupiter mass * 10')

#plt.plot([x_jupiter[-1]], [y_jupiter[-1]],markerfacecolor='r',
#	markeredgecolor='r',marker='o',markersize=20,
#	label = 'Jupiter')
#plt.plot(x_jupiter,y_jupiter,'r')

#plt.plot(x_sun2,y_sun2,'--y')

#plt.plot([x_earth2[-1]],[y_earth2[-1]],markerfacecolor='b',
#	markeredgecolor='b',marker='o',markersize=15)
plt.plot(x_earth2[0:1500],y_earth2[0:1500],'--b', label='w/ Jupiter mass')

#plt.plot([x_jupiter2[-1]], [y_jupiter2[-1]],markerfacecolor='r',
#	markeredgecolor='r',marker='o',markersize=20)
#plt.plot(x_jupiter2,y_jupiter2,'--r')


#plt.plot(x_earth2,y_earth2,'b--',label='4/pi,0,0')
#plt.plot([x_earth2[-1]],[y_earth2[-1]],markerfacecolor='b',
#	markeredgecolor='b',marker='o',markersize=15)



plt.legend()
plt.xlim([-1.5,1.5])
plt.ylim([-1.5,1.5])
plt.title('Effect on the position of Earth for larger Jupiter mass')
plt.ylabel('y')
plt.xlabel('x')

plt.show()
