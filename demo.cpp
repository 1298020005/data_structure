


#include <cstdlib>
#include <cstdio>

typedef struct Table{
    int * head;
    int size;
    int length;
}table;

table initTable(){
    table t;
    t.length=0;
    t.size=5;
    t.head=(int*)malloc(5*sizeof(int ));
    return t;
}
void display(table t){
    for (int i = 0; i < t.size; ++i) {
        printf("%d",t.head[i]);
    }
}
table insert(table t){
    for (int i = 1; i < t.size; i++) {
        t.head[i-1]=i;
        t.length++;
    }
    return t;
}
int main(){
    table t=initTable();
    insert(t);
    display(t);
    return 0;
}