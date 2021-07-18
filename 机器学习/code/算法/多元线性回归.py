import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_absolute_error

def h(theta, X):
    return np.dot(X, theta)


def dJ(theta, X, y):
    gd = np.dot(X.T, h(theta, X) - y)
    return gd / len(y)


def GD(X, y, lr=0.0001, maxInteration=50):
    theta = np.zeros((14, 1))
    for i in range(maxInteration):
        gd = dJ(theta, X, y)
        theta = theta - lr * gd

    return theta


boston = datasets.load_boston()

X = boston.data
y = boston.target

m = len(X)
n = X.shape[1]
XX = np.hstack((np.ones((m, 1)), X))

X_train, X_test, y_train, y_test = train_test_split(XX, y, test_size=0.3)

lr = 0.0001
maxInteration = 50
theta_1 = GD(X_train, y_train.reshape(-1, 1), lr, maxInteration)

theta_1

mean_absolute_error(y_test, h(theta_1, X_test))




