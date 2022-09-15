#include <stdio.h>
#include <stdlib.h>

struct no
{
    struct no *ant;
    int dado;
    struct no *prox;
};

typedef struct
{
    struct no *inicio;
    struct no *fim;
} listacircularde;

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

    insere(&lista,0);
    insere(&lista,6);
    insere(&lista,20);
    insere(&lista,14);
    insereOrdenado(&lista,  -2);

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
            } while (aux != q.inicio);
        }
        else
        {
            aux = q.fim;
            do
            {
                printf("%d ", aux->dado);
                aux = aux->ant;
            } while (aux != q.fim);
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
    struct no *troca;

    aux = q->inicio;
    if(q->inicio->dado == d){
        q->inicio = aux->prox;
        q->fim->prox = q->inicio;
    }
    while(aux->dado != d)
        aux = aux->prox;

    troca = aux->ant->prox;
    aux->ant->prox = aux->prox;
    aux->prox->ant = troca;

    free(aux);
}

int  insereOrdenado(listacircularde *q, int d)
{
    struct no *aux;
    struct no *inserir;
    inserir = (struct no*) malloc(sizeof(struct no));

    aux = q->inicio;
    do
    {

        if(d > (q->fim->dado)){
            inserir->dado = d;
            inserir->ant = q->fim;
            q->fim->prox = inserir;
            inserir->prox = q->inicio;
            q->inicio->ant = inserir;
            q->fim = inserir;
            return 1;
        }
        else if( d < (q->inicio->dado)){
            inserir->dado = d;
            inserir->prox = q->inicio;
            inserir->ant = q->fim;
            q->fim->prox = inserir;
            q->inicio->ant = inserir;
            q->inicio = inserir;
            return 0;
        }
        aux = aux->prox;
    }while(aux->dado < d);

    inserir->dado = d;
    printf("\n\n\t%d\n\n", aux->dado);
    printf("\n\n\t%d\n\n", inserir->dado);

    aux->ant->prox = inserir;
    aux->prox->ant = inserir;
    inserir->prox = aux;
    inserir->ant = aux->ant;
}

/*   while(aux->dado < d)
    {


        if (d > q->fim->dado)
            q->fim = q->inicio;
        aux = aux->prox;
    }

    if (d < aux->dado)
    {


    }

*/
