#include <stdio.h>
#include <stdlib.h>
#include "Metodos.h"
#include "MetodoAux.h"

void menorPeso(Item *itens, Mochila mochila, int qtd, int *resposta){
    int i = 0, pesoTotal = 0;
    
    mergesort(itens, 0, qtd);

    while(mochila.capacidade > pesoTotal + itens[i].peso){

        pesoTotal = pesoTotal + itens[i].peso;
        resposta[itens[i].indice] = 1;
        i++;
    }
}
void custoBeneficio(Item *itens, Mochila mochila, int qtd, int *resposta){
    
}

void progDinamica(Item *itens, Mochila mochila, int qtd){
    
}

void criarResposta(Item *itens, int *valores){
    
}
