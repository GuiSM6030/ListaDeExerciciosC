#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int compararIdade(const void *a, const void *b) {
    const struct Pessoa *pessoaA = (const struct Pessoa *)a;
    const struct Pessoa *pessoaB = (const struct Pessoa *)b;
    return pessoaA->idade - pessoaB->idade;
}

int main() {
    struct Pessoa pessoas[] = {
        {"Frederico", 25},
        {"Culinho", 30},
        {"Pafúncia", 20},
        {"Craudja", 35}
    };
    int tamanho = sizeof(pessoas) / sizeof(pessoas[0]);

    qsort(pessoas, tamanho, sizeof(struct Pessoa), compararIdade);

    printf("Pessoas ordenadas por idade:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }

    return 0;
}
