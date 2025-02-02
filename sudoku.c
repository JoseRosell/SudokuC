#include <stdio.h>
#include <stdbool.h>

int tablero[9][9] = {
    {0, 6, 0, 1, 0, 4, 0, 5, 0},
    {0, 0, 8, 3, 0, 5, 6, 0, 0},
    {2, 0, 0, 0, 0, 0, 0, 0, 1},
    {8, 0, 0, 4, 0, 7, 0, 0, 6},
    {0, 0, 6, 0, 0, 0, 3, 0, 0},
    {7, 0, 0, 9, 0, 1, 0, 0, 4},
    {5, 0, 0, 0, 0, 0, 0, 0, 2},
    {0, 0, 7, 2, 0, 6, 9, 0, 0},
    {0, 4, 0, 5, 0, 8, 0, 7, 0}
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

bool esValido(int tablero[9][9], int fila, int columna, int numero) {
    for (int x = 0; x < 9; x++) {
        if (tablero[fila][x] == numero || tablero[x][columna] == numero) {
            return false;
        }
    }

    int inicioFila = fila - fila % 3;
    int inicioColumna = columna - columna % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i + inicioFila][j + inicioColumna] == numero) {
                return false;
            }
        }
    }
    return true;
}

bool resolverSudoku(int tablero[9][9]) {
    int fila = -1;
    int columna = -1;
    bool vacio = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (tablero[i][j] == 0) {
                fila = i;
                columna = j;
                vacio = false;
                break;
            }
        }
        if (!vacio) {
            break;
        }
    }
    if (vacio) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (esValido(tablero, fila, columna, num)) {
            tablero[fila][columna] = num;
            if (resolverSudoku(tablero)) {
                return true;
            }
            tablero[fila][columna] = 0;
        }
    }
    return false;
}

void main() {
    imprimirTablero(tablero);
    if (resolverSudoku(tablero)) {
        printf("\n\nSolución:\n");
        imprimirTablero(tablero);
    } else {
        printf("No hay solucion");
    }
}