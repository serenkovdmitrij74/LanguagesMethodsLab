# num = 111
# text = "Some text about my life"
# print(num)
# print(text)
# print('TRalala', num)

# arr = [1,2,3,4,5]
# arr.append(6)
# print(arr)
# print(arr[5])

# arr = [1,2,3,4,5]
# for el in arr:
#     print(el**3)

# X = [0.2, 0.1, 0.67, 0.1111]
# Y = [0.11, 0.0, 1, 10]
# for x,y in zip(X,Y):
#     print(x*(x+y))

# def f(x,y):
#     return x+y 
# print(f(1,19))

# x=-12
# if x<0:
#     y=-x
# else:
#     y=x
# print(y) 

# P=[]
# f=open("points.txt")
# for line in f:
#     x,y = line.split()
#     P.append((float(x),float(y)))
# f.close()
# print(P)

# import random
# N = 100
# a = 0
# b = 10
# P = [] 
# X = [] 
# Y = [] 
# for i in range(N):
#     x = random.uniform(a,b)
#     y = random.uniform(a,b)
#     X.append(x)
#     Y.append(y)
#     P.append((x,y))
# print(P)

# X = [0.1,0.3,1,10]
# Y = [0.2,3,2,1]
# import matplotlib.pyplot as plt
# plt.plot(X,Y,'ro')
# plt.show()

# import math
# import random
# import matplotlib.pyplot as plt
# def f(x):
#     return math.sin(x)
# N=100
# a=0
# b=10
# P=[]
# X=[]
# Y=[]
# for i in range(N):
#     x = a+i*(b-a)/N
#     y=f(x)
#     X.append(x)
#     Y.append(y)
#     P.append((x,y))
# plt.plot(X,Y, 'rx')
# plt.show()
# import math
# import random
# import matplotlib.pyplot as plt
# #A=[0,1]
# #B=[0,0]
# def dist(A,B):
#     dx = B[0]-A[0]
#     dy = B[1]-A[1]
#     return math.sqrt(dx**2+dy**2)
# print(int(dist(A,B)))

# def dist(A,B):
#     d=0
#     for x,y in zip(A,B):
#         d+=(x-y)*(x-y)
#     return math.sqrt(d)
# print(dist(A,B))    

# e=[[0,0],[1,1]]
# l=[[1,2],[3,1]]
# def length(e):
#     return dist(e[0],e[1])
# print(length(e))

# A=[0,2]
# B=[3,1]
# P=[A,B] 
# def area(P):
#   dx=abs(P[1][0]-P[0][0])
#   dy=abs(P[1][1]-P[0][1])
#   return dx*dy
# print(area(P))

# A=[0,1]
# B=[1,0]
# C = [0,3]
# T1 = [A,B,C]
# T2 = [[0,2], [-1,4], [2,3]]
# def area_tr(T):
#     A = [T[1][0]-T[0][0], T[1][1]-T[0][1]]
#     B = [T[2][0]-T[0][0], T[2][1]-T[0][1]]
#     return abs(A[0]*B[1]-A[1]*B[0])
# print(area_tr(T1))

# import numpy as np
# A = [[2, 3, -1], [3, -1, 4], [5, -2, 2]]
# b = [5, 13, 7]
# A=np.array(A)
# b=np.array(b)
# x = np.linalg.inv(A).dot(b)
# print(x)
# import numpy as np
# # A = np.array([[2, 3, -1], [3, -1, 4], [5, -2, 2]]) 
# # b = np.array([5, 13, 7])
# # x = np.linalg.inv(A).dot(b) 
# # # print(x)
# # B = np.array([[0, 2, 4], [2, 0, -1], [1, 2, 6]]) 
# # # C = A*B 
# # # print(C)

# # # C=A.dot(B)
# # # print(C) умножение как на алгеме

# # # C=A+B 
# # # print(C)

# # detA = np.linalg.det(A)
# # print(detA)
# # D = A.T 
# # print(D)
# # F = np.linalg.inv(A)
# # print(F)
# # print(Eig)
# data = np.loadtxt("data.txt", delimiter=",")
# print(data[:,1:4])

# import numpy as np
# data = np.loadtxt("data.txt", delimiter=";")
# print(data[:,1:4])

# Laba0
import numpy as np
n = int(input("количество столбцов матрицы "))
s = int(input("количество строк матрицы "))
MAT = np.loadtxt("matrix_data.txt", delimiter=";")
sv_chleny = np.array(MAT[:,0])
if n==s:
    mat_A = np.array(MAT[:,1:s+1:1])
    x = np.linalg.inv(mat_A).dot(sv_chleny)
    x1 = np.linalg.solve(mat_A,sv_chleny)
    print(x,"посчитано с помощью обратной матрицы")
    print(x1, 'посчитано с помощью встроенной функцией библиотеки numpy')
    detA=np.linalg.det(mat_A)
    for i in range(0,s):
        MatI=mat_A.copy()
        MatI[:,i] = sv_chleny
        detMatI=np.linalg.det(MatI)
        i+=1
        xi = detMatI/detA
        print(xi)