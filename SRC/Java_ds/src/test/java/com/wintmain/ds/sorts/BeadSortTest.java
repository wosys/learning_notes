package com.wintmain.ds.sorts;

import static org.junit.Assert.assertEquals;
import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.Test;

public class BeadSortTest {
    BeadSort beadSort = new BeadSort();
    @Test
    public void beadSortEmptyArray() {
        int[] inputArray = {};
        Exception exception = assertThrows(IllegalArgumentException.class, ()->beadSort.sort(inputArray));
        assertEquals("输入的数组为空没有排序意义", exception.getMessage());
    }

    @Test
    public void beadSortSingleIntegerArray() {
        int[] inputArray = {4};
        int[] outputArray = beadSort.sort(inputArray);
        int[] expectedOutput = {4};
        assertArrayEquals(outputArray, expectedOutput);
    }

    @Test
    public void bogoSortNonDuplicateIntegerArray() {
        int[] inputArray = { 6, 1, 99, 27, 15, 23, 36 };
        int[] outputArray = beadSort.sort(inputArray);
        int[] expectedOutput = {1, 6, 15, 23, 27, 36, 99};
        assertArrayEquals(outputArray, expectedOutput);
    }
    
    @Test
    public void bogoSortDuplicateIntegerArray() {
        int[] inputArray = { 6, 1, 27, 15, 23, 27, 36, 23 };
        int[] outputArray = beadSort.sort(inputArray);
        int[] expectedOutput = {1, 6, 15, 23, 23, 27, 27, 36};
        assertArrayEquals(outputArray, expectedOutput);
    }
}
