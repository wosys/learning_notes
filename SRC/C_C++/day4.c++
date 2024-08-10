#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#include<iomanip>
using std::setw;

int main(){
    // int n[10];
    // int a[3][4]={
    //     {0,1,2,3},
    //     {4,5,6,7},
    //     {8,9,10,11}
    // };//等价于int a[3][4]={0,1,2,3,4,5,6,7,8,9,10,11}
    // for(int i=0;i<10;i++){
    //     n[i]=i+100;
    // }
    // cout<<"Element"<<setw(13)<<"Value"<<endl;
    // // 输出数组中每个元素的值                     
    // for ( int j = 0; j < 10; j++ )
    // {
    //     cout << setw( 7 )<< j << setw( 13 ) << n[ j ] << endl;
    // }
 
    //使用二维数组输入并输出
    vector<vector<int>> arry;
    vector<int> d;//定义一个一维的数组
    int i, j, n;
    int number;
    cin>>n;
     /*可以这样实现对vector二维的初始化，得到的是n行n列的矩阵*/ 
    for( i=0; i<n; i++ ){ 
        for( j=0; j<n; j++ ){
            cin>>number;
            d.push_back(number); 
        }
        sort(d.begin(), d.end()); //排序头文件algorithm 
        arry.push_back( d );
        //d.clear();        //清空一维的数组 
        d.resize(0);
    }
    if(arry.empty())
        printf("0\n");
    else{
        for( i=0; i<arry.size(); i++ ) {
            for( j=0; j<arry[0].size(3); j++ ){
                // printf("%d ", arry[i][j] );
                cout<<arry[i][j]<<" ";
            }
            printf("\n");
        }
    } 
    return 0;
}