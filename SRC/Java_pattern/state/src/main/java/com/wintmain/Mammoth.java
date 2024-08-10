package com.wintmain;

/**
 * Mammoth has internal state that defines its behavior.
 * 状态模式的对象有一个内部的状态去定义其行为。
 */
public class Mammoth {
  private State state;

  public Mammoth() {
    // 定义初始状态
    state = new PeacefulState(this);
  }

  /**
   * Makes time pass for the mammoth.
   * 随着时间的流逝
   */
  public void timePasses() {
    if (state.getClass().getName().contains("PeacefulState")) {
      changeStateTo(new AngryState(this));
    } else {
      changeStateTo(new PeacefulState(this));
    }
  }

  private void changeStateTo(State newState) {
    // 改变状态
    this.state = newState;
    // 定义状态接口，然后在它的子类中实现它的方法。这里的onEnterState()是每个状态的入口
    this.state.onEnterState();
  }

  @Override
  public String toString() {
    return "The mammoth";
  }

  public void observe() {
    this.state.observe();
  }

}
