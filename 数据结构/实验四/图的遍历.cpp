#include<stdio.h>
#include <iostream>
#define MVNum 100//最大顶点数
#define MAXQSIZE 100//最大队列长度
using namespace std;					
bool visited[MVNum];//访问标志数组，其初值为"false" 

typedef int VertexType;//顶点类型 
typedef struct{
	VertexType vexs[MVNum];
	int arcs[MVNum][MVNum];//邻接矩阵定义 
    int vexnum,arcnum;//图的当前点数和边数 	               		
}Graph;

typedef struct{  //队列的定义 
	int *base;  //初始化的动态分配存储空间
	int front; //头指针，若队列不空，指向队头元素
	int rear; //尾指针，若队列不空，指向队尾元素的下一个位置
}sqQueue;
void InitQueue(sqQueue &Q){//构造一个空队列Q
	Q.base = new int[MAXQSIZE];
	if(!Q.base)     
		exit(1);//存储分配失败
	Q.front = Q.rear = 0;
}
void EnQueue(sqQueue &Q,int e){//插入元素e为Q的新的队尾元素
	if((Q.rear+1)%MAXQSIZE==Q.front)
		return;//队尾在循环意义上加1等于头指针，表明队满 
	Q.base[Q.rear]=e;//新元素插入队尾 
	Q.rear=(Q.rear+1)%MAXQSIZE;//队尾指针加1 
}
bool QueueEmpty(sqQueue Q){//判断是否为空队	
	if(Q.rear == Q.front)
		return true;
	return false;
}
void DeQueue(sqQueue &Q, int &u){//队头元素出队
	//删除队头元素，用u返回其值	 
	u=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
} 
 								
int LocateVex(Graph G,VertexType v){
	//确定点v在G中的位置
	for(int i=0; i<G.vexnum;++i)
		if(G.vexs[i]==v)
			return i;
		return -1;
}
int CreateUDN(Graph &G){//采用邻接矩阵表示法，创建无向网G
	int i,j,k;
	printf("请输入总顶点数，总边数，以空格隔开:");
	scanf("%d %d",&G.vexnum,&G.arcnum);	
	printf("输入点的编号\n");	
	for(i=0;i<G.vexnum;++i){
		printf("请输入第%d个点的编号:",i+1);
		scanf("%d",&G.vexs[i]);//依次输入点的信息
	}
			
	for(i=0;i<G.vexnum;++i)//初始化邻接矩阵，边的权值均置为0 
		for(j=0;j<G.vexnum;++j)   
			G.arcs[i][j]=0;  
	printf("输入边依附的顶点，如1 2\n");
		
	for(k=0;k<G.arcnum;++k){//构造邻接矩阵 
		VertexType v1,v2;
		printf("请输入第%d条边依附的顶点:",k+1);
		scanf("%d %d",&v1,&v2);	//输入一条边依附的顶点
		i=LocateVex(G,v1);  
		j=LocateVex(G,v2);//确定v1和v2在G中的位置，即顶点数组的下标 
		G.arcs[j][i]=G.arcs[i][j]=1;//置<v1, v2>的对称边<v2, v1>
	}	
}
							
void DFS(Graph G, int v){//深度优先搜素遍历        		 
	int w;
	cout<<G.vexs[v]<<"  ";  visited[v]=true;//访问第v个顶点，并置访问标志数组相应分量值为true 
	for(w=0;w<G.vexnum;w++)   //依次检查邻接矩阵v所在的行  
		if((G.arcs[v][w]!=0)&&(!visited[w]))  DFS(G, w); 
	//G.arcs[v][w]!=0表示w是v的邻接点，如果w未访问，则递归调用DFS 
}

int FirstAdjVex(Graph G,int v){
	//返回v的第一个邻接点
	int i;
	for(i=0;i<G.vexnum;++i){
		if(G.arcs[v][i]==1&&visited[i]==false)//相邻且没有被访问过的 
			return i;
	}
	return -1;//如果没有边相邻，就失败 
}
int NextAdjVex(Graph G,int v,int w){
	//返回v相对于w的下一个邻接点
	int i;
	for(i=w;i<G.vexnum;++i){
		if(G.arcs[v][i]==1&&visited[i]==false)
			return i;
	}
	return -1;
}

void BFS (Graph G,int v){//广度优先搜索遍历   
	sqQueue Q;
	int u,w;
    cout << G.vexs[v] << "  "; visited[v] = true;//访问第v个顶点，并置访问标志数组相应分量值为true 
    InitQueue(Q);              					//辅助队列Q初始化，置空         
    EnQueue(Q,v);            	               //v进队 
    while(!QueueEmpty(Q)){                    //队列非空 
		DeQueue(Q, u);       				 //队头元素出队并置为u
		for(w=FirstAdjVex(G,u); w>=0; w=NextAdjVex(G,u,w)){
			//依次检查u的所有邻接点w ，FirstAdjVex(G, u)表示u的第一个邻接点 
			//NextAdjVex(G, u, w)表示u相对于w的下一个邻接点，w≥0表示存在邻接点 
			if(!visited[w]){	           		//w为u的尚未访问的邻接顶点 
				cout<<G.vexs[w]<<"  "; visited[w] = true;	//访问w，并置访问标志数组相应分量值为true 
				EnQueue(Q, w); //w进队
			}
		}
    } 
}

int main(){
	Graph G;
	VertexType c;
	int i,j,tp;
	printf("************邻接矩阵表示法中图的遍历************\n\n" );
	CreateUDN(G);
	printf("无向图G创建完成！邻接矩阵表示如下：\n");
	for (i=0;i<G.vexnum;i++){
      for (j=0;j<G.vexnum;j++)
         printf(" %d ",G.arcs[i][j]);//输出数组内容 
      printf("\n");
   }
	printf("请输入遍历无向图G的起始点编号:");	
	scanf("%d",&c);
	 
	for(i=0;i<G.vexnum;++i){
		if(c==G.vexs[i])
			break;//返回i 
	}
	while(i>=G.vexnum){
		printf("该点不存在，请重新输入！\n");
		printf("请输入遍历连通图的起始点编号：") ;
		scanf("%d",&c);
		for(i=0;i<G.vexnum;++i){
			if(c==G.vexs[i])
				break;//返回i 
		}
	}
	tp=i;
	printf("深度优先搜索遍历无向图G结果：\n");
	DFS(G,i);
	printf("\n广度优先搜索遍历无向图G结果:\n");
	for(i=0;i<G.vexnum;++i)
		visited[i]=false;
	BFS(G,tp);
}



