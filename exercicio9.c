#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

float calcularMedia(int *array, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return (float)soma / tamanho;
}

float calcularMediana(int *array, int tamanho) {
    if (tamanho % 2 == 0) {
        return (array[tamanho / 2 - 1] + array[tamanho / 2]) / 2.0;
    } else {
        return array[tamanho / 2];
    }
}

int calcularModa(int *array, int tamanho) {
    int frequenciaMaxima = 0, moda = 0, contagem = 0;
    for (int i = 0; i < tamanho; i++) {
        contagem = 0;
        for (int j = 0; j < tamanho; j++) {
            if (array[j] == array[i])
                contagem++;
        }
        if (contagem > frequenciaMaxima) {
            frequenciaMaxima = contagem;
            moda = array[i];
        }
    }
    return moda;
}

int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int *array = (int *)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    // Ordena o array para facilitar o cálculo da mediana
    qsort(array, tamanho, sizeof(int), comparar);

    float media = calcularMedia(array, tamanho);
    float mediana = calcularMediana(array, tamanho);
    int moda = calcularModa(array, tamanho);

    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    free(array);

    return 0;
}
