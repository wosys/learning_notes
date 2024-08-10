package com.wintmain.ds.sorts;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

import org.junit.jupiter.api.Test;

public class BubbleSortTest {

    private BubbleSort bubbleSort = new BubbleSort();

    @Test
    public void bubbleSortEmptyArray() {
        Integer[] inputArray = {};
        Integer[] outputArray = bubbleSort.sort(inputArray);
        Integer[] expectedOutput = {};
        assertArrayEquals(outputArray, expectedOutput);
    }

    @Test
    public void bubbleSortSingleIntegerElementArray() {
        Integer[] inputArray = { 6 };
        Integer[] outputArray = bubbleSort.sort(inputArray);
        Integer[] expectedOutput = { 6 };
        assertArrayEquals(outputArray, expectedOutput);
    }

    @Test
    public void bubbleSortSingleStringElementArray() {
        String[] inputArray = { "w","宜" };
        String[] outputArray = bubbleSort.sort(inputArray);
        String[] expectedOutput = { "w","宜" };
        assertArrayEquals(outputArray, expectedOutput);
    }

    @Test
    public void bubbleSortIntegerArray() {
        Integer[] inputArray = { 5, 21, -6, 78, 1, 55, 23, -6, -23, 8, 12 };
        Integer[] outputArray = bubbleSort.sort(inputArray);
        Integer[] expectedOutput = {
                -23,
                -6,
                -6,
                1,
                5,
                8,
                12,
                21,
                23,
                55,
                78,
        };
        assertArrayEquals(outputArray, expectedOutput);
    }

    @Test
    public void bubbleSortStringArray() {
        String[] inputArray = {
                "cbf",
                "auk",
                "ó",
                "(b",
                "a",
                ")",
                "au",
                "á",
                "cba",
                "auk",
                "(a",
                "bhy",
                "cba",
        };
        String[] outputArray = bubbleSort.sort(inputArray);
        String[] expectedOutput = {
                "(a",
                "(b",
                ")",
                "a",
                "au",
                "auk",
                "auk",
                "bhy",
                "cba",
                "cba",
                "cbf",
                "á",
                "ó",
        };
        assertArrayEquals(outputArray, expectedOutput);
    }
}