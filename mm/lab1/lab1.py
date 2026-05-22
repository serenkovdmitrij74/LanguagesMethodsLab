import math
import random
import matplotlib.pyplot as plt
import numpy as np
Y = np.array([7.5,24,32,47,93,120,134,144,245,260,380])
X=np.array([22,68,108,137,255,315,390,405,685,700,1100])
A=np.array([[11,np.sum(X)],[np.sum(X),np.dot(X,X)]]) 
b = np.array([np.sum(Y), np.dot(X,Y)])
a = np.linalg.inv(A).dot(b)
plt.plot(X,Y,'ro')
Xl = np.array([21, 1101])
Yl = np.array([a[0]+a[1]*Xl[0], a[0]+a[1]*Xl[1]])
plt.plot(Xl,Yl)
plt.show()
