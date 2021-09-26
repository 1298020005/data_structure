#include <stdio.h>
#include <stdlib.h>
//链表中节点的结构
typedef struct Link{
    char elem; //代表数据域
    struct Link * next; //代表指针域，指向直接后继元素
}link; //link为节点名，每个节点都是一个 link 结构体
//初始化链表的函数
link * initLink();
//用于输出链表的函数
void display(link *p);

int main() {
    link*p = NULL;
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    p = initLink();
    display(p);
    return 0;
}

//初始化有头结点的链表
link * initLink(){
    int i;
    link * p=(link*)malloc(sizeof(link));//创建一个头结点
    link * temp=p;//声明一个指针指向头结点，
    //生成链表
    for (i=1; i<5; i++) {
        //创建一个新结点并初始化
        link *a=(link*)malloc(sizeof(link));
        a->elem=i;
        a->next=NULL;
        //将temp结点与新建立的a结点建立逻辑关系
        temp->next=a;
        //指针temp每次都指向新链表的最后一个节点，其实就是 a节点，这里写temp=a也对
        temp=temp->next;
    }
    //返回建立的节点，只返回头指针 p即可，通过头指针即可找到整个链表
    return p;
}


void display(link *p){
    link* temp=p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    //while 这里 我第一次写的是！ 错了好久
    while (temp->next) {
        temp=temp->next;
        printf("%d",temp->elem);
    }
    printf("\n");
}