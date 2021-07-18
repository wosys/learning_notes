import numpy as np
import pandas as pd
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler

# 导入数据
dataFile = './ML/LogisticRegression_Data1.txt'
data = pd.read_csv(dataFile, names=['exam1','exam2','admitted'])
# print(data.shape)
# print(data.head())
# print(data.describe())


# 1.Sigmoid函数
def Sigmoid(z):
    return 1/(1+np.exp(-z))

# 2.假设函数
# 参数: x为 m*(n+1)的样本，theta为 (n+1)*1
# 返回: m*1, 表示 m个样本预测值向量
def h(theta, x):
    return Sigmoid(np.dot(x, theta))

# 3.成本函数
# 参数: x为 m*(n+1)，表示所有样本矩阵，第i行表示第i个样本向量的转置， theta为(n+1)*1， y为 m*1
# 返回:所有样本误差的均值
def J(theta, X, y):
    J1 = np.dot(np.log(h(theta, X)).T, y)
    J2 = np.dot((1-np.log(h(theta, X))).T, 1-y)
    return -(J1 + J2) / len(y)

# 4.梯度计算公式
def dJ(theta, X, y):
    gd = np.dot(X.T, h(theta,X)-y)
    return gd / len(y) 

# 5.梯度下降算法
# 参数: x为 m*(n+1)，表示所有样本矩阵，第i行表示第i个样本向量的转置， theta为(n+1)*1，y为 m*1
# 返回:最优参数theta
def gradient_descent(X, y, learningRate = 0.2, precision = 1e-4, maxIteration = 1000):
    theta0 = np.zeros((X.shape[1], 1)).reshape(-1, 1)
    J0 = J(theta0, X, y)
    theta1 = theta0.copy()
    k=0
    listTheta = []
    listJ = []
    listIter = []
    listTheta.append(theta0)
    listJ.append(J0)
    listIter.append(k)

    while k < maxIteration:
        k=k+1
        #计算梯度
        gd = dJ(theta0, X, y)
        #计算新的迭代点
        theta1 = theta0 - learningRate*gd
        #计算成本函数值
        J1 = J(theta1, X, y)
        #记录迭代过程
        listTheta.append(theta1)
        listJ.append(J1)
        listIter.append(k)
        #判断终止条件
        if (np.linalg.norm(gd, ord=2) < precision) and (np.linalg.norm(J1 - J0) < precision):
            break
        #更新迭代点及成本函数值
        theta0 = theta1
        J0=J1
    return theta1, listTheta, listJ, listIter

# 测试、可视化测试数据
# 数据标准化
data_value = np.array(data)
X = data_value[:, :2]
y = data_value[:, -1].reshape(-1,1)

std_scaler = StandardScaler()
std_scaler.fit(X)
X = std_scaler.transform(X)

# 求决策边界
m = len(X)
n = X.shape[1] # X的列数
XX = np.hstack((np.ones((m, 1)), X))


optTheta, thetaList, JList, iterList = gradient_descent(XX,y,learningRate=0.002)
thetaList = np.array(thetaList).reshape(-1,n+1)
JList = np.array(JList).reshape(-1,1)
iterList = np.array(iterList).reshape(-1,1)

#绘制决策边界
# (theta0+theta1* x1+theta2*x2=0)
# x2=-(theta0+theta1*x1)/theta2
x_max, x_min = np.min(X[:, 0]),np.max(X[:, 0])
x1_plot = np.linspace(x_max, x_min, 100)
x2_plot = -(optTheta[0]+optTheta[1]*x1_plot)/optTheta[2]
plt.plot(x1_plot, x2_plot)

plt.scatter(X[y[:,-1]==0,0], X[y[:,-1]==0,1],color='red')
plt.scatter(X[y[:,-1]==1,0], X[y[:,-1]==1,1],color='blue')
plt.show()

#显示迭代过程
plt.plot(iterList,JList)
plt.show()

#显示参数下降过程
fig = plt.figure()
axes3d = Axes3D(fig)
# print(thetaList.shape)
axes3d.scatter3D(thetaList[:,0],thetaList[:,1],thetaList[:,2])
plt.show()
