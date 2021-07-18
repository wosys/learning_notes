#PCA即主成分分析，通过在原始样本变量中选取一些变量来代表样本的大部分信息。
#这些选中的变量即为主成分。我们可以调用sklearn中的PCA函数来进行数据主成分分析。
# PCA主要是用来数据降维，将高纬度的特征映射到低维度的特征，加快机器学习的速度。
# from sklearn.datasets._samples_generator import
# from sklearn.decomposition import PCA
# n_components对应要降的维度
# pca=PCA(n_components=4)
# pca_result=pca_fit_transform(df[feat_cols].values)


from sklearn import datasets
from sklearn.decomposition import PCA
# from mpl_toolkits.mplot3d import Axes3D
# import matplotlib.pyplot as plt
# import numpy as np
# import pandas as pd
# from sklearn.discriminant_analysis import LinearDiscriminantAnalysis

iris = datasets.load_iris()
iris_X = iris.data   ##获得数据集中的输入
iris_y = iris.target ##获得数据集中的输出，即标签(也就是类别)
print(iris_X.shape)
print(iris.feature_names)
print(iris.target_names)
##加载PCA模型并训练、降维
model_pca = PCA(n_components=3)
X_pca = model_pca.fit(iris_X).transform(iris_X)
print(iris_X.shape)
print(iris_X[0:5])
print(X_pca.shape)
print(X_pca[0:5])
