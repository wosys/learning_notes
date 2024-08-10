#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define swap(a, b)           \
    {                        \
        __typeof(a) __c = a; \
        a = b, b = __c;      \
    }

void downUpdate(int *arr,int n,int ind){
    while((ind<<1) <= n){//有左孩子的话
        int temp = ind,l=ind<<1,r=2*ind+1;//l,r左右孩子下标
        if(arr[l]>arr[temp]) temp = l;
        if(r<=n && arr[r]>arr[temp]) temp = r;//当前有右孩子，且大于，更新temp
        if(temp==ind) break;
        swap(arr[ind],arr[temp]);
        ind = temp;
    }
}
//堆排序
void heap_sort(int *arr,int n){
    arr -= 1;//第一个元素是arr[1]
    //线性建堆法，O(n)
    
    for(int i=n>>1;i>=1;i--){//i=n>>1倒数第二层
        //向下调整
        downUpdate(arr,n,i);
    }
    for(int i = n;i>1;i--){
        swap(arr[i],arr[1]);//交换堆尾元素和堆顶元素
        downUpdate(arr,i-1,1);//从根结点向下调整
    }
    return ;
}

void output(int *arr,int n){
    printf("[");
    for(int i =0;i<n;i++){
        i && printf(" ");//控制格式
        printf("%d",arr[i]);
    }
    printf("]\n");
    return ;
}

int main(){
    srand(time(0));
#define MAX_N 20
    int *arr = (int *)malloc(sizeof(int)*MAX_N);
    for(int i=0;i<MAX_N;i++){
        arr[i] = rand()%100;
    }
    output(arr,MAX_N);
    printf("\n");
    heap_sort(arr,MAX_N);
    output(arr,MAX_N);
#undef MAX_N
    free(arr);
    return 0;
}