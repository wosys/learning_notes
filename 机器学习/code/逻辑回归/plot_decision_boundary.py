'''
@Descripttion: 绘制决策边界
@version: V1.0
@Author: XYZ
@Date: 2020-04-23 17:25:12
@LastEditors: XYZ
@LastEditTime: 2020-04-23 21:53:45
'''

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier

'''
@name: 绘制主函数
@msg: 
@param {type} 
@return: 
'''
def plot_decision_boundary(model, axis):
    x1 = np.linspace(axis[0], axis[1], int(axis[1] - axis[0])*100).reshape(-1, 1)
    x2 = np.linspace(axis[2], axis[3], int(axis[3] - axis[2])*100).reshape(-1, 1)
    X1, X2 = np.meshgrid(x1, x2)

    X_Plot = np.c_[X1.ravel(), X2.ravel()]
    y_Plot = model.predict(X_Plot).reshape(X1.shape)
    
    custom_cmap = ListedColormap(["#9BF2B2", "#9BC1F7", "#FAC9D6"])
    plt.contourf(X1, X2, y_Plot, linewidth=5, cmap=custom_cmap)



'''
@name: 测试主函数
@msg: 
@param {type} 
@return: 
'''
def main():
    iris = datasets.load_iris()
    X = iris.data
    y = iris.target

    # X = X[y<2,:2]
    # y = y[y<2]
    X = X[:,:2]
    
    knn = KNeighborsClassifier(n_neighbors=100)
    knn.fit(X, y)
    
    plot_decision_boundary(knn, axis=[4.0, 8.1, 1.8, 4.5])
    plt.scatter(X[y==0, 0], X[y==0, 1])
    plt.scatter(X[y==1, 0], X[y==1, 1])
    plt.scatter(X[y==2, 0], X[y==2, 1])
    plt.show()

if __name__ == "__main__":
    main()
    pass