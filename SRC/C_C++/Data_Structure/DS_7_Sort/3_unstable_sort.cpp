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

//选择排序
void select_sort(int *num, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (num[j] < num[min])
                min = j;
        }
        if (min != i)
            swap(num[i], num[min]);
    }
}

//快速排序
void quick_sort(int *num, int l, int r)
{
    if (l > r)
        return;
    int x = l, y = r, z = num[x];
    while (x < y)
    {
        while (x < y && num[y] > z)
            y--;
        if (x < y)
            num[x++] = num[y];
        while (x < y && num[x] < z)
            x++;
        if (x < y)
            num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return;
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
    TEST(arr, MAX_N, select_sort, num, MAX_N);
    TEST(arr, MAX_N, quick_sort, num, 0, MAX_N - 1);
#undef MAX_N //结束宏定义
    return 0;
}