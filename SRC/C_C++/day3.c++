#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main(void){
    // 数字定义
    short  s = 10;
    int    i = -1000;
    long   l = 100000;
    float  f = 230.47;
    double d = 200.374;

    // 数学运算
    cout << "sin(d) :" << sin(d) << endl;
    cout << "abs(i)  :" << abs(i) << endl;
    cout << "floor(d) :" << floor(d) << endl;
    cout << "sqrt(f) :" << sqrt(f) << endl;
    cout << "pow(d,2) :" << pow(d, 2) << endl;

    int a,b;
    //设置种子
    srand((unsigned)time(NULL));

    //生成10个随机数
    for(i=0;i<10;i++){
        b=rand()%100;//100之内
        cout<<"随机数："<<b<<endl;
    }

    return 0;
}