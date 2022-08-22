#multiprocessing_ex10.py
from multiprocessing import Process
import multiprocessing as m

import time

def p1(pipe):#发送信息
    for i in range(5):
        pipe.send(i)
        print('send......')
        time.sleep(1)
              
def p2(pipe):#接收信息
    while True:
        print('recv.....')
        print(pipe.recv())
if __name__ == '__main__':
    p3,p4 = m.Pipe()
    pq=Process(target=p1,args=(p3,))#发送信思
    pt=Process(target=p2,args=(p4,))#接收信息
    pq.start()
    pt.start()
    p3.close()
    p4.close()
    pt.join()
    pq.join()