import math
import random
import matplotlib.pyplot as plt
import numpy as np
data = np.loadtxt('1_2.csv', delimiter = ',')
Y = data[:,0]
X = data[:,1:3]
XX = np.copy(data)
XX[:,0] = 1
A = np.dot(XX.T, XX)
b = np.dot(XX.T, Y)
a = np.linalg.inv(A).dot(b)
print(a)
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(X[:,0], X[:,1], Y, s=100)
x = np.linspace(29,105,10)
y = np.linspace(2004, 2025,10)
xgrid, ygrid = np.meshgrid(x, y)
zgrid = a[0] + a[1]*xgrid + a[2]*ygrid
ax.plot_surface(xgrid, ygrid, zgrid, color='red')
plt.show()
