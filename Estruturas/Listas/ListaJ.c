#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    struct no *prox;
    int dado;
    struct no *ant;
} No;

typedef struct
{
    No *inicio;
    No *fim;
} Lista;

void criarLista(Lista *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
}

int inserir(Lista *lista, int dado)
{
    No *aux = malloc(sizeof(No));

    if(aux)
    {
        aux->dado = dado;
        if(lista->inicio == NULL)
        {
            lista->inicio = lista->fim = aux;
            aux->prox = lista->inicio;
            aux->ant = lista->fim;
            return 1;
        }

        aux->ant = lista->fim;
        lista->fim->prox = aux;
        aux->prox = lista->inicio;
        lista->inicio->ant = aux;
        lista->fim = aux;
        return 1;
    }
    else return 0;

}

void imprimir(Lista lista, int sentido)
{

    No  *aux;
    if(lista.fim == NULL)
        printf("Lista Vazia!\n");
    else
    {
        if(sentido == 0)
        {
            aux = lista.inicio;

            do
            {
                printf("%d ", aux->dado);

                aux = aux->prox;
            }
            while(aux !=lista.inicio);
        }
        else
        {

            aux = lista.fim;

            do
            {
                printf("%d ", aux->dado);
                aux = aux->prox;
            }
            while(aux != lista.fim);
        }
    }

}

int VerificaLista(Lista lista)
{
    if(lista.inicio == NULL)
        return 1;
    return 0;
}

int remover(Lista *lista, int dado)
{
    No *remove = NULL;

    if(lista->inicio == NULL)
    {
        printf("Lista Vazia!\n");
        return 0;
    }
    else
    {
        remove = lista->inicio;
        do
        {
            if(remove->dado == dado)
            {
                if( remove == lista->inicio && remove == lista->fim)
                {
                    lista->inicio = NULL;
                    lista->fim = NULL;
                    free(remove);
                }

                remove->ant->prox = remove->prox;
                remove->prox->ant = remove->ant;

                if(remove == lista->inicio)
                    lista->inicio = remove->prox;
                if(remove == lista->fim)
                    lista->fim = remove->ant;
                free(remove);
                return 1;
            }
            remove = remove->prox;
        }
        while(remove!= lista->inicio);
        return 0;
    }
}

int InsereOrdenado(Lista *lista, int dado)
{
    No *aux, *novo;
    if(lista->inicio == NULL)
    {
        inserir(lista, dado);
    }
    else
    {
        aux = lista->inicio;
        do
        {
            if(aux->dado > dado)
            {
                novo = (No*)malloc(sizeof(No));
                if(novo)
                {
                    novo->dado = dado;
                    aux->ant->prox = novo;
                    novo->ant=aux->ant;
                    aux->ant = novo;
                    novo->prox = aux;
                }
                else return 0;
            }
            aux= aux->prox;
        }
        while(aux != lista->inicio);
        inserir(lista, dado);
    }
    return 1;
}

int main()
{
    Lista lista;
    criarLista(&lista);
    int option, value;

    do
    {
        printf("\n\nEscolha o que deseja fazer:\n1-Adicionar dado à lista\n2-Remover dado da lista\n3-Mostrar a lista em sentido crescente\n4-Mostrar a lista em sentido decrescente\n5-Sair\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Digite o numero cujo queira adicionar: ");
            scanf("%d", &value);
            InsereOrdenado(&lista, value);
            break;
        case 2:
            if(lista.inicio != NULL)
            {
                printf("Digite o dado cujo queira remover: ");
                scanf("%d", &value);
                remover(&lista, value);
            }
            else
            {
                printf("Lista Vazia!\n");
            }
            break;
        case 3:
            printf("Mostrando a lista em sentido crescente:\n");
            imprimir(lista, 0);
            break;
        case 4:
            printf("Mostrando a lista em sentido decrescente:\n");
            imprimir(lista, 1);
            break;
        default:
            if(option != 5){
            printf("Digite uma opcao valida: ");
            scanf("%d", &option);
            }
        }
    }
    while(option != 5);


    return 0;
}
