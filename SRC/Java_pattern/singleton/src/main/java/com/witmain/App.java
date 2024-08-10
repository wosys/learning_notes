package com.witmain;

import lombok.extern.slf4j.Slf4j;
// import org.slf4j.Logger;
// import org.slf4j.LoggerFactory;

/**
 * <p>Singleton pattern ensures that the class can have only one existing instance per Java
 * classloader instance and provides global access to it.</p>
 * 单例模式保证了在Java的类加载器中只存在一个实例并且能提供全局访问入口
 * 
 * <p>One of the risks of this pattern is that bugs resulting from setting a singleton up in a
 * distributed environment can be tricky to debug since it will work fine if you debug with a
 * single classloader. Additionally, these problems can crop up a while after the implementation of
 * a singleton, since they may start synchronous and only become async with time, so it may
 * not be clear why you are seeing certain changes in behavior.</p>
 * 这种模式的缺点之一是很难在分布式环境中进行调试，因为使用了单个类加载器。
 * 此外，一些问题可能会实现单例类时突然出现，因为可能刚开始还是同步的，但是随着时间变化却成了异步，所以你会不清楚为什么看到某些行为上的变化
 * 
 * <p>There are many ways to implement the Singleton. The first one is the eagerly initialized
 * instance in {@link IvoryTower}. Eager initialization implies that the implementation is thread
 * safe. If you can afford to give up control of the instantiation moment, then this implementation
 * will suit you fine.</p>
 * 实现单例类的方式很多。第一种是饿汉式初始化实例{@link IvoryTower}。饿汉式初始化说明实现时线程安全的。如果你可以放弃某刻对实例化的控制
 * 这种方法会适合
 *
 * <p>The other option to implement eagerly initialized Singleton is enum-based Singleton. The example 
 * is found in {@link EnumIvoryTower}. At first glance, the code looks short and simple. However, you 
 * should be aware of the downsides including committing to implementation strategy, extending the enum 
 * class, serializability, and restrictions to coding. These are extensively discussed in Stack Overflow:
 * http://programmers.stackexchange.com/questions/179386/what-are-the-downsides-of-implementing-a-singleton-with-javas-enum</p>
 * 饿汉式初始化实例的另一个方法是基于枚举的单例模式，{@link EnumIvoryTower}。虽然代码看上去很短、很简单，但是你应该意识到缺点，包括提交实现策略、
 * 扩展枚举类、可序列化性和编码限制。在链接中进行了广泛的讨论
 *
 * <p>{@link ThreadSafeLazyLoadedIvoryTower} is a Singleton implementation that is initialized on
 * demand. The downside is that it is very slow to access since the whole access method is
 * synchronized.</p>
 * {@link ThreadSafeLazyLoadedIvoryTower}是实现单例类按需初始化实例（懒汉式）。缺点是访问很慢，因为所有方法都需要同步
 *
 * <p>Another Singleton implementation that is initialized on demand is found in
 * {@link ThreadSafeDoubleCheckLocking}. It is somewhat faster than {@link
 * ThreadSafeLazyLoadedIvoryTower} since it doesn't synchronize the whole access method but only the
 * method internals on specific conditions.</p>
 * 另一个实现单例类按需初始化实例（懒汉式）是{@link ThreadSafeDoubleCheckLocking}。它会比上面的那种方式快一点，因为只同步内部特定条件下的方法
 *
 * <p>Yet another way to implement thread-safe lazily initialized Singleton can be found in
 * {@link InitializingOnDemandHolderIdiom}. However, this implementation requires at least Java 8
 * API level to work.</p>
 * 实现线程安全的另一种懒汉式初始化单例类是{@link InitializingOnDemandHolderIdiom}。但是这种实现要求JDK8+
 */

@Slf4j
public class App {
    // lombok使用注解代替了这些
    //private static final Logger LOGGER = LoggerFactory.getLogger(App.class);
    /**
     * Program entry point.
     * 程序的入口
     * @param args command line args
    */
    public static void main( String[] args ){
        // eagerly initialized singleton
        var ivoryTower1 = IvoryTower.getInstance();
        var ivoryTower2 = IvoryTower.getInstance();
        LOGGER.info("ivoryTower1={}", ivoryTower1);
        LOGGER.info("ivoryTower2={}", ivoryTower2);

        // eagerly initialized singleton, enum singleton
        var enumIvoryTower1 = EnumIvoryTower.INSTANCE;
        var enumIvoryTower2 = EnumIvoryTower.INSTANCE;
        LOGGER.info("enumIvoryTower1={}", enumIvoryTower1);
        LOGGER.info("enumIvoryTower2={}", enumIvoryTower2);

        // lazily initialized singleton, the whole access method is synchronized
        var threadSafeIvoryTower1 = ThreadSafeLazyLoadedIvoryTower.getInstance();
        var threadSafeIvoryTower2 = ThreadSafeLazyLoadedIvoryTower.getInstance();
        LOGGER.info("threadSafeIvoryTower1={}", threadSafeIvoryTower1);
        LOGGER.info("threadSafeIvoryTower2={}", threadSafeIvoryTower2);
        
        // lazily initialized singleton, double checked locking, only the method internals on specific conditions
        var dcl1 = ThreadSafeDoubleCheckLocking.getInstance();
        var dcl2 = ThreadSafeDoubleCheckLocking.getInstance();
        LOGGER.info(dcl1.toString());
        LOGGER.info(dcl2.toString());

        // lazily initialized singleton, initialize on demand holder idiom, JDK8+
        var demandHolderIdiom = InitializingOnDemandHolderIdiom.getInstance();
        LOGGER.info(demandHolderIdiom.toString());
        var demandHolderIdiom2 = InitializingOnDemandHolderIdiom.getInstance();
        LOGGER.info(demandHolderIdiom2.toString());
    }

}
