import numpy as np
import random
import matplotlib.pyplot as plt

num = 100
text = "Some text"

print(num)
print(text)
print("Hello world!", num)

arr = [1,2,3,4,5] # определение массива
arr.append(6) # добавление нового элемента
print(arr) # вывод всего массива
print(arr[5]) # вывод элемнета массива

arr = [1,2,3,4,5]
for el in arr:
    print(el**3) # вывод третьих степеней чисел массива arr


X=[0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9]
Y=[0.01,0.04,0.09,0.16,0.25,0.36,0.49,0.64,0.81,1.0]
for x,y in zip(X,Y):
    print(x*x+y)

def f(x,y):
    return x+y
    print(f(1,2)) # печатает 3

x=-12
if x<0 :
    y=-x
else:
    y=x
print(y) # вывод модуля числа x.


P=[]
f = open("coords.txt")
for line in f:
    x,y = line.split()
P.append((float(x), float(y)))
f.close()
print(P)


N = 100
a = 0
b = 10
P = [] # массив всех точек
X = [] # массив координат x
Y = [] # массив координат y
for i in range(N):
    x = random.uniform(a,b)
    y = random.uniform(a,b)
    X.append(x)
    Y.append(y)
    P.append((x,y))


# массивы X и Y взяты из прошлого кода
plt.plot(X,Y,'ro')
plt.show()

import math
# функция зависимости y от x
def f(x):
    return math.sin(x)
N = 100
a = 0
b = 10
P = []
X = []
Y = []
for i in range(N):
    x = a + i*(b-a)/N
    y = f(x)
    X.append(x)
    Y.append(y)
    P.append((x,y))
plt.plot(X,Y, 'bx') # ’b’- blue, x- вид точки на графике
plt.show()

A=[0,1]
B=[0,0]
def dist(A,B):#поиск расстояние между двумя точками
    dx=B[0]-A[0]
    dy=B[1]-A[1]
    return math.sqrt(dx**2+dy**2)
print(dist(A,B))


def dist(A,B):
    d=0
    for x,y in zip(A,B):
        d+=(x-y)*(x-y)
    return math.sqrt(d)

e=[[0,0],[1,1]]
l=[[1,2],[3,1]]
def length(e): # вычисление длины отрезка
    return dist(e[0],e[1])

l=[1,-1,2] # прямая
p=[0,0] # точка
def from_line(l,p): # вычисление расстояния между прямой и точкой.
    den = math.abs(l[0]*p[0]+l[1]*p[1]+l[2])
    nom = math.sqrt(l[0]*l[0]+l[1]*l[1])
    return den/nom

A=[0,2]
B=[3,1]
P=[A,B] # прямоугольник
# процедура вычисления пощади прямоугольника.
def area(P):
    dx=abs(P[1][0]-P[0][0])
    dy=abs(P[1][1]-P[0][1])
    return dx*dy
print(area(P))

A = [0,0]
B = [1,0]
C = [0,3]
7
T1 = [A,B,C]
T2 = [[0,2],[-1,4],[2,3]]
# процедуравычисления пощади треугольника.
def area_tr(T):
    A = [T[1][0]-T[0][0], T[1][1]-T[0][1]]
    B = [T[2][0]-T[0][0], T[2][1]-T[0][1]]
    return abs(A[0]*B[1]-A[1]*B[0])/2
print(area_tr(T1))

A = [[2,3,-1], [3,-1, 4],[5,-2, 2]]
b = [5, 13, 7]

A = np.array(A)
b = np.array(b)
x = np.linalg.inv(A).dot(b)
print(x)

x = np.linalg.solve(A,b)
print(x)

A = np.array([[2, 3,-1], [3,-1,4], [5,-2, 2]]) #задаем матрицу системы
b = np.array([5, 13, 7]) # праваячасть системы
x = np.linalg.inv(A).dot(b) # решение СЛУ методом обратной матрицы
print(x)
B = np.array([[0, 2, 4], [2, 0,-1], [1, 2, 6]]) #задаем новую матрицу
C = A*B #поэлементное умножение
print(C)
C = A.dot(B)# матричное умножение
print(C)
C = A +B
print(C) # поэлементное сложение
det = np.linalg.det(A) # определитель матрицы
print(det)
D = A.T# транспонирование матрицы
print(D)
F = np.linalg.inv(A) # вычисление обратной матрицы
print(F)

data = np.loadtxt("data.txt", delimiter=";")
print(data[:,1:4])





#Задание 2
A = [[2, 3, -1],
     [3, -1, 4],
     [5, -2, 2]]
b = [5, 13, 7]

A = np.array(A, dtype=float)
b = np.array(b, dtype=float)
n = len(b)


#Обратная матрица
x1 = np.linalg.inv(A) @ b
print("Обратная матрица:")
print(x1)


#Метод Крамера
def cramer_solve(A, b):
    detA = np.linalg.det(A)
    if abs(detA) == 0:
        return "Определитель hfdyt yek."

    n = len(b)
    x = np.zeros(n)
    for i in range(n):
        Ai = A.copy()
        Ai[:, i] = b
        detI = np.linalg.det(Ai)
        x[i] = detI / detA
    return x

x2 = cramer_solve(A, b)
print("Метод Крамера:")
print(x2)


#Функция NumPy
x3 = np.linalg.solve(A, b)
print("NumPy linalg.solve:")
print(x3)


#Задание 3
A = np.loadtxt("A.csv", delimiter=";")

C = A.T @ A
print("A^T A = C:")
print(C)

try:
    D = np.linalg.inv(C) @ A.T
    print("(A^T A)^{-1} A^T = D:")
    print(D)
except np.linalg.LinAlgError:
    print("Матрица A^T A вырождена, обратной нет")
