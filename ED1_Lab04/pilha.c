#include "pilha.h"


No *criaNo(char x){
    No *novo;
    novo =(No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("ERRO");
        exit(1);
    }
    novo->simb = x;
    novo->prox = NULL;

    return novo;
}

No *Empilha(No *Pilha, char x){
    No *novo = criaNo(x);
    novo->prox = Pilha;
    Pilha = novo;
    return Pilha;
}

No *Desempilha (No *Pilha){
       No*aux = Pilha;
    if(Pilha == NULL)
        return Pilha;
    Pilha = Pilha->prox;
    free(aux);
    return Pilha;
}


void imprimir_Pilha(No *Pilha){
    No*aux = Pilha;
    if(Pilha != NULL){
        while(aux != NULL){
            printf("[%c]", aux->simb);
            aux = aux->prox;
        }
    }printf("\n\n");
}