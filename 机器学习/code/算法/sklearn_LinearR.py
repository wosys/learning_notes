from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score

iris=load_iris()
x,y=iris.data,iris.target

x_train,x_test,y_train,y_test=train_test_split(x,y,train_size=0.3,random_state=12)

lr=LinearRegression()

lr.fit(x_train,y_train)

y_pred=lr.predict(x_test)

score=r2_score(y_test,y_pred)
print("%.2f"%score)