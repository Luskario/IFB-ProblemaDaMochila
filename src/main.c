#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Metodos.h"
#include "Leitura.h"
#include "MetodoAux.h"
#include "Processamento.h"

struct resultado{
    int valorEficaz;
    float mediaTempo[3];
    int valores[3];
};
typedef struct resultado Resultado;

int main(void){
    char path[2][50] = {{"./dataset/large_scale/"}, {"./dataset/large_scale-optimum/"}};

    char entradas[9][100]={
        {"knapPI_1_1000_1000_1"},{"knapPI_1_5000_1000_1"},{"knapPI_1_10000_1000_1"},
        {"knapPI_2_1000_1000_1"},{"knapPI_2_5000_1000_1"},{"knapPI_2_10000_1000_1"},
        {"knapPI_3_1000_1000_1"},{"knapPI_3_5000_1000_1"},{"knapPI_3_10000_1000_1"}
    };

    char buffer[100];

    Resultado r[9] = {{0,{0,0,0},{0,0,0}}, {0,{0,0,0},{0,0,0}}, {0,{0,0,0},{0,0,0}},
    {0,{0,0,0},{0,0,0}}, {0,{0,0,0},{0,0,0}}, {0,{0,0,0},{0,0,0}}, {0,{0,0,0},{0,0,0}},
    {0,{0,0,0},{0,0,0}}, {0,{0,0,0},{0,0,0}}};

    int i, j, x, teste = 10, respostas[3];
    float tempos[3];
   
    for(i=0; i<teste; i++){
        for(j=0; j<9; j++){
            r[j].valorEficaz = valorEficaz((strcat(strcpy(buffer, path[1]), entradas[j])));

            executar((strcat(strcpy(buffer, path[0]), entradas[j])), respostas, tempos);

            for(x=0; x<3; x++){
                r[j].mediaTempo[x] +=(tempos[x]*1000/teste);
                r[j].valores[x] = respostas[x];
            }
        }
    }


    for(i=0; i<9; i++){
        printf("\n %s \n\n", entradas[i]);
        for(j=0; j<3; j++){
            printf("tempo: %.2f ms ----- Valor Total: %d ----- Eficacia: %f\n", 
            (r[i].mediaTempo[j]), r[i].valores[j], 
            (((float)r[i].valores[j]) / ((float)r[i].valorEficaz)));
        }
    }
    
    return 0;
}
