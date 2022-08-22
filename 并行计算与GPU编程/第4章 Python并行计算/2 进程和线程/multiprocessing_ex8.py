#multiprocessing_ex8.py

from multiprocessing import Process
import multiprocessing as m
from multiprocessing import RLock
import time

lock1=RLock()
lock2=RLock()
s=time.time()
def jc(num):
    lock1.acquire()
    lock2.acquire()
    print('start')
    print(m.current_process().pid,'run----',str(num))
    lock1.release()
    lock2.release()
    print('end')
if __name__ == '__main__':
    aa=[]
    for y in range(12):
        pp=Process(target=jc,args=(y,))
        pp.start()
        aa.append(pp)
    for x in aa:
        x.join()
    e=time.time()
    print(e - s)