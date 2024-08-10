package com.wintmain.ds.math;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import java.util.concurrent.ThreadLocalRandom;
import java.util.stream.Stream;

import org.junit.jupiter.api.Test;

public class AbsoluteValueTest {
    @Test
    public void getAbsValue(){
        Stream
            .generate(() -> ThreadLocalRandom.current().nextInt())
            .limit(1000)
            .forEach(number ->
                assertEquals(
                    Math.abs(number),
                    AbsoluteValue.getAbsValue(number)
                )
            );
    }

    @Test
    void testGetMaxValue() {
        assertEquals(16, AbsoluteValue.getAbsMax(-2, 0, 16));
        assertEquals(-10, AbsoluteValue.getAbsMax(3, -10, -2));
    }

    @Test
    void testGetMaxValueWithNoArguments() {
        Exception exception = assertThrows(
            IllegalArgumentException.class,
            () -> AbsoluteValue.getAbsMax()
        );
        assertEquals("传入的数组不应该是空的", exception.getMessage());
    }

    @Test
    void testGetMinValue() {
        assertEquals(0, AbsoluteValue.getAbsMin(4, 0, 16));
        assertEquals(-2, AbsoluteValue.getAbsMin(3, -10, -2));
    }

    @Test
    void testGetMinValueWithNoArguments() {
        Exception exception = assertThrows(
            IllegalArgumentException.class,
            () -> AbsoluteValue.getAbsMin()
        );
        assertEquals("传入的数组不应该是空的", exception.getMessage());
    }
}
