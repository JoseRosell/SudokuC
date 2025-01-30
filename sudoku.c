#include <stdio.h>
#include <stdbool.h>

int tablero[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};


void rellenarTablero(int tablero[9][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf("Ingrese el valor de la casilla [%d][%d]: ", i, j);
            scanf("%d", &tablero[i][j]);
        }
    }
}

void imprimirTablero(int tablero[9][9]){
    // Imprimir tablero formateado con tabulaciones y |
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf("%d ", tablero[i][j]);
            if (j == 2 || j == 5){
                printf("| ");
            }
        }
        printf("\n");
        if (i == 2 || i == 5){
            printf("---------------------\n");
        }
    }
}

int main()
{
    //rellenarTablero(tablero);
    imprimirTablero(tablero);
    return 0;
}