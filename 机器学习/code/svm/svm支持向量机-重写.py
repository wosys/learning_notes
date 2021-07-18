import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.preprocessing import StandardScaler
from sklearn.svm import LinearSVC

import sys
import os
from matplotlib.colors import ListedColormap

sys.path.append('.')
sys.path.append('..')
def plot_decision_boundary(pred_func):
 
    # 设定最大最小值，附加一点点边缘填充
    x_min, x_max = X[:, 0].min() - .5, X[:, 0].max() + .5
    y_min, y_max = X[:, 1].min() - .5, X[:, 1].max() + .5
    h = 0.01
 
    xx, yy = np.meshgrid(np.arange(x_min, x_max, h), np.arange(y_min, y_max, h))
 
    # 用预测函数预测一下
    Z = pred_func(np.c_[xx.ravel(), yy.ravel()])
    Z = Z.reshape(xx.shape)
 
    # 然后画出图
    plt.contourf(xx, yy, Z, cmap=plt.cm.Spectral)
    plt.scatter(X[:, 0], X[:, 1], c=y, cmap=plt.cm.Spectral)
                
iris = datasets.load_iris()
X_all = iris.data
y_all = iris.target
X= X_all[y_all<2,:2]
y = y_all[y_all<2]
plt.scatter(X[y==0,0],X[y==0,1],color='red.')
plt.scatter(X[y==1,0],X[y==1,1],color='blue.' )
StdScaler=StandardScaler()
StdScaler.fit(X)
X_std = StdScaler.transform(X)
svc=LinearSVC(color=1e10)
svc.fit(X_std,y)
plot_decision_boundary(svc, axis=[-3,3,-3,3])
plt.scatter(X_std[y==0,0],X_std[y==0, 1],color='red.' )
plt.scatter(X_std[y==1,0],X_std[y==1,1],color='blue.' )
plt.show( )
print(svc.coef_)
print(svc.intercept_)

def plot_svc_decision_boundary(model, axis ):
    X1 = np.linspace(axis[0], axis[1], int(axis[1] - axis[0])*100).reshape(-1,1)
    X2 = np.linspace(axis[2], axis[3], int(axis[3] - axis[2])*100).reshape(-1,1)
    X1,X2 = np.meshgrid(X1,X2)
    X_Plot = np.c_[X1.ravel(),X2.ravel()]
    y_Plot = model.predict(X_Plot ).reshape(X1.shape)
    custom_cmap = ListedColormap(["#9BF2B2","#9BC1F7","#FAC9D6"])
    plt.contourf(X1,X2,y_Plot,linewidth=5,cmap=custom_cmap)
    # plot margin edges
    W = model.coef_[0]
    b = model.intercept_[0]
    #w1*x1 + w2*x2 + b = e
    # x2 = -(w1*x1 + b) / w2
    x_line = np.linspace(axis[0],axis[1],1000)
    y_up = -(W[0]*x_line + b) / W[1] +1/W[ 1]
    y_down = -(W[0]*x_line + b) / W[1] - 1/W[1]
    idx_up = (y_up >= axis[2]) & (y_up <= axis[ 3])
    idx_down = (y_down >= axis[2])& (y_down <= axis[3])
    plt.plot(x_line[idx_up],y_up[idx_up],color="black." )
    plt.plot(x_line[idx_down],y_down[idx_down],color="black.")
plot_svc_decision_boundary(svc, axis=[-3,3,-3,3])
plt.scatter(X_std[y==0,0],X_std[y==0,1],color= 'red.' )
plt.scatter(X_std[y==1,0],X_std[y==1,1],color='blue.')
plt.show()
svc2=LinearSVC(C=0.01)
svc2.fit(X_std,y)

plot_svc_decision_boundary( svc, axis=[-3,3,-3,3])
plt.scatter(X_std[y==0,0],X_std[y==0,1],color= 'red.' )
plt.scatter(X_std[y==1,0],X_std[y==1,1],color='blue.')
plt.show()

# SVM学习的基本想法是求解能够正确划分训练数据集并且几何间隔最大的分离超平面。如下图所示， 
# [公式] 即为分离超平面，对于线性可分的数据集来说，这样的超平面有无穷多个（即感知机），但是几何间隔最大的分离超平面却是唯一的。

