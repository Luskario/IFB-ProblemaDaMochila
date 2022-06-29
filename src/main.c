#include <stdio.h>
#include <stdlib.h>
#include "MetodoAux.h"
#include "Metodos.h"
#include "Leitura.h"


int main(void){

    Item teste[10] = {{0, 12, 0}, {0, 11, 1}, {0, 12, 2}, {0, 12, 3}, 
    {0, 12, 4}, {0, 12, 5}, {0, 12, 6}, {0, 12, 7}, {0, 12, 8}, {0, 12, 9}};

    
    int x[10] = {1, 4, 534, 1, 4, 5, 42, 64, 7, 10};
    
    mergesort(0, 10, x);

    int a;

    for(a=0; a<10; a++){
        printf("%d ", x[a]);
    }
    printf("\n");

    return 0;
}