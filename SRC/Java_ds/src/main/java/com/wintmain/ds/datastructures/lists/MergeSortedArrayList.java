package com.wintmain.ds.datastructures.lists;

import java.util.ArrayList;
import java.util.List;

public class MergeSortedArrayList {
    public static void main(String[] args) {
        List<Integer> listA = new ArrayList<>();
        List<Integer> listB = new ArrayList<>();
        List<Integer> listC = new ArrayList<>();

        // init
        for (int i = 0; i < 10; i += 2) {
            listA.add(i);
            listB.add(i + 1);
        }

        merge(listA, listB, listC);

        System.out.println("listC:" + listC);

    }

    private static void merge(
            List<Integer> listA,
            List<Integer> listB,
            List<Integer> listC) {
        int idxA = 0;
        int idxB = 0;

        while (idxA < listA.size() && idxB < listB.size()) {
            if (listA.get(idxA) < listB.get(idxB)) {
                listC.add(listA.get(idxA));
                idxA++;
            } else {
                listC.add(listB.get(idxB));
                idxB++;
            }
        }

        while (idxA < listA.size()) {
            listC.add(listA.get(idxA++));
        }

        while (idxB < listB.size()) {
            listC.add(listB.get(idxB++));
        }
    }

}
