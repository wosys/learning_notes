package com.wintmain.ds.math;

import java.math.BigDecimal;
import java.util.List;
import java.util.Optional;
import java.util.stream.Stream;

/* ==================================================================
* FileName: Fibonacci.java
* FilePath: src/main/java/com/wintmain/ds/math/Fibonacci.java
* Description: 流实现斐波拉契
* Author: wintmain
* MailTo: wosintmain@gmail.com
* Date: 2023-04-10 23:24
* ===================================================================
*/
public class Fibonacci {
    public static Optional<BigDecimal> calculate(final BigDecimal index) {
        if (index == null || index.compareTo(BigDecimal.ZERO) < 0) {
            return Optional.empty();
        }

        if (index.compareTo(BigDecimal.ONE) < 0) {
            return Optional.of(BigDecimal.ZERO);
        }

        if (index.compareTo(new BigDecimal(2)) < 0) {
            return Optional.of(BigDecimal.ONE);
        }

        final List<BigDecimal> results = Stream
            .iterate(
                index,
                x -> x.compareTo(BigDecimal.ZERO) > 0,
                x -> x.subtract(BigDecimal.ONE)
            )
            .reduce(
                List.of(),
                (list, current) ->
                    list.isEmpty() || list.size() < 2
                        ? List.of(BigDecimal.ZERO, BigDecimal.ONE)
                        : List.of(list.get(1), list.get(0).add(list.get(1))),
                (list1, list2) -> list1
            );

        return results.isEmpty()
            ? Optional.empty()
            : Optional.of(results.get(results.size() - 1));
    }
}
