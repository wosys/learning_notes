实验一 线性表的操作与应用
一、实验学时： 4学时
二、背景知识:
线性表的动态分配顺序存储结构：
＃define LIST_INIT_SIZE       100       //线性表存储空间的初始分配量
＃define LISTINCREMENT    10        //线性表存储空间的分配增量
typedef  struct{ 
    ElemType    *elem;      //存储空间基址
    int    length;          //当前长度
    int    listsize;      //当前分配的存储容量（以sizeof(ElemType)为单位)
} SqList； 
    链表的分类：带头结点的/不带头结点的（单链表、双向链表、循环链表等）
链表的基本操作：插入、删除及应用。
单链表的结点存储定义:
    typedef struct LNode          
{
ElemType data;
struct LNode *next;
}Lnode,*LinkList;
双向链表的结点存储定义:
typedef struct DuLNode             
{
ElemType data;
struct DuLNode *prior;
struct DuLNode *next;
}DuLnode,*DuLinkList;
三、目的要求：
    1．掌握顺序和链式存储结构的特点。
2．掌握顺序和链式存储结构的基本算法。
3．顺序表和链表在实际问题中的应用。
四、实验内容:
1．顺序表的元素的插入、删除、修改、输出等基本操作。
2．带/不带头结点的单链表的元素的创建、查找、插入、删除等基本操作。
3．利用线性表实现一个班级学生信息管理（数据录入、插入、删除、排序、查找等）（提示：可以采用顺序表或任何一种链表形式）
五、程序实例: 带头结点的单链表的基本操作。
#include <stdlib.h>
struct llist                       /* 链表结构声明      */
{
   int num;                        /* 数据域          */
   struct llist *next;             /* 指针域      */
};
typedef struct llist node;         /* 类型重定义   */
typedef node *llink;               /* 重定义指针类型   */
/*――――――――――――链表的输出――――――――――――*/
void printllist(llink head)
{
   llink ptr;
   ptr = head->next;              /*  指向真正的起始   */
   while ( ptr != NULL )          /*  链表遍历循环     */
   {
      printf("[%d]",ptr->num);    /*  输出结点数据    */
      ptr = ptr->next;            /*  指向下一结点    */
   }
   printf("\n");                  /*  换行           */
}
/*――――――――――――链表的创建――――――――――――*/
llink createllist(int *array,int len)
{
   llink head;                     /*  链表的开始指针   */
   llink ptr,ptr1;
   int i;
   /* 建立开头结点 */
   head = ( llink ) malloc(sizeof(node));  /*  分配内存  */
   if ( !head )                       /*    检查指针      */
      return NULL;
   ptr = head;                    /* 将ptr指向链表开始 */
   for ( i = 0; i < len; i++ )    /* 建立其它结点回路  */
   {
       ptr1 = ( llink ) malloc(sizeof(node));
       if ( !ptr1 )
          return NULL;
       ptr1->num = array[i];      /* 建立结点内容      */
       ptr1->next = NULL;         /* 设定指针初值      */
       ptr->next = ptr1;          /* 连接结点          */
       ptr = ptr->next;           /* 指向下一结点      */
   }
   return head;
}
/*――――――――――――链表的结点插入―――――――――――*/
llink insertnode(llink head,llink ptr,int value)
{
   llink mnew;                      /* 新结点指针变量    */
   mnew = ( llink ) malloc(sizeof(node));  /* 建立新结点 */
   if ( !mnew )
      return NULL;
   mnew->num = value;              /* 建立结点内容      */
   mnew->next = NULL;              /* 设定指针初值      */
   /* 如果ptr等於头节点则是插入第一个结点 */
   mnew->next = ptr->next;        /* 新结点指向下一结点 */
   ptr->next = mnew;               /* 结点ptr指向新结点 */
   return head;
}
/*――――――――――――链表的结点删除―――――――――――－*/
llink deletenode(llink head,llink ptr)
{
   llink previous;
   previous = head;
   while ( previous->next != ptr ) /* 找结点ptr前一结点 */
      previous = previous->next;
   previous->next = ptr->next;    /* 删除中间结点      */
   free(ptr);                     /* 释放结点内存   */
   return head;
}
/*―――――――――――――主程序―――――――――――*/
void main()
{
   int llist1[6] = { 1, 2, 3, 4, 5, 6 };   /*数组内容   */
   llink head;                          /* 指向链表开始      */
   head = createllist(llist1,6);       /* 建立链表         */
   if ( !head )
   {
      printf("内存分配失败! \n");
      exit(1);
   }
   printf("原来的链表: ");
   printllist(head);               /* 输出原来链表      */
   head = insertnode(head,head,0); /* 插入新结点      */
   if ( !head )
   {
      printf("内存分配失败! \n");
      exit(1);
   }
   /* 删除链内结点 */
   head = deletenode(head,head->next->next->next);
   printf("最后的链表: ");
   printllist(head);              /*    输出结果    */
}
六、注意问题及相关提示:
1.	建立线性表时也可利用随机函数自动产生数据。
2.	注意带头结点的链表和不带头结点的链表在插入时（三个位置：开始、中间、末尾）算法的不同；在删除第一个元素后的两种情况（删除后表可能为空或不空）。

说明

1．顺序表的操作
2.带头结点的单链表操作。
3．不带头结点的单链表操作。
4．学生信息管理的单链表实现

