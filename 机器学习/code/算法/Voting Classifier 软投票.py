#软投票
from sklearn import datasets
from sklearn.tree import DecisionTreeClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.ensemble import VotingClassifier
from sklearn.model_selection import cross_val_score
# from itertools import product

#加载数据
iris=datasets.load_iris()
X=iris.data
y=iris.target

#测试
clf1=DecisionTreeClassifier(max_depth=4)
clf2=KNeighborsClassifier(n_neighbors=7)
clf3=SVC(gamma='scale',kernel='rbf',probability=True)

#软投票和硬投票的区别
eclf=VotingClassifier(estimators=[('dt',clf1),('knn',clf2),('svc',clf3)],voting='soft',weights=[2,1,2])

for clf,label in zip([clf1,clf2,clf3,eclf],['dt','knn','svc', 'Ensemble']):
    scores=cross_val_score(clf,X,y,cv=5,scoring='accuracy')
    print("准确性：%0.2f(+/-%0.2f)[%s]"%(scores.mean(),scores.std(),label))




