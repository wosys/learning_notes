//顺序串的基本操作
#include<iostream>
#include<string.h>
using namespace std;
#define max 50
typedef struct
{
	char data[max];
	int length;
}sqstring;
void display(sqstring s)//输出串
{
	int i;
	if(s.length>0)
		for(i=0;i<s.length;i++)
			cout<<s.data[i]<<" ";
		cout<<endl;
}
sqstring rep(sqstring s,int i,int j,sqstring t)//子串的替换
{
	int k;
	sqstring str;
	str.length=0;
	if(i<=0||i>s.length||i+j-1>s.length)
		return str;
	for(k=0;k<i-1;k++)
		str.data[k]=s.data[k];
	for(k=0;k<t.length;k++)
		str.data[i+k-1]=t.data[k];
	for(k=i+j-1;k<s.length;k++)
		str.data[t.length+k-j]=s.data[k];
	str.length=s.length-j+t.length;
	return str;
}
sqstring strdelete(sqstring s,int i,int j)//子串的删除
{
	int k;
	sqstring str;
	str.length=0;
	if(i<=0||i>s.length||i+j>s.length+1||j<0)
		return str;
	for(k=0;k<i-1;k++)
		str.data[k]=s.data[k];
	for(k=i+j-1;k<s.length;k++)
		str.data[k-j]=s.data[k];
	str.length=s.length-j;
	return str;
}
sqstring inset(sqstring s1,int i,sqstring s2)//串的插入
{
	int j;
	sqstring str;
	str.length=0;
	if(i<=0||i>s1.length+1)
		return str;
	for(j=0;j<i-1;j++)
		str.data[j]=s1.data[j];
	for(j=0;j<s2.length;j++)
		str.data[i+j-1]=s2.data[j];
	for(j=i-1;j<s1.length;j++)
		str.data[s2.length+j]=s1.data[j];
	str.length=s1.length+s2.length;
	return str;
}
int BF(sqstring s,sqstring t,int pos)//在串s里找第一个串t，并返回串t的第一个元素的下标
{   
	int i = pos;//初始化 
    int j = 1;
	int lens = s.length;
    int lensub = t.length;
    if(pos<0||pos>s.length)
        return -1;
    while (i <= lens && j <= lensub)//两个串均为比较到末尾 
    {
        if (s.data[i] == t.data[j])
        {
            ++i;
            ++j;//继续比较后继字符 
        }
        else//指针后退重新开始匹配 
        {
            i = i - j + 2;
            j = 1;
        }
	}
    if (j > t.length) return i-t.length;
    else return 0;
}
sqstring sub(sqstring s,int i,int j)//求子串
{
	int k;
	sqstring str;
	str.length=0;
	if(i<=0||i>s.length||j<0||i+j-1>s.length)
		return str;
	for(k=i-1;k<i+j-1;k++)
		str.data[k-i+1]=s.data[k];
	str.length=j;
	return str;
}
sqstring concat(sqstring s,sqstring t)//串的链接
{
	sqstring str;
	int i;
	str.length=s.length+t.length;
	for(i=0;i<s.length;i++)
		str.data[i]=s.data[i];
	for(i=0;i<t.length;i++)
		str.data[s.length+i]=t.data[i];
	return str;
}
void stringlength(sqstring s)//求串的长度
{
	int i=s.length;
	cout<<"串的长度为:"<<i<<endl;
}
void copy(sqstring&s,sqstring t)//串的复制
{
	int i;
	for(i=0;i<t.length;i++)
		s.data[i]=t.data[i];
	s.length=t.length;
}
bool equal(sqstring s,sqstring t)//判断串是否相等
{
	bool same=true;
	int i;
	if(s.length!=t.length)
		same=false;
	else
		for(i=0;i<s.length;i++)
			if(s.data[i]!=t.data[i])
			{
				same=false;
				break;
			}
			return same;
}
void destroy(sqstring&s)//销毁串
{
}
void create(sqstring&s,char a[])//生成串
{
	int i;
	for(i=0;a[i]!='\0';i++)
		s.data[i]=a[i];
	s.length=i;
}

int main()
{
	sqstring s;
	sqstring sl;
	sqstring t;
	sqstring s2;
	sqstring s3;
	sqstring s4;
	char a[max],b[max];
	cout<<"input string s:";
	cin>>a;
	create(s,a);
	cout<<"inout string sl:";
	cin>>b;
	create(sl,b);
	create(t,b);
    int index=BF(s,t,0);
	cout<<"串s为:";
	display(s);
	cout<<"s的长度为:";
	stringlength(s);
    
    
	cout<<"在s的第九个位置插入串sl:";
	s2=inset(s,9,sl);
	display(s2);
 
	cout<<"删除串s的第2个字符开始的5个字符：";
	s2=strdelete(s,2,5);
	display(s2);
	cout<<"删除后串的长度为:";
	stringlength(s2);
 
	cout<<"将s的第二个字符开始的五个字符替换成sl后：";
	s2=rep(s,2,5,sl);
	display(s2);
	cout<<"s的第二个字符开始的第十个字符：";
	 s3=sub(s,2,10);
	display(s3);
	cout<<"sl和s2链接后：";
	 s4=concat(sl,s2);
	display(s4);
	return 0;
}
