1.KNN、线性回归、逻辑回归要自己会写

2.sklearn官网
scikit-learn

3.sklearn中文文档
https://sklearn.apachecn.org/

4.make_classification 中参数
n_samples=100, 样本数
n_features=20, 特征个数= n_informative（） + n_redundant + n_repeated
n_informative=2, 多信息特征的个数
n_redundant=2, 冗余信息，informative特征的随机线性组合
n_repeated=0,  重复信息，随机提取n_informative和n_redundant 特征
n_classes=2,分类类别
n_clusters_per_class=2,某一个类别是由几个cluster构成的
weights=None, 列表类型，权重比
flip_y=0.01,
class_sep=1.0,乘以超立方体大小的因子。 较大的值分散了簇/类，并使分类任务更容易。默认为1
hypercube=True,shift=0.0, scale=1.0,
shuffle=True,
random_state=None  如果是int，random_state是随机数发生器使用的种子;
如果RandomState实例，random_state是随机数生成器; 如果没有，则随机数生成器是np.random使用的RandomState实例。





