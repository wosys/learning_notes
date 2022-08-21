#include<stdio.h>
#include<stdlib.h>

typedef int SelemType;
typedef int Status;

typedef struct sqstack{ 
	SelemType data; 
    struct sqstack *next;
}sqstack,*LinkStack;

Status initstack(LinkStack &S){
	//构造一个空栈S,栈顶指针置空
	S = NULL;
	return 1;
}

Status Push(LinkStack &S,SelemType e){
	//插入元素e为新的栈顶元素
	LinkStack p;
	p = new sqstack; //生成新结点
	p->data = e; //将新结点数据域置为e
	p->next = S; //将新结点插入栈顶
	S = p; //修改栈顶指针为p
	return e; 
}

Status Pop(LinkStack &S,SelemType &e){
	//删除S的栈顶元素，用e返回其值
	LinkStack p;
	if (S == NULL)
		return 0; //栈空
	e = S->data; //将栈顶元素赋给e
	p = S; //用p临时保存栈顶元素空间，以备释放
	S = S->next; //修改栈顶指针
	delete p; //释放原栈顶元素的空间
	//printf("删除的栈顶元素是：%d\n",e);
	return 1;  
}

Status Gettop(LinkStack S){
	//返回S的栈顶元素，不修改栈顶指针
	if (S != NULL) //栈非空
		return S->data; //返回栈顶元素的值，栈顶指针不变
	printf("栈顶元素是：%d\n",S->next->data);
	return 1;
} 

/*Status show_stack(sqstack &S){
	SelemType *i;
	if(S.top==S.base) return -1;
	for (i=S.base;i<S.top;i++){
		printf("%d ",*i);
	}
return 1;
}*/ 

int main(){
	int i,m,flag;
	SelemType e;
	printf("请输入链栈中元素的个数\n"); 
	scanf("%d",&m);
	LinkStack S;
	initstack(S);
	printf("栈中元素是：\n");
	for (flag = 0,i=1; flag<m; flag++,i=i+3){
		printf("%d ",Push(S,i));
}

//show_stack(S);
printf("\n");
printf("栈顶元素是：%d",Gettop(S));
Pop(S,e);
printf("\n");
printf("删除栈顶元素后现在的栈顶元素是：%d",Gettop(S));
}

