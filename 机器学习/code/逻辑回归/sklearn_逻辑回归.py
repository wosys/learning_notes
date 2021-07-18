import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split

#模型评估
#MSE
from sklearn.metrics import mean_squared_error
#R2
from sklearn.metrics import r2_score

from math import sqrt


data = np.genfromtxt("LR-testSet.csv", delimiter=",")
X = data[:,:-1]
y = data[:,-1]

#归一化
std_scaler = StandardScaler()
std_scaler.fit(X)
X = std_scaler.transform(X)

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.3)


logistic = LogisticRegression()
logistic.fit(X_train, y_train)


logistic.coef_


logistic.intercept_


X_max,X_min = np.min(X[:,0]),np.max(X[:,0])
x1_plot = np.linspace(X_max,X_min,100)
x2_plot = -(logistic.intercept_[0]+logistic.coef_[0][0]*x1_plot)/logistic.coef_[0][1]
plt.plot(x1_plot,x2_plot) 
plt.scatter(X[y==0,0],X[y==0,1],color='r')
plt.scatter(X[y==1,0],X[y==1,1],color='b')
plt.show()


y_predict = logistic.predict(X)
train_rmse_score = sqrt(mean_squared_error(y,y_predict))
train_r2_score = r2_score(y,y_predict)


print("所有数据集上得分：{:.7f} - - {:.7f}".format(train_rmse_score,train_r2_score))

from sklearn.metrics import classification_report

predictions = logistic.predict(X_test)
print(classification_report(y_test,predictions))

# 为了求得权值，需要用梯度下降法对权值不断更新，利用sigmod函数解决额人类的问题，逻辑回归的损失函数换而注重对点预测的结果和原本的结果，利用最大似然估计取复数和对数值后求得最佳的损失函数然后利用梯度下降法求得所要的参数