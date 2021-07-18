from sklearn import datasets
from sklearn.neural_network import MLPClassifier
import numpy as np
from sklearn import preprocessing
from sklearn.metrics import classification_report,confusion_matrix
from sklearn.model_selection import train_test_split

iris=datasets.load_iris()
x,y=iris.data,iris.target

x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.3,random_state=12)

mlp = MLPClassifier( )  #括号可加参数,例如:solver='lbfgs', alpha=1e-5,hidden_layer_sizes=(5, 2), random_state=1
# hidden_layer_sizes: 隐藏层单元数(tuple)，如(100,100,100,50)
# 	activation : 激活函数，{‘identity’, ‘logistic’, ‘tanh’, ‘relu’}, 缺省 ‘relu‘; [f(x) = x, 1/(1+exp(-x)), tanh(x), max(0, x)]
# 	solver : 解决器, {‘lbfgs’, ‘sgd’, ‘adam’}, 缺省 ‘adam’; [牛顿法,随机梯度下降, 自适应momemtum]
# 	alpha : L2正则化参数，float, 可选，缺省0.0001
# 	batch_size : 批次，可选, 不适用于’lbfgs’, 缺省 ‘auto‘, 此时，batch_size=min(200, n_samples)`
# 	learning_rate : 学习率, {‘constant’, ‘invscaling’, ‘adaptive’}, 缺省 ‘constant’, 只适用于梯度下降sgd
# 	learning_rate_init : 学习率初始值, 可选, 缺省 0.001, 仅适用于sgd或adam
# 	power_t : 下降指数, 可选, 缺省 0.5,  适用于’invscaling’,learning_rate_init/pow(t,power_t), 仅适用于sgd
# 	max_iter : 最大迭代数, 可选, 缺省200, 迭代器收敛迭代次数，对于sgd/adam, 代表的是epochs数目，不是下降步数
# 	shuffle : 每次迭代, 是否洗牌, 可选, 缺省True,仅适用于sgd或adam
# 	random_state: 缺省None; 若int, 随机数产生器seed, 若RandomStates实例, 随机数产生器, 若None, np.random
# 	tol : 容忍度, 可选, 缺省le-4, 连续两次迭代loss达不到此值，除非设置成’adaptive’,否则，就停止迭代，
# 	beta_1 : adam指数衰减参数1，可选, 缺省0.9
# 	beta_2 : adam指数衰减参数2，可选, 缺省0.999
# 	epsilon : adam数值稳定值，可选，缺省1e-8

mlp.fit(x_train,y_train)

print('训练集的准确率是：',mlp.score(x_train,y_train))
print('训练集的代价值是：',mlp.loss_)
print('训练集的权重值是：',mlp.coefs_)

matrix_train = confusion_matrix(y_train,mlp.predict(x_train))
print('训练集的混淆矩阵是：',matrix_train)

report_train = classification_report(y_train,mlp.predict(x_train))
print('训练集的分类报告是：',report_train)