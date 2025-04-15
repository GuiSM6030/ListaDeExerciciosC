#include <stdio.h>

char* converterParaMaiusculas(char *string) {
    char *ptr = string;
    while (*ptr != '\0') {
        if (*ptr >= 'a' && *ptr <= 'z') {
            *ptr -= 32;
        }
        ptr++;
    }
    return string;
}

int main() {
    char string[100];

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    printf("String em maiúsculas: %s\n", converterParaMaiusculas(string));

    return 0;
}
