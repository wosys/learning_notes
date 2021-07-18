import numpy as np
import matplotlib.pyplot as plt

def h(theta, X):
    return np.dot(X, theta)

def dJ(theta, X, y):
    gd = np.dot(X.T, h(theta, X) - y)
    return gd / len(y)

def GD(X, y, lr=0.0001, maxInteration=50):
    theta = np.zeros((2, 1))

    for i in range(maxInteration):

        gd = dJ(theta, X, y)

        theta = theta - lr * gd

    return theta


data = np.genfromtxt("data.csv", delimiter=',')

X = data[:, 0].reshape(-1, 1)

y = data[:, 1].reshape(-1, 1)

m = len(X)

n = X.shape[1]

XX = np.hstack((np.ones((m, 1)), X))

lr = 0.0001

maxInteration = 50


theta = GD(XX, y, lr, maxInteration)

plt.plot(X, y, 'b.')

plt.plot(X, theta[0] + theta[1] * X, 'r')

plt.show()

np.zeros(2).reshape(-1, 1)

np.zeros((2, 1))   #生成2行1列的零矩阵


