# 几种线性回归算法库
from sklearn import linear_model
import numpy as np
import matplotlib.pyplot as plt
# 读取点
data = np.genfromtxt("./ML/ex1data1.txt", delimiter=",")
x_data = data[:, 0, np.newaxis]
y_data = data[:, 1, np.newaxis]
# 调用库
reg1 = linear_model.LinearRegression()
reg2 = linear_model.Ridge()
reg3 = linear_model.RidgeCV()
reg4 = linear_model.Lasso()
reg5 = linear_model.ElasticNet()

a1 = reg1.fit(x_data, y_data)
a2 = reg2.fit(x_data, y_data)
a3 = reg3.fit(x_data, y_data)
a4 = reg4.fit(x_data, y_data)
a5 = reg5.fit(x_data, y_data)
# 画图
fig = plt.figure()

fig.add_subplot(2,3,1)
plt.scatter(x_data, y_data)
plt.plot(x_data, a1.predict(x_data), c="red")

fig.add_subplot(2,3,2)
plt.scatter(x_data, y_data)
plt.plot(x_data, a2.predict(x_data), c="yellow")

fig.add_subplot(2,3,3)
plt.scatter(x_data, y_data)
plt.plot(x_data, a3.predict(x_data), c="black")

fig.add_subplot(2,3,4)
plt.scatter(x_data, y_data)
plt.plot(x_data, a4.predict(x_data), c="green")

fig.add_subplot(2,3,5)
plt.scatter(x_data, y_data)
plt.plot(x_data, a5.predict(x_data), c="pink")

plt.show()

# 给出k
print(reg1.coef_,reg2.coef_,reg3.coef_,reg4.coef_,reg5.coef_)

