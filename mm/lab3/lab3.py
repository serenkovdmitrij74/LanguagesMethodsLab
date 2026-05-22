import numpy as np

X_train = np.array([[18, 25],[22, 100],[30, 70],[32, 120],[24, 15],[25, 22],[32, 50],[19, 45],[22, 75],[40, 90]])
Y_train = np.array([0, 0, 0, 0, 1, 0, 1, 1, 0, 1])

X_test = np.array([[19, 27],[33, 54],[39, 88],[27, 30]])

'''
Yn = np.zeros((len(Y_train), 2))
for i in range(len(Y_train)):
    j1 = Y_train[i]
    Yn[i, j1] = 1

C = np.dot(X_train.T, X_train)
B = np.dot(Yn.T, X_train)
C = np.linalg.inv(C)
A = np.dot(B, C)

Ypred = np.zeros(len(X_test), dtype=np.uint32)
for i in range(len(X_test)):
    Ypred[i] = np.argmax(np.dot(A, X_test[i]), axis=0)

for i in range(len(X_test)):
    print(f"Клиент {i+11} класс {Ypred[i]}")
'''

'''
k = 3
C = np.zeros(len(X_test))

for i in range(len(X_test)):
    d2 = np.zeros(len(X_train))
    for j in range(len(X_train)):
        d2[j] = np.dot(X_train[j] - X_test[i], X_train[j] - X_test[i])
    
    near_indices = np.argsort(d2)[:k]
    near_classes = Y_train[near_indices].astype(int)
    counts = np.bincount(near_classes)
    C[i] = np.argmax(counts)

for i in range(len(X_test)):
    print(f"Клиент {i+11} класс: {int(C[i])}")
'''

'''
import numpy as np

data = np.loadtxt('LabMiMiMi/lab1/Iris.csv', delimiter = ',')
X = data[:,0:-1]
Y = data[:,-1]

indices = np.arange(len(X))
np.random.shuffle(indices)
train=indices[0:100]
test=indices[100:]
X_train = X[train]
Y_train = Y[train]
X_test = X[test]
Y_test = Y[test]


k = 3
C = np.zeros(len(X_test))

for i in range(len(X_test)):
    d2 = np.zeros(len(X_train))
    for j in range(len(X_train)):
        d2[j] = np.dot(X_train[j] - X_test[i], X_train[j] - X_test[i])
    
    near_indices = np.argsort(d2)[:k]
    near_classes = Y_train[near_indices].astype(int)
    counts = np.bincount(near_classes)
    C[i] = np.argmax(counts)

for i in range(len(X_test)):
    print(f"Клиент {i+11} класс: {int(C[i])}")

Ypred = np.zeros(len(Y_test), dtype=np.uint32)
for i in range(len(X_test)):
    Ypred[i] = C[i]


print('Доля правильных ответов: ', 100*(1-np.sum(np.sum(Y_test != Ypred))/len(Y_test)))
'''
