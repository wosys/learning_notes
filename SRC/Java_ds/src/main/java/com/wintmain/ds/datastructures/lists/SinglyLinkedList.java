package com.wintmain.ds.datastructures.lists;

import java.util.StringJoiner;

// 结点信息，指针 + 值
class Node {
    int value;
    Node next;

    Node() {
    }

    Node(int value) {
        this(value, null);
    }

    Node(int value, Node next) {
        this.value = value;
        this.next = next;
    }
}

// 1. boolean detectloop() - 判断线性表是否是环
// 2. Node middle() - 返回线性表中间的那个结点
// 3. void swapNode(int valueFirst, int valueSecond) - 交换指定的两个结点
// 4. boolean isEmpty() - 判断线性表是否为空
// 5. int getSize() - 求线性表的长度
// 6. int getCount() - 求结点的数目，也是求长度
// 7. Node getHead()，void setHead(Node head) - get&set头结点
// 8. void clear() - 清空线性表
// 9. boolean search(int i) - 判断值i是否在线性表里面
// 10. int getNth(int position) - 返回指定位置的结点
// 11.插入（插入头，插入尾，插入指定位置）
// 12.删除（删除头，删除尾，删除指定位置，删除重复）

public class SinglyLinkedList extends Node {
    // head refer to the front of the list
    private Node head;
    private int size;

    // init
    public SinglyLinkedList() {
        head = null;
        size = 0;
    }

    // init with specific head and size
    public SinglyLinkedList(Node head, int size) {
        this.head = head;
        this.size = size;
    }

    /**
     * Detects if there is a loop in the singly linked list using floy'd turtle
     * and hare algorithm.
     *
     */
    public boolean detectloop() {
        Node curNodeFast = head;
        Node curNodeSlow = head;
        while (curNodeFast != null && curNodeFast.next != null) {
            curNodeFast = curNodeFast.next.next;
            curNodeSlow = curNodeSlow.next;
            if (curNodeFast == curNodeSlow) {
                return true;
            }
        }
        return false;
    }
    
    /**
     * Return the node in the middle of the list
     * If the length of the list is even then return item number length/2
     * @return middle node of the list
     */
    public Node middle() {
        if(head == null) return null;

        Node firNode = head;
        Node secNode = firNode.next;
        
        while((secNode !=null) && (secNode.next!=null)){
            firNode = firNode.next;
            secNode = secNode.next.next;
        }
        return firNode;
    }

    void clear() {
        Node cur = head;
        while (cur != null) {
            cur = cur.next;
        }
        head = null;
        size = 0;
    }

    void deleteDuplicates() {
        Node pred = head;
        // predecessor = the node having sublist of its duplicates
        Node newHead = head;
        while (newHead != null) {
            // if it's a beginning of duplicates sublist skip all duplicates
            if (newHead.next != null && newHead.value == newHead.next.value) {
                // move till the end of duplicates sublist
                while (newHead.next != null && newHead.value == newHead.next.value) {
                    newHead = newHead.next;
                }
                // skip all duplicates
                pred.next = newHead.next;
                newHead = null;
                // otherwise move predecessor
            }
            // move forward
            pred = pred.next;
            newHead = pred;
        }
    }
    
    void deleteNth(int position) {
        // delete value at position
        if (position > size - 1 || position < 0) {
            throw new IndexOutOfBoundsException(position + "");
        }
        if (position == 0) {
            head = head.next;
            size--;
            return;
        }
        Node cur = head;
        for (int i = 0; i < position - 1; i++) {
            cur = cur.next;
        }
        cur.next = cur.next.next;
        size--;
    }

    void delete() {
        // delete last
        deleteNth(size - 1);
    }

    void deleteHead() {
        // delete head
        deleteNth(0);
    }

    int getNth(int position) {
        // return element at special index
        if (position > size - 1 || position < 0) {
            throw new IndexOutOfBoundsException(position + "");
        }
        Node cur = head;
        for (int i = 0; i < position; i++) {
            cur = cur.next;
        }
        return cur.value;
    }

    boolean search(int i) {
        // test value whether in list at present
        Node cur = head;
        while (cur != null) {
            if (cur.value == i) {
                return true;
            }
            cur = cur.next;
        }
        return false;
    }

    public void insertNth(int value, int position) {
        // 在列表的指定位置插入值
        if (position > size || position < 0) {
            throw new IndexOutOfBoundsException(position + "");
        }
        Node newNode = new Node(value);
        if (head == null) {
            // list is empty
            head = newNode;
            size++;
            return;
        }
        if (position == 0) {
            // insert at head
            newNode.next = head;
            head = newNode;
            size++;
            return;
        }

        Node cur = head;
        for (int i = 0; i < position - 1; i++) {
            cur = cur.next;
        }
        newNode.next = cur.next;
        cur.next = newNode;
        size++;
    }

    void insert(int i) {
        // insert at last
        insertNth(i, size);
    }

    public void insertHeads(int i) {
        // insert an element at the head of a list
        insertNth(i, 0);
    }

    // swaps nodes of two given values a&b
    public void swapNode(int valueFirst, int valueSecond) {
        if (valueFirst == valueSecond)
            return;
        Node previousA = null, currentA = head; // ?
        while (currentA != null && currentA.value != valueFirst) {
            previousA = currentA;
            currentA = currentA.next;
        }

        Node previousB = null;
        Node currentB = head;
        while (currentB != null && currentB.value != valueSecond) {
            previousB = currentB;
            currentB = currentB.next;
        }

        // if 'a','b' not present, return
        if (currentA == null || currentB == null)
            return;

        // if 'a' is not head node of list
        if (previousA != null) {
            previousA.next = currentB;
        } else {
            // make 'b' as the new head
            head = currentB;
        }

        // if 'b' is not head node of list
        if (previousB != null) {
            previousB.next = currentA;
        } else {
            // make 'a' as the new head
            head = currentA;
        }

        // swap next pointer
        Node tmp = currentA.next;
        currentA.next = currentB.next;
        currentB.next = tmp;
    }

    // 判空
    public boolean isEmpty() {
        return size == 0;
    }

    // 求长度
    public int getSize() {
        return size;
    }

    public int getCount() {
        int count = 0;
        Node cur = head;
        while (cur != null) {
            cur = cur.next;
            count++;
        }
        return count;
    }

    // get&set head
    public Node getHead() {
        return head;
    }

    public void setHead(Node head) {
        this.head = head;
    }

    void print() {
        Node tmp = head;
        while (tmp != null && tmp.next != null) {
            System.out.println(tmp.value + "->");
            tmp = tmp.next;
        }
        if (tmp != null) {
            System.out.print(tmp.value);
            System.out.println();
        }
    }
    
    public String toString() {
        StringJoiner joiner = new StringJoiner("->");
        Node cur = head;
        while (cur != null) {
            joiner.add(cur.value + "");
            cur = cur.next;
        }
        return joiner.toString();
    }
}
