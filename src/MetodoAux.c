#include <stdio.h>
#include <stdlib.h>
#include "MetodoAux.h"
#include "Metodos.h"

int ordenacao(int ordem, Item *w, int i, int j){
    int resultado;
    switch (ordem){
    case 0:         //ordena pelo peso
        resultado = (w[i].peso <= w[j].peso);
        break;
    case 1:         //ordena pelo beneficio
        resultado = (((float)w[i].valor/w[i].peso) >= ((float)w[j].valor/w[j].peso));
        break;
    case 2:         //ordencao dinamica
        resultado = (w[i].indice <= w[j].indice);
        break;
    default:
        break;
    }

    return resultado;
}

void mergesort(Item *Vetor, int inicio, int fim, int ordem){
    if (inicio < fim-1) {
        int q = (inicio + fim)/2;
        mergesort(Vetor, inicio, q, ordem);
        mergesort(Vetor, q, fim, ordem);
        merge(Vetor, inicio, q, fim, ordem);
    }
}

void merge(Item *Vetor, int inicio, int q, int fim, int ordem){
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
        if (ordenacao(ordem, w, i, j)){
            Vetor[k] = w[i++];
        } else{
            Vetor[k] = w[j--];
        } 
    }
    free (w);
}
