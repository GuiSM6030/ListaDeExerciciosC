#include <stdio.h>

int ex2() {
    int n;
    scanf("%d", &n);
    int i = 1;
    int j = 1;

    while (i <= n) { //começa com 1 e é multiplicado por 2 a cada vez que roda, ou seja, log2(n)
        i = i * 2;
    }

    while (j <= n) { //começa com 1 e é somado a 1 a cada vez que roda, "n" vezes.
        j = j + 1;
    }

    // A complexidade é log2(n) + n e o big-O = O(n)
}

int ex3() {
    int n;
    scanf("%d", &n);
    int i = 1;
    int j = 1;
    int cont = 0;

    for (int i = 1; i <= n; i = i + 1) { // roda n vezes
        for (int j = 1; j <= n; j = j + 1) { // roda n vezes, mas com o outro fica n^2
            cont++;
        }
        int k = 1;

        while (k <= n) { //a cada vez roda n vezes dependendo das vezes que o loop de cima rodou, então aqui também fica n^2
            k++;
            cont++;
        }
    }
    // A complexidade é n^2 + n^2 = big-O = O(n^2)
}

int ex4() {
    int n;
    scanf("%d", &n);
    int cont = 0;

    for (int i = 1; i <= n; i = i + 1) { // roda n vezes
        for (int j = 1; j <= n; j = j + 1) { // roda n vezes, mas com o outro fica n^2
            for (int k = 1; k <= n; k = k + 1) { // roda n vezes, mas com o outro fica n^3
                cont++;
            }
        }
    }
    // Cada um roda n vezes, então a o big-o é O(n^3)
}

int ex5(){
float f(float* a, float* b, int n) {
    int i, j;
    float s = 0.0;
    for (i = 1; i < n; i++) { // roda n-1 vezes; O(n)
        
        if (a[i] > 10) {
            for (j = n - 1; j >= 0; j--) {
                s += a[i] + b[j];
            }
        } // roda de n-1 até 0; O(n^2)
            
        else if (a[i] <= 0) {
            for (j = n; j < n * n; j += 2) {
                s += a[i] + b[j];
            }
        } // roda (n^2-n)/2; On^2
        
        else {
            for (j = 1; j < n; j = s * j) {
                s += a[i] + b[j];
            }
        } //roda n vezes; O(n)
    }
    return s;
}


    //O melhor caso é se nenhum elemento de "a" for > 10 ou <= 0, daí então o algoritmo executa apenas o loop principal resultando O(n)
    //O pior caso é se todos os elementos de "a" forem > 10 daí então o algoritmo executa o loop interno n vezes pra cada vez que o principal rodar, resultando O(n^2)
    //Para o melhor caso, o vetor "a" tem que ter todos os elementos > 0 < 10 pra que não entre nos loops internos


#include <stdio.h>

// Função para simular a verificação da senha
int verificaSenha(int tentativa, int senha) {
    return (tentativa == senha);
}

int main() {
    int senha = 19395;
    int achou = 0;

    printf("Iniciando quebra de senha...\n");

    //testa todas as combinações de 00000 a 99999
    for (int i = 0; i <= 99999; i++) {
        if (verificaSenha(i, senha)) {
            printf("Senha encontrada: %05d\n", i); //formata o número com 5 dígitos
                achou = 1;
            break;
        }
    }
    if (!achou) {
        printf("Senha nao encontrada.\n");
    }

    return 0;

    //a colpexidade é O(10^5) (pq tem 5 digitos) e o big-O = O(n)
    //se tivesse 10 digitos, ou seja 10^10, e demoraria muito mais pra quebrar a senha, então acaba ficando impraticavel
}