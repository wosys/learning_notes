#include<iostream>

using namespace std;//告诉编译器使用 std 命名空间。命名空间是 C++ 中一个相对新的概念。
//区分大小写

#define MAX 1000

const int MIN=0;

extern int d = 3, f = 5;
// extern 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。当您使用 'extern' 时，对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置。
// 当您有多个文件且定义了一个可以在其他文件中使用的全局变量或函数时，可以在其他文件中使用 extern 来得到已定义的变量或函数的引用。
// 可以这么理解，extern 是用来在另一个文件中声明一个全局变量或函数。
// extern 修饰符通常用于当有两个或多个文件共享相同的全局变量或函数的时候
static int count = 10;
// static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。
// 因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。

// static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。
// 函数定义
void func( void )
{
    static int i = 5; // 局部静态变量
    i++;
    cout << "变量 i 为 " << i ;
    cout << " , 变量 count 为 " << count << std::endl;
}

int main(){
    typedef int feet;
    feet distance=5;

    // 局部变量的值会覆盖全局变量的值
    
    int d=6,f=5;
    char x='x';
    cout<<"Ready to systematically learning C++"<<endl;
    cout<<"Ready to systematically learning C++\n";//等价上一个
    cout<<d<<endl;//输出变量

//  整数常量可以是十进制、八进制或十六进制的常量。前缀指定基数：0x 或 0X 表示十六进制，0 表示八进制，不带前缀则默认表示十进制。
//  整数常量也可以带一个后缀，后缀是 U 和 L 的组合，U 表示无符号整数（unsigned），L 表示长整数（long）。后缀可以是大写，也可以是小写，U 和 L 的顺序任意。
    string greeting = "hello, c++\n";
    cout << greeting;


// static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。
// static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。
// 在 C++ 中，当 static 用在类数据成员上时，会导致仅有一个该成员的副本被类的所有对象共享。

    while(count--)
    {
       func();
    }

// .（点）和 ->（箭头）	成员运算符用于引用类、结构和共用体的成员。
// 指针运算符 & 返回变量的地址。例如 &a; 将给出变量的实际地址。
    return 0;  //终止 main()函数，并向调用进程返回值 0。
}