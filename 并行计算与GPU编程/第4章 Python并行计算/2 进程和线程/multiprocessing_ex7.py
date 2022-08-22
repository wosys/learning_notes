from multiprocessing import Process
import multiprocessing as m
from multiprocessing import Lock
import time

lock=Lock()
s=time.time()
def jc(num):
    lock.acquire()
    print('strart')
    print(m.current_process().pid,"run------",str(num))
    print('end')
    lock.release()
if __name__ == '__main__':
    aa=[]
    for y in range(12):
        pp = Process(target=jc,args=(y,))
        pp.start()
        aa.append(pp)
    for x in aa:
        x.join()
    e=time.time()
    print(e - s)