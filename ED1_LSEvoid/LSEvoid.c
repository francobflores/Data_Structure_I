#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
}No;

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
void insereInicio(No **L, int valor){
    No *novo = criaNo(valor);
    novo->prox = *L;
    *L= novo;
}

//função para imprimir uma LSE.
void imprimir_LSE(No *L){
    No*aux = L;
    if(L != NULL){
        while(aux != NULL){
            printf("[%d]", aux->chave);
            aux = aux->prox;
        }
    }printf("\n\n");
}
int main(){
    No *L1 = NULL;

    insereInicio(&L1, 9);
    insereInicio(&L1, 15);

    imprimir_LSE (L1);


    return 0;
}