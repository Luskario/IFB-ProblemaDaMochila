#ifndef Metodos
#define Metodos

struct item {
    int valor;
    int peso;
    int indice;
};
struct mochila {
    int capacidade;
    int *itens;
};
typedef struct item Item;
typedef struct mochila Mochila;

void menorPeso(Item *itens, Mochila mochila, int qtd);
void custoBeneficio(Item *itens, Mochila mochila, int qtd);
void progDinamica(Item *itens, Mochila mochila, int qtd);
void criarResposta(Item *itens);

#endif
