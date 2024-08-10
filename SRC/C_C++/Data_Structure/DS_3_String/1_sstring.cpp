//顺序存储——静态数组实现方式（定长顺序存储），注意下面实现在数组中存放字符串时，都会舍弃，Str[0]，第一个结点的空间，以保证字符下标和数组下标保证一致
#include <stdio.h>
#include <cstring>

#define MAXLEN 255

typedef struct{
    char ch[MAXLEN];
    int length;
}SString;

//函数声明
void Init(SString &s);//初始化
bool StrAssign(SString &T,char *str,int strLength);//赋值操作
void StrCopy(SString &T,SString S);//复制操作
bool StrEmpty(SString S);//判空
int StrLength(SString S);//获取字符串长度
void ConCat(SString &T,SString S1,SString S2);//串联接操作
bool SubString(SString &Sub,SString S,int pos,int len);//求子串
int StrCompare(SString S,SString T);//比较，若S>T返回0，反之返回值-1
int Index(SString S, SString T);//定位操作,若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置，否则函数值为0；


int Index_Simple(SString S, SString T);//简单模式匹配
//初始化
void InitStr(SString &S){
    S.ch[1]='\0';
    S.length=0;
}

//赋值操作
bool StrAssign(SString &T, char *str, int strLength){
    if(str[0]=='\0') return false;//传入空数组就失败，条件依据初始化操作和清空操作而定

    for (int i = 0; i < strLength; i++)
    {
        T.ch[i+1]=str[i];//空置T的第一个元素位置
    }
    T.length = strLength;
    return true;
}

void StrCopy(SString &T,SString S){//复制操作
    for(int i=1;i<S.length;i++){
        T.ch[i]==S.ch[i];
    }
    T.length=S.length;
}

bool StrEmpty(SString S){//判空
    if(S.length==0) return true;
    else return false;
}
int StrLength(SString S) {//获取字符串长度
    return S.length;
}

void ConCat(SString &T,SString S1,SString S2){
    //串联接操作
    for(int i=1;i<=S1.length;i++){
        T.ch[i]=S1.ch[i];
    }
    for(int j=S1.length+1;j<=S1.length+S2.length;j++){
        T.ch[j] = S2.ch[j - S1.length];//这里好好想一下循环的条件及数组下标
    }
    T.length = S1.length + S2.length;
}

bool SubString(SString &Sub, SString S, int pos, int len){
    //求子串
    if(pos + len-1 >S.length) return false;
    for(int i=pos;i<pos+len;i++){
        Sub.ch[i-pos+1] = S.ch[i];
    }
    Sub.length = len;
    return true;

}

int StrCompare(SString S,SString T){
    //比较
    for(int i=1;i<=S.length&i<=T.length;i++){
        if(S.ch[i]!=T.ch[i]){
            return S.ch[i]-T.ch[i];
        }
    }
}

//定位操作,若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置，否则函数值为0；
int Index(SString S, SString T){
    int i=1,n=S.length,m=T.length;
    SString sub;
    while (i<n-m+1)
    {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0)++i;
        else return i;//返回子串在主串中的位置
    }
    return 0;//S中不存在与T相等的子串
    
}

int Index_Simple(SString S,SString T){
    int k = 1;//k记录当前主串指针
    int i = k,j=1;//j记录模式串指针，i记录主串中与模式串进行对比的子串的起始地址
    while (i<=S.length&&j<=T.length)
    {
        if(S.ch[i]==T.ch[j]){
            ++i;
            ++j;//比较后继字符
        }
        else{
            k++;//检查下一个字符串
            i=k;
            j=1;//重置j的值
        }
    }
    if(j>T.length){//匹配成功
        return k;
    }
    else{
        return 0;
    }
}

//简单模式匹配-王道
int Index_Simple_CSKaoYan(SString S, SString T) {
    int i = 1;//i记录当前主串指针
    int j = 1;//j记录模式串指针
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;//继续比较后续字符
        } else {
            i = i - j + 2; //检查下一个字串
            j = 1;//重制j的值
        }
    }
    if (j > T.length) {//匹配成功
        return i - T.length;
    } else {
        return 0;
    }
}

//求模式串T的next数组
void getNext(SString T,int *next){
    int i=1,j=0;
    next[1]=0;
    while(i<T.length){
        if(j==0||T.ch[i]){
            ++i;
            ++j;
            //如果pi=pj，则next[j+1]=next[j]+1
            next[i] = j;
        }
        else{
            //否则令j=next[j],循环继续
            j = next[j];
        }
    }
}

//KMP1
int Index_KMP(SString S, SString T) {
    int i = 1, j = 1;
    int next[T.length + 1];
    getNext(T, next);
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i;
            ++j;//继续比较后继字符
        } else {
            j = next[j];//模式串向右移动
        }
    }
    if (j > T.length)//匹配成功
        return i - T.length;
    else
        return 0;
}

//优化next数组
void Get_BetterNext(SString T, int *betterNext){
    int i=1,j=0;
}



//清空操作
void ClearStr(SString &S){
    S.length = 0;
    memset(S.ch,'\0',MAXLEN);//用到了一个cstring库中的memset函数
}

//销毁操作
//void DestoryString(SString &S) {
//
//}
//基于数组实现的字符串存储会自动销毁，无须单独销毁