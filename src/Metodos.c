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

int progDinamica(Item *itens, Mochila mochila, int *resposta){
    int i, w;
    int K[mochila.qtd + 1][mochila.capacidade + 1];
 
    // Build table K[][] in bottom up manner
    for (i = 0; i <= mochila.qtd; i++){
        for (w = 0; w <= mochila.capacidade; w++){
            if (i == 0 || w == 0){
                K[i][w] = 0;
            }
                
            else if (itens[i - 1].peso <= w){
                K[i][w] = max(itens[i - 1].valor + K[i - 1][w - itens[i - 1].peso],K[i - 1][w]);}
            else{
                K[i][w] = K[i - 1][w];
            }
        }
    }
 
    return K[mochila.qtd][mochila.capacidade];
}

int calcularTotal(Item *itens, int *valores, int qtd){
    int valorTotal = 0, i;
    for(i=0; i<qtd; i++){
        valorTotal = valorTotal + itens[i].valor * valores[itens[i].indice];
    }
    return valorTotal;
}

int max(int a, int b){
    return (a > b) ? a : b;
}