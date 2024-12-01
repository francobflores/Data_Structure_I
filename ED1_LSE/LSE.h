#ifndef __LISTALSE_H__
#define __LISTALSE_H__

/*Inclusão de bibliotecas necessárias para o pacote*/
#include <stdlib.h>
#include <stdio.h>

//estrutura para um nó renomeado para No.
typedef struct no{
    int chave;
    struct no *prox;
}No;

No *criaNo(int valor);
No *insereInicio(No *L, int valor);
No *insereFinal(No *L, int valor);
void imprimir_LSE(No *L);
No *concatenaLSE(No *L1, No *L2);
No *excluiInicio(No* L);
No *excluiFinal(No *L);
No *excluiChave(No *L, int chave);    

#endif