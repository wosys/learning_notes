#include<stdio.h>
#include<stdlib.h>

typedef struct linklist {
	int num; //数据域
	struct linklist *next; //指针域
}node;
typedef node *llink; //重定义指针类型

llink creatllist(int *arry, int len) {
	llink head;
	llink ptr, ptr1;
	int i;
	head = (llink)malloc(sizeof(node));
	if (!head)
		return NULL;
	ptr = head; //将ptr指向链表开始
	for (i = 0; i < len; i++) {
		ptr1 = (llink)malloc(sizeof(node));
		if (!ptr1)
			return NULL;
		ptr1->num = arry[i]; //建立结点内容
		ptr1->next = NULL; //设定指针初值
		ptr->next = ptr1; //连接结点
		ptr = ptr->next; //指向下一结点
	}
	return head;
}

/*llink insertnode(llink head, llink ptr, int value) {
	llink newzhi;
	newzhi = (llink)malloc(sizeof(node));
	if (!newzhi)
		return NULL;
	newzhi->num = value;
	newzhi->next = NULL;
	newzhi->next = ptr->next;        
	ptr->next = newzhi;            
	return head;
}
llink Delete(llink head,llink ptr) {
	llink previous;
	previous = head;
	while (previous->next != ptr) // 找结点ptr前一结点 
		previous = previous->next;
	previous->next = ptr->next;    // 删除中间结点
	free(ptr);                     // 释放结点内存
	return head;
}*/

int Insert(llink head, int i, int e){//插入 
 	llink t,p; 	
	int j=1; 	
	t=head; 
	if(i<1){
		printf("插入错误,返回原链表：");
		return 0;
	} 	
	if(i==1){ //插入位置在表头  	
		p=(llink)malloc(sizeof(node)); 		
		p->num=e; 		
		p->next=t->next; 		
		head->next=p; 		
		//printf("插入成功\n"); 		
		return 0;	 
	} 	
	while(j<i-1&&head) { 			
		t=t->next; 			
		j++; 			
		if(t==NULL) { 				
			printf("插入错误，返回原链表："); 				
			return 0; 			
		} 	
	} 	
	//插在非表头 	
	t=t->next; 	
	p=(llink)malloc(sizeof(node)); 	
	p->num=e; 	
	p->next=t->next; 	
	t->next=p; 	
	//printf("插入成功\n");
}

int Delete(llink head, int i) {
	llink p, t;
	int j = 0;
	p = head;
	if (i < 1) {
		printf("删除失败，返回原链表：");
		return 0;
	}
	while (j < i - 1 && head) {
		p = p->next;
		j++;
		if (p == NULL) {
			printf("删除失败，返回原链表：");
			return 0;
		}
	}
	t = p->next;
	p->next = t->next;//删除成功
	free(t);
}



void outputlist(llink head) {
	llink ptr;
	ptr = head->next; //指向真正的起始
	while (ptr!= NULL) //链表遍历循环
	{
		printf("%d ", ptr->num); // 输出结点数据 
		ptr = ptr->next; //指向下一结点 
	}
	printf("\n");               

}

int main(void) {
	int list[10];
	printf("请输入10个整数:\n");
	for (int i = 0; i < 10; i++) {
		scanf("%d", &list[i]);
	}
	llink head; //指向链表开始
	head = creatllist(list, 10);
	if (!head) {
		printf("内存分配失败！\n");
		exit(1);
	}
	printf("原来的链表：");
	outputlist(head);
	printf("插入结点的链表：（在第七个位置上插入99）");
	Insert(head,7,99); //第二个参数表示在链表第几个后面插入，第三个参数是插入的值
	outputlist(head);
	Delete(head, 6);//通过修改第二个参数删除头节点后i个数
	printf("最后的链表:(删除第六个数) ");
	outputlist(head);
	/*head = insertnode(head, head->next->next, 8);
	if (!head)
	{
		printf("内存分配失败! \n");
		exit(1);
	}
	printf("插入结点的链表：");
	outputlist(head);
	head = Delete(head, head->next->next->next);
	printf("最后的链表: ");
	outputlist(head);*/

}