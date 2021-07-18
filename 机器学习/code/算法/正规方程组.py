import numpy as np
import matplotlib.pyplot as plt

data = np.genfromtxt("data.csv",delimiter = ',')

X = data[:,0].reshape(-1,1)
y = data[:,1].reshape(-1,1)

#增加theta0列

m = len(X)

XX = np.hstack((np.ones((m,1)),X))

#正规方程组  X.T * X * theta = X.T * y

XX_I = np.dot(XX.T,XX)

XX_n = np.linalg.inv(XX_I)

y_n = np.dot(XX.T,y)

theta = np.dot(XX_n,y_n)

theta

plt.plot(X, y, 'b.')

plt.plot(X, theta[0]+theta[1]*X, 'r')

plt.show()








