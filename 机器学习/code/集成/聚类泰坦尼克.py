import numpy as np
import pandas as pd
from sklearn import cluster, preprocessing
# 读取数据集
df = pd.read_excel(r'D:\code\Python_code\ML\KMeans\titanic.xls')
df.head()
# 删除任何和特定乘客有关的、和生存无关的列
df.drop(['body','cabin','ticket','name'], 1, inplace=True)
# 其他的死亡因素
# df.drop(['home.dest','name'], 1, inplace=True)
# df.drop(['home.dest','body'], 1, inplace=True)
# df.drop(['age','body','cabin'], 1, inplace=True)
df.head()
# 将空值用0填充
df.fillna(0, inplace=True)
# df.head()
# 将部分字段转换为数值类型
columns = df.columns.values
for i in columns:
    text_value_int = {}
    def text_to_val(val):
        return text_value_int[val]
    if df[i].dtype != np.int64 and df[i].dtype != np.float64:
        all_text = df[i].values.tolist()
        unique_elements = set(all_text)
        
        x = 0
        for unique in unique_elements:
            if unique not in text_value_int:
                text_value_int[unique] = x
                x+=1
        
        df[i] = list(map(text_to_val, df[i]))
df.head()
# 训练模型，看看哪些决定生存率，决定生存率的就会被用来测试模型的准确率
X = np.array(df.drop('survived', 1).astype(float))
X = preprocessing.scale(X)
y = np.array(df['survived'])
clf = cluster.KMeans(n_clusters=2)
clf.fit(X)
correct = 0
for i in range(len(X)):
    predict_me = np.array(X[i].astype(float))
    predict_me = predict_me.reshape(-1, len(predict_me))
    prediction = clf.predict(predict_me)
    if prediction[0] == y[i]:
        correct += 1

accuracy = correct/len(X)
accuracy