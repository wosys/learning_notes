from sklearn.ensemble import  GradientBoostingClassifier
from sklearn.datasets import make_hastie_10_2

X,y=make_hastie_10_2(random_state=2)
X_train,X_test=X[:2000],X[2000:]
y_train,y_test=y[:2000],y[2000:]

clf=GradientBoostingClassifier()
clf.fit(X_train,y_train)

print(clf.score(X_test,y_test))
