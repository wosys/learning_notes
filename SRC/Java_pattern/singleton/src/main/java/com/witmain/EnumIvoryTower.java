package com.witmain;

/**
 * <p>Enum based singleton implementation. Effective Java 2nd Edition (Joshua Bloch) p. 18</p>
 *
 * <p>This implementation is thread safe, however adding any other method and its thread safety
 * is developers responsibility.</p>
 */
public enum EnumIvoryTower{
    INSTANCE;

    @Override
    public String toString() {
        return getDeclaringClass().getCanonicalName() + "@" + hashCode();
    }

}