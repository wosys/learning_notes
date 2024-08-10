package com.wintmain.ds.math;

public class Numeric {
    //计算一个列表的平均数
    public static double average(double... numbers) {
        double sum = 0;
        for (double number : numbers) {
            sum += number;
        }
        return sum / numbers.length;
    }

    public static int average(int... array) {
        long sum = 0;
        for (int i = 0; i < array.length; ++i) {
            sum += array[i];
        }
        return (int) (sum / array.length);
    }

    //比较两个数字的大小
    public static int max(int a, int b){
        return (a>=b)?a:b;
    }

    public static double min(double a, double b){
        return (a<=b)?a:b;
    }
}
