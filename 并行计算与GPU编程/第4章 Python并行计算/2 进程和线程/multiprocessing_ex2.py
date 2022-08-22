from multiprocessing import Process

def jc(num):
    print("run------",str(num))

class pp(Process):
    def _init_(self):
        super(pp,self)._init_()
    def run(self,num):
        print("run------",str(num))
    
if __name__ == '__main__':
    for y in range(10):
        p=pp()
        p.run(y)