// 给你两个整数，n 和 start 。
// 数组 nums 定义为：nums[i] = start + 2*i（下标从 0 开始）且 n == nums.length 。
// 请返回 nums 中所有元素按位异或（XOR）后得到的结果。

// 1、按位或：如果两个相应的二进制位有一个为1，则该结果为1，否则为0。
// 2、按位异或(^)：如果两个相应的二进制位值不同则为1，否则为0。
// 3、按位与(&)：如果两个相应的二进制位都为1，则该位的结果值为1，否则为0。
#include<stdio.h>
int main(void){
    int n,start;
    int result=0;
    scanf("n = %d, start = %d",&n,&start);
    for(int i=0;i<n;i++){
        result ^= start + 2*i;
    }
    printf("%d",result);
    return 0;
}