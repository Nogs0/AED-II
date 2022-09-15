#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int dado;
    struct no *prox;
}No;

No* push(No *topo, int dado){
    No* novo;
    novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->dado = dado;
        novo->prox = topo;
        return novo;
    }
    else{
        printf("Não foi possível alocar memória para este nó");
        return NULL;
    }
}
No* pop(No* topo){
    No *remove;
    if(topo!=NULL){
    remove = topo;
    topo = topo->prox;
    free(remove);
    return topo;
    }
    else{
        printf("A pilha está vazia...");
        return NULL;
    }
}
void popVoid(No **topo){
    No *remove;
    if(*topo!=NULL){
    remove = *topo;
    *topo = remove->prox;
    free(remove);
    }

}
void printPilha(No *topo){
    No* aux;
    aux = topo;
    if(aux == NULL){
        printf("Pilha vazia!\n\n");
    }
    while(aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
}
int main(){

    No *topo = NULL;
    printPilha(topo);
    topo = push(topo, 4);
    topo = push(topo, 5);
    printPilha(topo);
    //topo = pop(topo);
    topo = pop(topo);
    //popVoid(&topo);
    popVoid(&topo);
    popVoid(&topo);
    printf("\n");
    printPilha(topo);

}
