#include <stdio.h>
#include <stdlib.h>
//�����нڵ�Ľṹ
typedef struct Link{
    char elem; //����������
    struct Link * next; //����ָ����ָ��ֱ�Ӻ��Ԫ��
}link; //linkΪ�ڵ�����ÿ���ڵ㶼��һ�� link �ṹ��
//��ʼ������ĺ���
link * initLink();
//�����������ĺ���
void display(link *p);



//��ʼ����ͷ��������
link * initLink(){
    int i;
    link * p=(link*)malloc(sizeof(link));//����һ��ͷ���
    link * temp=p;//����һ��ָ��ָ��ͷ��㣬
    //��������
    for (i=1; i<5; i++) {
        //����һ���½�㲢��ʼ��
        link *a=(link*)malloc(sizeof(link));
        a->elem=i;
        a->next=NULL;
        //��temp������½�����a��㽨���߼���ϵ
        temp->next=a;
        //ָ��tempÿ�ζ�ָ������������һ���ڵ㣬��ʵ���� a�ڵ㣬����дtemp=aҲ��
        temp=temp->next;
    }
    //���ؽ����Ľڵ㣬ֻ����ͷָ�� p���ɣ�ͨ��ͷָ�뼴���ҵ���������
    return p;
}


void display(link *p){
    link* temp=p;//��tempָ������ָ��ͷ���
    //ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
    //while ���� �ҵ�һ��д���ǣ� ���˺þ�
    while (temp->next) {
        temp=temp->next;
        printf("%d",temp->elem);
    }
    printf("\n");
}


//int main() {
//    link*p = NULL;
//    //��ʼ������1��2��3��4��
//    printf("��ʼ������Ϊ��\n");
//    p = initLink();
//    display(p);
//    return 0;
//}