#include <stdio.h>

void InsertionSort(int veotr[], int tamanho);

int main(){
    int vetor[] = {1,9,8,2,3,7,4,5,6,0};
    InsertionSort(vetor, sizeof(vetor)/sizeof(int));
    for(int i = 0; i<sizeof(vetor)/sizeof(int); i++)
        printf("%d  ", vetor[i]);
}
void InsertionSort(int vetor[], int tamanho){
    int i, j, aux;

    for(i = 1;i<tamanho;i++){
        aux = vetor[i];
        j = i-1;
        while(j>=0 && vetor[j] > aux){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = aux;
    }
}

/*for(j=i-1; j>=0;j--){
    if(vetor[j] < aux)
        vetor[j+1] = vetor[j];
}*/
