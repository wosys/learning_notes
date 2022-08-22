from multiprocessing import Process

def jc(num):
    print("run------",str(num))
    
if __name__ == '__main__':
    for y in range(10):
        m = Process(target=jc,args=(y,))
        m.start()
        m.join