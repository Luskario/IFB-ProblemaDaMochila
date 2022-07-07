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

int beneficioCusto(Item *itens, Mochila mochila){
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
    int i, peso;
    int K[mochila.qtd + 1][mochila.capacidade + 1];
 
    for (i = 0; i <= mochila.qtd; i++){
        for (peso = 0; peso <= mochila.capacidade; peso++){
            if (i == 0 || peso == 0){
                K[i][peso] = 0;
            } 
            else if (itens[i - 1].peso <= peso){
                K[i][peso] = max(itens[i - 1].valor + K[i - 1][peso - itens[i - 1].peso],K[i - 1][peso]);}
            else{
                K[i][peso] = K[i - 1][peso];
            }
        }
    }
 
    return K[mochila.qtd][mochila.capacidade];
}

int max(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}