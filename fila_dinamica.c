#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *anterior;
    struct Celula *proximo;
    int valor;
    
} Celula;

typedef struct{
    int qtde;
    Celula *head;
    Celula *tail;
} Fila;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->anterior = NULL;
    nova->proximo = NULL;
    nova->valor = valor;
    return nova;
}

void enfileirar(Fila *fila, int valor){
    Celula *nova = criar_celula(valor);
    if(fila->qtde == 0){
        fila->head = nova;
    } else{
        fila->tail->proximo = nova;
        nova->anterior = fila->tail;
    }
    fila->tail = nova;
    fila->qtde++;
}

int desenfileirar(Fila *fila){
    Celula *liberar = fila->head;
    int valor = fila->head->valor;
    if(fila->qtde == 0){
        return -1;
    }
    if(fila->qtde ==1){
        fila->head = NULL;
        fila->tail = NULL;

    } else{
        fila->head->proximo->anterior = NULL;
        fila->head = fila->head->proximo;
        
        
    }
    fila->qtde--;
    free(liberar);
    return valor;
}

void mostrar_fila(Fila *fila, int inversa){
    if(!inversa){
        Celula *atual = fila->head;
        printf("HEAD ->");
        while (atual != NULL){
            printf("%d ", atual->valor);
            atual = atual->proximo;
        }
        printf("<- TAIL");
    } else{
        Celula *atual = fila->tail;
        printf("HEAD ->");
        while(atual != NULL){
            printf("%d ", atual->valor);
            atual = atual->anterior;
        }
        printf("<- TAIL");
    }
    printf("\n");
}





int main(){
    Fila *fila = malloc(sizeof(Fila));
    fila->head = NULL;
    fila->tail = NULL;
    fila->qtde = 0;

    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);
    mostrar_fila(fila, 0);
    mostrar_fila(fila, 1);
    printf("%d\n", desenfileirar(fila));
    mostrar_fila(fila, 0);
    mostrar_fila(fila, 1);
    printf("%d\n", desenfileirar(fila));
    mostrar_fila(fila, 0);
    mostrar_fila(fila, 1);
    printf("%d\n", desenfileirar(fila));
    mostrar_fila(fila, 0);
    mostrar_fila(fila, 1);
    printf("%d\n", desenfileirar(fila));
    mostrar_fila(fila, 0);
    mostrar_fila(fila, 1);


    return 0;
}