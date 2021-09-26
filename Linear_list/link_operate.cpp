//
// Created by 12980 on 2021/9/26.
//

#include <stdio.h>
#include <stdlib.h>
#include "link_list.cpp"

//�������Ԫ��
//pΪԭ����elem��ʾ������Ԫ�أ�add��ʾ��Ԫ��Ҫ�����λ��
link * insertElem(link * p, int elem, int add) {
    link * temp = p;//������ʱ���temp
    link * c = NULL;
    int i = 0;
    //�����ҵ�Ҫ����λ�õ���һ�����
    for (i = 1; i < add; i++) {
        if (temp == NULL) {
            printf("����λ����Ч\n");
            return p;
        }
        temp = temp->next;
    }
    //����������c
    c = (link*)malloc(sizeof(link));
    c->elem = elem;
    //�������в�����
    c->next = temp->next;
    temp->next = c;
    return  p;
}

//����ɾ��Ԫ��
//pΪԭ����addΪҪɾ��Ԫ�ص�ֵ
link * delElem(link * p, int add) {
    link * temp = p;
    link * del = NULL;
    int i = 0;
    //tempָ��ɾ��������һ�����
    for (i = 1; i < add; i++) {
        temp = temp->next;
    }
    del = temp->next;//��������һ��ָ��ָ��ɾ����㣬�Է���ʧ
    temp->next = temp->next->next;//ɾ��ĳ�����ķ������Ǹ���ǰһ������ָ����
    free(del);//�ֶ��ͷŸý�㣬��ֹ�ڴ�й©
    return p;
}

//�������Ԫ��
//pΪԭ����elem��ʾ������Ԫ�ء�
int selectElem(link * p, int elem) {
    //�½�һ��ָ��t����ʼ��Ϊͷָ�� p
    link * t = p;
    int i = 1;
    //����ͷ�ڵ�Ĵ��ڣ����while�е��ж�Ϊt->next
    while (t->next) {
        t = t->next;
        if (t->elem == elem) {
            return i;
        }
        i++;
    }
    //����ִ�����˴�����ʾ����ʧ��
    return -1;
}

//�������Ԫ��
//���º��������У�add ��ʾ���Ľ���������е�λ�ã�newElem Ϊ�µ��������ֵ
link *amendElem(link * p, int add, int newElem) {
    int i = 0;
    link * temp = p;
    temp = temp->next;//�ڱ���֮ǰ��tempָ����Ԫ���
    //��������ɾ�����
    for (i = 1; i < add; i++) {
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}

int main() {
    link *p = NULL;
    int address;
    //��ʼ������1��2��3��4��
    printf("��ʼ������Ϊ��\n");
    p = initLink();
    display(p);

    printf("�ڵ�4��λ�ò���Ԫ��5��\n");
    p = insertElem(p, 5, 4);
    display(p);

    printf("ɾ��Ԫ��3:\n");
    p = delElem(p, 3);
    display(p);

    printf("����Ԫ��2��λ��Ϊ��\n");
    address = selectElem(p, 2);
    if (address == -1) {
        printf("û�и�Ԫ��");
    }
    else {
        printf("Ԫ��2��λ��Ϊ��%d\n", address);
    }
    printf("���ĵ�3��λ���ϵ�����Ϊ7:\n");
    p = amendElem(p, 3, 7);
    display(p);

    return 0;
}