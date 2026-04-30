import math
import random
import matplotlib.pyplot as plt
import numpy as np
A = np.loadtxt("3_zadanie_data.csv", delimiter=",")
D=A.T 
ATA = D.dot(A)
G=np.linalg.inv(ATA)
V = G.dot(D)
print(ATA)
print()
print(V)