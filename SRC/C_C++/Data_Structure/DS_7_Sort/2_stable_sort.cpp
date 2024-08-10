#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a, b)           \
    {                        \
        __typeof(a) __c = a; \
        a = b, b = __c;      \
    }

//args是func的参数
#define TEST(arr, n, func, args...)                \
    {                                              \
        int *num = (int *)malloc(sizeof(int) * n); \
        memcpy(num, arr, sizeof(int) * n);         \
        output(num, n);                            \
        printf("%s = ", #func);                    \
        func(args);                                \
        output(num, n);                            \
        free(num);                                 \
        printf("\n");                              \
    }

void insert_sort(int *num, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && num[j] < num[j - 1]; j--)
        {
            swap(num[j], num[j - 1]);
        }
    }
}

void bubble_sort(int *num, int n)
{
    int times; //优化
    for (int i = 0; i < n-1; i++)
    {
        times = 0;
        for (int j = n-1; j > i; j--)
        {
            if (num[j-1] > num[j]){
                swap(num[j-1], num[j]);
                times = 1;
            }      
        }
        if(times==0) return; 
    }
}


void merge_sort(int *num, int l, int r)
{
    if (r - l <= 1)
    {
        if (r - l == 1 && num[r] < num[l])
        { //当前正好还剩2个元素,后面的值小于前面的
            swap(num[r], num[l]);
        }
        return ;
    }
    int mid = (l + r) >> 1; //平分
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r)
    {
        if (p2 > r || (p1 <= mid && num[p1] <= num[p2]))
        {
            temp[k++] = num[p1++]; //放置p1
        }
        else
        {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1)); //拷贝至内存
    free(temp);
}

void randint(int *num, int n)
{
    while (n--)
    {
        num[n] = rand() % 100;
    }
}

void output(int *num, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        i &&printf(" "); //i不是0时打印
        printf("%d", num[i]);
    }
    printf("]\n");
}

int main(void)
{
    srand(time(0));
#define MAX_N 20
    int arr[MAX_N];
    randint(arr, MAX_N);
    TEST(arr, MAX_N, insert_sort, num, MAX_N);
    TEST(arr, MAX_N, bubble_sort, num, MAX_N);
    TEST(arr, MAX_N, merge_sort, num, 0, MAX_N - 1);
#undef MAX_N //结束宏定义
    return 0;
}