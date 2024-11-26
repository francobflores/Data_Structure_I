#ifndef __PILHA_H__
#define __PILHA_H__

/*Inclusão de bibliotecas necessárias para o pacote*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definição da estrutura para um nó renomeado para No.

typedef struct no{
    int chave;
    struct no *prox;
}No;

/* Essas Funções foram feitas com logica de Lista Circular Dinâmica
A convenção usada é que o Ponteiro da Lista aponta para o ultimo da Lista*/

/* Cabeçalhos das funções com suas respectivas descrições */

//

/*Função:No *criaNo(char x);
Descrição:função para criar um nó recebendo um caractere para o campo simbolo.
Entrada:
char x.

Saída:
ponteiro para novo nó;  
*/
No *criaNo(int valor);

/*
Função:No *Empilha(No *Pilha, char x);
Descrição: Adiciona um nó na pilha sempre no final da pilha.
Entrada:
No *Pilha.
char x.

Saída:
ponteiro para ultimo nó da Pilha
*/
No *Empilha(No *P, int valor);

/*
Função: No *Desempilha (No *Pilha);
Descrição: Remove sempre o ultimo nó inserido na pilha.
Entrada:
No *Pilha.

Saída:
ponteiro para ultimo nó da Pilha
*/
No *Desempilha (No *P);


/*Função: void imprimir_Pilha(No *Pilha)
Descrição: imprimir cada elemento da Pilha.
Entrada:
No *Pilha.

Saída:
impressão na tela de cada elemento da Pilha.
*/
void imprimir_Pilha(No *P);

#endif