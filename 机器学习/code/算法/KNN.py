import numpy as np
from sklearn.model_selection import train_test_split
from sklearn import datasets
from scipy.spatial.distance import euclidean
def KNN(data_train,testFeature,K):
    distance =[]
    preLabels=list()

    # 计算距离
    for row in data_train:
        distance.append(euclidean(row[:4],testFeature))
    # distance = [euclidean(row[4],testFeature) for row in data_train]
    #筛选距离
    maxdistance=max(distance)

    while K>0:
        pos=np.argmin(distance)
        preLabels.append(data_train[pos][4])
        distance[pos]+=maxdistance
        K=K-1

    return max(preLabels,key=preLabels.count)

iris=datasets.load_iris()

#合并数据集
iris_data,iris_target=iris.data,iris.target
data=np.column_stack((iris_data,iris_target))
data_train,data_test=train_test_split(data,test_size=0.3,random_state=12)

a=0
K=4

for row in data_test:
    testFeature=row[:4]
    preLabel=KNN(data_train,testFeature,K)
    if(preLabel==row[4]):
        a=a+1

    print("预测值：{}，真实值：{}".format(preLabel,row[4]))

print("准确率：{:.2f}%".format(a/data_test.shape[0]*100))


