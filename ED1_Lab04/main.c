#include "pilha.h"

int main(){
    No *Pilha = NULL;
    Pilha = Empilha(Pilha,'(');
    Pilha = Empilha(Pilha,'(');
    Pilha = Empilha(Pilha,')');

    printf("Pilha: ");
    imprimir_Pilha(Pilha);

    Pilha  = Desempilha(Pilha);
    printf("Pilha pode Desempilhar: ");
    imprimir_Pilha(Pilha);


    return 0;
}