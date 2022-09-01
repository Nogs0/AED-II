#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char telefone[15];
}AgendaTel;

void OrdenaLista(AgendaTel nomes[], int tam);
int main(){
    AgendaTel ListaTel[10];
    int numeros = 0, option = 0;
    do{
    printf("Escolha uma opcao: \n 1 - INCLUIR NUMERO \n 2 - MOSTRAR AGENDA \n 3 - SAIR\n");
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
    }
    }while(option != 3);

    return 0;
}

void OrdenaLista(AgendaTel lista[], int tam){
    int i, j, menor;
    AgendaTel aux;

    for(i=0; i<tam-1;i++){
        menor = i;
        for(j=i+1;j<tam;j++){
            if(strcmp(lista[j].nome,lista[menor].nome)>0)
            menor = j;
        }
        aux = lista[i];
        lista[i] = lista[menor];
        lista[menor] = aux;

    }
}


