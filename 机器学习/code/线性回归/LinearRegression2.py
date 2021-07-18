import numpy as np
import matplotlib.pyplot as plt
# from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

# 生成随机数据
m = 200
pa,pb = -3,3
X = np.random.uniform(pa, pb, size = m).reshape(-1,1)
y = 5*X + 3 + np.random.normal(0, (pb-pa)*0.23, size = m).reshape(-1,1)
# plt.scatter(X[:,-1],y)
# plt.axis([pa,pb,5*pa+3,5*pb+3])
# plt.show()

# 最速下降法求线性回归
'''
1.假设函数hypothesis function
'''
def h(theta, x):
    return theta[0]+theta[1]*x

"""
2.损失函数lost function
"""
def L(theta, x, y):
    return(h(theta, x)-y)**2

"""
3.成本函数cost function 
"""
def J(theta, X, y):
    m = len(y)
    jSum = 0
    for i in range(m):
        jSum += L(theta, X[i], y[i])
    return jSum / (2*m)

'''
梯度函数
'''
def GD(theta, X, y):
    m = len(y)
    gd = np.zeros((2,1), dtype=float).reshape(-1,1)
    for i in range(m):
        gd[0] += h(theta, X[i])-y[i]
        gd[1] +=(h(theta, X[i])-y[i])*X[i]
    return gd / m  

'''
梯度下降算法
'''
def GDA(X, y, thetaInit= [0,0], learningRate=0.2,precison=1e-4,maxIteration=10000):
    theta0 = np.array(thetaInit).reshape(-1,1)
    J0 = J(theta0,X,y)
    theta1 = np.zeros((2,1)).reshape(-1,1)

    listTheta = []
    listJ = []
    listIter = []
    listTheta.append(theta0)
    listJ.append(J0)
    listIter.append(0)

    for k in range(1, maxIteration):
        # 计算梯度
        gd = GD(theta0,X,y)
        # 计算新的迭代点
        theta1=theta0-learningRate*gd
        # 计算成本函数值
        J1 = J(theta1,X,y)
        # 判断终止条件
        if (np.linalg.norm(gd, ord=1)<precison) and (np.linalg.norm(J1 - J0)<precison):
            break
        # 更新迭代点及成本函数值
        theta0 = theta1
        J0 = J1
        # 记录迭代过程
        listTheta.append(theta0)
        listJ.append(J0)
        listIter.append(k)
    return theta1,np.array(listTheta),np.array(listJ),np.array(listIter)

# 求回归曲线（系数）
coef, thetaList, JList, iterList = GDA(X,y,learningRate=0.1)
thetaList.reshape(-1,2)
JList.reshape(-1,1)
iterList.reshape(-1,1)

fig=plt.figure()
fig.add_subplot(2,2,1)
plt.scatter(X[:,-1],y)#原始数据
plt.axis([pa,pb,5*pa+3,5*pb+3])
X_plot=np.linspace(pa,pb,100)
y_plot=coef[0]+coef[1]*X_plot
plt.plot(X_plot,y_plot,color='red')

#显示迭代过程
fig.add_subplot(2,2,2)
plt.plot(iterList,JList)

#显示参数下降过程
fig.add_subplot(2,2,3)
plt.plot(thetaList[:,0],thetaList[:,1])

#显示成本函数以及迭代过程
theta0=np.linspace(abs(np.min(thetaList[:,0]))-1,abs(np.max(thetaList[:,0])+1),50)
theta1=np.linspace(abs(np.min(thetaList[:,1]))-1,abs(np.max(thetaList[:,1])+1),50)
XLen = len(theta0)
YLen = len(theta1)
XX, YY=np.meshgrid(theta0,theta1)
JPlotList = np.zeros((XLen,YLen))
for i in range(XLen):
    for j in range(YLen):
        JPlotList[i,j]=J([theta0[i],theta1[j]],X,y)

# ax=fig.add_subplot(2,2,4,projection='3d')
# ax.plot_surface(XX,YY,JPlotList,cmap=cm.rainbow)
# ax.contour(XX,YY,JPlotList,zdir='z',offser=-2,cmap=plt.get_cmap('rainbow'))
# ax.scatter(thetaList[:,0],thetaList[:,1],JList,color='black',marker='o')

plt.show()



