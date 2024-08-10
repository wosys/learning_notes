#include<stdio.h>

int binary_search(int *arr,int n,int x){
    int head=0,tail=n-1,mid;
    while(head<=tail){
        mid=(head+tail)>>1;
        if(arr[mid]==x) return mid;
        if(arr[mid]<x) head=mid+1;
        else tail = mid-1;
    }
    return -1;
}

//00000001111111 找第一个1
int binary_search1(int *arr,int n){
    int head=0,tail=n,mid;//tail指向虚拟尾指针
    while(head<tail){
        mid=(head+tail)>>1;
        if(arr[mid]==1) tail=mid;
        else head=mid+1;
    }
    return head==n?-1:head;
}

//11111110000000 找最后一个1
int binary_search2(int *arr,int n){
    int head=1,tail=n-1,mid;//head指向虚拟头指针
    while(head<tail){
        mid=(head+tail+1)>>1;
        if(arr[mid]==1) head=mid;
        else tail=mid-1;
    }
    return head;
}

int main(void){
    int arr[100]={0},n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    // 1.binary_search
    // int x;
    // while(~scanf("%d",&x)){
    //     printf("%d\n",binary_search(arr,n,x));
    // }

    // 2.binary_search1
    // printf("%d",binary_search1(arr,n));

    // 3.binary_search2
    printf("%d",binary_search2(arr,n));

    return 0;
}