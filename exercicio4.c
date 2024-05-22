#include <stdio.h>
#include <stdlib.h>

int** multiplicarMatrizes(int **matriz1, int m1, int n1, int **matriz2, int m2, int n2) {
    if (n1 != m2) {
        printf("Impossível multiplicar as matrizes: o número de colunas da primeira matriz não é igual ao número de linhas da segunda matriz.\n");
        return NULL;
    }

    int **resultado = (int **)malloc(m1 * sizeof(int *));
    for (int i = 0; i < m1; i++) {
        resultado[i] = (int *)malloc(n2 * sizeof(int));
    }

    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < n1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    return resultado;
}

int** transporMatriz(int **matriz, int m, int n) {
    int **transposta = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        transposta[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    return transposta;
}

void imprimirMatriz(int **matriz, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m1, n1, m2, n2;

    m1 = 2, n1 = 3;
    int **matriz1 = (int **)malloc(m1 * sizeof(int *));
    for (int i = 0; i < m1; i++) {
        matriz1[i] = (int *)malloc(n1 * sizeof(int));
        for (int j = 0; j < n1; j++) {
            matriz1[i][j] = i + j;
        }
    }

    m2 = 3, n2 = 2;
    int **matriz2 = (int **)malloc(m2 * sizeof(int *));
    for (int i = 0; i < m2; i++) {
        matriz2[i] = (int *)malloc(n2 * sizeof(int));
        for (int j = 0; j < n2; j++) {
            matriz2[i][j] = i - j;
        }
    }

    int **resultado = multiplicarMatrizes(matriz1, m1, n1, matriz2, m2, n2);
    imprimirMatriz(resultado, m1, n2);

    int **matriz = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        matriz[i] = (int *)malloc(2 * sizeof(int));
        for (int j = 0; j < 2; j++) {
            matriz[i][j] = i + j;
        }
    }

    printf("\n");

    int **transposta = transporMatriz(matriz, 3, 2);
    imprimirMatriz(transposta, 2, 3);

    for (int i = 0; i < m1; i++) {
        free(matriz1[i]);
    }
    free(matriz1);

    for (int i = 0; i < m2; i++) {
        free(matriz2[i]);
    }
    free(matriz2);

    for (int i = 0; i < 3; i++) {
        free(matriz[i]);
    }
    free(matriz);

    for (int i = 0; i < 2; i++) {
        free(resultado[i]);
        free(transposta[i]);
    }
    free(resultado);
    free(transposta);

    return 0;
}
