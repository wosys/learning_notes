package com.wintmain;

/**
 * WeatherType enumeration.
 * 主体的类型
 */

// 集合类的code style
public enum WeatherType {
    sunny("Sunny"),
    rainy("Rainy"),
    windy("Windy"),
    cold("Cold");

    private final String description;

    WeatherType(String description) {
        this.description = description;
    }

    public String getDescription() {
        return this.description;
    }

    @Override
    public String toString() {
        return this.name().toUpperCase();
    }
}
