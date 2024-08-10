package com.wintmain.ds.math;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.math.BigDecimal;
import java.util.Optional;

import org.junit.jupiter.api.Test;

/* ==================================================================
* FileName: FibonacciTest.java
* FilePath: src/test/java/com/wintmain/ds/math/FibonacciTest.java
* Description: 流实现斐波拉契的测试类
* Author: wintmain
* MailTo: wosintmain@gmail.com
* Date: 2023-04-10 23:45
* ===================================================================
*/
public class FibonacciTest {
    @Test
    public void fibemptyTest(){
        final Optional<BigDecimal> result = Fibonacci.calculate(new BigDecimal(-1));
        assertEquals(true, result.isEmpty());
    }

    @Test
    public void fibzeroTest(){
        final Optional<BigDecimal> result = Fibonacci.calculate(BigDecimal.ZERO);
        assertEquals(true,result.isPresent());
        result.ifPresent(value -> assertEquals(BigDecimal.ZERO,value));
    }

    @Test
    public void fiboneTest(){
        final Optional<BigDecimal> result = Fibonacci.calculate(new BigDecimal(2));
        assertEquals(true,result.isPresent());
        result.ifPresent(value -> assertEquals(BigDecimal.ONE,value));
    }

    @Test
    public void fibthreeTest(){
        Optional<BigDecimal> result = Fibonacci.calculate(new BigDecimal(3));
        assertEquals(true,result.isPresent());
        result.ifPresent(value -> assertEquals(new BigDecimal(2),value));
    }
    
    @Test
    public void fibmidTest(){
        final Optional<BigDecimal> result = Fibonacci.calculate(new BigDecimal(30));
        assertEquals(true,result.isPresent());
        result.ifPresent(value -> assertEquals(new BigDecimal(832040),value)
        );
    }

    @Test
    public void fibbigTest(){
        final Optional<BigDecimal> result = Fibonacci.calculate(new BigDecimal(200));
            assertEquals(true,result.isPresent());
            result.ifPresent(value ->
                assertEquals(
                    new BigDecimal("280571172992510140037611932413038677189525"),
                    value
                )
            );
    }
}
