#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
}No;

typedef struct lista{
    /* int valor; */
    struct no *prox;
}Lista;

No *criaNo(int valor){
    No *novo =(No *)malloc(sizeof(No));
    if(novo == NULL){
        printf("ERRO:Falha ao alocar memória\n");
        exit(1);
    }
    novo->chave = valor;
    novo->prox = NULL;
    return novo;
}

Lista *criaLista(){
    Lista *novo =(Lista*)calloc(1,sizeof(Lista));
    if(novo == NULL){
        printf("ERRO: Falha ao alocar memória\n");
        exit(1);
    }
    return novo;
}

void insereInicio(Lista *L, int valor){
    No *novo = criaNo(valor);
    novo->prox = L->prox;
    L->prox = novo;
}

void insereFinal(Lista *L, int valor){
    No *novo = criaNo(valor);
    No *aux = L; /* aqui tive que iniciar em L pq se fosse em L->prox no loop eu tentaria acessar um campo de um ponteiro NULL */
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
}
void imprime(Lista *L){
    No *aux = L->prox;
    while(aux != NULL){
        printf("[%d] ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){

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
    No* atual = L->prox;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(L);

    // Liberar memória da lista vazia
    free(vazia);

    Struct lista 

    No* L = NULL; //cria um ponterio com conteúdo NULL


    No* L = malloc(1*sizeof(No)); // reservo 1 espaço na memória do tipo No
    L->prox = NULL // o campo prox aponta para NULL
    
    return 0;
}