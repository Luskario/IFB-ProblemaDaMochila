#include <stdio.h>
#include <stdlib.h>
#include "Metodos.h"
#include "Leitura.h"
#include "MetodoAux.h"


int main(void){

    Item teste[10] = {{52, 52, 0}, {200, 24, 1}, {1, 123, 2}, {5123, 43, 3}, 
    {2, 1, 4}, {54, 1654, 5}, {32, 24, 6}, {7, 7, 7}, {2, 9, 8}, {54, 8, 9}};
    Mochila mochila = {100, 10};
    
    int x[10] = {1, 4, 534, 1, 4, 5, 42, 64, 7, 10};
    int resp[10]= {0,0,0,0,0,0,0,0,0,0};
    menorPeso(teste, mochila, resp);
    //custoBeneficio(teste, mochila, resp);
    //mergesort(teste, 0, 10);
    int a;

    for(a=0; a<10; a++){
        printf("%d ", teste[a].peso);
    }
    printf("\n");
    for(a=0; a<10; a++){
        printf("%d ", resp[a]);
    }

    printf("\n %d \n", criarResposta(teste, resp, 10));

    return 0;
}