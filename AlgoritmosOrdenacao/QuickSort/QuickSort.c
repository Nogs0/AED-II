#include <stdio.h>
void q_sort(int vetor[], int left, int right){
    int esquerda = left;
    int direita = right;
    int pivo = vetor[(right+left)/2];
    int temp = 0;

    while(esquerda<=direita){
        while(vetor[esquerda] < pivo && esquerda < right)
            esquerda++;
        while(vetor[direita] > pivo && direita > left)
            direita--;

        if(esquerda <= direita){

            temp = vetor[esquerda];
            vetor[esquerda] = vetor [direita];
            vetor[direita] = temp;
            esquerda++;
            direita--;
        }
    }
    if(direita > left)
        q_sort(vetor, left, direita);
    if(esquerda < right)
        q_sort(vetor, esquerda, right);
}
void quick_sort(int vetor[], int n)
{
    q_sort(vetor, 0, n-1);
}
int main()
{
    int vetor[] = { 4, 6, 7, 1, 0, 9, 8, 5 };
    quick_sort(vetor, sizeof(vetor)/sizeof(int));

    for(int i = 0;i<8;i++)
        printf("%d ", vetor[i]);
    return 0;
}
