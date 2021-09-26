//
// Created by 12980 on 2021/9/26.
//

#include <stdio.h>
#include <stdlib.h>
#include "link_list.cpp"

//链表插入元素
//p为原链表，elem表示新数据元素，add表示新元素要插入的位置
link * insertElem(link * p, int elem, int add) {
    link * temp = p;//创建临时结点temp
    link * c = NULL;
    int i = 0;
    //首先找到要插入位置的上一个结点
    for (i = 1; i < add; i++) {
        if (temp == NULL) {
            printf("插入位置无效\n");
            return p;
        }
        temp = temp->next;
    }
    //创建插入结点c
    c = (link*)malloc(sizeof(link));
    c->elem = elem;
    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return  p;
}

//链表删除元素
//p为原链表，add为要删除元素的值
link * delElem(link * p, int add) {
    link * temp = p;
    link * del = NULL;
    int i = 0;
    //temp指向被删除结点的上一个结点
    for (i = 1; i < add; i++) {
        temp = temp->next;
    }
    del = temp->next;//单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
    free(del);//手动释放该结点，防止内存泄漏
    return p;
}

//链表查找元素
//p为原链表，elem表示被查找元素、
int selectElem(link * p, int elem) {
    //新建一个指针t，初始化为头指针 p
    link * t = p;
    int i = 1;
    //由于头节点的存在，因此while中的判断为t->next
    while (t->next) {
        t = t->next;
        if (t->elem == elem) {
            return i;
        }
        i++;
    }
    //程序执行至此处，表示查找失败
    return -1;
}

//链表更新元素
//更新函数，其中，add 表示更改结点在链表中的位置，newElem 为新的数据域的值
link *amendElem(link * p, int add, int newElem) {
    int i = 0;
    link * temp = p;
    temp = temp->next;//在遍历之前，temp指向首元结点
    //遍历到被删除结点
    for (i = 1; i < add; i++) {
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}

int main() {
    link *p = NULL;
    int address;
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    p = initLink();
    display(p);

    printf("在第4的位置插入元素5：\n");
    p = insertElem(p, 5, 4);
    display(p);

    printf("删除元素3:\n");
    p = delElem(p, 3);
    display(p);

    printf("查找元素2的位置为：\n");
    address = selectElem(p, 2);
    if (address == -1) {
        printf("没有该元素");
    }
    else {
        printf("元素2的位置为：%d\n", address);
    }
    printf("更改第3的位置上的数据为7:\n");
    p = amendElem(p, 3, 7);
    display(p);

    return 0;
}