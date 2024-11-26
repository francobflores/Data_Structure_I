#include "pilha.h"

int main(){
    No *Pilha = NULL;
    Pilha = Empilha(Pilha,90);
    Pilha = Empilha(Pilha,50);
    Pilha = Empilha(Pilha,80);

    printf("Pilha: ");
    imprimir_Pilha(Pilha);

    return 0;
}