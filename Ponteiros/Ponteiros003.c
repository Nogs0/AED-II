#include <stdio.h>

void swapNaoFuncional(int, int);
void swapFuncional(int*, int*);
void swapLogico(int *n1, int *n2);

int main(){
    int x = 100, y = 200;
    swapNaoFuncional(x, y);
    printf("%d  %d\n", x, y);
    swapFuncional(&x, &y);
    printf("%d  %d\n\n\n", x, y);
    return 0;
}

void swapNaoFuncional(int n1, int n2){
    int aux;
    aux = n1;
    n1 = n2;
    n2 = aux;
}
void swapFuncional(int *n1, int *n2){
    *n1 = *n1 + *n2;
    *n2 = *n1 - *n2;
    *n1 = *n1 - *n2;
}
void swapLogico(int *n1, int *n2){
    if(*n1 & *n2){
        
    }    
}

//ou exclusivo : " ^ "