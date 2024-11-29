#include <stdlib.h>
#include <stdio.h>

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

//Função para inserir um nó em uma lista ordenada nao descrescente do tipo LSE.
No *insereOrdenado1(No *L, int valor){
    No *novo = criaNo(valor);
    No *aux = L;
    No *pred = NULL;
    if(L == NULL){
        L = novo;
        return L;
    }else{
        while(aux != NULL && aux->chave <= valor){
            pred = aux;
            aux = aux->prox;
        }
        if(pred == NULL){
            novo->prox = L;
            L = novo;
        }else{
            pred->prox = novo;
            novo->prox = aux;
        }
        return L;
    }
}

//Função para inserir um nó em uma lista ordenada nao crescente do tipo LSE.
No *insereOrdenado2(No *L, int valor){
    No *novo = criaNo(valor);
    No *aux = L;
    No *pred = NULL;
    if(L == NULL){
        L = novo;
        return L;
    }else{
        while(aux != NULL && aux->chave >= valor){
            pred = aux;
            aux = aux->prox;
        }
        if(pred == NULL){
            novo->prox = L;
            L = novo;
        }else{
            pred->prox = novo;
            novo->prox = aux;
        }
        return L;
    }
}

//função para excluir uma chave em uma LSE Ordenada
No *excluiChaveOrdenada(No *L, int valor){
    No *aux = L;
    No *pred = NULL;
    if(L == NULL){
        return NULL;
    }
    while(aux != NULL && valor > aux->chave){
        pred = aux;
        aux = aux->prox;
    }
    if(aux !=NULL && aux->chave == valor){    
        if(pred == NULL){
        L= aux->prox;
        }
        else{
            pred->prox = aux->prox;
        }
        free(aux);
    }
    
    return L;
}
//Função principal para testar a inserção Ordenada nao descresente na LSE

/* int main(){
    No *L = NULL;

    L = insereOrdenado1(L, 10);
    L = insereOrdenado1(L, 50);
    L = insereOrdenado1(L, 8);
    L = insereOrdenado1(L, 90);
    L = insereOrdenado1(L, 70);
    printf("Lista: ");
    imprimir_LSE(L);
    return 0;
} */

//Função principal para testar a inserção Ordenada não crescente na LSE

/* int main(){
    No *L = NULL;

    L = insereOrdenado2(L, 90);
    L = insereOrdenado2(L, 90);
    L = insereOrdenado2(L, 90);
    L = insereOrdenado2(L, 90);
    L = insereOrdenado2(L, 90);
    
    printf("Lista: ");
    imprimir_LSE(L);
    return 0;
} */

int main(){
    No *L = NULL;

    L = insereOrdenado1(L, 10);
    L = insereOrdenado1(L, 50);
    L = insereOrdenado1(L, 8);
    L = insereOrdenado1(L, 90);
    L = insereOrdenado1(L, 70);
    printf("Lista: ");
    imprimir_LSE(L);

    L = excluiChaveOrdenada(L, 100);
    L = excluiChaveOrdenada(L, 8);
    L = excluiChaveOrdenada(L, 50);
    L = excluiChaveOrdenada(L, 90);
    printf("Lista pós exclusão: ");
    imprimir_LSE(L);

    return 0;
}

/* int main(){
    return 0;
} */