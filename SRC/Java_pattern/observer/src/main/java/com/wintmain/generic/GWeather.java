package com.wintmain.generic;

import com.wintmain.WeatherType;
import lombok.extern.slf4j.Slf4j;

/**
 * GWeather.
 */
@Slf4j
public class GWeather extends Observable<GWeather, Race, WeatherType> {

  private WeatherType currentWeather;

  public GWeather() {
    currentWeather = WeatherType.sunny;
  }

  /**
   * Makes time pass for weather.
   */
  public void timePasses() {
    var enumValues = WeatherType.values();
    currentWeather = enumValues[(currentWeather.ordinal() + 1) % enumValues.length];
    LOGGER.info("The weather changed to {}.", currentWeather);
    notifyObservers(currentWeather);
  }
}
