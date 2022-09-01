#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char telefone[15];
}AgendaTel;

int BuscaContato(AgendaTel lista[], char dado[], int fim);
int BuscaBinaria(AgendaTel lista[], char dado[], int inicio, int fim);
void OrdenaLista(AgendaTel nomes[], int tam);
int main(){
    AgendaTel ListaTel[10];
    int numeros = 0, option = 0, busca = 0;
    char dadoBusca[50];
    do{
    printf("Escolha uma opcao: \n 1 - INCLUIR NUMERO \n 2 - MOSTRAR AGENDA \n 3 - BUSCAR CONTATO\n");
    scanf("%d", &option);
    switch(option){
        case 1: printf("Insira seu nome: ");
                scanf("%s", ListaTel[numeros].nome);
                printf("Insira o numero de telefone: ");
                scanf("%s", ListaTel[numeros].telefone);
                numeros++;
                break;

        case 2: printf("Mostrando agenda...\n");
                printf("===================\n");
                OrdenaLista(ListaTel, numeros);
                for(int i =0;i<numeros;i++)
                    printf("Nome: %s\nTelefone: %s\n\n", ListaTel[i].nome, ListaTel[i].telefone);
                break;
        case 3: printf("Buscar contato: ");
                OrdenaLista(ListaTel, numeros);
                scanf("%s", dadoBusca);
                busca = BuscaBinaria(ListaTel, dadoBusca, 0, numeros);
                if(busca>=0)
                    printf("Contato: %s\n", ListaTel[busca].telefone);
                break;
                }
    }while(option != 4);

    return 0;
}

void OrdenaLista(AgendaTel lista[], int tam){
    int i, j, menor;
    AgendaTel aux;

    for(i=0; i<tam-1;i++){
        menor = i;
        for(j=i+1;j<tam;j++){
            if(strcmp(lista[j].nome,lista[menor].nome)<0)
            menor = j;
        }
        aux = lista[i];
        lista[i] = lista[menor];
        lista[menor] = aux;

    }
}

/*int BuscaContato(AgendaTel lista[], char dado[], int fim){
    int i;
    for(i = 0; i<fim ;i++){
        if(strcmp(lista[i].nome, dado)==0){
            return i;
        }
    }
    return -1;
}*/

int BuscaBinaria(AgendaTel lista[], char dado[], int inicio, int fim){

    int meio = (inicio+fim)/2;

    if(strcmp(lista[meio].nome, dado)==0)
        return meio;
    if(inicio >= fim)
        return -1;
    if(strcmp(dado, lista[meio].nome)<0)
        BuscaBinaria(lista, dado, inicio, meio-1 );
    else
        BuscaBinaria(lista, dado, meio+1, fim);
}

