#include "LSE.h"

// função principal para teste da função insereInicio().
/*
int main(){
    No *L = NULL;
    L = insereInicio(L, 10);
    L = insereInicio(L, 10);
    L = insereInicio(L, 10);
    L = insereInicio(L, 10);

    printf("Lista: ");
    imprimir_LSE(L);

    return 0;
}
*/
//lembrar de criar uma função main para testar cada função de inserção, 
//busca exclusão e impressão.
/*
int main(){
    No *L = NULL;
    L = insereFinal(L, 10);
    L = insereFinal(L, 20);
    //L = insereFinal(L, 30);

    printf("Lista: ");
    imprimir_LSE(L);

    L = excluiFinal(L);
    printf("Após exclusão do ultimo elemento: ");
    imprimir_LSE(L);

    return 0;
}
*/
// função principal para testar erro da exclusão de uma chave na LSE

int main(){
    No *L = NULL;
    L = insereFinal(L, 10);
    L = insereFinal(L, 20);
    L = insereFinal(L, 30);

    printf("Lista: ");
    imprimir_LSE(L);

    L = excluiChave(L,20);
    printf("Após exclusão da chave buscada: ");
    imprimir_LSE(L);

    return 0;
} 