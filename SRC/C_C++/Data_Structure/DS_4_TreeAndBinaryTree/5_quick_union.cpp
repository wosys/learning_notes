#include<stdio.h>
#include<stdlib.h>

#define swap(a,b){\
    __typeof(a) __temp = a;\
    a = b;b = __temp;\
}

typedef struct UnionSet{
    int *father,*size;//定义代表元素
    int n;//容量
}UnionSet;

UnionSet *init(int n){
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int)*(n+1));
    u->size = (int *)malloc(sizeof(int)*(n+1));
    u->n = n;
    for(int i =1;i<=n;i++){
        //初始化颜色数组
        u->father[i]=i;
        u->size[i] = 1;
    }
    return u;
}

int find(UnionSet *u,int x){//更改这里
    if(u->father[x]==x) return x;
    // return find(u,u->father[x]);
    return u->father[x] = find(u,u->father[x]);//路径压缩
}

int merge(UnionSet *u,int a,int b){//更改这里
    int fa = find(u,a),fb=find(u,b);
    if(fa == fb) return 0;
    if(u->size[fa]<u->size[fb]) swap(fa,fb);//结点包含的数量
    u->father[fb]==fa;//fb的父结点改成fa
    u->size[fa] += u->size[fb];
    return 1;
}

void clear(UnionSet *u){
    if(u==NULL) return ;
    free(u->father);//先清空数组域
    free(u->size);
    free(u);
    return ;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    UnionSet *u = init(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        switch(a){
            case 1:merge(u,b,c); break;
            case 2:printf("%s\n",find(u,b)==find(u,c)?"Yes":"No");
                break;
        }
    }
    clear(u);
    return 0;
}

//输入数据：
// 6 5
// 1 1 2
// 2 1 3
// 1 2 4
// 1 4 3
// 2 1 3

//期望输出：
// No
// Yes
