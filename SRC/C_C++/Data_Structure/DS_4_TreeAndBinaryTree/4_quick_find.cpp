#include<stdio.h>
#include<stdlib.h>

typedef struct UnionSet{
    int *color;//定义颜色数组
    int n;//容量
}UnionSet;

UnionSet *init(int n){
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->color = (int *)malloc(sizeof(int)*(n+1));
    u->n = n;
    for(int i =1;i<=n;i++){
        //初始化颜色数组
        u->color[i]=i;
    }
    return u;
}

int find(UnionSet *u,int x){
    return u->color[x];
}

int merge(UnionSet *u,int a,int b){
    if(find(u,a)==find(u,b)) return 0;
    int color_a = u->color[a]; //先记录a的color值
    for(int i=1;i<=u->n;i++){
        if(u->color[i] != color_a) continue;
        u->color[i] = u->color[b];//改为color[b]
    }
    return 1;
}

void clear(UnionSet *u){
    if(u==NULL) return ;
    free(u->color);//先清空数组域
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
