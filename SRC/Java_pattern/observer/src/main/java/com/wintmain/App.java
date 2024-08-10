package com.wintmain;

import com.wintmain.generic.GHobbits;
import com.wintmain.generic.GOrcs;
import com.wintmain.generic.GWeather;

import lombok.extern.slf4j.Slf4j;

/**
 * The Observer pattern is a software design pattern in which an object, called the subject,
 * maintains a list of its dependents, called observers, and notifies them automatically of any
 * state changes, usually by calling one of their methods. It is mainly used to implement
 * distributed event handling systems. The Observer pattern is also a key part in the familiar
 * model–view–controller (MVC) architectural pattern. The Observer pattern is implemented in
 * numerous programming libraries and systems, including almost all GUI toolkits.
 * 观察者模式是一种软件设计模式，其中称为主体的对象，维护其依赖项列表（列表里的每一个对象称为观察者），
 * 任何状态更改，主体的对象都会自动通知观察者，通常通过调用它们的方法之一。 
 * 这一设计模式主要用于实现分布式事件处理系统。 
 * 观察者模式也是熟悉的模型-视图-控制器 (MVC) 架构模式中的关键部分。 
 * 观察者模式在许多编程库和系统中实现，包括几乎所有的 GUI 工具包。
 * 
 * <p>In this example {@link Weather} has a state that can be observed. The {@link Orcs} and {@link
 * Hobbits} register as observers and receive notifications when the {@link Weather} changes.
 */
@Slf4j
public class App {
    public static void main(String[] args) {
        Weather weather = new Weather();
        weather.addObserver(new subobserver_one());
        weather.addObserver(new subobserver_two());
        weather.timePasses();
        weather.timePasses();
        weather.timePasses();
        weather.timePasses();

        // Generic observer inspired by Java Generics and Collections by Naftalin & Wadler
        // 这种编程思想慢慢体会～
        LOGGER.info("--Running generic version--");
        var gweather = new GWeather();
        gweather.addObserver(new GHobbits());
        gweather.addObserver(new GOrcs());
        gweather.timePasses();
        gweather.timePasses();
        gweather.timePasses();
        gweather.timePasses();
    }
}
