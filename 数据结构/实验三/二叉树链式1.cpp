#include<stdlib.h>
#include<stdio.h>
typedef struct tree
{ 
int data;
struct tree *left;
struct tree *right;
}treenode,*btree;
/*---------------------插入结点----------------------*/
btree insertnode(btree root,int value){  
 btree newnode;  /* 根指针 */
 btree current;  /* 当前结点指针 */
 btree back;     /* 父结点指针 */
 /* 创建结点内存 */
 newnode=(btree)malloc(sizeof(treenode)); 
 newnode->data=value;
 newnode->left=NULL;
 newnode->right=NULL;
 if(root==NULL)//如果根结点为空，就返回新插入的结点 
   {
    return newnode;
   }
 else//根节点不为空的情况下 
   {
    current=root;
    while(current!=NULL)
    {
	 back=current;
     if(current->data>value)//比较值的大小，如果大就在左，如果小就在右 
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
{   
btree root=NULL;
int i;
for(i=0;i<len;i++)
root=insertnode(root,data[i]);
return root;
}
/*------------------二叉树中序遍历----------------*/
void inorder(btree ptr)
{  
if(ptr!=NULL){  
 inorder(ptr->left);
 printf("[%2d]\n",ptr->data);
 inorder(ptr->right);}
}
/*------------------主函数---------------------*/
int main()
{  
btree root=NULL;
int data[9]={5,6,4,8,2,3,1,7,9};
root=createbtree(data,9);
printf("输出这颗树:\n");
inorder(root);
printf("\n\n插入一个值为-5的结点：\n");
insertnode(root,-5);
inorder(root);
}

