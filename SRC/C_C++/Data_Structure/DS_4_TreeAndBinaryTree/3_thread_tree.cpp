#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NORMAL 0
#define THREAD 1

typedef struct Node{
    int data;
    struct Node *lchild,*rchild;
    int ltag,rtag;
}Node;

Node *getNewNode(int val){
    Node *p =(Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = NULL;
    p->rchild = NULL;
    p->ltag = NORMAL;
    p->rtag = NORMAL;
    return p;
}

Node *insert(Node *root,int val){
    if(root == NULL) return getNewNode(val);
    if(root->data == val) return root;
    if(val < root->data) root->lchild = insert(root->lchild,val);
    else root->rchild = insert(root->rchild,val);
    return root;
}

void build_thread(Node *root){
    if(root==NULL) return ;
    static Node *pre = NULL;//静态的变量，前驱
    build_thread(root->lchild);
    if(root->lchild==NULL){//左子树为空，建立前驱线索
        root->lchild = pre;
        root->ltag = THREAD;//加上线索
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=root;//建立前驱结点的后继线索
        pre->rtag = THREAD;
    }
    pre = root;
    build_thread(root->rchild);
    return ;
}

Node *most_left(Node *p){//从当前根节点一直往左走
    //当前结点不为空，它的左孩子不是线索，左孩子也不为空，就一直往左走
    while(p!=NULL && p->ltag == NORMAL && p->lchild!=NULL) p=p->lchild;
    return p;
}

void output(Node *root){//中序，第一个读取最左结点
    Node *p = most_left(root);
    while(p!=NULL){
        printf("%d ",p->data);
        if(p->rtag==THREAD){//当前结点的rtag是线索的话
            p=p->rchild;//沿着线索走
        }else{//不是结点，是一个正常的右孩子
            p=most_left(p->rchild);
        }
    }
    return ;
}

void in_order(Node *root){//中序遍历
    if(root == NULL) return ;
    if(root->ltag == NORMAL) in_order(root->lchild);
    printf("%d ",root->data);
    if(root->rtag == NORMAL) in_order(root->rchild);
    return ;
}

void clear(Node *root){
    if(root==NULL) return ;
    if(root->ltag == NORMAL) clear(root->lchild);
    if(root->rtag == NORMAL) clear(root->rchild);
    free(root);//最后释放当前根结点
    return ;
}

int main(){
    srand(time(0));
    #define MAX_OP 20
    Node *root = NULL;//初始化一个根结点
    for(int i=0;i<MAX_OP;i++){
        int val=rand()%100;
        root=insert(root,val);//插入元素
    }
    build_thread(root);//给当前的树添加线索

    output(root),printf("\n");//线索化遍历，速度块
    in_order(root),printf("\n");//递归遍历
    clear(root);
    #undef MAX_OP
    return 0;
}