package com.wintmain.java_exercise;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;

/* ==================================================================
* FileName: reflectDemo_one.java
* FilePath: src/main/java/com/wintmain/java_exercise/reflectDemo_one.java
* Description: 泛型反射
* Author: wintmain
* MailTo: wosintmain@gmail.com
* Date: 2023-04-11 21:13
* ===================================================================
*/
public class reflectDemo_one {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(5);
        System.out.println(list); //在这个泛型为 Integer 的ArrayList中存放一个String类型
        try {
            //通过反射获取ArrayList集合的字节码对象
            Class cla = Class.forName("java.util.ArrayList");
            //通过反射获取add方法
            Method addMethod = cla.getMethod("add", Object.class);
            //通过反射调用
            addMethod.invoke(list, "反射正常");
            System.out.println(list);
            
        } catch (ClassNotFoundException | NoSuchMethodException | SecurityException | IllegalAccessException | IllegalArgumentException | InvocationTargetException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        
    }
}
