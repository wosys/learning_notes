package com.wintmain.ds.sorts;

//二分插入排序
public class BinaryInsertionSort {

    // 定义方法
    public int[] binaryInsertionSort(int[] array){

        for(int i=1;i<array.length;i++){
            int temp = array[i];
            int low = 0;
            int high = i-1;

            while(low <= high){
                int mid = (low+high)/2;
                if(temp < array[mid]){
                    high = mid-1; //这里需要注意
                }else{
                    low = mid+1;
                }
            }

            for(int j=i;j>=low+1;j--){ //移动
                array[j]=array[j-1];
            }

            array[low] = temp;
        }

        return array;
    }
    
}
