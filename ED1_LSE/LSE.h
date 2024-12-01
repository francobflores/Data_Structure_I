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
/* Cabeçalhos das funções com suas respectivas descrições */

/*Função:No *criaNo(int valor);
Descrição:função para criar um nó.
Entrada: int valor.

Saída:
ponteiro para novo nó;  
*/
No *criaNo(int valor);


/*Função:No *insereInicio(No *L, int valor);
Descrição:função para inserir um nó no inicio da lista
Entrada: int valor.

Saída:
ponteiro para inicio da lista L;  
*/
No *insereInicio(No *L, int valor);

/*Função:No *insereFinal(No *L, int valor);
Descrição:função para inserir um nó no final da lista
Entrada: int valor.

Saída:
ponteiro para inicio da lista L;  
*/
No *insereFinal(No *L, int valor);

/*Função: void imprimir_LSE(No *L)
Descrição: função para mostrar na tela cada nó de uma lista.
Entrada: No *L

Saída:
impressão na tela de cada valor do campo chave da lista.
*/
void imprimir_LSE(No *L);

/*Função:No *concatenaLSE(No *L1, No *L2);
Descrição:função para unir duas listas
Entrada: No *L1, No *L2.

Saída:
ponteiro para inicio da lista L1;  
*/
No *concatenaLSE(No *L1, No *L2);

/*Função:No *excluiInicio(No *L, int valor);
Descrição:função para excluir um nó no inicio da lista
Entrada: int valor.

Saída:
ponteiro para inicio da lista L;  
*/

No *excluiInicio(No* L);

/*Função:No *excluiFinal(No *L, int valor);
Descrição:função para excluir um nó no final da lista
Entrada: int valor.

Saída:
ponteiro para inicio da lista L;  
*/
No *excluiFinal(No *L);

/*Função:No *excluiChave(No *L, int valor);
Descrição:função para excluir um nó com uma chave informada.
Entrada: int valor.

Saída:
ponteiro para inicio da lista L;  
*/
No *excluiChave(No *L, int chave);    

#endif