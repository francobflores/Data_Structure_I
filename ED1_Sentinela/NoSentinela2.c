#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *prox;
} No;

typedef struct lista {
    No *sentinela;
} Lista;

// Função para criar e inicializar uma nova lista com nó sentinela
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

// Função para criar e inicializar um novo nó
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

// Função para inserir um nó no início da lista
void insereInicio(Lista *L, int valor) {
    No *novo = criaNo(valor);
    novo->prox = L->sentinela->prox;
    L->sentinela->prox = novo;
}

// Função para excluir o primeiro nó da lista (após o sentinela)
void excluiInicio(Lista* L) {
    if (L->sentinela->prox != NULL) {
        No* aux = L->sentinela->prox;
        L->sentinela->prox = aux->prox;
        free(aux);
    }
}

// Função para inserir um nó no final da lista
void insereFinal(Lista *L, int valor) {
    No *novo = criaNo(valor);
    No *aux = L->sentinela;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
}

// Função para excluir o último nó da lista
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

// Função para imprimir todos os nós da lista
void imprime(Lista *L) {
    No *aux = L->sentinela->prox;
    while (aux != NULL) {
        printf("[%d] ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}
// Função para buscar um nó na lista com um valor específico
// Retorna um ponteiro para o nó se encontrado, caso contrário retorna NULL
No* busca(Lista *L, int valor) {
    No* aux = L->sentinela->prox;
    while (aux != NULL) {
        if (aux->chave == valor) {
            break;
        }
        aux = aux->prox;
    }
    return aux;
}

#include <stdio.h>
#include <stdlib.h>

// Inclua aqui todas as suas funções e definições, incluindo a função busca

int main() {
    Lista *L = criaLista();
    
    // Testes de Inserção no Início
    printf("Inserindo no início:\n");
    insereInicio(L, 10);
    insereInicio(L, 20);
    imprime(L); // Deve imprimir: [20] [10]

    // Testes de Inserção no Final
    printf("Inserindo no final:\n");
    insereFinal(L, 30);
    insereFinal(L, 40);
    imprime(L); // Deve imprimir: [20] [10] [30] [40]

    // Teste de Exclusão do Início
    printf("Excluindo do início:\n");
    excluiInicio(L);
    imprime(L); // Deve imprimir: [10] [30] [40]

    // Teste de Exclusão do Final
    printf("Excluindo do final:\n");
    excluiFinal(L);
    imprime(L); // Deve imprimir: [10] [30]

    // Teste de Lista Vazia
    printf("Teste de lista vazia:\n");
    Lista *vazia = criaLista();
    printf("Lista inicialmente vazia: ");
    imprime(vazia); // Deve imprimir: (nada)

    // Teste de Inserção em Lista Vazia
    printf("Inserindo em lista vazia:\n");
    insereInicio(vazia, 50);
    imprime(vazia); // Deve imprimir: [50]

    // Teste da função busca
    printf("Testando a função busca:\n");
    No* resultado = busca(L, 30);
    if (resultado != NULL) {
        printf("Valor 30 encontrado: [%d]\n", resultado->chave); // Deve imprimir: Valor 30 encontrado: [30]
    } else {
        printf("Valor 30 não encontrado\n");
    }

    resultado = busca(L, 50);
    if (resultado != NULL) {
        printf("Valor 50 encontrado: [%d]\n", resultado->chave);
    } else {
        printf("Valor 50 não encontrado\n"); // Deve imprimir: Valor 50 não encontrado
    }

    // Liberar memória
    No* aux = L->sentinela->prox;
    while (aux != NULL) {
        No* temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(L->sentinela);
    free(L);

    // Liberar memória da lista vazia
    aux = vazia->sentinela->prox;
    while (aux != NULL) {
        No* temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(vazia->sentinela);
    free(vazia);

    return 0;
}
