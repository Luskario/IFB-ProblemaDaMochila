#ifndef Metodos
#define Metodos

struct item {
    int valor;
    int peso;
};
struct mochila {
    int capacidade;
    Item *itens;
};
typedef struct item Item;
typedef struct mochila Mochila;

void menorPeso(Item *itens, Mochila *mochila);
void menorPeso(Item *itens, Mochila *mochila);

#endif