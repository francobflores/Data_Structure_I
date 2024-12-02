#include <stdlib.h>
#include <stdio.h>

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

No *insereInicio(No *L, int valor){
    No *novo = criaNo(valor);
    novo->prox = L;
    L = novo;
    return L;
}
// 1 Função para que cria e retorna uma LSE L com
// números inteiros fornecidos pelo usuário.
No *criaLista(){
    No *L = NULL;
    int op;

    do{
        printf("(1) Para inserir um elemeno na lista.\n");
        printf("(2) Para encerrar a criação da lista.\n");
        
        scanf("%d",&op);
        if(op == 1){
            int valor;
            printf("Digite o valor a ser inserido.\n");
            scanf("%d", &valor);
            L=insereInicio(L, valor);}
        else{ if(op != 2){
            printf("opção inválida\n\n");}
        }
        }while(op != 2);
        
        return L;
}
// 3 Função para imprimir uma LSE na Tela
void imprimir_LSE(No *L){
    No*aux = L;
    if(L != NULL){
        while(aux != NULL){
            printf("[%d]", aux->chave);
            aux = aux->prox;
        }
    }printf("\n\n\n");
}

// 4 Função para concatenar duas LSE.
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

No* ExcluiRepetidos(No* L) {
    No* aux = L;
    No* pred = aux;
    No* aux2 = aux->prox;

    if (L == NULL)
        return L;

    while (aux->prox != NULL) {
        while (aux2 != NULL) {
            if (aux->chave == aux2->chave) {
                pred->prox = aux2->prox;
                free(aux2);
                aux2 = pred->prox;
            } else {
                pred = aux2;
                aux2 = aux2->prox;
            }
        }
        aux = aux->prox;
        pred = aux;
        aux2 = aux->prox;
    }
    return L;
}



/* int main(){
    No *L = criaLista();
    printf("AGORA PARA LISTA 2\n\n");
    No *L2 = criaLista();
    printf("L1: ");
    imprimir_LSE(L);
    printf("L2: ");
    imprimir_LSE(L2);
    concatenaLSE(L, L2);
    printf("\n\n");

    printf("Lista: ");
    imprimir_LSE(L);
    return 0;
} */

 int main(){
    No *L = criaLista();
    printf("AGORA PARA LISTA 2\n\n");
    /* No *L2 = criaLista(); */
    printf("L1: ");
    imprimir_LSE(L);
    L = ExcluiRepetidos(L);
    printf("L1 depois de excluir repetidos: ");
    imprimir_LSE(L);


    /* printf("L2: ");
    imprimir_LSE(L2);
    concatenaLSE(L, L2); */
    printf("\n\n");

    printf("Lista: ");
    imprimir_LSE(L);
    return 0;
} 
