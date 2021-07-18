import numpy as np
from sklearn.model_selection import train_test_split
from sklearn import datasets
from scipy.spatial.distance import euclidean #*


def KNN(data_train,testFeature,K):
    distance = []
    preLabels = list()

    # 计算距离
    for row in data_train:
        distance.append(euclidean(row[:4],testFeature))

    # distance = [euclidean(row[4],testFeature) for row in data_train]

    #筛选距离
    maxdistance = max(distance)
    while K>0:
        pos = np.argmin(distance)
        preLabels.append(data_train[pos][4]) #*
        distance[pos] += maxdistance 
        K = K - 1
    
    return max(preLabels,key = preLabels.count)


iris = datasets.load_iris()

#合并数据集
iris_data = iris.data
iris_target = iris.target

data = np.column_stack((iris_data,iris_target))

data_train,data_test = train_test_split(data,test_size=0.3,random_state=4)


a = 0
K = 4
for row in data_test:
    testFeature = row[:4]
    preLabel = KNN(data_train,testFeature,K)

    if(preLabel == row[4]):
        a = a + 1
    print("预测值：{}，真实值：{}".format(preLabel,row[4]))

print("准确率：{:.2f}%".format(a/data_test.shape[0]*100))

# 算法概述：
# kNN算法的核心思想是如果一个样本在特征空间中的k个最相邻的样本中的大多数属于某一个类别，则该样本也属于这个类别，并具有这个类别上样本的特性。该方法在确定分类决策上只依据最邻近的一个或者几个样本的类别来决定待分样本所属的类别。

# 步骤：
# 1）计算测试数据与各个训练数据之间的距离；

# 2）按照距离的递增关系进行排序；

# 3）选取距离最小的K个点；

# 4）确定前K个点所在类别的出现频率；

# 5）返回前K个点中出现频率最高的类别作为测试数据的预测分类。