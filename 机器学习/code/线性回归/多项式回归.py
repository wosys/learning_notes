import numpy as np 
import matplotlib.pyplot as plt
from sklearn import metrics,model_selection,linear_model
from sklearn.model_selection import train_test_split
from sklearn.datasets import load_boston
import time

def setTime():
    t1 = time.time()
    return t1

def getTimeDelta(t1):
    t2 = time.time()
    t_delta = t2 - t1
    return t_delta

def getData():
    boston_data = load_boston()
    return boston_data

#通过SKlearn模块内函数进行训练与预测
def LinearRegression_1(boston_data):
    X = boston_data.data
    y = boston_data.target
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 5)

    LR = linear_model.LinearRegression()
    LR.fit(X_train,y_train)
    print("准确率为：",LR.score(X_test,y_test)) #输出测试集评估情况

#最速下降法进行线性回归,这个函数由于np不支持过大数字报错了，linearRegression_3修改了theta与temp等np数组为列表
def LinearRegression_2(boston_data):
    m = len(boston_data.data) #数据长度
    a = 0.1 #学习率
    theta = np.array([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0])  #共14个θ
    J, Jtemp = 0, 0
    precision = 1e-2  #精度
    count = 0 #计数器

    X = np.array(boston_data.data)
    y = np.array(boston_data.target)

    X = np.insert(X, 0, 1, axis = 1) #设X0为1以便矩阵相乘，此时X的子项为14项

    for Xtemp, ytemp in zip(X, y):
        Jtemp += (np.dot(Xtemp, theta) - ytemp)**2 
    Jtemp /= 2*m

    while True:
        J = Jtemp
        temp = np.array([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0])  #共14个θ
        for Xtemp, ytemp in zip(X, y):
            for i in range(14):
                temp[i] += (np.dot(Xtemp, theta) - ytemp) * Xtemp[i]    #求和
                
        
        for i in range(14):
            temp[i] = theta[0] - a/m*temp[i]    #计算temp[i]
            print(temp[i])
        
        for i in range(14):
            theta[i] = temp[i]  #赋值给theta

        for Xtemp, ytemp in zip(X, y):
            Jtemp += (np.dot(Xtemp, theta) - ytemp)**2 
        Jtemp /= 2*m    

        #判断是否达到精确度
        if(abs(Jtemp - J) < precision):
            print("线性拟合的结果为：")
            for i in range(14):
                print("θ{} = {}".format(i, theta[i]))
            break
        else:
            count += 1
            print("迭代第{}次".format(count))

def LinearRegression_3(boston_data):
    m = len(boston_data.data) #数据长度
    a = 1e-6 #学习率
    theta = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] #共14个θ
    J, Jtemp = 0, 0
    precision = 1  #精度
    count = 0 #计数器

    X = np.array(boston_data.data)
    y = np.array(boston_data.target)

    X = np.insert(X, 0, 1, axis = 1) #设X0为1以便矩阵相乘，此时X的子项为14项

    for Xtemp, ytemp in zip(X, y):
        Jtemp += (np.dot(Xtemp, theta) - ytemp)**2 
    Jtemp /= 2*m

    t = setTime()
    while True:
        J = Jtemp
        temp = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]  #共14个θ
        for Xtemp, ytemp in zip(X, y):
            for i in range(14):
                sum = 0
                for j in range(14):
                    sum += Xtemp[j] * theta[j]  #求矩阵的乘积
                temp[i] += (sum - ytemp) * Xtemp[i]    #求和
                
        
        for i in range(14):
            temp[i] = theta[0] - a/m*temp[i]    #计算temp[i]
            # print(temp[i])
        
        for i in range(14):
            theta[i] = temp[i]  #赋值给theta

        for Xtemp, ytemp in zip(X, y):
            Jtemp += (np.dot(Xtemp, theta) - ytemp)**2 
        Jtemp /= 2*m    

        #判断是否达到精确度
        if(abs(Jtemp - J) < precision):
            print("线性拟合结束，结果为：")
            for i in range(14):
                print("θ{} = {}".format(i, theta[i]))
            print("迭代共{}次,jtemp = {}, 与精度差距为{}".format(count+1,Jtemp,abs(Jtemp - J) - precision))
            print("时间：",getTimeDelta(t))
            break
        else:
            count += 1
            print("迭代第{}次,jtemp = {}, 与精度差距为{}".format(count,Jtemp,abs(Jtemp - J) - precision))

boston_data = getData()
print(boston_data.data)
LinearRegression_1(boston_data)

print(boston_data.data[1])
LinearRegression_1(boston_data)
LinearRegression_3(boston_data)

# 多项式回归的主要思想就是通过历史数据拟合出多项式回归的方程，并利用多项式回归的方程对新的数据进行预测。多项式回归的方程如下:
# 要想获得一个与目标数据集完美拟合的多项式回归模型，求解出每个特征自变量的权值。线性回归首先构建一个凸函数的优化函数(诸如: 给定的函数值与模型预测值之差的平方和最小)，并使用最小二乘法和梯度下降法来计算最终的拟合参数。
