 import numpy as np
 import matplotlib.pyplot as plt
 from sklearn.linear_model import LinearRegression
 # 下面导入的包是用来实现多项式的
 from sklearn.preprocessing import PolynomialFeatures

 # 载入数据
 data = np.genfromtxt("job.csv",delimiter= ",")
 x_data = data[1:,1]
 y_data = data[1:,2]
 # 下面是将取得的数据画一个散点图
 # plt.scatter(x_data,y_data)
 # plt.show()

 x_data = data[1:,1,np.newaxis]  # 或者x_data = x_data[:,np.newaxis]
 y_data = data[1:,2,np.newaxis]  # 或者y_data = y_data[:,np.newaxis]


 # 创建并拟合模型
 # model = LinearRegression()
 # model.fit(x_data,y_data)
 # 画图
 # plt.plot(x_data,y_data,'b.') #画一个蓝色点的图
 # plt.plot(x_data,model.predict(x_data),'r') # 此处用的线性回归模型进行预测，将预测值作为y值，画一个红色的直线拟合
 # plt.show()


 # 定义多项式回归，degree的值可以调节多项式的特征
 poly_reg = PolynomialFeatures(degree=5)
 # 特征处理
 x_poly = poly_reg.fit_transform(x_data)
 # 定义回归模型
 lin_reg = LinearRegression()
 # 训练模型
 lin_reg.fit(x_poly,y_data)

 # 画图
 plt.plot(x_data,y_data,'b.') #用蓝色的点把数据集表示出来
 x_test = np.linspace(1,10,100) #linspace(a,b,c)表示划分区间[a,b],等分c份
 x_test = x_test[:,np.newaxis] #设置x_test数组格式为一列
 plt.plot(x_test,lin_reg.predict(poly_reg.fit_transform(x_test)),c = 'r')
 plt.title('Truth or Bluff(Polynomial Regression)')
 plt.xlabel('Position level')
 plt.ylabel('Salary')
#  plt.show()在这里插入图片描述

# 当因变量y与自变量x为非线性关系时，线性关系不满足拟合状态，找不到合适的曲线拟合，可采用一元多项式回归，通过增加x的高次项对实测点进行逼近，直到拟合结果满意为止。
