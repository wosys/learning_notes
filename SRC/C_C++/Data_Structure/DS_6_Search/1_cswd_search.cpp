#include<stdlib.h>
#include<stdio.h>


typedef struct{
    int *elem;//元素存储空间基址，建表时按照实际长度分配，0号单元留空
    int TableLen;//表长
}SSTable;

typedef struct SeqList {
    int *elem;
    int TableLen; 
} SqList;

//一般线性表的顺序查找
int Search_Seq(SSTable ST,int key){
    int i;
    ST.elem[0] = key;//哨兵
    for(i=ST.TableLen;ST.elem[i]!=key;--i);//从后向前找
    return i;    //若不存在关键字为key的元素，将查找的i为0时退出for循环
}

//折半查找,数组版本
int Binary_Search(SeqList L,int key){
    int low=0,high=L.TableLen-1,mid;
    while(low<=high){
        mid = (low+high)/2; //中间
        if(L.elem[mid]==key){
            return mid;
        }
        else if(L.elem[mid]>key){
            high = mid-1;//在前部分找
        }
        else{
            low = mid+1;//在后部分找
        }
    }
    return -1;//查找失败
}

int BinarySearch2(SeqList *sqList,int key){
    int low = 0;
    int high = sqList->TableLen - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sqList->elem[mid] == key) {
            return mid;
        } else if (sqList->elem[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

//递归折半查询
int BinSearchRec(SSTable ST,int key,int low,int high){
    int mid;
    int low = 1,high = ST.TableLen;
    if(low<=high){
        mid=(low+high)/2;
        if(key>ST.elem[mid])
        //在后面 
            BinSearchRec(ST,key,mid+1,high);
        else if(key<ST.elem[mid])
        //在前面
            BinSearchRec(ST,key,low,mid-1);

        return mid;
    }
    else{
        return 0;
    }

}

// 线性表中各结点的检索概率不等时，可用如下策略提高顺序检索的效率：
// 若找到指定的结点，则将该结点和其前驱结点(若存在)交换，使得经常被检索的结点尽量位于表的前端。
// 试设计在顺序结构和链式结构的线性表上实现.上述策略的顺序检索算法。
int SeqSearch(SSTable ST,int key){
    int i=0;
    while ((ST.elem[i]!=key)&&(i<ST.TableLen))
    {
        i++;
    }
    if(i<ST.TableLen&&i>0){
        int temp=ST.elem[i];
        ST.elem[i]=ST.elem[i-1];
        ST.elem[i-1]=temp;
        return --i;//交换成功返回交换后的位置
    }
    else{
        return -1;
    }
    
}
