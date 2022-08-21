#include <stdio.h>
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
int insertnode(llink &head,llink ptr,int value)
{
   llink mnew;                      /* 新结点指针变量    */
   mnew = ( llink ) malloc(sizeof(node));  /* 建立新结点 */
   if ( !mnew )
      return 0;
   mnew->num = value;              /* 建立结点内容      */
   mnew->next = NULL;              /* 设定指针初值      */
   /* 如果ptr等於头节点则是插入第一个结点 */
   mnew->next = ptr->next;        /* 新结点指向下一结点 */
   ptr->next = mnew;               /* 结点ptr指向新结点 */
   return 1;
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
  
   if ( !insertnode(head,head,0) )
   {
      printf("内存分配失败! \n");
      exit(1);
   }
   /* 删除链内结点 */
   head = deletenode(head,head->next->next->next);
   printf("最后的链表: ");
   printllist(head);              /*    输出结果    */
}


