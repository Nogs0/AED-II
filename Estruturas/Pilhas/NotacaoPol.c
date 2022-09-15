#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    float valor;
    struct no *prox;
}No;

No* Push(No *pilha, float valor){
    No* aux = malloc(sizeof(No));
    if(aux){
    aux->valor = valor;
    aux->prox = pilha;
    return aux;
    }
    printf("Erro ao alocar!\n");
    return NULL;
}

No* Pop(No **pilha){
    No *remove = NULL;
    if(pilha){
    remove = *pilha;
    *pilha = remove->prox;
    }
    return remove;
}

float DescobreOp(float a, float b, char x){
    switch (x){
    case '+': return a+b;
        break;
    case '-': return a-b;
        break;
    case '/': return a/b;
        break;
    case '*': return a*b;
        break;
    default:
        return 0.0;
    }
}
float Resolve(char x[]){
    char *pt;
    float num;
    No *n1, *n2, *pilha = NULL;

    pt = strtok(x, " "); //Divide a string x sempre que encontrar um 'espaço'
    /* A função strtok(), cria tokens a partir da string, destruindo-a, colocando um \0 sempre quando encontra o
    delimitador, assim a cada substring criada dentro da string-mãe passa a ser um vetor de caracteres,
    referenciada a partir de índices. Esse o motivo de analisarmos sempre o pt[0], no if abaixo!*/
    while(pt){
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){ //5 3 2 * +
            n1 = Pop(&pilha);
            n2 = Pop(&pilha);
            num = DescobreOp(n2->valor, n1->valor, pt[0]);
            pilha = Push(pilha, num);
            free(n1);
            free(n2);
        }
        else{
            num = strtol(pt, NULL, 10); //Função que recebe 3 parâmetros, a stirng que contém o número, um ponteiro para ponteiro, no caso de armazenar o resto da string, base numerica
            //Função que transforma string em números
            pilha = Push(pilha, num);
        }
        pt = strtok(NULL, " "); // Continua analisando a string de onde parou
    }
    n1 = Pop(&pilha);
    num = n1->valor;
    return n1->valor;

}

int main(){
    char Expressao[50];

    printf("Entre com uma expressçao na notação polonesa: \n");
    scanf("%49[^\n]", Expressao);
    printf("Resultado = %.2f", Resolve(Expressao));
    return 0;
}
