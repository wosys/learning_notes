import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import mean_squared_error,r2_score
from math import sqrt

data = np.genfromtxt("LR_test.csv", delimiter=",")
X = data[:,:-1]
y = data[:,-1]


#归一化
std_scaler=StandardScaler()
std_scaler.fit(X)
X=std_scaler.transform(X)

logistic=LogisticRegression()
logistic.fit(X,y)

X_max,X_min=np.min(X[:,0]),np.max(X[:,0])
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