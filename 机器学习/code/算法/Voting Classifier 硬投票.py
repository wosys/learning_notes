#硬投票
from sklearn import datasets
from sklearn.model_selection import cross_val_score
from sklearn.linear_model import LogisticRegression
from sklearn.naive_bayes import GaussianNB
from sklearn.ensemble import RandomForestClassifier
from sklearn.ensemble import VotingClassifier

iris=datasets.load_iris()
#剪裁特征向量
X,y=iris.data[:,1:3],iris.target
clf1=LogisticRegression(solver='lbfgs',multi_class='multinomial',random_state=1)
clf2=RandomForestClassifier(n_estimators=50,random_state=1)
clf3=GaussianNB()

#硬投票
# estimators 分类器列表
# voting 投票方式
eclf=VotingClassifier(estimators=[('lr',clf1),('rf',clf2),('gnb',clf3)],voting='hard')

for clf,label in zip([clf1,clf2,clf3,eclf],['Logistic Regression','Random Forest'
 'naive bayes','Ensemble']):
    scores=cross_val_score(clf,X,y,cv=5,scoring='accuracy')
    print("准确性：%0.2f(+/-%0.2f)[%s]"%(scores.mean(),scores.std(),label))
