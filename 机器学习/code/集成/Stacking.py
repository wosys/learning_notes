import numpy as np

from sklearn.model_selection import train_test_split
from sklearn import datasets

from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import StackingClassifier


iris = datasets.load_iris()
X = iris.data
y = iris.target


X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.3)

#定义三个不同的分类器
# clf1 = KNeighborsClassifier(n_neighbors=5)
# clf2 = DecisionTreeClassifier()
# clf3 = LogisticRegression()
estimators = [('dtree', DecisionTreeClassifier()),
              ('logistic', LogisticRegression()),
              ('knn', KNeighborsClassifier(n_neighbors=20,
                                          metric='euclidean'))]


#定义一个次级分类器
lr = LogisticRegression()


sclf = StackingClassifier(estimators=estimators,final_estimator=lr)

sclf.fit(X_train, y_train).score(X_test, y_test)

# 使用多个不同地分类器对训练集进行预测，把预测得到地结果作为一个次级分类器地输入。次机分类器地输出是整个模型地预测结果
