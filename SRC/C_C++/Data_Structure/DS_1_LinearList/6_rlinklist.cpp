//循环单链表
//与单链表的区别在于最后一个结点的指针指向的不是NULL，而是头结点
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//函数声明
bool InitRLinkList(LNode &L);//初始化
bool IsTail(LinkList L,LNode *p);//判断P是不是表尾指针

bool InitRLinkList(LinkList &L){
    L=(LNode *)malloc(sizeof(LNode));//分配一个头节点
    if (L=NULL)
        return false;//内存不足，分配失败；
    L->next=L;//头节点nex指向头节点，以此形成循环链表
    return true;
}

//判断p是不是表尾元素，是的话就把他的下一个直至连接头结点
bool IsTail(LinkList L,LNode *p){
    if(p->next==NULL){
        p->next=L;
    }
    return true;
}