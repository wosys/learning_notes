# 估计器和预处理器
from sklearn.ensemble import RandomForestClassifier

clf  = RandomForestClassifier(random_state=0)
X = [[1,2,3],
    [11,12,13]] # 3个特征，2个样本
y = [0,1] # 样本的分类
clf.fit(X,y) #一旦估计器被拟合，它就可以用于预测新数据的目标值。您不需要重新训练估算器：

print(clf.predict(X))
print(clf.predict([[4,5,6],[14,15,16]])) # 用新的数据预测分类

from sklearn.preprocessing import StandardScaler

X = [[0,15],
     [1,-10]]
StandardScaler().fit(X).transform(X)

# 管道：链接预处理器和估计器
from sklearn.datasets import load_iris
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split

from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import make_pipeline
from sklearn.metrics import accuracy_score

    # 创建一个管道对象
pipe = make_pipeline(
    StandardScaler(),LogisticRegression()
)

    # 加载数据集，并拆分
X,y=load_iris(return_X_y=True)
X_train,X_test,y_train,y_test = train_test_split(X,y,random_state=0)

    # 拟合
pipe.fit(X_train,y_train)

    # 评分
accuracy_score(pipe.predict(X_test),y_test)

# 模型评估
from sklearn.datasets import make_regression
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import cross_validate

X,y = make_regression(n_samples=1000,random_state=0)
Ir = LinearRegression()

result=cross_validate(Ir,X,y)
print(result['test_score'])