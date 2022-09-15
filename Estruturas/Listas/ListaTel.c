#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    char telefone[15];
}AgendaTel;

typedef struct no{
    struct no *ant;
    AgendaTel contato;
    struct no *prox;
}No;

typedef struct lista{
    No *inicio;
    No *fim;
}Lista;

void criarLista(Lista *lista);
int EstaVazia(Lista lista);
int insere(Lista *lista);

int main(){

    Lista lista;
    criarLista(&lista);
    insere(&lista);
    ImprimirLista(lista);
    return 0;
}

void criarLista(Lista *lista){
    lista->inicio =NULL;
    lista->fim =NULL;
}
AgendaTel lercontato(Lista *agenda){
    AgendaTel aux;
    char nome[30];
    char numero[20];

        printf("Digite o nome: ");
        scanf("%s", nome);
        printf("\nDigite o numero: ");
        scanf("%s", numero);
        strcpy(aux.nome, nome);
        strcpy(aux.telefone, numero);

        return aux;
}
int insere(Lista *lista){
    No *aux = malloc(sizeof(No));

    if(aux){
        aux->contato = lercontato(lista);
        if(aux){
        if(lista->inicio == NULL){
            lista->inicio = lista->fim = aux;
            aux->ant = lista->fim;
            aux->prox = lista->inicio;
            return 1;
        }

        aux->ant = lista->fim;
        lista->fim->prox = aux;
        aux->prox = lista->inicio;
        lista->inicio->ant = aux;
        lista->fim = aux;
        return 1;
    }
    }
    else
    return 0;
    return 0;
}
int ImprimirLista(Lista lista){
    No *aux;
    aux = lista.inicio;

    if(lista.inicio == NULL){
        printf("A lista está vazia!\n");
        return 0;
    }
    do{
        printf("Nome: %s\nTelefone: %s\n", aux->contato.nome, aux->contato.telefone);
        printf("--------------\n");
        aux= aux->prox;
    }while(aux != lista.inicio);
    return 0;
}
int EstaVazia(Lista lista){
    if(lista.inicio == NULL)
        return 1;
    return 0;
}
