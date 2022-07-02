#include <stdio.h>
#include <stdlib.h>
#include "Leitura.h" 
#include "Metodos.h"


Mochila lerDado(FILE *arq){
    int valor;
    Mochila mochila;

    fscanf(arq, "%d", &mochila.capacidade);
    fscanf(arq, "%d", &mochila.qtd);

    return mochila;
}


Item lerItem(FILE *arq){
    Item dado;
    char aux;
    
    //pular a linha
    fscanf(arq, "%c", &aux);

    //ler o valor e peso de cada item
    fscanf(arq, "%d", &dado.peso);
    fscanf(arq, "%d", &dado.valor);
    
    return dado;
}