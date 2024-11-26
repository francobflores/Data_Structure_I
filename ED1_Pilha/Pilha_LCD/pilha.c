#include "pilha.h"

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

No *Empilha(No *P, int valor){
    No *novo = criaNo(valor);
    if(P == NULL){
        P = novo;
        novo->prox = P;
        return P;
    }
    novo->prox = P->prox;
    P->prox = novo;
    return P; 
}
/* No *Desempilha (No *P){

} */

void imprimir_Pilha(No *P){
    if(P != NULL){
        No *aux = P->prox;
        do{
            printf("%d ", aux->chave);
            aux = aux->prox;
        }while(aux != P->prox);
        printf("\n");
    }else{
        printf("\n");
    }

}