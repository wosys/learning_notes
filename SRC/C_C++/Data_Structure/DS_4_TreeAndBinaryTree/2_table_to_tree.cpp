#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char data;
    struct Node *lchild,*rchild;
}Node;
typedef struct Tree{
    Node *root;//指向根结点的指针变量
    int length;
}Tree;
typedef struct Stack{//栈
    Node **data;//Node *data指的是当前拥有一片连续的存储空间，**指的是每一个元素存储的内容就是一个结点的地址
    int top,size;
}Stack;

Node *getNewNode(char val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}
Tree *getNewTree(){
    Tree *tree =(Tree *)malloc(sizeof(Tree));
    tree->root=NULL;
    tree->length=0;
    return tree;
}

Stack *init_stack(int n){
    Stack *s=(Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *)*n);
    s->top = -1;
    s->size = n;
    return s;
}

Node *top(Stack *s){//打印栈顶元素
    return s->data[s->top];
}

int empty(Stack *s){
    return s->top == -1;
}

int push(Stack *s,Node *val){//入栈
    if(s==NULL) return 0;//栈不存在
    if(s->top==s->size-1) return 0;//栈满
    s->data[++(s->top)] = val;
    return 1;
}

int pop(Stack *s){
    if(s==NULL) return 0;//栈不存在
    if(empty(s)) return 0;//栈为空
    s->top -= 1;
    return 1;
}

void clear_stack(Stack *s){
    if(s==NULL) return ;
    free(s->data);//释放数据域
    free(s);//释放结点
    return ;
}

void clear_node(Node *root){
    if(root==NULL) return ;
    clear_node(root->lchild);
    clear_node(root->rchild);//递归释放左子树和右子树
    free(root);//最后释放根结点
    return ;
}

void clear_tree(Tree *tree){
    if(tree==NULL) return ;
    clear_node(tree->root);
    free(tree);
    return ;
}

void pre_order_node(Node *root){//前序遍历
    if(root == NULL) return ;
    printf("%c ",root->data);
    pre_order_node(root->lchild);
    pre_order_node(root->rchild);
    return ;
}
void pre_order(Tree *tree){
    if(tree==NULL) return ;
    printf("pre_order(%d):",tree->length);
    pre_order_node(tree->root);
    printf("\n");
    return ;
}

void in_order_node(Node *root){//中序遍历
    if(root == NULL) return ;
    in_order_node(root->lchild);
    printf("%c ",root->data);
    in_order_node(root->rchild);
    return ;
}
void in_order(Tree *tree){
    if(tree==NULL) return ;
    printf("in_order(%d):",tree->length);
    in_order_node(tree->root);
    printf("\n");
    return ;
}

void post_order_node(Node *root){//后序遍历
    if(root == NULL) return ;
    post_order_node(root->lchild);
    post_order_node(root->rchild);
    printf("%c ",root->data);
    return ;
}
void post_order(Tree *tree){
    if(tree==NULL) return ;
    printf("post_order(%d):",tree->length);
    post_order_node(tree->root);
    printf("\n");
    return ;
}

Node *build(const char *str,int *node_num){//广义表还原为二叉树
    Stack *s = init_stack(strlen(str));//暴力控制空间
    int flag=0;//记录有没有遇到逗号
    Node *temp = NULL,*p=NULL;
    while(str[0]){
        switch(str[0]){
            case '(':{
                push(s,temp);//入栈操作，当前所存好的结点入栈
                flag = 0;
            }break;
            case ')':{
                p = top(s);//记录栈顶元素
                pop(s);//弹栈
            }break;
            case ',': flag=1;break;
            case ' ': break;
            default:
                temp = getNewNode(str[0]);
                if(!empty(s)&&flag==0){
                    top(s)->lchild = temp;
                }else if(!empty(s)&&flag==1){
                    top(s)->rchild = temp;
                }
                ++(*node_num);//增加二叉树结点的num
                break;
        }
        str++;
    }
    clear_stack(s);
    if(temp&&p==NULL) p=temp;//temp不为空，p为空
    return p;
}

int main(){
    char str[1000] = {0};
    int node_num = 0;
    scanf("%[^\n]s",str);//读入带空格的字符串
    getchar();//主动吞掉上次打的空行
    Tree *tree = getNewTree();
    tree->root = build(str,&node_num);//&node_num传出参数，表示这个值是通过build（）得到的
    tree->length = node_num;
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clear_tree(tree);
    return 0;
}


// 输入广义表格式：A(B(,D),C(E))