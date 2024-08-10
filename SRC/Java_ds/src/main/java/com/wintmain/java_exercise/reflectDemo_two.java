package com.wintmain.java_exercise;

import java.lang.reflect.Method;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;

/* ==================================================================
* FileName: reflectDemo_two.java
* FilePath: src/main/java/com/wintmain/java_exercise/reflectDemo_two.java
* Description: 用反射去创建对象有两种方式
* Author: wintmain
* MailTo: wosintmain@gmail.com
* Date: 2023-04-11 22:22
* ===================================================================
*/
public class reflectDemo_two {
    public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, NoSuchMethodException, SecurityException, NoSuchFieldException {
        // 获取Student类的字节码对象
        Class clazz = Class.forName("com.wintmain.java_exercise.Student");
        //1.利用反射创建一个空的对象
        Student student = (Student) clazz.getDeclaredConstructor().newInstance();
        //2.获取字段
        Field ageField = clazz.getDeclaredField("age");
        Field nameField = clazz.getDeclaredField("name");
        //取出私有属性
        ageField.setAccessible(true);
        nameField.setAccessible(true);
        //3.给字段设置值
        ageField.set(student, 30);
        nameField.set(student, "张A");
        System.out.println(student);

        //第二种方式用反射去创建对象
        Method setAgeMethod = clazz.getMethod("setAge", int.class);
        Method setNameMethod = clazz.getMethod("setName", String.class);
        setAgeMethod.invoke(student, 38);
        setNameMethod.invoke(student, "张B");
        System.out.println(student);

        // 获取有参构造
        Constructor constructor = clazz.getConstructor(int.class, String.class);

        Student stu = (Student) constructor.newInstance(30, "张亮");
        System.out.println(stu);
    }
}

class Student {
    private int age;
    private String name;

    public Student() {
    }

    public Student(int age, String name) {
        super();
        this.age = age;
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Student [age=" + age + ", name=" + name + "]";
    }

}