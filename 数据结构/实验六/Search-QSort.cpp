#include <iostream.h>
#include <iomanip.h>
#define N 10
struct studscore
{
	char name[10];
	int score;
};
void QSort(studscore sc[N+1], int low, int high);

void main()
{
	char a[10];
	int b;
	studscore sc[N+1];
	cout<<"请输入"<<N<<"个学生的姓名及成绩："<<'\n';
	for (int i=1;i<=N;i++){
		cin>>a>>b;
		for(int j=0;j<10;j++){
		   sc[i].name[j]=a[j];
	   }
		sc[i].score=b;
	}
	cout<<"对输入的"<<N<<"个学生按分数从高到低排序："<<'\n';
	QSort(sc,1,N);
	for(i=1;i<=N;i++){
		cout<<setw(10)<<sc[i].name<<setw(6)<<sc[i].score<<'\n';
	}
}
int Partition(studscore sc[N+1], int low, int high) {  // 算法
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
} // Partition
void QSort(studscore sc[N+1], int low, int high) {  //算法
  // 对顺序表L中的子序列L.r[low..high]进行快速排序
  int pivotloc;
  if (low < high) {                      // 长度大于1
    pivotloc = Partition(sc, low, high);  // 将sc[low..high]一分为二
    QSort(sc, low, pivotloc-1); // 对低子表递归排序，pivotloc是枢轴位置
    QSort(sc, pivotloc+1, high);          // 对高子表递归排序
  }
} // QSort

