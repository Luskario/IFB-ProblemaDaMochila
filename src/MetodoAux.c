#include <stdio.h>
#include <stdlib.h>
#include "MetodoAux.h"
#include "Metodos.h"


void mergesort(int inicio, int fim, int *Vetor){
    if (inicio < fim-1) {
        int q = (inicio + fim)/2;
        mergesort(inicio, q, Vetor);
        mergesort(q, fim, Vetor);
        merge(inicio, q, fim, Vetor);
    }
}

void merge(int inicio, int q, int fim, int *Vetor){
    int i, j, *w;
    w = malloc ((fim-inicio) * sizeof(int));

    for (i = inicio; i < q; i++){
        w[i-inicio] = Vetor[i];
    }
    for (j = q; j < fim; j++){
        w[fim-inicio+q-j-1] = Vetor[j];
    }
    i = 0; 
    j = fim-inicio-1;

    for (int k = inicio; k < fim; k++){
        if (w[i] <= w[j]){
            Vetor[k] = w[i++];
        } else{
            Vetor[k] = w[j--];
        } 
    }
    free (w);
}