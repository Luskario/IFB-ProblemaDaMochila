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

int menorPeso(Item *itens, Mochila mochila);
int custoBeneficio(Item *itens, Mochila mochila);
int progDinamica(Item *itens, Mochila mochila);
int max(int a, int b);

#endif
