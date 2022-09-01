#include <stdio.h>
#include <stdlib.h>

int main(){
    int x;
    int *ptr_x = NULL;

    *ptr_x = (int *)malloc(sizeof(int));
    ptr_x = &x;
    x = 100;
    printf("\n Valor de x = %d", *ptr_x);

    *ptr_x = 200;
    printf("\nValor de x = %d", x);

    return 0;
}