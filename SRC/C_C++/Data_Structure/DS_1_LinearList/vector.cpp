// 顺序表

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int Type;

#define COLOR(a,b) "\033[" #b "m" a "\033[0m" //绿色的定义
#define GREEN(a) COLOR(a,32)

typedef struct Vector{
    Type *data;  
    int size,length;
}Vector;

Vector *init(int n){
    Vector *v = (Vector *)malloc(sizeof(Vector));//动态开辟空间，向内存堆区（很大，栈区只有8MB）
    //动态申请的空间必须主动释放，free（地址）
    v->data = (int *)malloc(sizeof(int)* n);
    v->size = n;
    v->length = 0;
    return v;
}

int expand(Vector *v){
// malloc只是申请空间，对空间里面的不考虑
// calloc申请空间,初始化,主动清空
// realloc重新分配空间
    // v->data = (int *)realloc(v->data,sizeof(int)*(v->size*2));
	// v->size = 2*(v->size);
	//上述的开辟没有考虑开辟失败
	int extr_size = v->size;
	int *p;
	while(extr_size){
		p = (int *)realloc(v->data,sizeof(int)*(v->size + extr_size));
		if(p!=NULL) break;
		extr_size *= 2;
	}
	if(p==NULL) return 0;//开辟失败
	v->data = p;
	v->size += extr_size;
	return 1; 
}

void clear(Vector *v){
    if(v==NULL) return ;
    free(v->data);
    free(v);
    return ;
}

int insert(Vector *v,int ind,int val){
    if(v==NULL) return 0;//初始化失败的时候
    if(v->length == v->size) {
        // return 0;//存满了不开拓
        if(!expand(v)) return 0;
        printf(GREEN("Sucess to expand! The size = %d\n"),v->size);
    }  
    if(ind<0||ind>v->length) return 0;//数组越界的情况
    for(int i=v->length;i>ind;i--){//从前往后会覆盖
        v->data[i] = v->data[i-1];
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

int erase(Vector *v,int ind){
    if(v==NULL) return 0;
    if(ind<0||ind>=v->length) return 0;
    for(int i=ind+1;i<v->length;i++){
        v->data[i-1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

void output(Vector *v){
    if(v==NULL) return ;
    printf("Vector : [");
    for(int i = 0;i<v->length;i++){
        i&&printf(" ");//i与上printf,i不是第一个元素就输出一个空格
        printf("%d",v->data[i]);
    }
    printf("]\n");
    return ;
}

int main(){
    srand(time(0));//随机种子
    #define MAX_OP 20
    Vector *v = init(1); //expand扩容
    for(int i = 0;i<MAX_OP;i++){
        int op = rand()%4;
        int val = rand()%100;
        int ind = rand()%(v->length + 3)-1;//[-1,v->length+1]
        switch (op){
            case 0:
			case 1:
			case 2:{
                printf("insert %d at %d to Vector = %d\n",val,ind,insert(v,ind,val));
            }break;
            case 3:{
                printf("erase a iterm at %d from Vector = %d\n",ind,erase(v,ind));
            }break;
        }
        output(v),printf("\n");
    }
    #undef MAX_OP
    clear(v);
    return 0;
}