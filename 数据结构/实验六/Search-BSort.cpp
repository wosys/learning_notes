#include <iostream.h>
#include <iomanip.h>
#define N 10
struct studscore
{
	char name[10];
	int score;
};
void BInsertSort(studscore sc[N+1]);
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
	BInsertSort(sc);
	for(i=1;i<=N;i++){
		cout<<setw(10)<<sc[i].name<<setw(6)<<sc[i].score<<'\n';
	}
}

void BInsertSort(studscore sc[N+1]) {  // 算法
  // 对数组作折半插入排序。
  int i,j,high,low,m;
  for (i=2; i<=N; ++i) {
    sc[0] = sc[i];       // 将sc[i]暂存到sc[0]
    low = 1;   high = i-1;
    while (low<=high) {    // 在sc[low..high]中折半查找有序插入的位置
      m = (low+high)/2;                            // 折半
      if (sc[0].score<sc[m].score) high = m-1;  // 插入点在低半区
      else  low = m+1;                             // 插入点在高半区
    }
    for (j=i-1; j>=high+1; --j) {
		sc[j+1]=sc[j];
	}// 记录后移
    sc[high+1]=sc[0]; // 插入
  }
} // BInsertSort
