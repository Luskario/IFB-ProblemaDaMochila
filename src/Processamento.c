#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MetodoAux.h"
#include "Metodos.h"
#include "Leitura.h"

void executar(char* ArqEntrada, int *Resp, float* Tempos){
    FILE *arq = fopen(ArqEntrada, "r");
    Mochila m = lerMochila(arq);
    Item itens[m.qtd];
    int i, valorTotal;
    float tempo;
    clock_t timer;

    for(i=0; i<m.qtd; i++){
        itens[i] = lerItem(arq);
        itens[i].indice = i;
    }


    //-----------------------------------------------------------------------------//

    timer = clock();
    Resp[0] = menorPeso(itens, m);
    timer = clock() - timer;
    Tempos[0] = ((float)timer/CLOCKS_PER_SEC);

    mergesort(itens, 0, m.qtd, 2);

    timer = clock();
    Resp[1] = beneficioCusto(itens, m);
    timer = clock() - timer;
    Tempos[1] = ((float)timer/CLOCKS_PER_SEC);

    mergesort(itens, 0, m.qtd, 2);

    timer = clock();
    Resp[2] = progDinamica(itens, m);
    timer = clock() - timer;
    Tempos[2] = ((float)timer/CLOCKS_PER_SEC);

    fclose(arq);
}

int valorEficaz(char* ArqEntrada){
    FILE *arq = fopen(ArqEntrada, "r");
    int valor;

    valor = lerDado(arq);
    
    return valor;
}