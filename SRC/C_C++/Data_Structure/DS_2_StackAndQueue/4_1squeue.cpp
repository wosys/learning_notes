//循环顺序队列的第一种实现方式
#include <stdio.h>

/**定义模块**/
#define MaxSize 10

typedef struct{
    int data[MaxSize];
    int front,rear;//队头指针和队尾指针
}SqQueue;

//函数声明

void InitQueue(SqQueue &Q);//初始化
bool QueueEmpty(SqQueue Q);//判空
bool EnQueue(SqQueue &Q, int t);//入队操作
bool DeQueue(SqQueue &Q, int &x);//出队操作
bool GetHead(SqQueue Q, int &x);//获取队头元素,用x返回

void InitQueue(SqQueue &Q){
    Q.front=Q.rear=0;//初始化时，队头队尾都指向0
}

bool QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear)
        return true;//对空条件
    else
        return false;
}

bool EnQueue(SqQueue &Q,int t){
    if((Q.rear+1)%MaxSize==Q.front) return false;//队满报错
    Q.data[Q.rear]=t;
    Q.rear=(Q.rear+1)%MaxSize;//队尾指针加1取模，让整个队列循环起来
    return true;
}

bool DeQueue(SqQueue &Q,int &x){
    if(Q.rear == Q.front) return false;//队空
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;//队头指针加1取模，让整个队列循环起来
    return true;
}

bool GetHead(SqQueue Q,int &x){
     if(Q.front == Q.rear) return false;
     x = Q.data[Q.front];
     return true;
}