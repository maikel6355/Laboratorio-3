#include <stdio.h>

#define TAMANO 7

int matriz[TAMANO][TAMANO] = {
    {1, 0, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0}
};


int encontrar_max_secuencia() {
    int max_secuencia = 0;

    
    int contador = 0;
    for (int i = 0; i < TAMANO; i++) {
        int fila = i, columna = 1;  

        while (fila < TAMANO && columna >= 0) {
            if (matriz[fila][columna] == 1) {
                contador++;
                if (contador > max_secuencia) {
                    max_secuencia = contador;
                }
            } else {
                contador = 0; 
            }
            fila++;
            columna--;
        }
    }

    
    for (int j = 2; j < TAMANO; j++) {
        int fila = 0, columna = j;
        

        while (fila < TAMANO && columna >= 0) {
            if (matriz[fila][columna] == 1) {
                contador++;
                if (contador > max_secuencia) {
                    max_secuencia = contador;
                }
            } else {
                contador = 0;
            }
            fila++;
            columna--;
        }
    }

    return max_secuencia;
}

int main() {
    int longitud_maxima = encontrar_max_secuencia();
    printf("La secuencia de 1s mas larga es: %d\n", longitud_maxima);
    return 0;
}