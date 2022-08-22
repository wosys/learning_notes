#multiprocessing_ex11.py
from multiprocessing import Process
import multiprocessing as m
from multiprocessing import Queue

def fd(a):
    for y in range(10):
        a.put(y)  #插入数据
        print('插入：',str(y))
def df(b):
    while True:
        aa=b.get(True) #删除数据
        print('释放：',str(aa))
if __name__ == '__main__':
    q=Queue()
    ff=Process(target=fd,args=(q,))
    dd=Process(target=df,args=(q,))
    ff.start() #开始运行
    dd.start()
    dd.terminate() #关闭
    ff.join()