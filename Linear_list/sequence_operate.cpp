//
// Created by 12980 on 2021/9/26.
//

#include <stdio.h>
#include <stdlib.h>
#include "sequence_list.cpp"

//���뺯�������У�elemΪ�����Ԫ�أ�addΪ���뵽˳����λ��
table addTable(table t, int elem, int add)
{
    int i;
    //���жϲ��뱾���Ƿ�������⣨�������Ԫ��λ�ñ����ű�ĳ���+1���������ȣ���β�������������߲����λ�ñ������ڣ�������Ϊ��ʾ���Զ��˳���
    if (add > t.length + 1 || add < 1) {
        printf("����λ��������");
        return t;
    }
    //�����������ʱ��������Ҫ��˳����Ƿ��ж���Ĵ洢�ռ��ṩ�������Ԫ�أ����û�У���Ҫ����
    if (t.length == t.size) {
        t.head = (int *)realloc(t.head, (t.size + 1) * sizeof(int));
        if (!t.head) {
            printf("�洢����ʧ��");
            return t;
        }
        t.size += 1;
    }

    //�۲����������Ҫ���Ӳ���λ�ÿ�ʼ�ĺ���Ԫ�أ��������
    // �˷���Ϊ�����ʼ�����ƶ�����Ϊ������addλ�ÿ�ʼ�ƶ������Ḳ�Ǻ�ߵ�Ԫ��
    for (i = t.length - 1; i >= add - 1; i--) {
        t.head[i + 1] = t.head[i];
    }
    //�ܺ�����ɺ�ֱ�ӽ��������Ԫ�أ���ӵ�˳������Ӧλ��
    t.head[add - 1] = elem;
    //�����������Ԫ�أ����Գ���+1
    t.length++;
    return t;
}

// ɾ��Ԫ��
table delTable(table t, int add) {
    int i;
    if (add > t.length || add < 1) {
        printf("��ɾ��Ԫ�ص�λ������");
        exit(0);
    }
    //ɾ������
    for (i = add; i < t.length; i++) {
        t.head[i - 1] = t.head[i];
    }
    t.length--;
    return t;
}

//���Һ��������У�elem��ʾҪ���ҵ�����Ԫ�ص�ֵ
int selectTable(table t, int elem) {
    int i;
    for (i = 0; i < t.length; i++) {
        if (t.head[i] == elem) {
            return i + 1;
        }
    }
    return -1;//�������ʧ�ܣ�����-1
}

//���ĺ��������У�elemΪҪ���ĵ�Ԫ�أ�newElemΪ�µ�����Ԫ��
table amendTable(table t, int elem, int newElem) {
    int add = selectTable(t, elem);
    t.head[add - 1] = newElem;//���ڷ��ص���Ԫ����˳����е�λ�ã�����-1���Ǹ�Ԫ���������е��±�
    return t;
}





int main() {
    int i, add;
    table t1 = initTable();
    for (i = 1; i <= Size; i++) {
        t1.head[i - 1] = i;
        t1.length++;
    }
    printf("ԭ˳���\n");
    displayTable(t1);

    printf("ɾ��Ԫ��1:\n");
    t1 = delTable(t1, 1);
    displayTable(t1);

    printf("�ڵ�2��λ�ò���Ԫ��5:\n");
    t1 = addTable(t1, 5, 2);
    displayTable(t1);

    printf("����Ԫ��3��λ��:\n");
    add = selectTable(t1, 3);
    printf("%d\n", add);

    printf("��Ԫ��3��Ϊ6:\n");
    t1 = amendTable(t1, 3, 6);
    displayTable(t1);
    return 0;
}