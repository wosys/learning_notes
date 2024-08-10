//顺序表——动态分配的实现方式
#include <stdio.h>
#include <stdlib.h>

# define InitSize 10
typedef struct {
    int *data;//动态分配方式
    int MaxSize;//顺序表的最大容量
    int length;//顺序表当前的长度
}SeqList;

//函数声明
bool InitList(SeqList &L);                  //初始化
bool Empty(SeqList L);                      //判空
bool Full(SeqList L);                       //判满
void IncreaseSize(SeqList &L, int len);     //动态扩展空间
bool ListInsert(SeqList &L, int i, int e);  //插入
int GetElem(SeqList L, int i);              //按位查找
int LocateElem(SeqList L, int e);           //按值查找
bool ListDelete(SeqList &L, int i, int &e); //删除
void DestroySqList(SeqList &L);             //销毁

//1.初始化
bool InitList(SeqList &L){
    //c++用new
    L.data = (int *)malloc(InitSize * sizeof(int));
    //(int *) 是指针的强制类型转换
    if(L.data==NULL){
        return false;
    }
    L.length=0;
    L.MaxSize=InitSize;
    return true;
}
//2.判空
bool Empty(SeqList L){
   return (L.length == 0);
}
//3.判满
bool Full(SeqList L) {
    return (L.length >= L.MaxSize);
}
//4.拓展空间
void IncreaseSize(SeqList &L, int len){
    int *p = L.data;//注意这里为什么是定义一个指针
    L.data = (int *) malloc((InitSize + len) * sizeof(int));//重新分配内存
    //复制转移数据
    for (int i = 0; i < L.length; i++)
    {
        L.data[i]=p[i];
    }
    L.MaxSize = L.MaxSize + len;//将之前的内存空间的长度拓展
    free(p);//释放
}

//5.插入
bool ListInsert(SeqList &L, int i, int e) {
    //判断插入的位置是否合法，
    if (i < 1 || i > L.length + 1){
        return false;
    }     
    //判断表是否存满了
    // if (L.length>=L.MaxSize){
    //     return false;
    // }   
    if (Full(L)){
        return false;
    }
    //后面的元素后移
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

//6.查找
//按位查找
int GetElem(SeqList L, int i) {
    //判断是否越界
    if (i < 0 || i > L.length)
        return -1;
    return L.data[i - 1];
}
//按值查找
int LocateElem(SeqList L, int e) {
    //循环出查找
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1; //返回位序
    }
    return -1;
}

//7.删除
bool ListDelete(SeqList &L, int i, int &e) {
    //判断i的位置是否合法
    if (i < 0 || i > L.length) {
        return false;
    }
    //取出将要被删除的数
    e = L.data[i - 1];
    //将其后的数据前移
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    //线性表长度减一
    L.length--;
    return true;
}

//8.销毁
//动态分配需要手动销毁
void DestroySqList(SeqList &L){
    free(L.data);
    L.data=NULL;
    L.length=0;
}

/**测试模块**/

//测试
//打印整个顺序表
void PrintSqList(SeqList L) {
    if (L.data == NULL || L.length == 0)
        printf("这是一个空表！");
    else {
        //循环打印
        printf("开始打印顺序表\n");
        for (int i = 0; i < L.length; i++) {
            printf("Data[%d]==%d\n", i, L.data[i]);
        }
        printf("打印结束！\n");
    }
}

//测试输出
void TestPrint(bool test, char message[]) {
    if (test)
        printf("%s成功啦!\n", message);
    else
        printf("%s失败啦！\n", message);
}

void testModule() {
    SeqList L;

    TestPrint(InitList(L), "初始化");

//    初试化一些值
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    PrintSqList(L);

    //循环插入直到表满
    int i = 4;
    int InsertValue = 4;
    while (L.length < L.MaxSize) {
        TestPrint(ListInsert(L, i, InsertValue), "插入");
        i++;
        InsertValue++;
    }
    PrintSqList(L);

    //表满则扩展空间
    if (Full(L))IncreaseSize(L, 5);

    //按位查找
    printf("第5个元素是%d\n", GetElem(L, 5));

    //按值查找
    printf("值为6的元素的位序是%d\n", LocateElem(L, 6));

    //删除
    int e;
    TestPrint(ListDelete(L, 4, e), "删除");
    printf("删除的元素是%d\n", e);
    PrintSqList(L);

    //销毁
    DestroySqList(L);
    TestPrint(Empty(L), "删除");
    PrintSqList(L);
}

int main() {
    testModule();
    return 0;
}