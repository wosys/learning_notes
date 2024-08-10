#include<stdio.h>
#include<stdlib.h>

//直接插入排序
void InsertSort(int A[],int n){
    int i,j;
    for(i=2;i<=n;i++){//依次将A[2]~A[n]插入到前面已经排列的序列
        if(A[i]<A[i-1]){//若A[i]关键码小于前驱，将A[i]插入有序表
            A[0]=A[i];//复制为哨兵，A[0]不存放元素
            for(j=i-1;A[0]<A[j];--j){//先后挪
                A[j+1]=A[0];//复制到插入位置
            }
        }
    }
}


//冒泡排序（交换排序）
void BubbleSort(int A[],int n){
    int i,j,temp;
    bool flag;
    for(i=0;i<n-1;i++){
        flag=false;//表示本趟冒泡是否发生交换的标志
        for(j=n-1;j>i;j--){//一趟冒泡排序
            if(A[j-1]>A[j]){//若为逆序
                temp = A[j-1];
                A[j-1]=A[j];
                A[j]=temp;//交换
                // swap(A[j-1],A[j]);
                flag=true;
            }
        }
    if(flag=false)
        return;//本趟遍历后没有发生交换，说明表已经有序
    }
}

#define n 10
int *B = (int *)malloc((n+1)*sizeof(int)); //辅助数组
// Merge()的功能是将前后相邻的两个有序表归并为一个有序表。
// 设两段有序表A[1..mid]、A[mid+1..high]存放在同一顺序表中的相邻位置，先将它们复制到辅助数组B中。
// 每次从对应B中的两个段取出一个记录进行关键字的比较，将较小者放入A中，当数组B中有一段的下标超出其对应的表长(即该段的所有元素都已复制到A中)时
// 将另一段中的剩余部分直接复制到A中

//2路归并排序
void Merge(int A[],int low,int mid,int high){
    //表A的两段A[1ow..mid]和A[mid+1..high]各自有序，将它们合并成一个有序表
    int i=low,j=mid+1,k;
    for(int k=low;k<=high;k++)
        B[k] = A[k];//将A中所有元素复制到B中
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(B[i]<B[j])//比较B的左右两段大小
            A[k]=B[i++];//将较小值复制到A中
        else
            A[k]=B[j++];
    }
    while(i<=mid) A[k++]=B[i++];//若第一个表未检测完，复制
    while(j<=high) A[k++]=B[j++];//若第二个表未检测完，复制，这两个while只会执行一个
}

void MergeSort(int A[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;//从中间划分两个子序列
        MergeSort(A,low,mid);//对左侧子序列进行递归排序
        MergeSort(A,mid+1,high);//对右侧子序列进行递归排序
        Merge(A,low,mid,high);//归并
    }
}