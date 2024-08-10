#include <stdio.h>
#include <time.h>
#define MAX_N 10000

#define swap(a, b)           \
    {                        \
        __typeof(a) __c = a; \
        a = b, b = __c;      \
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

//改进的快速排序
void quick_sort2(int *num, int l, int r)
{
    while (l > r)
    {
        int x = l, y = r, z = num[(l + r) >> 1];
        do
        {
            while (num[x] < z)
                x++;
            while (num[y] > z)
                y--;
            if (x <= y)
            {
                swap(num[x], num[y]);
                x++;
                y--;
            }
        } while (x <= y);
        quick_sort2(num, l, y);
        l = x;
    }
    return;
}

void init_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
    return;
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
    int arr[MAX_N] = {0};
    init_arr(arr, MAX_N);
    // const double start_time = clock();
    quick_sort2(arr, 0, MAX_N - 1);
    // const double end_time = clock();
    output(arr, MAX_N);
    // printf("%f",end_time-start_time);
    return 0;
}