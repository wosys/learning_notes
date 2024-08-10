#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char *str;
    struct Node *next; 
}Node;

typedef struct HashTable{
    Node **data;
    int size;
}HashTable;

Node *init_node(char *str,Node *head){//头插法
    Node *p=(Node *)malloc(sizeof(Node));
    p->str = strdup(str);//拷贝一份
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n){
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));//指向首地址
    h->size = n<<1;//扩大空间2倍，空间利用率70%就是优秀的hash表
    // h->data = (Node **)malloc(sizeof(Node *)*h->size);
    h->data = (Node **)calloc(h->size,sizeof(Node *));
    return h;
}

int BKDRHash(char *str){
    int seed=31,hash=0;
    for(int i=0;str[i];i++) hash=hash*seed+str[i];
    return hash & 0x7fffffff;//hash可能是复数，这里把他变成正数
}

int insert(HashTable *h,char *str){
    int hash = BKDRHash(str);
    int ind = hash%h->size;
    h->data[ind] = init_node(str,h->data[ind]);
   
}

int search(HashTable *h,char *str){
    int hash = BKDRHash(str);//将当前字符串映射成唯一整型值
    int ind = hash%h->size;
    Node *p = h->data[ind];
    while(p && strcmp(p->str,str)) p = p->next;
    return p!=NULL;
}

void clear_node(Node *node){
    if(node == NULL) return ;
    Node *p=node,*q;
    while(p){
        q=p->next;
        free(p->str);
        free(p);
        p=q;
    }
    return ;
}

//hash表回收
void clear(HashTable *h){
    if(h==NULL) return ;
    for(int i=0;i<h->size;i++){
        clear_node(h->data[i]);
    }
    free(h->data);
    free(h);
    return ;
}


int main(){
    int op;
    #define MAX_N 100
    char str[MAX_N+5]={0};
    HashTable *h=init_hashtable(MAX_N + 5);
    while(~scanf("%d%s",&op,str)){
        switch(op){
            case 0:
                printf("insert %s to HashTable\n",str);
                insert(h,str);
                break;
            case 1:
                printf("search %s from HashTable result = %d\n",str,search(h,str));
                break; 
        }
    }
    #undef MAX_N
    clear(h);
    return 0;
}