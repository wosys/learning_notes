import numpy as np
import matplotlib.pyplot as plt


def h(theta,X):
    return np.dot(X,theta)


# def hypothesis(theta0,theta1,X):
#     return 
def dJ(theta,X,y):
    gd = np.dot(X.T,h(theta,X)-y)
    return gd/len(y)


def GD(X,y,lr = 0.0001,maxInteration = 50):
    theta = np.zeros((2,1))
    for i in range(maxInteration):
        # theta0_grad = 0
        # theta1_grad = 0
        gd = dJ(theta,X,y)
        # for j in range(0,len(X)):
        #     theta0_grad =theta0_grad + ((theta0 + theta1*X[j])-y[j])/m
        #     theta1_grad =theta1_grad + ((theta0 + theta1*X[j])-y[j])*X[j]/m
        theta = theta - lr*gd
        # theta0 = theta0 - lr*theta0_grad
        # theta1 = theta1 - lr*theta1_grad
    
    return theta


data = np.genfromtxt("data.csv",delimiter=',')
# X = data[:,0]
# y = data[:,1]
X = data[:,0].reshape(-1,1)
y = data[:,1].reshape(-1,1)


m = len(X)
n = X.shape[1]
XX = np.hstack((np.ones((m,1)),X))

lr = 0.0001
maxInteration = 50
# theta0 = 0
# theta1 = 0
# theta = GD(X,y,theta0,theta1,lr,maxInteration)
theta = GD(XX,y,lr,maxInteration)


plt.plot(X, y, 'b.')
plt.plot(X, theta[0]+theta[1]*X, 'r')
plt.show()
