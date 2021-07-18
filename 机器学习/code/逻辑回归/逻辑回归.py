# 1.手写逻辑回归
# import numpy as np
# import matplotlib.pyplot as plt
# from sklearn.preprocessing import StandardScaler

# def Sigimod(z):
#     return 1/(1+np.exp(-z))

# def h(theta,X):
#     return Sigimod(np.dot(X,theta))

# def dJ(X,y,theta):
#     gd = np.dot(X.T,h(theta,X)-y)
#     return gd / len(X)

# def GD(X,y,n,lr=0.0001,maxInteration = 100):
#     theta = np.zeros((n,1))
#     for i in range(maxInteration):
#         gd = dJ(X,y,theta)
#         theta = theta - lr*gd
#     return theta

# data = np.genfromtxt("ML\复习\逻辑回归\LogisticRegression_Data1.txt",delimiter=",")
# X = data[:,:-1]
# y = data[:,-1].reshape(-1,1)
# #归一化，不然很难收敛十分重要
# std_scaler = StandardScaler()
# std_scaler.fit(X)
# X = std_scaler.transform(X)
# m = len(X)
# XX = np.hstack((np.ones((m,1)),X))

# lr = 0.001
# n = XX.shape[1]
# maxInteration = 100
# optTheta = GD(XX,y.reshape(-1,1),n,lr,maxInteration)

# #绘制决策边界
# X_max,X_min = np.min(X[:,0]),np.max(X[:,0])
# x1_plot = np.linspace(X_max,X_min,100)
# x2_plot = -(optTheta[0]+optTheta[1]*x1_plot)/optTheta[2]
# plt.plot(x1_plot,x2_plot) 
# plt.scatter(X[y[:,-1]==0,0],X[y[:,-1]==0,1],color="r")
# plt.scatter(X[y[:,-1]==1,0],X[y[:,-1]==1,1],color="b",marker="x")
# plt.show()

# 2.库实现
# import numpy as np
# import matplotlib.pyplot as plt
# from sklearn.linear_model import LogisticRegression
# from sklearn.preprocessing import StandardScaler

# #模型评估
# #MSE
# from sklearn.metrics import mean_squared_error
# #R2
# from sklearn.metrics import r2_score
# from math import sqrt

# data = np.genfromtxt("ML\复习\逻辑回归\LR-testSet.csv", delimiter=",")
# X = data[:,:-1]
# y = data[:,-1]
# #归一化
# std_scaler = StandardScaler()
# std_scaler.fit(X)
# X = std_scaler.transform(X)

# logistic = LogisticRegression()
# logistic.fit(X, y)

# X_max,X_min = np.min(X[:,0]),np.max(X[:,0])
# x1_plot = np.linspace(X_max,X_min,100)
# x2_plot = -(logistic.intercept_[0]+logistic.coef_[0][0]*x1_plot)/logistic.coef_[0][1]
# plt.plot(x1_plot,x2_plot) 
# plt.scatter(X[y==0,0],X[y==0,1],color='r')
# plt.scatter(X[y==1,0],X[y==1,1],color='b')
# plt.show()

# y_predict = logistic.predict(X)
# train_rmse_score = sqrt(mean_squared_error(y,y_predict))
# train_r2_score = r2_score(y,y_predict)
# print("所有数据集上得分：{:.7f} - - {:.7f}".format(train_rmse_score,train_r2_score))