#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *prox;
} No;

typedef struct lista {
    No *sentinela;
} Lista;

Lista* criaLista() {
    Lista *L = (Lista*)malloc(sizeof(Lista));
    if (L == NULL) {
        printf("ERRO: Falha ao alocar memória\n");
        exit(1);
    }
    L->sentinela = (No*)malloc(sizeof(No));
    if (L->sentinela == NULL) {
        printf("ERRO: Falha ao alocar memória para sentinela\n");
        free(L);
        exit(1);
    }
    L->sentinela->prox = NULL; // Inicializa a lista vazia com sentinela apontando para NULL
    return L;
}

No* criaNo(int valor) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("ERRO: Falha ao alocar memória\n");
        exit(1);
    }
    novo->chave = valor;
    novo->prox = NULL;
    return novo;
}

void insereInicio(Lista *L, int valor) {
    No *novo = criaNo(valor);
    novo->prox = L->sentinela->prox;
    L->sentinela->prox = novo;
}
void excluiInicio(Lista* L) {
    if (L->sentinela->prox != NULL) {
        No* aux = L->sentinela->prox;
        L->sentinela->prox = aux->prox;
        free(aux);
    }
}


void insereFinal(Lista *L, int valor) {
    No *novo = criaNo(valor);
    No *aux = L->sentinela;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
}

void excluiFinal(Lista *L) {
    if (L->sentinela->prox != NULL) {
        No* aux = L->sentinela->prox;
        No* pred = NULL;
        while (aux->prox != NULL) {
            pred = aux;
            aux = aux->prox;
        }
        if (pred != NULL) {
            pred->prox = NULL;
        } else {
            L->sentinela->prox = NULL;
        }
        free(aux);
    }
}


void imprime(Lista *L) {
    No *aux = L->sentinela->prox;
    while (aux != NULL) {
        printf("[%d] ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

int main() {
    Lista *L = criaLista();
    // Testes de Inserção no Início
    insereInicio(L, 10);
    insereInicio(L, 20);
    printf("Após inserir no início: ");
    imprime(L);

    // Testes de Inserção no Final
    insereFinal(L, 30);
    insereFinal(L, 40);
    printf("Após inserir no final: ");
    imprime(L);

    // Testes de Lista Vazia
    Lista *vazia = criaLista();
    printf("Lista inicialmente vazia: ");
    imprime(vazia);

    // Teste de Inserção em Lista Vazia
    insereInicio(vazia, 50);
    printf("Após inserir em lista vazia: ");
    imprime(vazia);

    // Testes de Estresse (opcional)
    for (int i = 0; i < 1000; i++) {
        insereFinal(L, i);
    }
    printf("Após inserir 1000 elementos: ");
    imprime(L);  // Pode ser simplificado se imprimir for muito lento para muitos elementos

    // Liberar memória (opcional, mas recomendável)
    No* atual = L->sentinela->prox;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(L->sentinela);
    free(L);

    // Liberar memória da lista vazia
    atual = vazia->sentinela->prox;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(vazia->sentinela);
    free(vazia);

    return 0;
}
