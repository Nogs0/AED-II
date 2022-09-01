#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    char telefone[15];
}AgendaTel;

void QuickSort(AgendaTel Lista[], int tam);
void q_sort(AgendaTel Lista[], int left, int right);
void swap(AgendaTel*, AgendaTel*);

int main(){
    AgendaTel ListaTel[10];
    int option = 0, numeros = 0;

    do{
        printf("Escolha uma opcao:\n1 - Incluir Numero\n2 - Mostrar Agenda:\n3 - Sair\n");
        scanf("%d", &option);
        switch (option){
            case 1: printf("Enter with name: ");
                    scanf("%s", ListaTel[numeros].nome);
                    printf("Enter with number: ");
                    scanf("%s", ListaTel[numeros].telefone);
                    numeros++;
                    break;
            case 2: printf("Agenda:\n");
                    QuickSort(ListaTel, numeros);
                    for(int i = 0; i<numeros;i++){
                        printf("Contato #%d\n", i+1);
                        printf("Nome: %s Telefone: %s\n", ListaTel[i].nome, ListaTel[i].telefone);
                    }
                    break;
        }
    }while(option !=3);
    return 0;
}

void QuickSort(AgendaTel Lista[], int tam){
    q_sort(Lista, 0, tam-1);
}

void q_sort(AgendaTel Lista[], int left, int right){
    int i, j;
    AgendaTel pivo, aux;

    i = left;
    j = right;
    pivo = Lista[(left+right)/2];

    while(i<=j){
        while(strcmp(Lista[i].nome, pivo.nome)<0)
            i++;
        while(strcmp(Lista[j].nome, pivo.nome)>0)
            j--;
        if(i<=j){
            aux = Lista[i];
            Lista[i]=Lista[j];
            Lista[j]=aux;
            i++;
            j--;
        }
        }
    if(j>left)
        q_sort(Lista, left, j);
    if(i<right)
        q_sort(Lista, i, right);
}

void swap(AgendaTel *n1, AgendaTel *n2){

    AgendaTel aux;

    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}
