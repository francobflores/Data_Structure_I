#include "LSE.h"

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
//Função para inserir um nó no inicio da lista.
No *insereInicio(No *L, int valor){
    No *novo = criaNo(valor);
    novo->prox = L;
    L = novo;
    return L;
}

//Função para inserir um nó no final da lista.
No *insereFinal(No *L, int valor){
    No *novo = criaNo(valor);
    No *aux = L;
    if(L == NULL){
        L = novo;
    }else{
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return L;
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

//Função para concatenar duas LSE.
No *concatenaLSE(No *L1, No *L2){
    No *aux = L1;
    if(L1 == NULL){
        L1 = L2;
        L2 = NULL;
        return L1;
    }
    if(L2 == NULL){
        return L1;
    }
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = L2;
    L2 = NULL;
    return L1;
}

//Função que exclui o primeiro elemento da lista.
No *excluiInicio(No* L){
    No*aux = L;
    if(L == NULL)
        return L;
    L = L->prox;
    free(aux);
    return L;
}

//Função que exclui o ultimo elemento da lista.
No *excluiFinal(No *L){
    No *aux = L;
    No *pred = NULL;
    if(L == NULL)
        return NULL;
    while(aux->prox != NULL){
        pred = aux;
        aux = aux->prox;
    }
    if(pred == NULL)
        L = NULL;
    else
        pred->prox = NULL;
    free(aux);
    return L;
}

//Função para excluir uma chave buscada na LSE
No *excluiChave(No *L, int chave){
    No *aux = L;
    No *pred = NULL;
    if(L == NULL)
        return L;
    else{
        while(aux != NULL && aux->chave != chave){
            pred = aux;
            aux = aux->prox;
        }
        if(aux == NULL)
            return L;//chave nao encontrada.
        if(pred == NULL){
            L = aux->prox;
        }
        else{
            pred->prox = aux->prox;
        }
        free(aux);
        return L;
    }    
}
