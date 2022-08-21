#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
struct student
{
	int id;
	char name[20];
	char sex[2];
	int age;
};
struct llist                       /* 链表结构声明      */
{
   struct student num;                        /* 数据域          */
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
      printf("[%d,%s,%s,%d]",ptr->num.id,ptr->num.name,ptr->num.sex,ptr->num.age);    /*  输出结点数据    */
	  printf("\n");
      ptr = ptr->next;            /*  指向下一结点    */
   }
   printf("\n");                  /*  换行           */
}
/*――――――――――――链表的创建――――――――――――*/
llink Initllist(llist &L)
{
   llink head;                     /*  链表的开始指针   */
   /* 建立开头结点 */
   head = ( llink ) malloc(sizeof(node));  /*  分配内存  */
   if ( !head )                       /*    检查指针      */
      return NULL;
   head->num.id=0;
   head->next=NULL;
   return head;
}
/*――――――――――――链表的结点插入―――――――――――*/
llink insertnode(llink head, student S)
{
   int i;
   int j;
   llink ptr;
   llink ptr1;
   llink mnew;                      /* 新结点指针变量    */
   mnew = ( llink ) malloc(sizeof(node));  /* 建立新结点 */
   if ( !mnew )
      return NULL;

   mnew->num = S;              /* 建立结点内容      */
   mnew->next = NULL;              /* 设定指针初值      */
   /* 如果ptr等於头节点则是插入第一个结点 */
   i=S.id;
   ptr1=head;
   ptr=head->next;
   for(j=1;j<=head->num.id;j++)
   {
	   if(ptr->num.id<i){ptr1=ptr;ptr=ptr->next;}
   }
   mnew->next=ptr1->next;
   ptr1->next=mnew;
   head->num.id++;
   return head;
}
/*――――――――――――链表的结点删除―――――――――――－*/
llink deletenode(llink head,int i)
{
   llink previous;
   llink deleteptr;
   llink ptr;
   deleteptr=head;
   previous=head;
   ptr = head->next;
   if(!ptr){printf("空表！\n");return head;};
   while(ptr->num.id!= i){
	   previous=ptr;
	   ptr = ptr->next;
       if(!ptr){
		   printf("无该学号！\n");
		   return head;
	   }
   }
   deleteptr=previous->next;
   previous->next=previous->next->next;
   free(deleteptr);
   head->num.id--;
   return head;
}
/*―――――――――――――主程序―――――――――――*/
void main()
{
   char flag;
   char flag1;
   int a;
   char b[20];
   char c[2];
   int d;
   int deleteid;
   int i;
   student s1;
   llist llist1;
   llink head;                          /* 指向链表开始      */
   head = Initllist(llist1);       /* 建立链表         */
   if ( !head )
   {
      printf("内存分配失败! \n");
      exit(1);
   }
   printf("原来的链表: ");
   printllist(head);               /* 输出原来链表      */
   printf("插入新结点?Y?N?\n");
   cin>>flag;
   while(flag=='Y'){
	   printf("输入学生信息:\n");
	   cin>>a>>b>>c>>d;
	   s1.id=a;
	   for(i=0;i<20;i++){
		   s1.name[i]=b[i];
	   }
	   for(i=0;i<2;i++){
		   s1.sex[i]=c[i];
	   }
	   s1.age=d;
	   head = insertnode(head, s1); /* 插入新结点      */
	   if ( !head )
	   {
		  printf("内存分配失败! \n");
		  exit(1);
	   }
      printf("当前的链表: ");
	   printllist(head); 
	   printf("插入新结点?Y?N?\n");
	   cin>>flag;
   }

   /* 删除链内结点 */
   printf("删除结点?Y?N?\n");
   cin>>flag1;
   while(flag1=='Y'){
	   printf("输入学号:");
	   scanf("%d",&deleteid);
	   head = deletenode(head,deleteid);
	   printf("当前的链表: ");
	   printllist(head); 
	   printf("删除结点?Y?N?\n");
	   cin>>flag1;
   }

   printf("最后的链表: ");
   printllist(head);              /*    输出结果    */
}

