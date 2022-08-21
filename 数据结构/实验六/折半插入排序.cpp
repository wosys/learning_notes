#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
 
typedef struct{
	char name[5];  //姓名 
	int score;   //成绩
}record;
 
typedef struct{
	record rec[MAXSIZE+1]; //包含MAXSIZE+1个记录,记录0是哨兵,相当于tmp 
	int length;           //顺序表的长度 
}sqList;
 
int main(){
	sqList L; 
	L.length = MAXSIZE; 
	for(int i = 1;i<=L.length;i++){
		printf("请输入第%d个学生的姓名:",i);
		scanf("%s",&L.rec[i].name);
		L.rec[i].score = 1+rand()%100;		 
	}		
	printf("给这些录入的学生随机生成成绩\n结果如下：\n");
	//输出排序前的记录
	for(int i = 1;i<=L.length;i++)
		printf("record %2d:name =%5s  score = %2d\n",i,L.rec[i].name,L.rec[i].score);
			
	//折半插入排序;关键字排序,i从第2个记录开始比较 
	for(int i = 2;i<=L.length;i++){
		int low = 1,mid,high = i-1;
		L.rec[0] = L.rec[i];         //将L.rec[i]暂存到L.rec[0]
		while(low<=high){			//折半查找待插入的位置; 
			mid = (low + high)/2;  //折半  
			if(L.rec[mid].score<L.rec[0].score)
				low = mid + 1;   //插入点在高半区 
			else 
				high = mid - 1; //插入点在低半区 
		}//退出while循环时high之后的单元为待插入的单元 
		for(int j = i-1;j>=low;--j)    //或者将low换成high+1 
			L.rec[j+1] = L.rec[j];//记录后移
		L.rec[low] = L.rec[0];        //插入或者将low换成high+1 
	} 
	//输出排序后的记录 
	printf("\n------>折半插入排序后<------\n");
	for(int i = L.length,j=1;i>=1,j<=L.length;i--,j++)
		printf("名次 %2d:name =%5s  score = %2d \n",j,L.rec[i].name,L.rec[i].score);	
} 
