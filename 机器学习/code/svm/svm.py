import numpy as np
from scipy.io import loadmat
from sklearn.svm import SVC
import matplotlib.pyplot as plt
from pydash import py_
from stemming.porter2 import stem

# 垃圾邮件分类器
data = loadmat(r'D:\code\Python_code\ML\SVM\data_email\spamTrain.mat')
X = np.mat(data['X'])
y = data['y']
m, n = X.shape

# 使用训练集训练分类器
clf = SVC(C=0.1, kernel='linear', tol=1e-3)
clf.fit(X, y.ravel())
predictions = np.mat([clf.predict(X[i, :])  for i in range(m)])
accuracy = 100 * np.mean(predictions == y)
print ('训练数据集的准确率: %0.2f %%' % accuracy)

# 使用测试集评估训练结果
data = loadmat(r'D:\code\Python_code\ML\SVM\data_email\spamTest.mat')
XTest = np.mat(data['Xtest'])
yTest = data['ytest']
mTest, _ = XTest.shape

clf.fit(XTest, yTest.ravel())
predictions = np.mat([clf.predict(XTest[i, :])  for i in range(mTest)])
accuracy = 100 * np.mean(predictions == yTest)
print ('测试数据集的准确率: %0.2f %%' % accuracy)

# 获得词汇表
vocabList = []
with open(r'D:\code\Python_code\ML\SVM\vocab.txt') as f:
    for line in f:
        idx, w = line.split()
        vocabList.append(w)


def processEmail(email):
    """预处理邮件
    Args:
        email 邮件内容
    Returns:
        indices 单词在词表中的位置
    """
    # 转换为小写 --> 标准化 URL --> 标准化 邮箱地址
    # --> 去除 HTML 标签 --> 标准化数字
    # --> 标准化美元 --> 删除非空格字符
    return py_(email) \
        .strip_tags() \
        .reg_exp_replace(r'(http|https)://[^\s]*', 'httpaddr') \
        .reg_exp_replace(r'[^\s]+@[^\s]+', 'emailaddr') \
        .reg_exp_replace(r'\d+', 'number') \
        .reg_exp_replace(r'[$]+', 'dollar') \
        .lower_case() \
        .trim() \
        .words() \
        .map(stem) \
        .map(lambda word : py_.index_of(vocabList, word) + 1) \
        .value()

def extractFeatures(indices):
    """提取特征
    Args:
        indices 单词索引
    Returns:
        feature 邮件特征
    """
    feature = py_.map(range(1, len(vocabList) + 1),
                      lambda index: py_.index_of(indices, index) > -1)
    return np.array(feature, dtype=np.uint)

def getTopPredictors(weights, count):
    """获得最佳标识词汇
    Args:
        weights 权值
        count top count
    Returns:
        predictors predicators
    """
    return py_(vocabList) \
        .map(lambda word, idx: (word, weights[idx])) \
        .sort_by(lambda item: item[1], reverse = True) \
        .take(count) \
        .value()

# 获得最能标识垃圾邮件的词汇（在模型中获得高权值的）
weights = abs(clf.coef_.flatten())
top = 15
predictors = getTopPredictors(weights, top)
print ('\nTop %d predictors of spam:'%top)
for word, weight in predictors:
    print ('%-15s (%f)' % (word, weight))

# 使用邮件测试
def genExample(f):
    email = open(f).read()
    indices =  processEmail(email)
    features =  extractFeatures(indices)
    return features

files = [
    r'D:\code\Python_code\ML\SVM\data_email\emailSample1.txt',
    r'D:\code\Python_code\ML\SVM\data_email\emailSample2.txt',
    r'D:\code\Python_code\ML\SVM\data_email\spamSample1.txt',
    r'D:\code\Python_code\ML\SVM\data_email\spamSample1.txt',   
]
labels = np.array([[0, 0, 1, 1]]).reshape(-1, 1) # 垃圾邮件为1
emails = np.mat([genExample(f) for f in files], dtype=np.uint8)
print(labels)
predictions = np.mat([clf.predict(emails[i, :])  for i in range(len(files))])
for i in range(len(files)):
    if predictions[i]==0:
        print("这是一份正常邮件")
    else:
        print("这是一份垃圾邮件")
accuracy = 100 * np.mean(predictions == labels)
print('\n判断垃圾邮件的准确率: %0.2f %%' % accuracy)