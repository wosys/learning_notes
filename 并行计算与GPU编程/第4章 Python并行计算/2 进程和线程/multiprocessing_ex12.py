#multiprocessing_ex12.py
from multiprocessing import Process
import multiprocessing as m
from multiprocessing import Manager

def fd(dt,lt):
    dt['one'] = 10
    lt.append('32')
    print(dt)
    print(lt)

if __name__ == '__main__':
    with Manager() as mg:
        dt=mg.dict()
        lt=mg.list()
        pp=Process(target=fd,args=(dt,lt))
        pp.start() #开始运行
        pp.join()