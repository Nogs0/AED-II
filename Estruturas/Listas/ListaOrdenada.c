#include <stdio.h>
#include <stdlib.h>

struct no
{
    struct no *ant;
    int dado;
    struct no *prox;
} No;

typedef struct
{
    struct no *inicio;
    struct no *fim;
} listacircularde;
int InsereO(listacircularde *lista, int dado);
void cria(listacircularde *q);
int  insere(listacircularde *q, int dado);
void mostra(listacircularde q, int sentido);
int  estaVazia(listacircularde q);

int  retira(listacircularde *q, int d);
int  insereOrdenado(listacircularde *q, int d);

int main()
{
    listacircularde lista;
    cria(&lista);
    InsereO(&lista, 4);
    InsereO(&lista, 2);

    if (!estaVazia(lista))
    {
        printf("Apresentando a lista do inicio para o fim...\n");
        printf("============================================\n");
        mostra(lista,0);
        printf("\n\n");
        printf("Apresentando a lista do fim para o inicio...\n");
        printf("============================================\n");
        mostra(lista,0);
        printf("\n\n");
    }
    else
        printf("Lista vazia...\n\n");


}

void cria(listacircularde *q)
{
    q->inicio = NULL;
    q->fim = NULL;
}

int  insere(listacircularde *q, int d)
{
    struct no *aux;
    aux = (struct no*) malloc(sizeof(struct no)); //declarãção e alocação de memória para o ponteiro
    if (aux == NULL)
        return 0;

    if (q->inicio == NULL)
    {
        aux->dado = d;
        q->inicio = q->fim = aux;
        aux->prox = q->inicio;
        aux->ant = q->fim;
        return 1;
    }

    aux->dado = d;
    aux->ant = q->fim;
    q->fim->prox = aux;
    aux->prox = q->inicio;
    q->inicio->ant = aux;
    q->fim = aux;

    return 1;
}

void mostra(listacircularde q, int sentido)
{
    struct no *aux;
    if (q.inicio == NULL)
        printf("Lista vazia...\n\n");
    else
    {
        if (sentido == 0)
        {
            aux = q.inicio;
            do
            {
                printf("%d ", aux->dado);
                aux = aux->prox;
            }
            while (aux != q.inicio);
        }
        else
        {
            aux = q.fim;
            do
            {
                printf("%d ", aux->dado);
                aux = aux->ant;
            }
            while (aux != q.fim);
        }
    }
}

int  estaVazia(listacircularde q)
{
    if (q.inicio == NULL)
        return 1;
    return 0;
}

int  retira(listacircularde *q, int d)
{
    struct no *aux;

    if(q->inicio == NULL) return 1;
    else
    {
        do
        {
            if(aux->dado == d)
            {
                if(aux == q->inicio && aux == q->fim)
                {
                    free(aux);
                    q->inicio = q->fim = NULL;
                }

                aux->prox->ant = aux->ant;
                aux->ant->prox = aux->prox;

                if(aux == q->inicio)
                    q->inicio = aux->prox;
                if(aux == q->fim)
                    q->fim = aux->ant;

                free(aux);
                return 1;
            }
            aux = aux->prox;
        }
        while( aux != q->inicio);

        return 0;
    }
}
/*int  insereOrdenado(listacircularde *q, int d)
{
    struct no *aux, *inserir;
    inserir = (struct no*) malloc(sizeof(struct no));

    aux = q->inicio;
    do
    {

        if(d > (q->fim->dado))
        {
            inserir->dado = d;
            inserir->ant = q->fim;
            q->fim->prox = inserir;
            inserir->prox = q->inicio;
            q->inicio->ant = inserir;
            q->fim = inserir;
            return 1;
        }
        else if( d < (q->inicio->dado))
        {
            inserir->dado = d;
            inserir->prox = q->inicio;
            inserir->ant = q->fim;
            q->fim->prox = inserir;
            q->inicio->ant = inserir;
            q->inicio = inserir;
            return 0;
        }
        if(aux == NULL)
        {
            inserir->dado = d;
            q->inicio = q->fim = inserir;
            inserir->prox = q->inicio;
            inserir->ant = q->fim;
            return -1;
        }
        aux = aux->prox;
    }
    while(aux->dado < d);
}*/

int InsereO(listacircularde *lista, int dado)
{
    struct no *aux, *novo;

    if(lista->inicio == NULL)
    {
        return insere(lista, dado);
    }
    else
    {
                aux = lista->inicio;
        do
        {


            if(aux->dado > dado)
            {
                novo = (struct no*)malloc(sizeof(struct no));

                if(novo == NULL)
                    return 0;

                novo->dado = dado;
                novo->prox = aux;
                novo->ant = aux->ant;
                aux->ant->prox = novo;
                aux->ant = novo;

                if(lista->inicio == aux)
                    lista->inicio = novo;
                return 1;
            }
            aux = aux->prox;
        }
        while(aux != lista->inicio);

        insere(lista, dado);
    }
}
