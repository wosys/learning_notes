package com.wintmain;

import lombok.var;

/**
 * In the State pattern, the container object has an internal state object that
 * defines the current
 * behavior. The state object can be changed to alter the behavior.
 * 在状态模式中，容器对象有一个内部的状态对象去定义当前的行为。状态对象可以随行为的改变而变化。
 * <p>
 * This can be a cleaner way for an object to change its behavior at runtime
 * without resorting
 * to large monolithic conditional statements and thus improves maintainability.
 * 对于对象来说，这可能是一种更简洁的方式，可以在运行时更改其行为，而无需求助于大型单一条件语句，从而提高了可维护性。
 * <p>
 * In this example the {@link Mammoth} changes its behavior as time passes by.
 * 在这个例子中，Mammoth改变它的行为随着时间的流逝。
 */
public class App {
    public static void main(String[] args) {

        var mammoth = new Mammoth();
        // Mammoth mammoth = new Mammoth();
        mammoth.observe();
        mammoth.timePasses();
        mammoth.observe();
        mammoth.timePasses();
        mammoth.observe();
    }
}
