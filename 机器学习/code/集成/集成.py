# 集成学习的方法：Boosting（Gradient Tree Boosting、AdaBoost），Voting（Voting Regression，Voting Classifier）
# Bagging，Stacking（Stacking Regression，Stacking Classifier）

# 通常我们将训练数据进行交叉验证，比如说10则交叉验证，我们将训练数据平均分为10份，循环用其中的9份数据来训练模型，用另一份数据验证准确率，最后将结果准确率平均就是最后的分类准确率。当然还有其他方法。
# 但是寻找一个可以有很高准确率的算法是很难的。
# 它最初的思想很简单：使用一些（不同的）方法改变原始训练样本的分布，从而构建多个不同的分类器，并将这些分类器线性组合得到一个更强大的分类器，来做最后的决策。也就是常说的“三个臭皮匠顶个诸葛亮”的想法。

# 集成学习的理论基础来自于Kearns和Valiant提出的基于PAC（probably approximately correct）的可学习性理论 ，PAC 定义了学习算法的强弱：

# 弱学习算法：识别错误率小于1/2(即准确率仅比随机猜测略高的算法)
# 强学习算法：识别准确率很高并能在多项式时间内完成的算法

# 集成学习是指通过训练多个分类器，然后将这些分类器组合起来，来获得比单个分类器更优的性能（比最好的那个分类器还要好）。如果每个分类器都是同种类型的（比如都是决策树或者都是SVM等等），那么这些单个的分类器我们称为基学习器；
# 如果集成中包含不同类型的分类器，这样的集成是异质的。需要注意的是，这些单个的分类器性能不一定要很好，只需要比随机猜测好就可以。在我们一般的经验中，如果把好的东西与坏的东西掺杂在一起，那么结果通常是比最坏的要好但比最好的要差一些。

# 随机森林
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
print(RF.score(X_test,y_test))

from sklearn.ensemble import RandomForestRegressor
RR = RandomForestRegressor(n_estimators=100)
RR.fit(X_train,y_train)
print(RR.score(X_test,y_test))

# 决策树
from sklearn.tree import DecisionTreeClassifier
dtree=DecisionTreeClassifier()
dtree.fit(X_train,y_train)
print(dtree.score(X_test,y_test))

#Adaboost
from sklearn.ensemble import AdaBoostClassifier
model = AdaBoostClassifier(DecisionTreeClassifier(max_depth=3),n_estimators=10)
model.fit(X_train,y_train)
print(model.score(X_test,y_test))



from sklearn import datasets
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
import numpy as np
iris = datasets.load_iris()
#故意选择两个特征降低准确率来比较
X = iris.data[:,:2]
y = iris.target

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.3)

from sklearn.neighbors import KNeighborsClassifier

#KNN
knn = KNeighborsClassifier()
knn.fit(X_train,y_train)

def plot(model):
    X_min,X_max = X[:,0].min()-1,X[:,0].max()+1
    y_min,y_max = X[:,1].min()-1,X[:,0].max()+1

        # 生成网格矩阵
    xx, yy = np.meshgrid(np.arange(X_min, X_max, 0.02),
                         np.arange(y_min, y_max, 0.02))

    z = model.predict(np.c_[xx.ravel(), yy.ravel()])# ravel与flatten类似，多维数据转一维。flatten不会改变原始数据，ravel会改变原始数据
    z = z.reshape(xx.shape)
    # 等高线图
    cs = plt.contourf(xx, yy, z)

plot(knn)

plt.scatter(X[:,0],X[:,1],c=y)
knn.score(X_test,y_test)

#决策树
from sklearn.tree import DecisionTreeClassifier

dtree = DecisionTreeClassifier()
dtree.fit(X_train,y_train)

plot(dtree)
plt.scatter(X[:,0],X[:,1],c = y)
plt.show()

dtree.score(X_test,y_test)


#集成学习
from sklearn.ensemble import BaggingClassifier

#传入模型，前面定义好的模型knn，n_estimators是定义多少次有放回的抽样
bagging_knn = BaggingClassifier(knn,n_estimators=100)

bagging_knn.fit(X_train,y_train)
plot(bagging_knn)
plt.scatter(X[:,0],X[:,1],c = y)
plt.show()
bagging_knn.score(X_test,y_test)

#传入模型，前面定义好的模型knn，n_estimators是定义多少次有放回的抽样
bagging_tree = BaggingClassifier(dtree,n_estimators=100)

bagging_tree.fit(X_train,y_train)
plot(bagging_tree)
plt.scatter(X[:,0],X[:,1],c = y)
plt.show()
bagging_tree.score(X_test,y_test)