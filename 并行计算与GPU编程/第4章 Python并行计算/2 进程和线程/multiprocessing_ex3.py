from multiprocessing import Process
import multiprocessing as m

def jc(num):
    print("run------",str(num))

    
if __name__ == '__main__':
    for y in range(10):
        p = Process(target=jc,args=(12,))
        p.start()
        p.join()
        print(p.pid)