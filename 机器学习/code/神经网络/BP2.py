import numpy as np
from matplotlib import pyplot as plt
import pandas as pd

# 导入数据
data_file = './ML/LogisticRegression_Data1.txt'
data = pd.read_csv(data_file, names=['exam1','exam2','admitted'])

# 将两类数据点分开并画出
one_points = np.array([[temp[0], temp[1], temp[2]] for temp in data.values if temp[2] == 1])
zero_points = np.array([[temp[0], temp[1], temp[2]] for temp in data.values if temp[2] == 0])
plt.scatter(one_points[:, 0], one_points[:, 1], c='red')
plt.scatter(zero_points[:, 0], zero_points[:, 1], c='blue')

# 定义训练用常量以及更改数据格式
theta = np.array([1, 1, 1])
max_iterate = 1000000
alpha = 0.1
X = np.ones((100, 3))
X[:, 1:3] = np.array(data[['exam1', 'exam2']])
Y = np.array(data.admitted)

# 1.Sigmoid函数
def Sigmoid(z):
    return 1 / (1 + np.exp(-z))

def hx(theta, X):
    hx = Sigmoid(np.dot(X, theta.T))
    return hx 

# 开始迭代
for _ in range(max_iterate):
    hx1 = hx(theta, X)
    gradient_J = np.dot(hx1 - Y, X) / len(one_points)
    last_theta = theta
    theta = theta - alpha * gradient_J

# 得出超平面公式
x = np.linspace(min(data.exam1), max(data.exam1))
bias = theta[0]
k = -theta[1] / theta[2]
b = -bias / theta[2]
y = k * x + b

# 画出超平面
plt.plot(x, -theta[0] / theta[2] - x * theta[1] / theta[2])
plt.show()