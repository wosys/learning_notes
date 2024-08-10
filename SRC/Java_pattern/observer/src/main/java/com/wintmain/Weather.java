package com.wintmain;

import java.util.ArrayList;
import java.util.List;

import lombok.extern.slf4j.Slf4j;

/**
 * Weather can be observed by implementing {@link WeatherObserver} interface and
 * registering as listener.
 * 主体Weather类，维护的列表只要是WeatherObserver的实现类就可以接受Weather的变化
 */
@Slf4j
public class Weather {

    private WeatherType currentWeather;
    private final List<WeatherObserver> observers; // 维护的列表

    public Weather() {
        observers = new ArrayList<>(); //初始化
        currentWeather = WeatherType.sunny;
    }

    public void addObserver(WeatherObserver obs) {
        observers.add(obs);
    }

    public void removeObserver(WeatherObserver obs) {
        observers.remove(obs);
    }

    /**
     * Makes time pass for weather.
     */
    public void timePasses() {
        var enumValues = WeatherType.values();
        currentWeather = enumValues[(currentWeather.ordinal() + 1) % enumValues.length];
        LOGGER.info("The weather changed to {}.", currentWeather);
        notifyObservers();
    }

    private void notifyObservers() {
        for (var obs : observers) {
            obs.update(currentWeather);
        }
    }
}
