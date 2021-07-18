
from sklearn import datasets
from sklearn.linear_model import RidgeCV,LassoCV
from sklearn.neighbors import KNeighborsRegressor
from sklearn.ensemble import StackingRegressor
from sklearn.ensemble import GradientBoostingRegressor
from sklearn.model_selection import train_test_split

estimators=[
    ('ridge',RidgeCV()),
    ('lasso',LassoCV()),
    ('knn',KNeighborsRegressor())
]

final_estimator=GradientBoostingRegressor()

#读取数据
iris=datasets.load_iris()

#分割数据
X_train,X_test,y_train,y_test=train_test_split(iris.data,iris.target,test_size=0.3)

#模型选择
reg=StackingRegressor(estimators=estimators,final_estimator=final_estimator)

reg.fit(X_test,y_test)
# reg.fit(X_train,y_train)

print(reg.score(X_test,y_test))


