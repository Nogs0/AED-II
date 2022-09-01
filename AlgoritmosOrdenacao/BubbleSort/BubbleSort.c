#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *primeiro, int *segundo){
    int aux;

    aux = *primeiro;
    *primeiro = *segundo;
    *segundo = aux;
}
void FillArray(int array[], int size){
    srand(time(NULL));
    for(int i=0; i<size; i++)
        array[i] = rand() % size;
}
void BubbleSort(int vetor[], int tamanho){
    int i;
    int ordenados=0; // indica que os elementos adjacentes não estão ordenados

    while(ordenados == 0){
        ordenados = 1;
        for(i = 0; i<tamanho-1;i++){
            if(vetor[i]>vetor[i+1]){
                swap(&vetor[i], &vetor[i+1]);
                ordenados = 0;
            }
        }
    }
}

int main(){
    int vetor[50];
    FillArray(vetor, sizeof(vetor)/sizeof(int));
    BubbleSort(vetor, sizeof(vetor)/sizeof(int));

    for(int i = 0; i<sizeof(vetor)/sizeof(int);i++)
        printf("%d ", vetor[i]);

    return 0;
}
