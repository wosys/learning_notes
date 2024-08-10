//链栈的实现
#include <stdio.h>
#include <stdlib.h>

# define MaxSize 10 
/**定义模块**/
typedef struct Linkn{
    int data;
    struct Linkn *next;
}*LinkStack;

//函数声明
bool InitStack(LinkStack &LS);//初始化
bool Push(LinkStack &LS, int t);//入栈 参考头插法建立单链表
bool Pop(LinkStack &LS, int &x);//出栈,并打印出栈顶元素
bool GetTop(LinkStack LS, int &x);//读取栈顶元素，栈

bool InitStack(LinkStack &LS){
    LS = (Linkn *)malloc(sizeof(Linkn));//分配一个头结点
    if(LS==NULL) return false;
    LS->next = NULL;
    return true;
}

bool Push(LinkStack &LS, int t){
    //入栈不需要检查
    Linkn *s = (Linkn *)malloc(sizeof(Linkn));
    if(s==NULL) return false;
    s->data = t;
    s->next= LS->next;
    LS->next = s;
    return true;
}

bool Pop(LinkStack &LS, int &x){
    //判断
    if (LS->next == NULL) return false;//栈空,这里的条件
    Linkn *q;
    q=LS->next;
    LS->next=q->next;
    x=q->data;
    free(q);
    return true;
}

bool GetTop(LinkStack LS,int &x){
    if(LS==NULL) return false;
    x = LS->next->data;
    return true;
}