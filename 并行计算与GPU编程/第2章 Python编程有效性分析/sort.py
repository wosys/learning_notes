@profile
def sortport(lis):
    for i in range(len(lis)-1):
        for j in range(len(lis)-1-i):
            if lis[j]>lis[j+1]:
                lis[j],lis[j+1] = lis[j+1],lis[j]
    return lis
@profile
def sortport_fast(lis):
    for i in range(len(lis)-1):
        flag = False
        # 设定一个变量为False，如果元素之间交换了位置，将变量重新赋值为True,最后再判断，
        # 在一次循环结束后，变量如果还是为False，则brak退出循环，结束排序。
        for j in range(len(lis)-1-i):
            if lis[j] > lis[j + 1]:
                lis[j], lis[j + 1] = lis[j + 1], lis[j]
                flag = True
        if not flag:
            break
    return lis

lis1 = [56,12,1,8,354,10,100,34,56,7,23,456,234,-58,12,1,8,354,10,100,34,56,7,23,456,234,-58,12,1,8,354,10,100,34,56,7,23,456,234]
lis2 = [56,12,1,8,354,10,100,34,56,7,23,456,234,-58,12,1,8,354,10,100,34,56,7,23,456,234,-58,12,1,8,354,10,100,34,56,7,23,456,234]
sortport(lis1)
sortport_fast(lis2)