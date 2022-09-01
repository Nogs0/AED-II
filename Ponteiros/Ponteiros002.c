#include <stdio.h>

int main(){
    int *p, *q, a = 10, b = 10, c = 0;

    p = &a;
    q = &b;
    c = *p + *q;
    printf("\n\n%p // %p // %d\n\n", p, q, c);
}

//Ao invés de usar %x (32bits), use %p (64bits)(Valor do ponteiro)
