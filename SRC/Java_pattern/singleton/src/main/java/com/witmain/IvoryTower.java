package com.witmain;

/**
 * Singleton class. Eagerly initialized static instance guarantees thread safety.
 * 饿汉式单例类，在类加载的时候就直接创建类的静态实例保证线程安全
 */
public final class IvoryTower {
    /**
    * Private constructor so nobody can instantiate the class.
    * 私有方法，所以没有人能实例化这个类
    */
    private IvoryTower(){
      // do nothing
    }
    /**
    *  Static to class instance of the class.
    *  静态到类的实例
    */
    private static final IvoryTower INSTANCE = new IvoryTower();

  /**
   * To be called by user to obtain instance of the class.
   * 由用户调用去获得类的实例
   * @return instance of the singleton.
   */
  public static IvoryTower getInstance() {
    return INSTANCE;
  }

}
