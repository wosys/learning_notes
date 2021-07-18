from sklearn import linear_model
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data=pd.read_csv("L:/机器学习/实验/数据/ex1data1.txt",header=None,names=['x','y'])
x=np.array(data['x']).reshape(-1,1)
y=np.array(data['y']).reshape(-1,1)
#%matplotlib inline
plt.scatter(x,y)
plt.show()

fig = plt.figure()
# 使用不同库函数进行测试
# LinearRegression（普通的线性回归）
LR = linear_model.LinearRegression()
LR.fit(x,y)
fig.add_subplot(3,2,1)
plt.scatter(x,y)
X_plot=np.linspace(4.5,23,100)
y_plot=LR.intercept_[0]+LR.coef_[0][0]*X_plot
plt.plot(X_plot, y_plot, color='red' )

# Ridge（岭回归，可以防止过拟合，L2正则化）
R = linear_model.Ridge()
R.fit(x,y)
fig.add_subplot(3,2,2)
plt.scatter(x,y)
X_plot=np.linspace(4.5,23,100)
y_plot=R.intercept_[0]+R.coef_[0][0]*X_plot
plt.plot(X_plot, y_plot, color='red')

# RidgeCV（带交叉验证的岭回归）
RCV = linear_model.RidgeCV()
RCV.fit(x,y)
fig.add_subplot(3,2,3)
plt.scatter(x,y)
X_plot=np.linspace(4.5,23,100)
y_plot=RCV.intercept_[0]+RCV.coef_[0][0]*X_plot
plt.plot(X_plot, y_plot, color='red')

# Lasso（套索回归，线性回归的L1正则化）
L = linear_model.Lasso()
L.fit(x,y)
fig.add_subplot(3,2,4)
plt.scatter(x,y)
X_plot=np.linspace(4.5,23,100)
y_plot=L.intercept_[0]+L.coef_[0]*X_plot
plt.plot(X_plot, y_plot, color='red' )

# Elastic Net（弹性网模型，综合了Ridge与Lasso模型，实际中这个模型最好，但在估计两个参数）
E = linear_model.ElasticNet()
E.fit(x,y)
fig.add_subplot(3,2,5)
plt.scatter(x,y)
X_plot=np.linspace(4.5,23,100)
y_plot=E.intercept_[0]+E.coef_[0]*X_plot
plt.plot(X_plot, y_plot, color='red' )
