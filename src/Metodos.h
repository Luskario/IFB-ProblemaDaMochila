#ifndef Metodos
#define Metodos

struct item {
    int valor;
    int peso;
    int indice;
};
struct mochila {
    int capacidade;
    int qtd;
};
typedef struct item Item;
typedef struct mochila Mochila;

void menorPeso(Item *itens, Mochila mochila,  int *resposta);
void custoBeneficio(Item *itens, Mochila mochila, int *resposta);
int progDinamica(Item *itens, Mochila mochila, int *resposta);
int calcularTotal(Item *itens, int *valores, int qtd);
int max(int a, int b);

#endif
