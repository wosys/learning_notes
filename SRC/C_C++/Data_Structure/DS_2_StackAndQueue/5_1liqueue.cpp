//链式队列（带头节点版本）

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

//函数声明
void InitQueue(LinkQueue &Q);//初始化
bool EnQueue(LinkQueue &Q, int x);//入队操作
bool DeQueue(LinkQueue &Q, int &x);//出队
bool GetHead(LinkQueue Q, int &x);//获取头元素
bool IsEmpty(LinkQueue Q);//判空

void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));//建立头结点,初始化时，front 、rear 都指向头结点
    Q.front->next=NULL;
}

bool IsEmpty(LinkQueue Q){
    if(Q.rear==Q.front) return true;
    else return false;
}

bool EnQueue(LinkQueue &Q, int x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    //判满？链式存储一般不需要判满，除非内存不足
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;//创建新结点插入到链尾
    Q.rear = s;//修改队尾指针
    return true;
}

bool DeQueue(LinkQueue &Q, int &x){
    if (Q.front == Q.rear) return false;//队空
    LinkNode *p=Q.front->next;//用指针p记录队头元素
    x=p->data;//用x变量返回队头元素
    Q.front->next=p->next;//修改头节点的next指针
    if(Q.rear==p){//此次是最后一个结点出队
        Q.rear = Q.front;//如果原队列中只有一个结点删除后变空
    }
    free(p);
    return true;
}

bool GetHead(LinkQueue Q, int &x){
    if(Q.front == Q.rear) return false;//队空
    x=Q.front->next->data;
    return true;
}