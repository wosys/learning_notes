from sklearn import datasets
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
import numpy as np
import matplotlib.pyplot as plt

def objectiveFunction(theta, X, y):
    # 计算成本函数，等于各损失函数的平均值
    cost = 0
    # 样本数
    m = X.shape[0]
    # 特征数
    n = X.shape[1]  
    for i in range(m):
        #损失函数，表示单个样本预测值与真实值的差
        lost = 0
        for j in range(n):
            lost = np.dot(theta[j],X[i][j])
        lost -= y[i]
        cost += lost**2
    # 成本函数
    lost /= 2*m 
    return lost

def gradientFunction(theta,X,y):
    m=X.shape[0]
    n=X.shape[1]
    gdvalue=np.zeros(n).reshape(n,1)
    for k in range(n):
        for i in range(m):
            dTheta = 0
            for j in range(n):
                dTheta = np.dot(theta[j],X[i][j])
            dTheta -= y[i]
            dTheta /= m # 梯度
        # 更新theta值 
        gdvalue[k] = dTheta
    return gdvalue

def batchGradientDecent(theta,X,y,iterNumber,lr=0.02):
    # 保留原来的theta值
    _theta = theta.copy()
    # 计算成本函数值
    costData = [objectiveFunction(_theta,X,y)]
    m = X.shape[0]
    n = X.shape[1]
    for k in range(iterNumber):
        gdValue = gradientFunction(_theta,X,y)
        for i in range(n):
            _theta[i] -= lr*gdValue[i]
        costData.append(objectiveFunction(_theta,X,y))
    return _theta,costData

def main():
    # 1.加载数据
    boston = datasets.load_boston()
    X, y = boston.data, boston.target

    # 2.拆分数据集
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=12)
    
    # 3.数据预处理
    scaler = preprocessing.StandardScaler().fit(X_train)
    X_train = scaler.transform(X_train)
    X_test = scaler.transform(X_test)

    # 4.模型求解
    n = X_train.shape[1]
    theta = np.zeros(n).reshape(n,1)
    iterNumber = 1000
    optTheta, costData = batchGradientDecent(theta,X_train,y_train,iterNumber)
    print(optTheta)
    print(costData) 

if __name__ == "__main__":
    main()
    pass