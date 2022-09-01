#include <stdio.h>

void SelectionSort(int vetor[], int tamanho);

int main(){
    int i, vetor[] = {1,9,8,2,3,7,4,5,6,0};

    SelectionSort(vetor, sizeof(vetor)/sizeof(int));

    for(i=0;i<sizeof(vetor)/sizeof(int);i++)
        printf("%d  ", vetor[i]);

}

void SelectionSort(int vetor[], int tamanho){
    int i, j, aux, IndiceMenor;

    for(i=0;i<tamanho-1;i++){
        IndiceMenor = i;
        for(j=i+1; j<tamanho;j++){
            if(vetor[IndiceMenor] < vetor[j])
                IndiceMenor = j;
        }
        aux = vetor[i];
        vetor[i] = vetor[IndiceMenor];
        vetor[IndiceMenor] = aux;
    }
}
