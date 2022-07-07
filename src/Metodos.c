#include <stdio.h>
#include <stdlib.h>
#include "Metodos.h"
#include "MetodoAux.h"

int menorPeso(Item *itens, Mochila mochila){
    int i = 0, pesoTotal = 0, valorTotal = 0;
    
    mergesort(itens, 0, mochila.qtd, 0);

    while(mochila.capacidade >= pesoTotal + itens[i].peso){

        pesoTotal = pesoTotal + itens[i].peso;
        valorTotal = valorTotal + itens[i].valor;
        i++;
    }

    return valorTotal;
}

int custoBeneficio(Item *itens, Mochila mochila){
    int i, pesoTotal = 0, valorTotal = 0;
    
    mergesort(itens, 0, mochila.qtd, 1);
    
    for(i=0; i<mochila.qtd;i++){
        if(mochila.capacidade >= pesoTotal + itens[i].peso){
            pesoTotal = pesoTotal + itens[i].peso;
            valorTotal = valorTotal + itens[i].valor;
        }
    }

    return valorTotal;
}

int progDinamica(Item *itens, Mochila mochila){
    int i, w;
    int K[mochila.qtd + 1][mochila.capacidade + 1];
 
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

int max(int a, int b){
    return (a > b) ? a : b;
}