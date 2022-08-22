from multiprocessing import Process

def jc(num):
    print("run------",str(num))
    
if __name__ == '__main__':
    m = Process(target=jc,args=(2,))
    m.start()
    m.join