#include <stdio.h>
#include <stdlib.h>
#include "Metodos.h"
#include "MetodoAux.h"

void menorPeso(Item *itens, Mochila mochila, int *resposta){
    int i = 0, pesoTotal = 0;
    
    mergesort(itens, 0, mochila.qtd, 0);

    while(mochila.capacidade >= pesoTotal + itens[i].peso){

        pesoTotal = pesoTotal + itens[i].peso;
        resposta[itens[i].indice] = 1;
        i++;
    }
}

void custoBeneficio(Item *itens, Mochila mochila, int *resposta){
    int i, pesoTotal = 0;
    
    mergesort(itens, 0, mochila.qtd, 1);
    
    for(i=0; i<mochila.qtd;i++){
        if(mochila.capacidade >= pesoTotal + itens[i].peso){
            pesoTotal = pesoTotal + itens[i].peso;
            resposta[itens[i].indice] = 1;
        }
    }
}

void progDinamica(Item *itens, Mochila mochila){
    
}

int criarResposta(Item *itens, int *valores, int qtd){
    int valorTotal = 0, i;
    for(i=0; i<qtd; i++){
        valorTotal = valorTotal + itens[i].valor * valores[itens[i].indice];
    }
    return valorTotal;
}
