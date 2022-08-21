#include <stdio.h>
#include <stdlib.h>
#define N 8
 
typedef struct {
	char name[5];  //姓名 
	int score;   //成绩
}stu;

int Partition(stu sc[N+1], int low, int high) {
   // 交换顺序表L中子序列sc[low..high]的记录，使枢轴记录到位，
   // 并返回其所在位置，此时，在它之前（后）的记录均不大（小）于它
   int pivotkey;
   sc[0] = sc[low];            // 用子表的第一个记录作枢轴记录
   pivotkey = sc[low].score;      // 枢轴记录关键字
   while (low<high) {            // 从表的两端交替地向中间扫描
      while (low<high && sc[high].score>=pivotkey) --high;
      sc[low] = sc[high];      // 将比枢轴记录小的记录移到低端
      while (low<high && sc[low].score<=pivotkey) ++low;
      sc[high] = sc[low];      // 将比枢轴记录大的记录移到高端
   }
   sc[low] = sc[0];            // 枢轴记录到位
   return low;                   // 返回枢轴位置
}

void QSort(stu sc[N+1], int low, int high) {
  //对顺序表L中的子序列L.r[low..high]进行快速排序
  int pivotloc;
  if (low < high) {                      // 长度大于1
    pivotloc = Partition(sc, low, high);  // 将sc[low..high]一分为二
    QSort(sc, low, pivotloc-1);  //对低子表递归排序，pivotloc是枢轴位置
    QSort(sc, pivotloc+1, high);          // 对高子表递归排序
  }
} 

int main(){
	stu sc[N+1];//记录0是哨兵,相当于tmp  
	for(int i = 1;i<=N;i++){
		printf("请输入第%d个学生的姓名:",i);
		scanf("%s",&sc[i].name);
		sc[i].score = 1+rand()%100;		 
	}		
	printf("给这些录入的学生随机生成成绩\n结果如下：\n");
	for(int i = 1;i<=N;i++)
		printf("record %2d:name =%5s  score = %2d\n",i,sc[i].name,sc[i].score);
	QSort(sc,1,N);//快速排序 
	printf("\n------>快速排序后<------\n");
	for(int i = N,j=1;i>=1,j<=N;i--,j++)
		printf("名次 %2d:name =%5s  score = %2d \n",j,sc[i].name,sc[i].score);	
} 
