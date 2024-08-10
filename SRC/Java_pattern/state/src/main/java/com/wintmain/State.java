package com.wintmain;

/** 
 * State interface.
 * 状态接口
 */
public interface State {
    void onEnterState();

    void observe();
}
