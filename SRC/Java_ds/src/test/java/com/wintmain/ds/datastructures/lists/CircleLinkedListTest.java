package com.wintmain.ds.datastructures.lists;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.Test;

public class CircleLinkedListTest {
    @Test
    public void append(){
        CircleLinkedList<Integer> cl = new CircleLinkedList<>();
        assertEquals(0, cl.getSize());

        cl.append(3);
        System.out.println(cl);
        assertEquals(1,cl.getSize());
    }

    @Test
    public void remove(){
        CircleLinkedList<Integer> cl = new CircleLinkedList<>();
        cl.append(1);
        cl.append(2);
        cl.append(3);
        assertEquals(3, cl.getSize());

        cl.remove(2);
        assertEquals(2, cl.getSize());
    }

    @Test
    public void unexpected(){
        CircleLinkedList<Integer> cl = new CircleLinkedList<>(); 
        Exception exception = assertThrows(
            NullPointerException.class,
            () -> cl.append(null)
        );
        assertEquals("不能添加空值到列表", exception.getMessage());
    }
}
