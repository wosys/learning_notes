# 用正规方程组方法求解单特征线性回归
import numpy as np
import matplotlib.pyplot as plt

data = np.genfromtxt("./ML/ex1data1.txt", delimiter=",")
x_data = data[:, 0, np.newaxis]
y_data = data[:, 1, np.newaxis]

#数据初始化
X = np.c_[np.ones(len(x_data)),x_data] # 创建一个行数为len（x_data）列数为1的矩阵
y = np.c_[y_data] # np.c_是按行连接两个矩阵，就是把两矩阵左右相加，要求行数相等。

#初始化⊙
theta = np.zeros((2,1))

#正规方程的代码表示 
theta = np.linalg.inv(X.T.dot(X)).dot(X.T.dot(y)) # 矩阵求逆

# 画图
plt.scatter(x_data, y_data)
plt.xlabel('X')
plt.ylabel('y')

#画回归方程
theta0 = theta[0]
theta1 = theta[1]

min_x,max_x = np.min(X),np.max(X)
min_y = theta1*min_x + theta0
max_y = theta1*max_x + theta0
plt.plot((min_x,max_x),(min_y,max_y),c='g')

plt.show()