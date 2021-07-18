import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.model_selection import train_test_split


def h(theta,X):
    return np.dot(X,theta)


def dJ(theta,X,y):
    gd = np.dot(X.T,h(theta,X)-y)
    return gd/len(y)


def GD(X,y,lr = 0.0001,maxInteration = 50):
    theta = np.zeros((14,1))
    for i in range(maxInteration):
        gd = dJ(theta,X,y)
        theta = theta - lr*gd
    
    return theta


boston = datasets.load_boston()

X = boston.data
y = boston.target

m = len(X)
n = X.shape[1]
XX = np.hstack((np.ones((m,1)),X))

X_train,X_test,y_train,y_test = train_test_split(XX,y,test_size=0.3)


lr = 0.0001
maxInteration = 50
theta_1 = GD(X_train,y_train.reshape(-1,1),lr,maxInteration)


theta_1


#MSE 平均绝对误差
from sklearn.metrics import mean_absolute_error
mean_absolute_error(y_test,h(theta_1,X_test))

# 由最小二乘法，需要求得多元线性回归的损失函数的最小值，损失函数对需要求解的参数进行求导（求梯度），并且令其导数为0，求得相应的参数。让预测结果和真实的结果的差值的平方 尽可能的小。