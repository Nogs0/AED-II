#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
}No;

void Push(No **fila, int dado){
    No *aux, *novo = (No*)malloc(sizeof(No));
    if(novo){
        novo->dado = dado;
        novo->prox = NULL;
        if(*fila){
            aux = *fila;
            while(aux->prox)
                aux = aux->prox;
            aux->prox = novo;
        }
        else{
         *fila = novo;
        }
    }
}

No* Pop(No **fila){
    No *aux = NULL;

    if(*fila){
        aux = *fila;
        *fila = aux->prox;
    }
    else
        printf("Fila vazia!\n");
    return aux;
}

void ImprimirFila(No *fila){
    No *aux = NULL;
    aux = fila;
    if(fila){
    printf("Fila: ");
    while(aux){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
    }
    else printf("Fila Vazia!\n");

}
int main(){
    No* Fila = NULL, *r;
    int valor, option = 0;
    do{
        printf("\t---------Demonstração de Pilhas--------\n");

        printf("Faca sua escolha:\n\t0-Sair\n\t1-Inserir\n\t2-Remover\n\t3-Imprimir\n");
        scanf("%d", &option);

        switch (option){
            case 1:
                printf("Digite o numero cujo queira inserir: ");
                scanf("%d", &valor);
                Push(&Fila, valor);
                break;
            case 2:
                r = Pop(&Fila);
                if(r) printf("%d removido!", r->dado);
                break;
            case 3:
                ImprimirFila(Fila);
                break;

        }
    }while(option != 0);

    return 0;
}
