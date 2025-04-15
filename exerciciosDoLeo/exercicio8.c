#include <stdio.h>
#include <stdlib.h>

int* inverterArray(int *array, int tamanho) {
    int *arrayInvertido = (int *)malloc(tamanho * sizeof(int));
    if (arrayInvertido == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    int *ptr = arrayInvertido + tamanho - 1;
    for (int i = 0; i < tamanho; i++) {
        *ptr-- = *array++;
    }

    return arrayInvertido;
}

int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    int *arrayInvertido = inverterArray(array, tamanho);

    printf("Array invertido:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arrayInvertido[i]);
    }
    printf("\n");

    // Liberando a memória alocada para o array invertido
    free(arrayInvertido);

    return 0;
}
