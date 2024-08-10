package com.wintmain.ds.sorts;

// 珠排序，只能对正整数进行排序
public class BeadSort {
    public int[] sort(int[] unsorted){
        final int l = unsorted.length;
        if(l == 0){
            throw new IllegalArgumentException("输入的数组为空没有排序意义");
        }
        /* 传入的是原始的无序数组 */
        int[] sorted = new int[l];
        int max = 0;
        /* 得到最大的数 */
        for(int i=0;i<l;i++){
            max = Math.max(max, unsorted[i]);
        }

        /* 把排序的个数和最大数想象成一个平面，先初始化 */
        char[][] grid = new char[l][max];
        int[] count =new int[max];
        for(int i=0;i<l;i++){
            for(int j=0;j<max;j++){
                grid[i][j] = '-';
            }
        }

        /* 初始化计数器 */
        for(int i=0;i<max;i++){
            count[i] = 0;
        }

        /* 挂珠子 */
        for(int i=0;i<l;i++){
            int k=0;
            for(int j=0;j<(int)unsorted[i];j++){
                grid[count[max-k-1]++][k] = '*';
                k++;
            }
        }

        /* 珠子开始自由下降 */
        for(int i=0;i<l;i++){
            int k=0;
            for(int j=0;j<max && grid[l-1-i][j] == '*';j++){
                k++;
            }
            sorted[i] = k;
        }
        return sorted;
    }
}
