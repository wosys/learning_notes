实验三 二叉树的操作与应用
一、实验学时   4学时
二、背景知识
二叉树的存储定义分为两种：`
1．顺序存储结构：
   #define MAX_TREE_SIZE 100    //最大结点数
   typedef TelemType SqBiTree[MAX_TREE_SIZE];   //0号单元存储根结点
   SqBiTree bt;
2．链式存储结构:
typedef struct BiTNode             
{
TElemType data;
struct BiTNode *lchild,*rchild;   //左右孩子指针
}BiTNode,*BiTree;
三、目的要求
    1．掌握二叉树的基本概念、链式存储结构。
2．重点掌握二叉树的生成、遍历等算法。
3. 应用二叉树的链式存储求解实际问题。
四、实验内容
1．	编写程序实现二叉树的链式存储和基本操作。
2．	编写程序实现二叉树的前序遍历、中序遍历和后序遍历的算法。
3．	编写编写程序求二叉树的深度和结点的个数。
4．	利用二叉树求解表达式的值：利用栈操作创建一棵表达式对应的二叉树，利用二叉树的遍历等操作实现表达式的求值运算。
五、程序实例
二叉树中序遍历的递归算法。
#include "stdlib.h"
#include “stdio.h”
struct tree
{ int data;
struct tree *left;
struct tree *right;
};
typedef struct tree treenode;
typedef struct tree *btree;
/*---------------------插入结点----------------------*/
btree insertnode(btree root,int value)
{  btree newnode;  /* 根指针 */
 btree current;  /* 当前结点指针 */
 btree back;     /* 父结点指针 */
 /* 创建结点内存 */
 newnode=(btree)malloc(sizeof(treenode));
 newnode->data=value;
 newnode->left=NULL;
 newnode->right=NULL;
 if(root==NULL)
   {return newnode;}
 else
   {current=root;
    while(current!=NULL)
    {back=current;
     if(current->data>value)
       current=current->left;
     else
       current=current->right;
    }
   if(back->data>value)
    back->left=newnode;
  else
  back->right=newnode;
  }
return root;
}
/*------------------创建二叉树----------------*/
btree createbtree(int *data,int len)
{   btree root=NULL;
int i;
for(i=0;i<len;i++)
root=insertnode(root,data[i]);
return root;
}
/*------------------二叉树中序遍历----------------*/
void inorder(btree ptr)
{  if(ptr!=NULL)
{  inorder(ptr->left);
 printf("[%2d]\n",ptr->data);
inorder(ptr->right);
}
}
/*------------------主函数---------------------*/
void main()
{  btree root=NULL;
int data[9]={5,6,4,8,2,3,7,1,9};
root=createbtree(data,9);
printf("out put the bitree:\n");
inorder(root);
}
