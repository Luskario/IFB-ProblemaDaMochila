#include <stdio.h>
#include <stdlib.h>
#include "MetodoAux.h"
#include "Metodos.h"
#include "Leitura.h"

void executar(char* ArqEntrada){
    char* teste = "/home/tw/Documentos/git/ProblemaDaMochila/dataset/large_scale/knapPI_1_100_1000_1";
    FILE *arq = fopen(teste, "r");
    Mochila m = lerMochila(arq);
    Item itens[m.qtd];
    int i, resposta[m.qtd];

    //printf("%d %d \n", m.capacidade, m.qtd);

    for(i=0; i<m.qtd; i++){
        itens[i] = lerItem(arq);
        //printf("%d %d \n", itens[i].peso, itens[i].valor);
        itens[i].indice = i;
    }
    
    
    
    //menorPeso(itens, m);

    //beneficioCusto(itens, m);

    printf("%d \n", progDinamica(itens, m));


    fclose(arq);
}

