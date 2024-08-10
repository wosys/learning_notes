package com.wintmain.java_exercise;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/* ==================================================================
* FileName: reflectDemo_three.java
* FilePath: src/main/java/com/wintmain/java_exercise/reflectDemo_three.java
* Description: 给类增加一个实例方法。使用反射创建该类的对象， 并调用该对象中的方法。
* Author: wintmain
* MailTo: wosintmain@gmail.com
* Date: 2023-04-11 22:27
* ===================================================================
*/
public class reflectDemo_three {
    public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, NoSuchMethodException, SecurityException {
        // 获取Demo.java的字节码对象
        Class clazz = Class.forName("com.wintmain.java_exercise.Demo");
        // 利用反射创建对象
        Demo demo = (Demo) clazz.getDeclaredConstructor().newInstance();
        // 利用反射获取print方法
        Method printMethod = clazz.getMethod("print", String.class);
        printMethod.invoke(demo, "Android");
    }
}

class Demo {
    public Demo() {
    }

    public void print(String str) {
        System.out.println("Hello " + str);
    }
}