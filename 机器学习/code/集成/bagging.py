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

# 在原始训练集的随机子集上建立一个黑箱估计的多个实例，然后将它们各自的预测聚合起来形成最终的预测。这些方法通过在基本估计量（如决策树）的构造过程中引入随机化，然后对其进行集成，来降低其方差。在许多情况下，bagging方法是相对于单个模型进行改进的一种非常简单的方法，而无需调整底层的基本算法。
# bagging,是在原始数据集选择S次后得到S个新数据集的一种技术。是一种又放回的抽样


