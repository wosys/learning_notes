from sklearn import datasets
from sklearn.svm import SVR
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score
from sklearn import preprocessing
import numpy as np

# 载入数据
boston=datasets.load_boston()
x,y=boston.data,boston.target


x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.3,random_state=12)

# 将y变成SVM支持的一维数据
y_train=np.array(y_train).reshape(-1,1)
# print(y_train)
y_test=np.array(y_test).reshape(-1,1)
# print(y_test)

# 数据预处理，进行归一化
x_train=preprocessing.StandardScaler().fit_transform(x_train)
x_test=preprocessing.StandardScaler().fit_transform(x_test)
y_train=preprocessing.StandardScaler().fit_transform(y_train).ravel()
y_test=preprocessing.StandardScaler().fit_transform(y_test).ravel()


# 声明模型
svr=SVR()

# 训练模型
svr.fit(x_train,y_train)

# 预测
y_pred=svr.predict(x_test)

# 评估
score=r2_score(y_test,y_pred)
print(score)