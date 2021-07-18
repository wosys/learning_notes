# 集成学习(ensemble learning)
from sklearn.ensemble import RandomForestClassifier  #随机森林分类器
from sklearn.ensemble import RandomForestRegressor  #随机森林回归器
from sklearn.ensemble import AdaBoostClassifier   # AdaBoost分类器
from sklearn.ensemble import GradientBoostingClassifier # GBDT 梯度提升树分类器

# 分类(Classification)
from sklearn.linear_model import SGDClassifier #SGD分类器
from sklearn import svm #SVM分类器
from sklearn.tree import DecisionTreeClassifier #决策树分类
from sklearn.naive_bayes import GaussianNB #朴素贝叶斯（高斯分布型）
from sklearn.naive_bayes import BernoulliNB # 朴素贝叶斯（伯努利型）
from sklearn.neighbors import KNeighborsClassifier #KNN分类器

# 聚类(Clustering) 
from sklearn.neighbors import KNeighborsRegressor #KNN回归
from sklearn.tree import DecisionTreeRegressor #决策树回归
from sklearn.svm import LinearSVR #SVM回归
from sklearn.linear_model import LinearRegression #线性回归

# 降维(Dimensionality Reduction)
from sklearn.decomposition import PCA #PCA降维
from sklearn.manifold import LocallyLinearEmbedding #LLE降维
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis #LDA降维

# 数据集
from sklearn.datasets import load_iris #鸢尾花数据集
from sklearn.datasets import load_boston #波士顿房价数据集
from sklearn.datasets import load_digits #手写数字数据集
from sklearn.datasets import load_wine #葡萄酒数据集
from sklearn.datasets import load_barest_cancer #乳腺癌数据集
from sklearn.datasets import load_diabetes #糖尿病数据集

# 模型选择(Model Selection)
from sklearn.model_selection import train_test_split #数据集划分
from sklearn.model_selection import cross_validate #交叉验证
from sklearn.model_selection import KFold # K折交叉验证

# 预处理 (Preprocessing)
from sklearn.preprocessing import OneHotEncoder #one-hot编码
from sklearn.preprocessing import LabelEncoder #标签编码
from sklearn.preprocessing import MinMaxScaler #归一化
from sklearn.preprocessing import StandardScaler #标准化
from sklearn.preprocessing import normalize #正则化  （norm=L1/L2）


