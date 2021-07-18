from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.tree import DecisionTreeClassifier

iris=datasets.load_iris()
X = iris.data
y = iris.target

X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.3)

#随机生成树
RF=RandomForestClassifier(n_estimators=50)
RF.fit(X_train,y_train)
RF.score(X_test,y_test)

#决策树
dtree=DecisionTreeClassifier()
dtree.fit(X_train,y_train)
dtree.score(X_test,y_test)