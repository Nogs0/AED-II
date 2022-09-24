
#include <stdio.h>

int main(){
    int i = 3, j = 5, *p, *q;
    p = &i;
    q = &j;
    *p -= *q;
    printf("%d\n\n", **&p);
    return 0;
}
