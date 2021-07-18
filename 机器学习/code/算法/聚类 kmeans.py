import numpy as np
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.cluster import KMeans


data = np.genfromtxt("kmeans.txt",delimiter=' ')
#设置k
k = 4

#训练模型
model = KMeans(n_clusters=k)
model.fit(data)


#分类中心点坐标
centers = model.cluster_centers_
print(centers)

#预测结果
result  = model.predict(data)
print(result)


model.labels_


import matplotlib.pyplot as plt
# 画出各个数据点，用不同颜色表示分类
mark = ['or', 'ob', 'og', 'oy']
for i,d in enumerate(data):
    plt.plot(d[0], d[1], mark[result[i]])

# 画出各个分类的中心点
mark = ['*r', '*b', '*g', '*y']
for i,center in enumerate(centers):
    plt.plot(center[0],center[1], mark[i], markersize=20)
    
plt.show()


# 获取数据值所在的范围
x_min, x_max = data[:, 0].min() - 1, data[:, 0].max() + 1
y_min, y_max = data[:, 1].min() - 1, data[:, 1].max() + 1

# 生成网格矩阵
xx, yy = np.meshgrid(np.arange(x_min, x_max, 0.02),
                     np.arange(y_min, y_max, 0.02))

z = model.predict(np.c_[xx.ravel(), yy.ravel()])# ravel与flatten类似，多维数据转一维。flatten不会改变原始数据，ravel会改变原始数据
z = z.reshape(xx.shape)
# 等高线图
cs = plt.contourf(xx, yy, z)
# 显示结果
# 画出各个数据点，用不同颜色表示分类
mark = ['or', 'ob', 'og', 'oy']
for i,d in enumerate(data):
    plt.plot(d[0], d[1], mark[result[i]])

# 画出各个分类的中心点
mark = ['*r', '*b', '*g', '*y']
for i,center in enumerate(centers):
    plt.plot(center[0],center[1], mark[i], markersize=20)
    
plt.show()


# 聚类（Clustering）是一种无监督学习(unsupervised learning)，简单地说就是把相似的对象归到同一簇中。簇内的对象越相似，聚类的效果越好。

# 定义：给定一个有个对象的数据集，聚类将数据划分为个簇，而且这个划分满足两个条件：(1)每个簇至少包含一个对象；(2)每个对象属于且仅属于一个簇。

# 基本思想：对给定的，算法首先给出一个初始的划分方法，以后通过反复迭代的方法改变划分，使得每一次改进之后的划分方案都较前一次更好。
# 聚类分析（cluster analysis）试图将相似对象归入同一簇，将不相似对象归到不同簇。