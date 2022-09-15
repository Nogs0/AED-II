#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *prox;
} No;

No* Push(No *pilha, int num)
{
    No *aux;
    aux = (No *)malloc(sizeof(No));
    if(aux){
        aux->dado = num;
        aux->prox = pilha;
        return aux;
    }
    else printf("Erro ao alocar memória!\n");
    return NULL;
}

/*void Pushvoid(No **pilha, int num)
{
    No *aux;
    aux = (No *)malloc(sizeof(No));
    if(aux)
    {
        aux->dado = num;
        aux->prox = *pilha;
        *pilha = aux;
    }
}*/

No* Pop(No **pilha){
    No *removido = NULL;

    if(*pilha){
        removido = *pilha;
        *pilha = removido->prox;
        return removido;
    }
    else printf("Pilha vazia!");
    return NULL;
}

void PrintPilha (No *pilha){
    printf("\n\tPILHA\n");
    while(pilha){
        printf("\t%d\n", pilha->dado);
        pilha = pilha->prox;
    }
    printf("\n");
}

int Fatorial(int num){
    No *pilha = NULL, *remover = NULL;
    while(num>1){
        pilha = Push(pilha, num);
        num--;
    }

    PrintPilha(pilha);

    while(pilha){
        remover = Pop(&pilha);
        num = num * remover->dado;
        free(remover);
    }
    return num;
}
int main()
{
    int valor;
    printf("Digite p numero cujo queira o fatorial: ");
    scanf("%d", &valor);
    printf("\tFatorial de  %d: %d\n", valor, Fatorial(valor));


    return 0;
}
