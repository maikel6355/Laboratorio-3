#include <stdio.h>
#define TAMANO 3

int matriz[TAMANO][TAMANO] = {
    {1, 3, 8},
    {4, 6, 2},
    {7, 5, 9}
};


void sumar_diagonales(int matriz[][TAMANO]) {
    int suma_diagonal_principal = 0;
    int suma_diagonal_secundaria = 0;

    // Se suma la diagonal principal
    for (int i = 0; i < TAMANO; i++) {
        suma_diagonal_principal += matriz[i][i];
    }
    printf("Suma de la diagonal principal: %d\n", suma_diagonal_principal);

    // Se suma la diagonal secundaria
    for (int i = 0; i < TAMANO; i++) {
        suma_diagonal_secundaria += matriz[i][TAMANO - i - 1];
    }


    // Se suman las diagonales paralelas a la diagonal principal
    for (int d = 1; d < TAMANO; d++) {
        int suma_superior = 0, suma_inferior = 0;
        for (int i = 0; i < TAMANO - d; i++) {
            suma_superior += matriz[i][i + d];
            suma_inferior += matriz[i + d][i];
        }
        printf("Suma de la diagonal paralela superior %d: %d\n", d, suma_superior);
        printf("Suma de la diagonal paralela inferior %d: %d\n", d, suma_inferior);
    }
    printf("Suma de la diagonal secundaria: %d\n", suma_diagonal_secundaria);

    // Se suman las diagonales paralelas a la diagonal secundaria
    for (int d = 1; d < TAMANO; d++) {
        int suma_superior = 0, suma_inferior = 0;
        for (int i = 0; i < TAMANO - d; i++) {
            suma_superior += matriz[i][TAMANO - i - d - 1];
            suma_inferior += matriz[i + d][TAMANO - i - 1];
        }
        printf("Suma de la diagonal secundaria paralela superior %d: %d\n", d, suma_superior);
        printf("Suma de la diagonal secundaria paralela inferior %d: %d\n", d, suma_inferior);
    }
}

int main() {
    sumar_diagonales(matriz);
    return 0;
}