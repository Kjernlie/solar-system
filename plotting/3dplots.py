import numpy as np
infile = open('3d.txt')

N = 10 # number of celestial bodies


hmm = 13000

xcoords = np.zeros((hmm-1,N))
ycoords = np.zeros((hmm-1,N))
zcoords = np.zeros((hmm-1,N))
numbers = []


for line in infile:
    if not line.startswith("T"):
        numbers.append([float(i) for i in line.split()])

for i in range(hmm-1):
	for j in range(N):
		xcoords[i][j] = numbers[N*i+j][1]
		ycoords[i][j] = numbers[N*i+j][2]
		zcoords[i][j] = numbers[N*i+j][3]

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import seaborn as sns
from scipy.misc import imread


# Create 3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
#ax.set_axis_bgcolor('black')
ax.grid(False)

# Adding a picture of the universe...
img = imread('uni2.jpg')
ax.imshow(img, extent=[-0.1, 0.1, -0.1, 0.1],alpha=0.9)

# Plotting the sun
ax.plot([0.0],[0.0],[0.0], markerfacecolor='y', markeredgecolor='r', marker='o', markersize = 25,label='Sun')
#ax.plot(x_sun,y_sun,z_sun,'y') 

# Plotting Earth
ax.plot(xcoords[:,1],ycoords[:,1],zcoords[:,1],'b')
ax.plot([xcoords[-1,1]], [ycoords[-1,1]], [zcoords[-1,1]], markerfacecolor='b', markeredgecolor='b', marker='o', markersize=15, alpha=0.9, label='Earth')

# Plotting Jupyter
ax.plot(xcoords[:,2],ycoords[:,2],zcoords[:,2],'r')
ax.plot([xcoords[-1,2]], [ycoords[-1,2]], [zcoords[-1,2]], markerfacecolor='r', markeredgecolor='r', marker='o', markersize=20, alpha=0.9, label="Jupiter")

# Plotting Mercury
ax.plot(xcoords[:,3],ycoords[:,3],zcoords[:,3],'g')
ax.plot([xcoords[-1,3]], [ycoords[-1,3]], [zcoords[-1,3]], markerfacecolor='g', markeredgecolor='g', marker='o', markersize=15, alpha=0.9, label="Mercury")

# Plotting Venus
ax.plot(xcoords[:,4],ycoords[:,4],zcoords[:,4],'c')
ax.plot([xcoords[-1,4]], [ycoords[-1,4]], [zcoords[-1,4]], markerfacecolor='c', markeredgecolor='c', marker='o', markersize=15, alpha=0.9, label="Venus")

# Plotting Mars
ax.plot(xcoords[:,5],ycoords[:,5],zcoords[:,5],'m')
ax.plot([xcoords[-1,5]], [ycoords[-1,5]], [zcoords[-1,5]], markerfacecolor='m', markeredgecolor='m', marker='o', markersize=15, alpha=0.9, label="Mars")

# Plotting Saturn
ax.plot(xcoords[:,6],ycoords[:,6],zcoords[:,6],'azure')
ax.plot([xcoords[-1,6]], [ycoords[-1,6]], [zcoords[-1,6]], markerfacecolor='azure', markeredgecolor='azure', marker='o', markersize=15, alpha=0.9, label="Saturn")

# Plotting Uranus
ax.plot(xcoords[:,7],ycoords[:,7],zcoords[:,7],'indigo')
ax.plot([xcoords[-1,7]], [ycoords[-1,7]], [zcoords[-1,7]], markerfacecolor='indigo', markeredgecolor='indigo', marker='o', markersize=15, alpha=0.9, label="Uranus")


# Plotting Neptune
ax.plot(xcoords[:,8],ycoords[:,8],zcoords[:,8],'powderblue')
ax.plot([xcoords[-1,8]], [ycoords[-1,8]], [zcoords[-1,8]], markerfacecolor='powderblue', markeredgecolor='powderblue', marker='o', markersize=15, alpha=0.9, label="Neptune")

# Plotting Pluto
ax.plot(xcoords[:,9],ycoords[:,9],zcoords[:,9],'crimson')
ax.plot([xcoords[-1,9]], [ycoords[-1,9]], [zcoords[-1,9]], markerfacecolor='crimson', markeredgecolor='crimson', marker='o', markersize=15, alpha=0.9, label="Pluto")


ax.set_xlim([-8,8])
ax.set_ylim([-8,8])
ax.set_zlim([-0.3,0.3])
l = plt.legend()
for text in l.get_texts():
	text.set_color("white")

plt.show()

