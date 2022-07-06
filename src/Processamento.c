#include <stdio.h>
#include <stdlib.h>
#include "MetodoAux.h"
#include "Metodos.h"
#include "Leitura.h"

void executar(char* ArqEntrada){
    FILE *arq = fopen(ArqEntrada, "r");
    Mochila m = lerMochila(arq);
    Item itens[m.qtd];
    int i, resposta[m.qtd];

    for(i=0; i<m.qtd; i++){
        itens[i] = lerItem(arq);
        itens[i].indice = i;
    }
    
    menorPeso(itens, m, resposta);

    custoBeneficio(itens, m, resposta);

    progDinamica(itens, m, resposta);


    fclose(arq);
}

