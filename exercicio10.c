#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio, fim;
    double tempo_decorrido;

    inicio = clock();,

    

    int soma = 0;
    for (int i = 1; i <= 1000000; i++) {
        soma += i;
    }

    fim = clock();

    tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo decorrido: %.6f segundos\n", tempo_decorrido);

    return 0;
}
