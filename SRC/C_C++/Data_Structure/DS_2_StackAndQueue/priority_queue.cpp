#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define swap(a, b)           \
    {                        \
        __typeof(a) __c = a; \
        a = b, b = __c;      \
    }

//结构定义
typedef struct priority_queue{
    int *data; 
    int cnt,size;//个数，容量
}priority_queue;

priority_queue *init(int n){//优先队列初始化
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int)*(n+1));
    q->cnt = 0;
    q->size = n;
    return q;
}

int empty(priority_queue *q){
    return q->cnt == 0;
}

int top(priority_queue *q){
    return q->data[1];//0是空的
}

int push(priority_queue *q,int val){//尾部插入
    if(q==NULL) return 0;
    if(q->cnt==q->size) return 0;//队满
    //插入一个
    // q->cnt += 1;
    // q->data[q->cnt]=val;//插入队尾

    //不断维护
    q->data[++(q->cnt)]=val;
    int ind = q->cnt;
    while(ind>>1&&q->data[ind] > q->data[ind>>1]){//当前结点上面还有元素的话，不断向上调整&&结点值大于他的父节点
        swap(q->data[ind],q->data[ind>>1]);
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *q){
    if(q==NULL) return 0;
    if(empty(q)) return 0;
    q->data[1] = q->data[q->cnt--];
    int ind=1;
    while((ind<<1)<=q->cnt){
        int temp = ind,l=ind<<1,r=ind<<1 | 1;
        if(q->data[l]>q->data[temp]) temp = l;
        if(r<=q->cnt&&q->data[r] > q->data[temp]) temp = r;
        if(temp==ind) break;
        swap(q->data[temp],q->data[ind]);
        ind = temp;
    }
    return 1;
}

void clear(priority_queue *q){
    if(q==NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main(){
    srand(time(0));
#define MAX_OP 20
    priority_queue *q = init(MAX_OP);
    for(int i=0;i<MAX_OP;i++){
        int val=rand()%100;
        push(q,val);
        printf("insert %d to the priority_queue\n",val);
    }
    for(int i=0;i<MAX_OP;i++){
        printf("%d ",top(q));
        pop(q);
    }
    printf("\n");
#undef MAX_OP
    clear(q);
    return 0;
}
