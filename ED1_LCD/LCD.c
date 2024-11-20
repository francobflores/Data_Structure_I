#include<stdio.h>
#include<stdlib.h>

//estrutura para um nó renomeado para No.
typedef struct no{
    int chave;
    struct no *prox;
}No;

//função para criar um nó recebendo uma valor para o campo chave.
No *criaNo(int valor){
    No *novo;
    novo =(No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("ERRO");
        exit(1);
    }
    novo->chave = valor;
    novo->prox = NULL;

    return novo;
}

//função que insere um nó no inicio de uma Lista Circular
No *insereInicio(No *L, int valor){
    No *novo = criaNo(valor);
    if(L == NULL){
        L = novo;
        novo->prox = L;
        return L;
    }
    novo->prox = L->prox;
    L->prox = novo;
    return L; 
}

//função que insere um nó no final de uma Lista Circular

//função para imprimir uma LCD
void imprime(No *L){
    if(L != NULL){
        No *aux = L->prox;
        do{
            printf("%d ", aux->chave);
            aux = aux->prox;
        }while(aux != L->prox);
        printf("\n");
    }else{
        printf("\n");
    }

}


int main(){
    No *L = NULL;

    L = insereInicio(L, 10);
    L = insereInicio(L, 15);
    L = insereInicio(L, 12);
    L = insereInicio(L, 18);

    printf("Lista: ");
    imprime(L);
    return 0;
}