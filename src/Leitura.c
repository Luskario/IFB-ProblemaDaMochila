#include <stdio.h>
#include <stdlib.h>
#include "Leitura.h" 
#include "Metodos.h"


int lerDado(FILE *arq){
    int valor;

    fscanf(arq, "%d", &valor);

    return valor;
}

Mochila lerMochila(FILE *arq){
    int valor;
    Mochila mochila;

    fscanf(arq, "%d", &mochila.qtd);
    fscanf(arq, "%d", &mochila.capacidade);

    return mochila;
}


Item lerItem(FILE *arq){
    Item dado;
    char aux;
    
    //pular a linha
    fscanf(arq, "%c", &aux);

    //ler o valor e peso de cada item
    fscanf(arq, "%d", &dado.valor);
    fscanf(arq, "%d", &dado.peso);
    
    return dado;
}