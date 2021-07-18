from sklearn import datasets
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score,r2_score
#r2_score适用于回归问题，accuracy_score适用于分类问题，r2_score的输入可以是浮点数，而accuracy_score必须是整型

iris=datasets.load_iris()
x,y=iris.data,iris.target
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.3,random_state=12)

ss=preprocessing.StandardScaler()
x_train=ss.fit_transform(x_train)
x_test=ss.transform(x_test)

clf=SVC(kernel='rbf',C=1.0)  #C大惩罚大，C小惩罚小   kernel核函数类型，默认rbf
clf.fit(x_train,y_train)

y_pred=clf.predict(x_test)
score=accuracy_score(y_pred,y_test)
score_r2=r2_score(y_pred,y_test)
print(score)
print(score_r2)




