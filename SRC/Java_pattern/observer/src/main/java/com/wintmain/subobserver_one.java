package com.wintmain;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class subobserver_one implements WeatherObserver {

    @Override
    public void update(WeatherType currentweatherType) {
        LOGGER.info("The subobserver_one are facing " +
                currentweatherType.getDescription() + " weather now");
    }

}
