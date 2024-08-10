package com.wintmain.ds.math;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class AliquotSumTest {
    @Test
    public void testGetMaxValue() {
        assertEquals(0, AliquotSum.getAliquotValue(1));
        assertEquals(6, AliquotSum.getAliquotValue(6));
        assertEquals(9, AliquotSum.getAliquotValue(15));
        assertEquals(1, AliquotSum.getAliquotValue(19));
        assertEquals(0, AliquotSum.getAliquotSum(1));
        assertEquals(6, AliquotSum.getAliquotSum(6));
        assertEquals(9, AliquotSum.getAliquotSum(15));
        assertEquals(1, AliquotSum.getAliquotSum(19));
        assertEquals(AliquotSum.getAliquotSum(100), AliquotSum.getAliquotValue(100));
    }
}
