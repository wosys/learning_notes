//循环双链表
//头结点的prior要指向表尾结点
#include <stdio.h>
#include <stdlib.h>

/**定义模块**/

typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

//函数声明
bool InitRDLinkList(DLinkList &L);//初始化
bool isTail(DLinkList L,DNode *p);//判断节点p是不是循环双链表的表尾节点
bool InsertNextDNode(DNode *p,DNode *s);//在p节点之后插入s节点
bool DeleteNextDNode(DLinkList &L,DNode *p);//删除操作

bool InitRDLinkList(DLinkList &L){
    L=(DNode *)malloc(sizeof(DNode));//分配头节点
    if (L==NULL) return false;
    L->next=L;
    L->prior=L;//循环抱住自己   
    return true;
}

//判断节点p是不是循环双链表的表尾节点，是的话将头结点的prior指针指向它
bool isTail(DLinkList L,DNode *p){
    if(p->next==NULL){
        p->next=L->prior;
    }
    return true;
}

//在p节点之后插入s节点
bool InsertNextDNode(DNode *p,DNode *s){
    s->next=p->next;
    p->next->prior=s;
    s->prior=p;
    p->next=s;
    return true;
}

//删除操作
bool DeleteNextDNode(DLinkList &L,DNode *p){
    DNode *q = p->next;
    p->next=q->next;
    q->next->prior=p;
    free(q);
    return true;
}

