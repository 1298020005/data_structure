#include <cstdlib>
#include <cstdio>

typedef struct Link{
    int elem;
    struct  Link * next;
}link;

//  有头结点的链表
link* initLink(){
    link* p=(link *) malloc(sizeof (link));
    link *temp=p;
    for (int i = 1; i < 5; ++i) {
        link * a= (link*)malloc(sizeof (link));
        a->elem=i;
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    return p;
};

void display(link* p){
    link *temp=p;
    while(temp->next) {
        temp=temp->next;
        printf("%d",temp->elem);
    }
}

int main(){
    link * p;
    p=initLink();
    display(p);
    return  0;
}