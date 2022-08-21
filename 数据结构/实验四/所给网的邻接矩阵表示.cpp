#include<stdio.h>
int matrix[6][6];//根据所给图形设出邻接数组
void creategraph(int *node,int num) {//建立图形 
   int from;//边线的起点
   int to;//边线的终点
   int i;
   for(i=0;i<num;i++) {//读取边线的回路
      from = node[i*2];//边线的起点
      to = node[i*2+1];//边线的终点
      matrix[from][to] = 1;//存入图形
   }
}
int main(){
   int node[12][2]={ {0,2}, {2,0}, //边线数组
                    {1,4}, {4,1},
                    {1,5}, {5,1},
                    {3,4}, {4,3},
                    {3,5}, {5,3},
                    {4,5}, {5,4} };
   int i,j;
   for(i=0;i<=5;i++)
      for(j=0;j<=5;j++)
	 matrix[i][j]=0;    //清除图形邻接数组
   creategraph(*node,12);       //建立图形  
   printf("图形的邻接数组内容:\n");
   for (i=0;i<=5;i++)
   {
      for (j=0;j<=5;j++)
         printf(" %d ",matrix[i][j]);//输出数组内容 
      printf("\n");
   }
}




