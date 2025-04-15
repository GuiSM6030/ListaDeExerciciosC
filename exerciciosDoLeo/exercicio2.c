#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char string[100];
    int vogais = 0;

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    for (int i = 0; string[i] != '\0'; i++) {
        char c = tolower(string[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vogais++;
        }
    }

    printf("Número de vogais na string: %d\n", vogais);

    return 0;
}
