package com.wintmain.ds.math;

import java.util.Arrays;

public class AbsoluteValue{
    public static int getAbsValue(int value){
        
        return (value>0) ? value : -value;
    }

    public static int getAbsMax(int... numbers){
        if(numbers.length <= 0){
            throw new IllegalArgumentException("传入的数组不应该是空的");
        }

        // 赋的初始值是numbers数组的第一个
        var absMaxWrapper = new Object(){
            int value = numbers[0];
        };
        
        // 遍历
        Arrays.stream(numbers)
            .skip(1)
            // .filter(number -> getAbsValue(number)>getAbsValue(absMaxWrapper.value))
            .filter(number -> Math.abs(number)>Math.abs(absMaxWrapper.value))
            .forEach(number -> absMaxWrapper.value = number);

        return absMaxWrapper.value;
    }

    public static int getAbsMin(int... numbers){
        if(numbers.length <= 0){
            throw new IllegalArgumentException("传入的数组不应该是空的");
        }

        // 赋的初始值是numbers数组的第一个
        var absMinWrapper = new Object(){
            int value = numbers[0];
        };
        
        // 遍历
        Arrays.stream(numbers)
            .skip(1)
            .filter(number -> Math.abs(number)<Math.abs(absMinWrapper.value))
            .forEach(number -> absMinWrapper.value = number);

        return absMinWrapper.value;
    }

}