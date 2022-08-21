#include<stdio.h>
#include<stdlib.h> 

typedef char ElemType;
typedef char Status;
typedef struct QNode{
ElemType data;
struct QNode *next; //指针域 
}Qnode,*Queueptr;
typedef struct{
Queueptr front; //队头指针 
Queueptr rear; //队尾指针 
}LinkQueue;

Status initqueue(LinkQueue &Q){
	Q.front=Q.rear=new Qnode;
	Q.front->next=NULL;
	return 1;
}

Status EnQueue(LinkQueue &Q,ElemType e)   //入队
{
    Queueptr p;
    p=new QNode;
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;     //将新结点插入到队尾
    Q.rear=p;           //修改队尾指针
    return 1;
}
 
Status DeQueue(LinkQueue &Q,ElemType &e)    //出队
{
    Queueptr p;
    if(Q.front==Q.rear) return -1;
    p=Q.front->next;        //删除队头元素
    e=p->data;
    Q.front->next=p->next;      //修改头结点的指针域
    if(Q.rear==p) Q.rear=Q.front;   //如果最后一个元素被删，队尾指针指向头结点
    delete p;               //释放原队头元素的空间
    return 1;
}
 
Status GetHead(LinkQueue Q)
{
    if(Q.front!=Q.rear)
        return Q.front->next->data;
}

int main()
{
    LinkQueue Q;
    initqueue(Q);
    int i;
    printf("五元素入队: ");
    for(i=0;i<5;i++)
    {   
		char j;
        scanf("%c",&j);
        EnQueue(Q,j);
    }
    char k;
    DeQueue(Q,k);
    printf("出队1位：");
    printf("%c",k);
    DeQueue(Q,k);
    printf("再出队1位：");
    printf("%c",k);
    printf("取队头元素：");
    printf("%c",GetHead(Q));
    return 0;
}
