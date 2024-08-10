//共享顺序栈的实现
//简单来说就是两个栈共享一片存储空间，提高顺序栈的对存储空间的使用率
#include <stdio.h>

/**定义模块**/
# define  MaxSize 10
typedef struct {
    int data[MaxSize];
    int top0;
    int top1;//从结构体的定义就可以看出来，两个共享栈的根源就在于定义两个指针
} ShStack;

//函数声明
void InitStack(ShStack &S);//初始化
bool Push0(ShStack &S, int t);//入栈0
bool Push1(ShStack &S, int t);//入栈1
bool Pop0(ShStack &S, int &x);//出栈0,并打印出栈顶元素
bool Pop1(ShStack &S, int &x);//出栈1,并打印出栈顶元素
bool GetTop0(ShStack S, int &x);//读取栈顶元素，栈0
bool GetTop1(ShStack S, int &x);//栈1

void InitStack(ShStack &S){
    S.top0 = -1;//这种初始化的方式，栈顶指针始终指向栈顶元素
    S.top1 = MaxSize;//这里的MaxSize就是所谓的第二个栈的栈底
}

bool Push0(ShStack &S,int t){
    if(S.top1-S.top0==1)//栈满
        return false;
    S.data[++S.top0] = t;
    return true;
}

bool Push1(ShStack &S,int t){
    if(S.top1-S.top0==1)//栈满
        return false;
    S.data[--S.top1] = t;
    return true;
}

bool Pop0(ShStack &S, int &x) {
    //判断
    if (S.top0 == -1) return false;//栈空报错
    x = S.data[S.top0--];
//    等价于下面
//    x=S.data[S.top];//先取元素
//    S.top -=1;//再改指针
    return true;
}

bool Pop1(ShStack &S, int &x) {
    //判断
    if (S.top1 == MaxSize) return false;//注意一下它的栈空报错条件
    x = S.data[S.top1++];//注意这个栈修改指针是++
//    等价于下面
//    x=S.data[S.top];//先取元素
//    S.top +=1;//再改指针
    return true;
}

bool GetTop0(ShStack S, int &x){
    if (S.top0 == -1) return false;
    x = S.data[S.top0];
    return true;
}

bool GetTop1(ShStack S, int &x){
    if (S.top1 == MaxSize) return false;
    x = S.data[S.top1];
    return true;
}