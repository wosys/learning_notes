
from sklearn import datasets
from sklearn.ensemble import StackingClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.ensemble import GradientBoostingClassifier
# from sklearn.preprocessing import StandardScaler

iris=datasets.load_iris()

X_train,X_test,y_train,y_test=train_test_split(iris.data,iris.target,test_size=0.3)

estimators = [
    ('knn', KNeighborsClassifier()),
    ('Ann', MLPClassifier(max_iter=1000)),  #最大迭代次数
    ('RM', RandomForestClassifier())
]

final_estimator = GradientBoostingClassifier()

clf = StackingClassifier(estimators=estimators,final_estimator=final_estimator)

clf.fit(X_train, y_train)

print(clf.score(X_test, y_test))





