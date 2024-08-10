package com.wintmain;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class subobserver_two implements WeatherObserver{

    @Override
    public void update(WeatherType currentweatherType) {
        LOGGER.info("The subobserver_two are facing " +
                currentweatherType.getDescription() + " weather now");
    }
    
}
