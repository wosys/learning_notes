//顺序栈的实现
#include<stdio.h>

#define MaxSize 50
typedef struct
{
    int data[MaxSize]; //存放栈中元素
    int top; //栈顶指针
} SqStack;

//函数声明
void InitStack(SqStack &S);//初始化
bool Push(SqStack &S, int t);//入栈
bool Pop(SqStack &S, int &x);//出栈,并打印出栈顶元素
bool GetTop(SqStack S, int &x);//读取栈顶元素
int GetTopOther(SqStack S);//读取栈顶元素的第二种实现方式
bool StackEmpty(SqStack S);//判空


void InitStack(SqStack &S){
    S.top = -1;//这种初始化的方式，栈顶指针始终指向栈顶元素
    // S.top = 0;//这种初始化方式，栈顶指针始终会指向栈顶元素的下一空元素
}

bool Push(SqStack &S, int t){
    if(S.top==MaxSize-1) return false; //栈满
    S.top+=1;//先将栈顶指针指向下一个位置
    S.data[S.top]=t;//再填充元素
    return true;
}

bool Pop(SqStack &S, int &x){
    if(S.top==-1) return false;//栈空
    x=S.data[S.top];//先取元素
    S.top -=1;//再改指针
    return true;
}

bool GetTop(SqStack S, int &x) {
    if(S.top==-1) return false;
    x = S.data[S.top];
    return true;
}

//读取栈顶元素的第二种实现方式
//利用返回值返回栈顶元素，若成功就返回栈顶元素，失败就返回-1；
//缺点：如果栈顶元素就是-1，容易造成误判，正因它的缺点，如果考试考到了它，写这种方式应该是会被扣部分分数的
int GetTopOther(SqStack S) {
    if (S.top == -1)return -1;
    return S.data[S.top];
}

bool StackEmpty(SqStack S){
    if(S.top==-1)//栈空
        return true;
    else
        return false;
}