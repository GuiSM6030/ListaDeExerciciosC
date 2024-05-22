#include <stdio.h>

int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];
    int soma = 0;

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
        soma += array[i];
    }

    printf("A soma dos elementos do array é: %d\n", soma);

    return 0;
}
