实验二 栈和队列、串的操作与应用
一、实验学时  4学时
二、背景知识
    1.栈:
(1).入栈和进栈操作只能从栈顶一端进行;
(2).LIFO(后进先出);
(3).栈的两种存储定义:顺序栈和链式栈。以下为顺序栈的定义
Typedef struct{
SelemType *base;
SelemType *top;
Int stacksize;
}sqstack;
2.队列:
(1).入队操作从队尾进行,出队操作从对头进行;
(2).FIFO(先进先出);
(3).队列的两种存储定义:顺序队和链队。
链队列：
Typedef struct Qnode{
QelemType data;
struct Qnode *next;
} Qnode,*Queueptr;
Typedef struct{
Queueptr front;
Queueptr rear;
}linkQueue;
顺序队列:
#define MAXQSIZE 100
Typedef struct{
Qelemtype *base;
int front;
int rear;
}sqQueue;
3.串的存储定义分为两种：
定长顺序存储
#define MAXLEN  255    //串的最大长度
typedef struct{
   char ch[MAXLEN+1];  //存储串的一维数组
   int  length;        //串的当前长度
}SString;
堆式顺序存储（动态分配）
typedef struct{
   char *ch;      //若串非空,则按串长分配存储区, 否则ch为NULL
   int  length;   //串长度
}HString;
三、目的要求
1．	掌握栈的顺序、链式表示和实现。
2．	掌握队列的顺序、链式表示和实现。
3．	掌握串的存储方式和简单模式匹配算法。
四、实验内容
1．	顺序栈/链栈和循环队列/链队列的创建、入栈（队）、出栈（队）等基本操作。
2．	顺序串的创建、插入、删除、销毁、模式匹配等基本操作。
3．	数制转换问题：试编制一段程序满足下列要求：对于输入的任意一个非负十进制整数，打印输出与其等值的d进制数。
4．	舞伴配对问题: 设置两个队列分别存放男士和女士，依次将两队当前的队头元素出队来配成舞伴，直至某队列变空为止。若某队仍有等待配对者，则输出此队列中排在队头的等待者的姓名，此人将是下一轮舞曲开始时第一个可获得舞伴的人。

说明
SqStack  顺序栈
linkStack  链栈
SqQueue  顺序队列
LinkQueue  链队列
SZZH     数制转换
WBPD     舞伴配对
MSPP     模式匹配