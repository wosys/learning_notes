#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    int data;
    struct Node *lchild,*rchild;
} Node;

typedef struct Tree{
    Node *root;
    int length;
} Tree;

Node *getNewNode(int val){//结点初始化
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree(){//树的初始化
    Tree *tree =(Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->length = 0;
    return tree;
}

Node *insert_node(Node *root,int val,int *flag){
    if(root==NULL) {
        *flag = 1;
        return getNewNode(val);
    }
    if(root->data == val) return root;
    if(root->data > val) root->lchild = insert_node(root->lchild,val,flag);
    else root->rchild = insert_node(root->rchild,val,flag);
    return root;
}

//二叉树的插入，二叉排序树（二叉查找树），根是中间值，左小右大
void insert(Tree *tree,int val){
    if(tree==NULL) return ;
    int flag = 0;
    tree->root = insert_node(tree->root,val,&flag);//flag作为一个传出变量
    tree->length += flag;
    return ;
}

void clear_node(Node *root){//结点销毁，传进来一个结点
    if(root==NULL) return ;
    clear_node(root->lchild);
    clear_node(root->rchild);
    free(root);
    return ;
}

void clear(Tree *tree){
    if(tree==NULL) return ;
    clear_node(tree->root);
    free(tree);
    return ;
}

void pre_order_node(Node *root){//前序遍历
    if(root == NULL) return ;
    printf("%d ",root->data);
    pre_order_node(root->lchild);
    pre_order_node(root->rchild);
    return ;
}
void pre_order(Tree *tree){
    if(tree==NULL) return ;
    printf("pre_order:");
    pre_order_node(tree->root);
    printf("\n");
    return ;
}

void in_order_node(Node *root){//中序遍历
    if(root == NULL) return ;
    in_order_node(root->lchild);
    printf("%d ",root->data);
    in_order_node(root->rchild);
    return ;
}
void in_order(Tree *tree){
    if(tree==NULL) return ;
    printf("in_order:");
    in_order_node(tree->root);
    printf("\n");
    return ;
}

void post_order_node(Node *root){//后序遍历
    if(root == NULL) return ;
    post_order_node(root->lchild);
    post_order_node(root->rchild);
    printf("%d ",root->data);
    return ;
}
void post_order(Tree *tree){
    if(tree==NULL) return ;
    printf("post_order:");
    post_order_node(tree->root);
    printf("\n");
    return ;
}

void output_node(Node *root){//二叉树广义表的转换
    if(root == NULL) return ;
    printf("%d",root->data);
    if(root->lchild==NULL && root->rchild==NULL) return ;
    printf("(");
    output_node(root->lchild);
    printf(",");
    output_node(root->rchild);
    printf(")");
    return ;
}
void output(Tree *tree){
    if(tree==NULL) return ;
    printf("tree(%d):",tree->length);//输出当前这棵树的结点数
    output_node(tree->root);//这棵二叉树转广义表
    printf("\n");
    return ;
}

int main(){
    srand(time(0));
    Tree *tree = getNewTree();
#define MAX_OP 10
    for(int i=0;i<MAX_OP;i++){
        int val = rand()%100;
        insert(tree,val);//向树中插入val
        output(tree);
    }
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clear(tree);
#undef MAX_OP
    return 0;
}

//思考二叉排序树和堆的关系