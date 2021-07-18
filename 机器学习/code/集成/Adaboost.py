import numpy as np
from sklearn import datasets
from sklearn.model_selection import train_test_split


iris = datasets.load_iris()
X = iris.data
y = iris.target

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.3)


#决策树
from sklearn.tree import DecisionTreeClassifier


dtree = DecisionTreeClassifier(max_depth=3)
dtree.fit(X_train,y_train)
dtree.score(X_test,y_test)


#Adaboost
from sklearn.ensemble import AdaBoostClassifier


model = AdaBoostClassifier(DecisionTreeClassifier(max_depth=3),n_estimators=10)
model.fit(X_train,y_train)
model.score(X_test,y_test)

# 每次迭代只训练一个弱分类器，训练好的弱分类器将参与下一次迭代的使用。也就是说，在第N次迭代中，一共就有N个弱分类器，其中N-1个是以前训练好的，其各种参数都不再改变，本次训练第N个分类器。其中弱分类器的关系是第N个弱分类器更可能分对前N-1个弱分类器没分对的数据，最终分类输出要看这N个分类器的综合效果

# AdaBoost:自适应增强
# 自适应在于：前一个基本分类器被错误分类的样本的权值会增大，而正确分类的样本权值会减小，并再次用来训练下一个基本分类器。同时，在每一轮迭代中，加入一个新的弱分类器，直到达到某个预定的足够小的错误率或达到预先指定的最大迭代次数才确定最终的强分类器
