import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets


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

# 求解线性回归问题时引入梯度下降算法的目的是，为了找到代价函数的最小值，也就是代价函数曲线的最低点
# 线性回归模型的代价函数为误差平方和代价函数 梯度下降对参数θ求偏导得出参数值
