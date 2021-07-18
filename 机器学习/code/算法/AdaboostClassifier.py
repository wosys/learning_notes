from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import AdaBoostClassifier

iris=datasets.load_iris()
X=iris.data
y=iris.target

X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.3)

#决策树
dtree=DecisionTreeClassifier(max_depth=3)
dtree.fit(X_train,y_train)
dtree.score(X_test,y_test)
print(dtree.score(X_test,y_test))

#Adaboost
model=AdaBoostClassifier(DecisionTreeClassifier(max_depth=3),n_estimators=10)
model.fit(X_train,y_train)
model.score(X_test,y_test)
print(model.score(X_test,y_test))