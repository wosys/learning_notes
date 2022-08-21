#include<stdio.h>
#include<stdlib.h> 
#define MAXQSIZE 100

typedef char QElemType;
typedef char SElemType;
typedef int Status;

typedef struct {
	QElemType *base;//初始化时动态分配存储空间
	int front;//头指针
	int rear;//尾指针
} SqQueue;

//循环队列的初始化
Status InitQueue(SqQueue &Q) {//构造一个空队列Q
	Q.base = new QElemType[MAXQSIZE]; //为队列分配一个最大容量为MAXSIZE的数组空间
	if (!Q.base)
		exit(-2); //存储分配失败
	Q.front = Q.rear = 0; //头指针和尾指针置为零，队列为空
	return 1;
}

//求循环队列的长度
int QueueLength(SqQueue Q) {//返回Q的元素个数，即队列的长度
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//循环队列的入队
Status EnQueue(SqQueue &Q, QElemType e) {//插入元素e为Q的新的队尾元素
	if ((Q.rear + 1) % MAXQSIZE == Q.front) //尾指针在循环意义上加1后等于头指针，表明队满
		return 0;
	Q.base[Q.rear] = e; //新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE; //队尾指针加1
	return 1;
}

//循环队列的出队
Status DeQueue(SqQueue &Q, QElemType &e) {//删除Q的队头元素，用e返回其值
	if (Q.front == Q.rear)
		return 0; //队空
	e = Q.base[Q.front]; //保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE; //队头指针加1
	return 1;
}

//取循环队列的队头元素
SElemType GetHead(SqQueue Q) {//返回Q的队头元素，不修改队头指针
	if (Q.front != Q.rear) //队列非空
		return Q.base[Q.front]; //返回队头元素的值，队头指针不变
}

int main(){
	SqQueue Q;
	int i;
	InitQueue(Q);
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
