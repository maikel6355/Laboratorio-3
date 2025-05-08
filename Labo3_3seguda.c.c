#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO 7

int matriz[TAMANO][TAMANO];


void llenar_matriz() {
    srand(time(NULL)); // Inicializar la semilla de números aleatorios
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            matriz[i][j] = rand() % 2; // Generar 0 o 1 
        }
    }
}


void imprimir_matriz() {
    printf("Matriz generada:\n");
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para encontrar la secuencia más larga de 1s en la diagonal
int encontrar_max_secuencia() {
    int max_secuencia = 0, contador = 0;

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
    llenar_matriz(); // Llenar la matriz con valores aleatorios
    imprimir_matriz(); // Mostrar la matriz generada

    int longitud_maxima = encontrar_max_secuencia();
    printf("La secuencia de 1s mas larga es: %d\n", longitud_maxima);

    return 0;
}