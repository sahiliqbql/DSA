#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int main(){

    struct stack s;
    s.size = 80;
    s.top = -1;
    s.arr = (int*)malloc(s.size*sizeof(int));
}

//or we can write
int main(){

    struct stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));
}
