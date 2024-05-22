#include <stdio.h>

// Definição da estrutura Produto
struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

int main() {
    int n;
    float total = 0;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    // Declaração de um array de estruturas Produto
    struct Produto produtos[n];

    // Loop para cadastrar os produtos
    for (int i = 0; i < n; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", produtos[i].nome);
        printf("Preço: ");
        scanf("%f", &produtos[i].preco);
        printf("Quantidade em estoque: ");
        scanf("%d", &produtos[i].quantidade);

        // Calcula o valor total em estoque
        total += produtos[i].preco * produtos[i].quantidade;
    }

    // Exibe as informações dos produtos cadastrados
    printf("\nProdutos cadastrados:\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Preço: %.2f, Quantidade: %d\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }

    // Exibe o valor total em estoque
    printf("\nValor total em estoque: %.2f\n", total);

    return 0;
}
