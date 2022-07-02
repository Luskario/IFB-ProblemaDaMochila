#ifndef MetodoAux
#define MetodoAux
#include "Metodos.h"

void mergesort(Item *Vetor, int inicio, int fim, int ordem);
void merge(Item *Vetor, int inicio, int q, int fim, int ordem);
int ordenacao(int ordem, Item *w, int i, int j);
#endif