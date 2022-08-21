#include<stdio.h>
#include<stdlib.h>

typedef struct Bnode{
	int data;//结点数据域
	Bnode *lchild,*rchild;//左右孩子指针
}Bnode,*Btree;

void insert_tree(Btree &T,int a){
//当二叉排序树T中不存在值等于a的数据元素时，则插入该元素
	Btree S;
	if(!T){//找到插入位置，递归结束
		S=new Bnode; //生成新结点*S
		S->data=a;//新结点*S的数据域置为a
		S->lchild=S->rchild=NULL;//新结点*S作为叶子结点
		T=S;	//把新结点*S链接到已找到的插入位置
	}
	else if(a<T->data)
		insert_tree(T->lchild,a);//将*S插入左子树
	else if(a>T->data)
		insert_tree(T->rchild,a);//将*S插入右子树
}

void creat_tree(Btree &T){
//依次读入一个关键字为a的结点，将此结点插入二叉排序树T中
	T=NULL;
	int a;
	scanf("%d",&a);
	while(a!=0){
		insert_tree(T,a);//将此结点插入二叉排序树T中
		scanf("%d",&a);
	}
}

Btree search(Btree T,int key){
//在根指针T所指二叉排序树中递归地查找某关键字等于key的数据元素
//若查找成功，则返回指向该数据元素结点的指针，否则返回空指针
	if((!T)||key==T->data) return T;//查找结束
	else if(key<T->data) return search(T->lchild,key);//在左子树中继续查找
	else return search(T->rchild,key);//在右子树中继续查找
}

void InOrderTraverse(Btree &T){//中序遍历 
	if(T){
	InOrderTraverse(T->lchild);
	printf("%d ",T->data);
	InOrderTraverse(T->rchild);
	}
}

int main(){
	int m;
	Btree T;
	printf("请输入若干整数，用回车区分，以0结束输入\n");
	creat_tree(T);
	printf("当前有序二叉树中序遍历结果为\n");
	InOrderTraverse(T);
	printf("\n请输入你要查找的数:");
	scanf("%d",&m);
	Btree result=search(T,m); 
	if(result)
		printf("二叉排序树中有该数");
	else
		printf("未找到");
		
}
