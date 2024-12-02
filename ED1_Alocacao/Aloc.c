#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int *V = NULL;

    V = (int *)malloc(3 * sizeof(int));

    V[0] = 11;
    V[1] = 23;
    V[2] = 15;

    
    int i = 0;
    while(i <= 2){
        printf("[%d] ", V[i]);
        i++;
    }


    printf("\n\n");

    printf("imprimir o endereco de V: %p \n", &V);
    printf("imprimir o endereco de V[0]: %p \n", &V[0]);
    printf("imprimir o endereco de V[1]: %p \n", &V[1]);
    printf("imprimir o endereco de V[2]: %p \n", &V[2]);

    return 0;
}