from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier

iris =datasets.load_iris()
X_data=iris.data
y_target=iris.target
X_train,X_test,y_tarin,y_test=train_test_split(X_data,y_target,test_size=0.3,random_state=12)
knn=KNeighborsClassifier(n_neighbors=4)
knn.fit(X_train,y_tarin)

#评估模型
accuracy=knn.score(X_test,y_test)

#输出准确率
print("准确率为{:.2f}".format(accuracy*100))