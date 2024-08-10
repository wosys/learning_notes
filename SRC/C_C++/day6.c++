#include <iostream>
#include <cstring>
#include<string>
 
using namespace std;
 
int main (){
   char str1[10] = "instagram";
   char str2[13] = "google";
   char str3[13];
   int  len;
 
   // 复制 str1 到 str3
   strcpy(str3, str1);
   cout << "strcpy( str3, str1) : " << str3 << endl;
    
   // 连接后，str1 的总长度
   len = strlen(str1);
   cout << "strlen(str1) : " << len << endl;
   
   // 连接 str1 和 str2
   strcat( str1, str2);
   cout << "strcat( str1, str2): " << str1 << endl;
   // 如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。
   cout<<strcmp(str1, str2)<<endl;

   string str="wijiao"; 
   cout<<str.size()<<endl;
   return 0;
}