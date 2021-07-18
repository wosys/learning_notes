from sklearn import datasets
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier

def main():
    #载入数据
    wine = datasets.load_wine()

    #获取特征数据及标签数据
    X = wine.data
    Y = wine.target

    #拆分数据集
    X_train,X_test,Y_train,Y_test=train_test_split(X,Y,test_size = 0.30, random_state = 12)

    #声明并训练模型
    KNNClassfiler = KNeighborsClassifier(n_neighbors=5)
    KNNClassfiler.fit(X_train,Y_train)

    #评估模型
    accuracy = KNNClassfiler.score(X_test,Y_test)

    #输出准确率
    print("预测准确率为:{:.2f}%".format(accuracy*100))


if __name__ == "__main__":
    main()
    pass


