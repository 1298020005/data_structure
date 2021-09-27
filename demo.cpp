#include <cstdlib>
#include <cstdio>

typedef struct lineStack{
    int data;
    struct lineStack * next;
}lineStack;

lineStack* push(lineStack * stack,int a){
    lineStack* p=(lineStack*) malloc(sizeof(lineStack) );
    p->data=a;
    p->next=stack;
    stack=p;
    return  stack;

}

lineStack * push(lineStack *stack){
    stack=stack->next;
}