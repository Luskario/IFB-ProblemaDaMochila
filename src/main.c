#include <stdio.h>
#include <stdlib.h>
#include "Metodos.h"
#include "Leitura.h"
#include "MetodoAux.h"


int main(void){

    Item teste[10] = {{0, 5, 0}, {0, 3, 1}, {0, 123, 2}, {0, 43, 3}, 
    {0, 1, 4}, {0, 1654, 5}, {0, 1, 6}, {0, 7, 7}, {0, 9, 8}, {0, 8, 9}};

    
    int x[10] = {1, 4, 534, 1, 4, 5, 42, 64, 7, 10};
    
    mergesort(teste, 0, 10);

    int a;

    for(a=0; a<10; a++){
        printf("%d ", teste[a].peso);
    }
    printf("\n");

    return 0;
}