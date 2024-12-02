#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int quantidade;
    int *V = NULL;

    printf("Quantos valores voce deseja inserir?");
    scanf("%d", &quantidade);

    V = (int *)malloc(quantidade * sizeof(int));

    for(int i=0; i<= quantidade -1; i++){
        printf("Insira valor V[%d]:",i);
        scanf("%d", &V[i]);
    }

    for(int i=0; i<= quantidade -1; i++){
        printf("[%d] ", V[i]);
    }
    printf("\n\n");
    return 0;
}