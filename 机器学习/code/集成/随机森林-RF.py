import numpy as np
from sklearn import datasets
from sklearn.model_selection import train_test_split


iris = datasets.load_iris()
X = iris.data
y = iris.target

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.3)


#随机生成树
from sklearn.ensemble import RandomForestClassifier


RF = RandomForestClassifier(n_estimators=50)
RF.fit(X_train,y_train)

RF.score(X_test,y_test)


#决策树
from sklearn.tree import DecisionTreeClassifier


dtree = DecisionTreeClassifier()
dtree.fit(X_train,y_train)
dtree.score(X_test,y_test)


# 随机森林（Random Forest）
# RF = 决策树 + Bagging + 随机属性选择
# 1.样本随机：bagging
# 2.特征随机：从所有属性d中随机选择k个属性（k《d),然后从k个属性中选择最佳分割属性作为节点建立CART决策树
# 3.重复以上两个步骤m次，建立m棵CART决策树
# 4.这m棵CART决策树形成随机森林，通过投票表决结果，决定数据属于哪一类