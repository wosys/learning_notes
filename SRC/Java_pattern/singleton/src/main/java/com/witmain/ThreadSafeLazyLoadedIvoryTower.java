package com.witmain;

/**
 * <p>Thread-safe Singleton class. The instance is lazily initialized and thus needs synchronization
 * mechanism.</p>
 * 线程安全的单例类，懒汉式初始化实例，因此需要同步机制
 */
public final class ThreadSafeLazyLoadedIvoryTower {
    private static volatile ThreadSafeLazyLoadedIvoryTower instance;

    private ThreadSafeLazyLoadedIvoryTower(){
        // Protect against instantiation via reflection
        // 通过反射反之实例化
        if(instance != null){
            throw new IllegalStateException("已经初始化过了");
        }
    }
    /**
    * The instance doesn't get created until the method is called for the first time.
    * 实例不会被创建除非该方法是第一次被调用
    */
    public static synchronized ThreadSafeLazyLoadedIvoryTower getInstance(){
        if(instance == null){
            synchronized(ThreadSafeLazyLoadedIvoryTower.class){
                if(instance == null){
                    instance = new ThreadSafeLazyLoadedIvoryTower();
                }
            }
        }
        return instance;
    }
}
