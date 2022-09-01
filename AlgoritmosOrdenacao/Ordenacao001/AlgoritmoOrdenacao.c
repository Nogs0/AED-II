#include <stdio.h>

void selection(int vetor[], int tamanho);
void q_sort(int vetor[], int left, int right);
int main(){
    int vetor[] = {1, 8, 4, 6, 3, 2, 5, 0, 9, 7};
    for(int i=0; i<sizeof(vetor)/sizeof(int); i++)
        scanf("%d", &vetor[i]);

    q_sort(vetor, sizeof(vetor)/sizeof(int));

    for(int i=0; i<sizeof(vetor)/sizeof(int); i++)
        printf("%d  ", vetor[i]);

}

void selection(int vetor[], int tamanho){
    int i, j, aux, menor;
    for(i=0;i<tamanho;i++){
        menor = i;
        for(j=i+1;j<=tamanho-1;j++){
            if(vetor[menor] > vetor[j])
                menor = j;
        }
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;

    }
}

void q_sort(int vetor[], int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = vetor[(left + right) / 2];

    while(i <= j) {
        while(vetor[i] < x && i < right) {
            i++;
        }
        while(vetor[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        q_sort(vetor, left, j);
    }
    if(i < right) {
        q_sort(vetor, i, right);
    }
}

void quick_sort(int vetor[], int n) {
    q_sort(vetor, 0, n-1);
}
