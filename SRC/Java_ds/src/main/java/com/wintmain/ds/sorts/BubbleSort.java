package com.wintmain.ds.sorts;

public class BubbleSort{
    static <T extends Comparable<T>> boolean greater(T v,T w){
        /* 检查第一个元素是不是比第二个大 */
        return v.compareTo(w)>0;
    }

    static <T> boolean swap(T[] arrTs,int idx,int idy){
        /* 将数组的两个元素换一下 */
        T swap = arrTs[idx];
        arrTs[idx] = arrTs[idy];
        arrTs[idy] = swap;
        return true;
    }

    /**
     * Main method arrays sorting algorithms
     *
     * @param array - an array should be sorted
     * @return a sorted array
     */
    public <T extends Comparable<T>> T[] sort(T[] array) {
        for(int i=1;i<array.length;i++){
            boolean swaped = false;
            for(int j=0;j<array.length-i;j++){
                if(greater(array[j], array[j+1])){
                    swap(array,j,j+1);
                    swaped = true;
                }
            }
            if(swaped==false){
                break;
            }
        }
        return array;
    }
}
