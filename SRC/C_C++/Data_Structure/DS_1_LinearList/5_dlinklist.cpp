//带有头结点版本——双链表

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;//数据域
    struct DNode *prior, *next;//前指针和后指针
} DNode, *DLinkList;

//函数声明
bool InitDLinkList(DLinkList &L);//初始化
bool Empty(DLinkList L);//判空
bool InsertNextElem(DNode *p, DNode *s);//指定节点的后插操作
bool DeleteNextNode(DNode *p);//删除P节点的后继节点
bool DestroyList(DLinkList &L);//销毁整个表
bool PrintNextElems(DNode *p);//从P点向后遍历
bool PrintPriorElemsOverHead(DNode *p);//从P点向前遍历（跳过头节点）

//初始化
bool InitDLinkList(DLinkList &L){
    L = (DNode *)malloc(sizeof(DNode));//分配一个头结点
    if(L==NULL){
        return false;
    }
    L->prior == NULL;//头结点的前后指针都指空
    L->next == NULL;
    return true;
}

//判空
bool Empty(DLinkList L){
    if(L->next==NULL){
        return true;
    }
    else{
        return false;
    }
}

//指定结点的后插
bool InsertNextElem(DNode *p, DNode *s){
    s->next = p->next; //p的后继连接到插入的那个结点s上
    p->next->prior = s; //原来p的后继的前继连接到新插入的结点s上
    s->prior = p; //新插入的s的前继是p
    p->next =s; //p的后继是s
    return true;
}

//删除p结点后的后继结点
bool DeleteNextNode(DNode *p){
    if(p==NULL) return false; //p结点为空，没有后继结点
    DNode *q=p->next; //q是p的后继，也是需要删除的
    if(q==NULL) return false; //q节点没有后继
    p->next=q->next; //将q的后继直接连接在p的后继（代替q）
    if(q->next!=NULL){ //q不是最后一个结点
        q->next->prior = p; //q的后继的前继改成p
    }
    return true;
}

//销毁整个表
bool DestroyList(DLinkList &L){
    while(L->next!=NULL){
        //循环遍历删除并释放每个结点
        DeleteNextNode(L);
    }
    free(L);//释放头结点
    L = NULL;
    return true;
}

//从p结点向后遍历
bool PrintNextElems(DNode *p){
    if(p==NULL) return false;
    while (p!=NULL){
        printf("当前结点的值是:%d",p->data);
        p=p->next;
        //向前遍历的只需要改这里
        //p = p->prior;
    }
    return true;
}

//从P点向前遍历（跳过头节点）
bool PrintPriorElemsOverHead(DNode *p) {
    if (p == NULL)return false;
    while (p->prior != NULL) {//这里是判断p->prior
        printf("当前节点的值是:%d", p->data);
        p = p->prior;
    }
    return true;
}