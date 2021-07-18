# 普通最小二乘法
from sklearn import linear_model
reg = linear_model.LinearRegression()
reg.fit([[0,0],[1,1],[2,2]],[0,1,2])

print(reg.coef_)


import matplotlib.pyplot as plt
import numpy as np
from sklearn import datasets,linear_model
from sklearn.metrics import mean_squared_error,r2_score

# 加载数据集
diabetes_X, diabetes_y = datasets.load_diabetes(return_X_y=True)
diabetes_X = diabetes_X[:,np.newaxis,2]
# Split the data into training/testing sets
diabetes_X_train = diabetes_X[:-20]
diabetes_X_test = diabetes_X[-20:]
# Split the targets into training/testing sets
diabetes_y_train = diabetes_y[:-20]
diabetes_y_test = diabetes_y[-20:]

# 模板
regr = linear_model.LinearRegression()
# Train the model using the training sets
regr.fit(diabetes_X_train, diabetes_y_train)
# Make predictions using the testing set
diabetes_y_pred = regr.predict(diabetes_X_test)

# The coefficients
print('Coefficients(系数): \n', regr.coef_)

# The mean squared error
print('Mean squared error: %.2f'
      % mean_squared_error(diabetes_y_test, diabetes_y_pred))
# The coefficient of determination: 1 is perfect prediction
print('Coefficient of determination: %.2f'
      % r2_score(diabetes_y_test, diabetes_y_pred))

# Plot outputs
plt.scatter(diabetes_X_test, diabetes_y_test,  color='black')
plt.plot(diabetes_X_test, diabetes_y_pred, color='blue', linewidth=3)
plt.xticks(())
plt.yticks(())
plt.show()



# 一元线性回归
# import numpy as np
# import matplotlib.pyplot as plt

# def h(theta,X):
#     return np.dot(X,theta)

# def dJ(theta,X,y):
#     gd = np.dot(X.T,h(theta,X)-y)
#     return gd/len(y)


# def GD(X,y,lr = 0.0001,maxInteration = 50):
#     theta = np.zeros((2,1))
#     for i in range(maxInteration):
#         gd = dJ(theta,X,y)       
#         theta = theta - lr*gd
#     return theta

# data = np.genfromtxt("ML\复习\线性回归\data.csv",delimiter=',')
# X = data[:,0].reshape(-1,1)
# y = data[:,1].reshape(-1,1)


# m = len(X)
# n = X.shape[1]
# XX = np.hstack((np.ones((m,1)),X))

# lr = 0.0001
# maxInteration = 50
# theta = GD(XX,y,lr,maxInteration)

# plt.plot(X, y, 'b.')
# plt.plot(X, theta[0]+theta[1]*X, 'r')
# plt.show()

# 多元线性回归
# import numpy as np
# import matplotlib.pyplot as plt
# from sklearn import datasets
# from sklearn.model_selection import train_test_split

# def h(theta,X):
#     return np.dot(X,theta)

# def dJ(theta,X,y):
#     gd = np.dot(X.T,h(theta,X)-y)
#     return gd/len(y)

# def GD(X,y,lr = 0.0001,maxInteration = 50):
#     theta = np.zeros((14,1))
#     for i in range(maxInteration):
#         gd = dJ(theta,X,y)
#         theta = theta - lr*gd 
#     return theta

# boston = datasets.load_boston()

# X = boston.data
# y = boston.target

# m = len(X)
# n = X.shape[1]
# XX = np.hstack((np.ones((m,1)),X))

# X_train,X_test,y_train,y_test = train_test_split(XX,y,test_size=0.3)


# lr = 0.0001
# maxInteration = 50
# theta_1 = GD(X_train,y_train.reshape(-1,1),lr,maxInteration)
# print(theta_1)

# #MSE 平均绝对误差
# from sklearn.metrics import mean_absolute_error
# print(mean_absolute_error(y_test,h(theta_1,X_test)))


# 3.调库
import numpy as np
from sklearn import datasets
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

data = datasets.load_boston()
X = data.data
y=data.target.reshape(-1,1)

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.3)

model = LinearRegression()
model.fit(X_train,y_train)

y_pred = model.predict(X_test)

# 评价指标
from math import sqrt
from sklearn.metrics import mean_absolute_error
from sklearn.metrics import mean_squared_error
from sklearn.metrics import r2_score

print("MAE:",mean_absolute_error(y_test,y_pred))
print("MSE:",mean_squared_error(y_test,y_pred))
print("RMSE:",sqrt(mean_squared_error(y_test,y_pred)))
print("R2:",r2_score(y_test,y_pred))

