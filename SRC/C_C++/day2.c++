#include<iostream>
#include<vector>
using namespace std;

// int max(int num1,int num2){//函数声明中，参数名不重要，重要的是类型
//     int res;
//     res = num1>num2?num1:num2;
//     return res;
// }

// int main(void){
//     int res;
//     res = max(5,12);
//     cout<<"Max value is :"<<res<<endl;
//     return 0;
// }

class test{
public:
    void hello() {
        cout << "test hello!\n";
    };
    void lambda() {
        auto fun = [this]{ // 捕获了 this 指针
            this->hello(); // 这里 this 调用的就是 class test 的对象了
        };
        fun();
    }
};

int main(){
    int i=1024,j = 2048;
    //什么也不捕获
    // auto func=[=]{//[=]标明将外部所有变量拷贝一份到Lambda函数内部
    //     cout<<i;
    // };
    // func();

    //引用捕获
    // cout<<&i<<endl;
    // auto func1=[&]{
    //     cout<<&i<<endl;
    // };
    // func1();

    //复制并引用捕获
    // cout << "i:" << &i << endl;
    // cout << "j:" << &j << endl;
    // auto fun1 = [=, &i]{ // 默认拷贝外部所有变量，但引用变量 i
    //     cout << "i:" << &i << endl;
    //     cout << "j:" << &j << endl;
    // };
    // fun1();

    //指定引用或复制
    // cout << "outside i value:" << i << " addr:" << &i << endl;
 
    // auto fun1 = [i]{
    //     cout << "inside i value:" << i << " addr:" << &i << endl;
    //     // cout << j << endl; // j 未捕获
    // };
    // fun1();

    //捕获this指针
    test t;
    t.lambda();

// []：默认不捕获任何变量；
// [=]：默认以值捕获所有变量；
// [&]：默认以引用捕获所有变量；
// [x]：仅以值捕获x，其它变量不捕获；
// [&x]：仅以引用捕获x，其它变量不捕获；
// [=, &x]：默认以值捕获所有变量，但是x是例外，通过引用捕获；
// [&, x]：默认以引用捕获所有变量，但是x是例外，通过值捕获；
// [this]：通过引用捕获当前对象（其实是复制指针）；
// [*this]：通过传值方式捕获当前对象

}