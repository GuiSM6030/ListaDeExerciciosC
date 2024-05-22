#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

struct Funcionario {
    char nome[MAX_NOME];
    int idade;
    float salario;
};

void adicionarRegistro(FILE *arquivo) {
    struct Funcionario funcionario;
    printf("Nome: ");
    fgets(funcionario.nome, MAX_NOME, stdin);
    funcionario.nome[strcspn(funcionario.nome, "\n")] = 0;
    printf("Idade: ");
    scanf("%d", &funcionario.idade);
    printf("Salário: ");
    scanf("%f", &funcionario.salario);
    fwrite(&funcionario, sizeof(struct Funcionario), 1, arquivo);
}

void listarRegistros(FILE *arquivo) {
    struct Funcionario funcionario;
    rewind(arquivo);
    printf("\nRegistros de funcionários:\n");
    while (fread(&funcionario, sizeof(struct Funcionario), 1, arquivo) == 1) {
        printf("Nome: %s\n", funcionario.nome);
        printf("Idade: %d\n", funcionario.idade);
        printf("Salário: %.2f\n", funcionario.salario);
        printf("\n");
    }
}

void buscarRegistro(FILE *arquivo, char *nome) {
    struct Funcionario funcionario;
    int encontrado = 0;
    rewind(arquivo);
    while (fread(&funcionario, sizeof(struct Funcionario), 1, arquivo) == 1) {
        if (strcmp(funcionario.nome, nome) == 0) {
            printf("\nRegistro encontrado:\n");
            printf("Nome: %s\n", funcionario.nome);
            printf("Idade: %d\n", funcionario.idade);
            printf("Salário: %.2f\n", funcionario.salario);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nRegistro não encontrado.\n");
    }
}

int main() {
    FILE *arquivo;
    int opcao;
    char nome[MAX_NOME];

    arquivo = fopen("funcionarios.bin", "ab+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar novo registro\n");
        printf("2. Listar todos os registros\n");
        printf("3. Buscar registro por nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                adicionarRegistro(arquivo);
                break;
            case 2:
                listarRegistros(arquivo);
                break;
            case 3:
                printf("Digite o nome a ser buscado: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = 0;
                buscarRegistro(arquivo, nome);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    fclose(arquivo);

    return 0;
}
