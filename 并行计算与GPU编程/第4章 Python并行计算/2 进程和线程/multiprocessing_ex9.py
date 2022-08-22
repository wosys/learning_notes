#multiprocessing_ex9.py
from multiprocessing import Process
import multiprocessing as m
from multiprocessing import Event

import time
e=Event()
def main(num):
    while True:
        if num<5:
            e.clear()   #清空信号标志
            print('清空')
        if num>=5:
            e.wait(timeout=1) #等待信号标志为真
            e.set()
            print('启动')
            
        if num==10:
            e.wait(timeout=3)
            e.clear()
            print('退出')
            break
        num+=1
        time.sleep(2)
if __name__ == '__main__':
    for y in range(10):
        pp=Process(target=main,args=(y,))
        pp.start()
        pp.join()