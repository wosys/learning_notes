package com.wintmain.ds.datastructures.lists;

/*
 * A circular linked list where next pointer of last node 
 * points to first node of linked list.
 */
public class CircleLinkedList<T> {
    private static class Node<T>{
        T element;
        Node<T> next;

        private Node(T element, Node<T> next){
            this.element = element;
            this.next = next;
        }
    }

    private int size;
    private Node<T> head = null; // 指向假头，头指针
    private Node<T> tail = null; // 尾指针，列表的尾部
    // constructor, make a dummy node for circly linked list implementation
    // 初始化。因为列表永远不为空，所以可以减少错误
    public CircleLinkedList(){
        head = new Node<T>(null, head);
        tail = head;
        size = 0;
    }

    // 返回列表的大小
    public int getSize(){
        return size;
    }

    public void append(T value){
        if(value == null){
            throw new NullPointerException("不能添加空值到列表");
        }
        // head.next指向最后一个值
        if(tail == null){
            tail = new Node<T>(value, head);
            head.next = tail;
        }else{
            tail.next = new Node<T>(value, head);
            tail = tail.next;
        }
        size++;
    }

    // utility function for traversing the list
    public String toString() {
        Node<T> p = head.next;
        String s = "[ ";
        while (p != head) {
            s += p.element;
            if (p != tail) {
                s += " , ";
            }
            p = p.next;
        }
        return s + " ]";
    }

    public T remove(int pos){
        if(pos>size || pos<0){
            throw new IndexOutOfBoundsException("越界");
        }
        Node<T> before = head;
        for(int i=1;i<=pos;i++){
            before = before.next;
        }
        Node<T> destroy = before.next;
        T saved = destroy.element;

        before.next = before.next.next;
        if(destroy == tail){
            tail = before;
        }
        destroy = null;
        size--;
        return saved;
    }
}
