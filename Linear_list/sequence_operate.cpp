//
// Created by 12980 on 2021/9/26.
//

#include <stdio.h>
#include <stdlib.h>
#include "sequence_list.cpp"

//插入函数，其中，elem为插入的元素，add为插入到顺序表的位置
table addTable(table t, int elem, int add)
{
    int i;
    //①判断插入本身是否存在问题（如果插入元素位置比整张表的长度+1还大（如果相等，是尾随的情况），或者插入的位置本身不存在，程序作为提示并自动退出）
    if (add > t.length + 1 || add < 1) {
        printf("插入位置有问题");
        return t;
    }
    //②做插入操作时，首先需要看顺序表是否有多余的存储空间提供给插入的元素，如果没有，需要申请
    if (t.length == t.size) {
        t.head = (int *)realloc(t.head, (t.size + 1) * sizeof(int));
        if (!t.head) {
            printf("存储分配失败");
            return t;
        }
        t.size += 1;
    }

    //③插入操作，需要将从插入位置开始的后续元素，逐个后移
    // 此方法为从最后开始依次移动，因为如果你从add位置开始移动，将会覆盖后边的元素
    for (i = t.length - 1; i >= add - 1; i--) {
        t.head[i + 1] = t.head[i];
    }
    //④后移完成后，直接将所需插入元素，添加到顺序表的相应位置
    t.head[add - 1] = elem;
    //⑤由于添加了元素，所以长度+1
    t.length++;
    return t;
}

// 删除元素
table delTable(table t, int add) {
    int i;
    if (add > t.length || add < 1) {
        printf("被删除元素的位置有误");
        exit(0);
    }
    //删除操作
    for (i = add; i < t.length; i++) {
        t.head[i - 1] = t.head[i];
    }
    t.length--;
    return t;
}

//查找函数，其中，elem表示要查找的数据元素的值
int selectTable(table t, int elem) {
    int i;
    for (i = 0; i < t.length; i++) {
        if (t.head[i] == elem) {
            return i + 1;
        }
    }
    return -1;//如果查找失败，返回-1
}

//更改函数，其中，elem为要更改的元素，newElem为新的数据元素
table amendTable(table t, int elem, int newElem) {
    int add = selectTable(t, elem);
    t.head[add - 1] = newElem;//由于返回的是元素在顺序表中的位置，所以-1就是该元素在数组中的下标
    return t;
}





int main() {
    int i, add;
    table t1 = initTable();
    for (i = 1; i <= Size; i++) {
        t1.head[i - 1] = i;
        t1.length++;
    }
    printf("原顺序表：\n");
    displayTable(t1);

    printf("删除元素1:\n");
    t1 = delTable(t1, 1);
    displayTable(t1);

    printf("在第2的位置插入元素5:\n");
    t1 = addTable(t1, 5, 2);
    displayTable(t1);

    printf("查找元素3的位置:\n");
    add = selectTable(t1, 3);
    printf("%d\n", add);

    printf("将元素3改为6:\n");
    t1 = amendTable(t1, 3, 6);
    displayTable(t1);
    return 0;
}