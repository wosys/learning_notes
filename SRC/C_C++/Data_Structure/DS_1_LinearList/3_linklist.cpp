//带头结点的单链表

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    LNode *next;
}LNode,*LinkList;

//函数定义
bool InitList(LinkList &L);     //初始化
bool Empty(LinkList L);         //判空
bool ListInsert(LinkList &L, int i, int e);//按位插入
bool InsertNextNode(LNode *p, int e);//指定节点的后插操作
bool InsertPriorNode(LNode *p, int e);//指定节点的前插操作————先完成后插，再交换数据以实现前插
bool ListDelete(LinkList &L, int i, int &e);//按指定位序删除节点并返回其值
bool DeleteNode(LNode *p);//删除指定节点

//1.初始化(带有一个头结点)
bool InitList(LinkList &L){
    L=(LNode *)malloc(sizeof(LNode));//分配一个头结点
    if(L == NULL){
        //空表
        return false;//分配失败，可能是内存不足
    }
    L->next = NULL;//头结点之后暂时没有结点，头结点也不存放数据
    return true;
}

//2.判空
bool Empty(LinkList L){
    // if(L->next==NULL)
    //    return true;
    // else
    //    return false;
    return (L->next == NULL);
}

//3.按位插入
bool ListInsert(LinkList &L,int i,int e){
    if(i<1) return false;
    if(i==0) return L;//i为0，返回头结点
    LNode *p=L->next;//头结点指针赋给p
    //LNode *p；
    // p=L;
    int j=0;//记录p指向的节点的位序
    while (p!=NULL && j<i-1)//0的时候是i-1，1的时候是i
    {
        //循环扫描
        p = p->next;
        j++;
    }
    if(p==NULL){
        //i值超过表长，不合法
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    //下面的顺序不可交换
    s->next = p->next;
    p->next = s;
    return true;  
}

//4.指定节点的后插操作
bool InsertNextNode(LNode *p, int e){
    if(p==NULL){
        return false;//判断指定结点是否存在
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) return false;//分配内存失败
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

//5.指定节点的前插操作
//先完成后插，再交换数据以实现前插
bool InsertPriorNode(LNode *p, int e) {
    if(p==NULL){
        return false;//判断指定结点是否存在
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) return false;//分配内存失败
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}

//6.按指定位序删除节点并返回其值
bool ListDelete(LinkList &L, int i, int &e){
    if(i<1) return false;
    LNode *p=L->next;
    int j=0;
    while (p!=NULL && j<i-1){
        p=p->next;
        j++;
    }
    LNode *q = p->next;//令q指向*p的后继结点
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}
//7.删除指定结点
bool DeleteNode(LNode *p){
    p->data=p->next->data;
    p->next=p->next->next;
}