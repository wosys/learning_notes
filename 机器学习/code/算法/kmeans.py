import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
# from sklearn.datasets._samples_generator import make_blobs
from sklearn.datasets import make_blobs

# Generate some data
X,y=make_blobs(n_samples=400,centers=4,cluster_std=0.60,random_state=0)
# n_samples表示样本的个数  centers是聚类中心点的个数
# cluster_std设置每个类别的方差  random_state是随机种子，可以固定生成的数据

# kmeans clustering
kmeans =KMeans(4,random_state=0)
kmeans.fit(X)  # 训练模型
labels =kmeans.predict(X)   # 预测分类
plt.scatter(X[:,0],X[:,1],c=labels,s=40,cmap='viridis')
plt.show()