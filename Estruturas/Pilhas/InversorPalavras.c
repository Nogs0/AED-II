#include <stdio.h>
#include <stdlib.h>

typedef struct no{ //Criação do struct Nó
    char dado;
    struct no *prox;
}No;

No* push(No *topo, char dado){ //Realiza a adição de um Nó à pilha e retorna o nó, se for possível alocar o nó
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
No* pop(No** pilha){ //Realiza a remoção de um Nó da pilha, se pilha != NULL, retorna o dado removido
    No *remove =NULL;
    if(*pilha){
        remove = *pilha;
        *pilha = remove->prox;
    }
    return remove;
}
void popVoid(No **topo){ // Realiza a remoção de um nó da pilha e não retorna nada
    No *remove;
    if(*topo!=NULL){
    remove = *topo;
    *topo = remove->prox;
    free(remove);
    }

}

void inverterPalavras(char frase[]){ // fuñção utilizada para reverter a palavra/frase dada
    No *remove, *pilha = NULL;
    int i=0;
    remove = (No *)malloc(sizeof(No));
    while(frase[i] != '\0'){ // Enquanto a string não tiver vazia
        if(frase[i] != ' '){ // Se a string for diferente de 'espaço'
            pilha = push(pilha, frase[i]); // Operação de push(adicionando nós a pilha)
        }
        else{//se for encontrado um espaço
            while(pilha){ // se pilha != NULL
                remove = pop(&pilha); // Operação de remoção na pilha
                printf("%c", remove->dado); // Imprimindo o dado removido
                free(remove);//Libera a memória alocada pelo remove
            }
            printf(" ");
        }
        i++;
    }
    while(pilha){ //While usado para printar a última palavra digitada, pois o primeiro while não permite a entrada no último caractere, assim não executando o else no seu escopo
        remove = pop(&pilha);
        printf("%c", remove->dado);
        free(remove);
    }
    printf("\n");
}
int main(){
    char frase[80];
    printf("Digite uma frase:\n");
    scanf("%79[^\n]", frase); //Scanf personalzado para não finalizar sua leitura com o espaço e também que limita o tamanho da string a ser recebida
    printf("Inversão:\n");
    inverterPalavras(frase);

}
