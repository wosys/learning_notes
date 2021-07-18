from sklearn import datasets
from sklearn.ensemble import GradientBoostingRegressor
from sklearn.ensemble import RandomForestRegressor
from sklearn.linear_model import LinearRegression
from sklearn.ensemble import VotingRegressor

#加载数据
boston=datasets.load_boston()
x=boston.data
y=boston.target

#训练
reg1=GradientBoostingRegressor(random_state=1,n_estimators=10)
reg2=RandomForestRegressor(random_state=1,n_estimators=10)
reg3=LinearRegression()
ereg=VotingRegressor(estimators=[('gb',reg1),('rf',reg2),('lr',reg3)])
ereg=ereg.fit(x,y)

print("准确性：",ereg.score(x,y))