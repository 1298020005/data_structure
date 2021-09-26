//
// Created by 12980 on 2021/9/26.
//

#include <stdio.h>
#include <stdlib.h>
#include "double_link.cpp"



line * insertLine(line * head, int data, int add) {
    //新建数据域为data的结点
    line * temp = (line*)malloc(sizeof(line));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;
    //插入到链表头，要特殊考虑
    if (add == 1) {
        temp->next = head;
        head->prior = temp;
        head = temp;
    }
    else {
        int i = 0;
        line * body = head;
        //找到要插入位置的前一个结点
        for (i = 1; i < add - 1; i++) {
            body = body->next;
            if (body == NULL) {
                printf("插入位置有误\n");
                break;
            }
        }
        if (body) {
            //判断条件为真，说明插入位置为链表尾
            if (body->next == NULL) {
                body->next = temp;
                temp->prior = body;
            }
            else {
                body->next->prior = temp;
                temp->next = body->next;
                body->next = temp;
                temp->prior = body;
            }
        }
    }
    return head;
}
line * delLine(line * head, int data) {
    line * temp = head;
    //遍历链表
    while (temp) {
        //判断当前结点中数据域和data是否相等，若相等，摘除该结点
        if (temp->data == data) {
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    printf("链表中无该数据元素\n");
    return head;
}
//head为原双链表，elem表示被查找元素
int selectElem(line * head, int elem) {
    //新建一个指针t，初始化为头指针 head
    line * t = head;
    int i = 1;
    while (t) {
        if (t->data == elem) {
            return i;
        }
        i++;
        t = t->next;
    }
    //程序执行至此处，表示查找失败
    return -1;
}
//更新函数，其中，add 表示更改结点在双链表中的位置，newElem 为新数据的值
line *amendElem(line * p, int add, int newElem) {
    int i = 0;
    line * temp = p;
    //遍历到被删除结点
    for (i = 1; i < add; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("更改位置有误！\n");
            break;
        }
    }
    if (temp) {
        temp->data = newElem;
    }
    return p;
}


int main() {
    line * head = NULL;
    //创建双链表
    printf("初始链表为：\n");
    head = initLine(head);
    display(head);
    //在表中第 3 的位置插入元素 7
    printf("在表中第 3 的位置插入新元素 7：\n");
    head = insertLine(head, 7, 3);
    display(head);
    //表中删除元素 2
    printf("删除元素 2：\n");
    head = delLine(head, 2);
    display(head);

    printf("元素 3 的位置是：%d\n", selectElem(head, 3));
    //表中第 3 个节点中的数据改为存储 6
    printf("将第 3 个节点存储的数据改为 6：\n");
    head = amendElem(head, 3, 6);
    display(head);
    return 0;
}