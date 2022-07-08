#include <stdio.h>
#include <stdlib.h>
#include "MetodoAux.h"
#include "Metodos.h"
#include "Leitura.h"

void executar(char* ArqEntrada){
    char* teste = "/home/tw/Documentos/git/ProblemaDaMochila/dataset/large_scale/knapPI_1_500_1000_1";
    FILE *arq = fopen(teste, "r");
    Mochila m = lerMochila(arq);
    Item itens[m.qtd];
    int i, valorTotal;
    float tempo, fracao;

    //printf("%d %d \n", m.capacidade, m.qtd);

    for(i=0; i<m.qtd; i++){
        itens[i] = lerItem(arq);
        //printf("%d %d \n", itens[i].peso, itens[i].valor);
        itens[i].indice = i;
    }
    
    
    
    //valorTotal = menorPeso(itens, m);
    //fracao = ((float) valorTotal)/((float) valorEficaz);
    //beneficioCusto(itens, m);

    printf("%d \n", progDinamica(itens, m));


    fclose(arq);
}

