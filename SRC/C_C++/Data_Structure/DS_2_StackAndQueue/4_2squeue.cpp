//循环顺序队列的第二种实现方式

#include <stdio.h>

/**定义模块**/
#define MaxSize 10

typedef struct{
    int data[MaxSize];
    int front,rear;//对头指针和队尾指针
    int size;//利用size变量记录队列长度，并用作判满的条件！有了size就不会浪费一个存储空间
} SqQueue;


//函数声明
void InitQueue(SqQueue &Q);//初始化
bool QueueEmpty(SqQueue Q);//判空
bool EnQueue(SqQueue &Q, int t);//入队操作
bool DeQueue(SqQueue &Q, int &x);//出队操作
bool GetHead(SqQueue Q, int &x);//获取队头元素,用x返回

void InitQueue(SqQueue &Q) {
    Q.rear = Q.front = 0;//初始化时，队头队尾都指向0
    Q.size = 0;//初始长度
}

bool QueueEmpty(SqQueue Q) {
    if (Q.size == 0)//有了size，条件不一样了
        return true;
    else
        return false;
}

bool EnQueue(SqQueue &Q, int t) {
    if (Q.size == MaxSize) return false;//队满，注意这里的判满条件
    Q.data[Q.rear] = t;
    Q.rear = (Q.rear + 1) % MaxSize;//通过取余操作让整个队列循环起来
    Q.size++;
    return true;
}

bool DeQueue(SqQueue &Q, int &x) {
    if (Q.size == 0) return false;//队空
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.size--;
    return true;
}

bool GetHead(SqQueue Q, int &x) {
    if (Q.size == 0)return false;
    x = Q.data[Q.front];
    return true;
}