#include <stdio.h>
#include <stdlib.h>
#include "MetodoAux.h"
#include "Metodos.h"

int ordem(int ordem, Item *w, int i, int j){
    int resultado;
    switch (ordem){
    case 0:
        resultado = w[i].peso <= w[j].peso;
        break;
    case 1:
        resultado = w[i].peso <= w[j].peso;
        break;
    case 2:
        resultado = w[i].indice <= w[j].indice;
        break;
    default:
        break;
    }

    return resultado;
}

void mergesort(Item *Vetor, int inicio, int fim){
    if (inicio < fim-1) {
        int q = (inicio + fim)/2;
        mergesort(Vetor, inicio, q);
        mergesort(Vetor, q, fim);
        merge(Vetor, inicio, q, fim);
    }
}

void merge(Item *Vetor, int inicio, int q, int fim){
    int i, j;
    Item *w = (Item*)malloc ((fim-inicio) * sizeof(Item));

    for (i = inicio; i < q; i++){
        w[i-inicio] = Vetor[i];
    }
    for (j = q; j < fim; j++){
        w[fim-inicio+q-j-1] = Vetor[j];
    }
    i = 0; 
    j = fim-inicio-1;

    for (int k = inicio; k < fim; k++){
        if (ordem(0, w, i, j)){
            Vetor[k] = w[i++];
        } else{
            Vetor[k] = w[j--];
        } 
    }
    free (w);
}