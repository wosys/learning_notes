#include<stdio.h>
#include<string.h>

void shift(char *p,long m,int n)    
{
    int r;
    while (m>0)
    {
        r = m%n;			//求余
        if (r<10)
        {
            *p=r+48;    //小余10的数转换成字符后赋给P所指向的元素
        }
        else
        {
            *p=r+55;	//10-15转化为“A~F”后赋给P所指向的元素
        }
        m=m/n;
        p++; 				//指针后移

    }
    *p = '/0';
}
int main(void)
{
    int x;
    long y;
    char a[32] = {};		//存放结果的数组
    L:
    printf("输入要转化的进制数:"); 
    scanf("%d", &x);
    if (x <= 0)
    {
        printf("输入有误！请重新输入！\n");
        goto L;
    }
    else
    {
        printf("请输入需要被转换的十进制数：");
        scanf("%ld", &y);
        printf("\n");
        printf("%d转换为%d进制数为：",y,x);
        shift(a,y,x);
        for (int i=strlen(a)-1;i>=0;i--)    //逆向输出字符串
        {
            printf("%c",*(a+i));         		//*(a+i)即a[i];
        }
    }
    printf("\n");
    return 0;
}

