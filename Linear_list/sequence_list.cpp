#include <stdio.h>
#include <stdlib.h>  //malloc()��exit()

typedef struct Table{
    int * head;//������һ����Ϊhead�ĳ��Ȳ�ȷ�������飬Ҳ�С���̬���顱
    int length;//��¼��ǰ˳���ĳ���
    int size;//��¼˳������Ĵ洢����
}table;


#define Size 5 //��Size���к궨�壬��ʾ˳�������ռ�Ĵ�С
table initTable(){
    table t;
    t.head = (int*)malloc(Size * sizeof(int));//����һ���յ�˳�����̬����洢�ռ�
    if (!t.head) //�������ʧ�ܣ�������ʾ��ֱ���˳�����
    {        printf("��ʼ��ʧ��");
        exit(0);    }
    t.length = 0;//�ձ�ĳ��ȳ�ʼ��Ϊ0
    t.size = Size;//�ձ�ĳ�ʼ�洢�ռ�ΪSize
    return t;}

//���˳�����Ԫ�صĺ���
void displayTable(table t) {
    int i;
    for (i = 0; i < t.length; i++) {
        printf("%d ", t.head[i]);
    }
    printf("\n");
}

int main() {
    int i;
    table t = initTable();
    //��˳��������Ԫ��
    for (i = 1; i <= Size; i++) {
        t.head[i - 1] = i;
        t.length++;
    }
    printf("˳����д洢��Ԫ�طֱ��ǣ�\n");
    displayTable(t);
    return 0;
}