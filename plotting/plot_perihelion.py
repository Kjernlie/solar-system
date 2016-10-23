import matplotlib.pyplot as plt
import seaborn as sns

infile = open('perihelion20_8Newton.txt')

numbers = []
for line in infile:
	numbers.append(float(line))



plt.plot(numbers)
plt.title('The perihelion precession of Mercury')
plt.ylabel('Perihelion angle [rad]')
plt.xlabel('Number of full rotations around the Sun')
plt.show()
