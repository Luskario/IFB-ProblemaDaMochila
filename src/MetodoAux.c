#include <stdio.h>
#include <stdlib.h>
#include "MetodoAux.h"


void quickSort(int* V, int inicio, int fim){
    int pivo;

    if(fim > inicio){
        pivo = particao(V, inicio, fim);
        quickSort(V, inicio, pivo-1);       //realiza do inicio até o pivo
        quickSort(V, pivo+1, fim);            //realiza do pivo até o fim
    }
}

int particao(int* V, int inicio, int fim){
    int esquerda, direita, pivo, aux;
    esquerda = inicio;
    direita = fim;
    pivo = V[inicio];

    while(esquerda < direita){

        while(esquerda <= fim && V[esquerda] <= pivo){      //percorre da esquerda para direita
            esquerda++;
        }

        while(direita >= 0 && V[direita] > pivo){           //percorre da direita para esquerda
            direita--;
        }

        if(esquerda < direita){     //inverte a posição
            aux = V[esquerda];
            V[esquerda] = V[direita];
            V[direita] = aux;
        }
    }
    V[inicio] = V[direita];
    V[direita] = pivo;

    return direita;     // retorna o valor do pivo
}