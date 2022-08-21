#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100 //顺序栈储存空间的初始分配量
#define SIZEINCREMENT 10

typedef int SelemType;
typedef int Status;

typedef struct{ //顺序栈的定义
	SelemType *base; //栈底指针 
	SelemType *top; //栈顶指针 
	int stacksize; //栈可用的最大容量 
}sqstack;

Status initstack(sqstack &S){
	//构造一个空栈S
	S.base=(SelemType *)malloc(MAXSIZE*sizeof(SelemType));
	if(!S.base)  exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return 1;
}

Status Push(sqstack &S,SelemType e){
	//插入元素e为新的栈顶元素
	if(S.top-S.base>=S.stacksize){
	 S.base=(SelemType *)realloc(S.base,(S.stacksize+SIZEINCREMENT)*sizeof(SelemType));
	 if(!S.base) return -1;
	 S.top=S.base+S.stacksize;
	 S.stacksize+=SIZEINCREMENT;
	}
	*S.top++=e;
	return 1; 
}

Status Pop(sqstack &S, SelemType &e){
	//删除S的栈顶元素，用e返回其值
	if(S.top==S.base) 
		return -1;
	e=*--S.top;
	printf("删除的栈顶元素是：%d\n",e);
	return 1;  
}

Status Gettop(sqstack S){
	//返回S的栈顶元素，不修改栈顶指针
	if(S.top!=S.base)
	printf("栈顶元素是：%d\n",*(S.top-1));
	return 1;
} 

Status show_stack(sqstack &S){
	SelemType *i;
	if(S.top==S.base) return -1;
	for (i=S.base;i<S.top;i++){
		printf("%d ",*i);
	}
return 1;
}

int main(void){
	int i,m,flag;
	SelemType e;
	printf("请输入顺序栈中元素的个数\n");
	scanf("%d",&m);
	sqstack S;
	initstack(S);
	for (flag = 0,i=1; flag<m; flag++,i=i+3){
		Push(S,i);
}
printf("栈中元素是：\n");
show_stack(S);
printf("\n");
Gettop(S);
Pop(S,e);
printf("此时的栈顶元素是\n");
Gettop(S);
}

