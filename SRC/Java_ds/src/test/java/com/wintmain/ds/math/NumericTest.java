package com.wintmain.ds.math;

import java.util.Random;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class NumericTest {
    @Test
    public void testAverage() {
        double[] numbers = {1, 1, 2, 2, 3, 3, 9};
        Assertions.assertEquals(3, Numeric.average(numbers));
    }

    @Test
    public void testMax(){
        Random random = new Random();
        /* test 100 times using rand numbers */
        for (int i = 1; i <= 100; ++i) {
            /* generate number from 0 to 10 */
            int a = random.nextInt(10);
            int b = random.nextInt(10);
            if(i==50){
                System.out.println("a:"+a+"b:"+b);
            }
            assert Numeric.max(a, b) == Math.max(a, b);
        }
    }
    
    @Test
    public void testMin(){
        Random random = new Random();
        /* test 100 times using rand numbers */
        for (int i = 1; i <= 100; ++i) {
            /* generate number from 0 to 5 */
            double a = random.nextDouble(5);
            double b = random.nextDouble(5);
            if(i == 50){
                System.out.println("a:"+a+"; b:"+b);
            }
            assert Numeric.min(a, b) == Math.min(a, b);
        }
    }


}
