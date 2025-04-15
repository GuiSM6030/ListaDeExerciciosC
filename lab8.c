#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct {
  int valores[LEN];
  int qtde;
} heap;

int filho_esq(int pai) {
  return 2 * pai + 1;
}

int filho_dir(int pai) {
  return 2 * pai + 2;
}

int pai(int filho) {
  return (filho - 1) / 2;
}

int ultimo_pai(heap *h) {
  if (h->qtde <= 1)
    return -1;
  return (h->qtde / 2) - 1;
}



void peneirar(heap *h, int i) {
  //implementar
  int maior = i;
  int esq = filho_esq(i);
  int dir = filho_dir(i);
  

  if (esq < h->qtde && h->valores[esq] > h->valores[maior]) {
    maior = esq;
  }

  if (dir < h->qtde && h->valores[dir] > h->valores[maior]) {
    maior = dir;
  }

  if (maior != i) {

    int temp = h->valores[i];
    h->valores[i] = h->valores[maior];
    h->valores[maior] = temp;

    peneirar(h, maior);
  }
  
}

void mostrar(heap *h) {
  //implementar
  for (int i = 0; i < h->qtde; i++) {
    printf("%d ", h->valores[i]);
  }
  printf("\n");
}

void construir(heap *h) {
  //implementar
  for (int i = ultimo_pai(h); i >= 0; i--) {
    peneirar(h, i);
  }
}

void inserir(heap *h, int valor) {
  //implementar
  h->valores[h->qtde++] = valor;
  construir(h); // poderia ser otimizado com subir valor mas não dessa vez
}

void remover(heap *h) {
  //implementar
  if (h->qtde == 0) {
    return;
  }

  h->qtde--;
  h->valores[0] = h->valores[h->qtde];
 

  peneirar(h, 0);

  // Pega o maior valor, joga na ultima posição, coloca a ultima posição no começo, diminui a quantidade da lista, e chama o peneirar
}

int main(void) {
  heap *h = malloc(sizeof(heap));
  int valor;
  h->qtde = 0;

  for (int i = 0; i < LEN; i++) {
    scanf("%d", &valor);
    inserir(h, valor);
    mostrar(h);
  }

  for (int i = 0; i < LEN; i++) {
    remover(h);
    mostrar(h);
  }

  free(h);
  return 0;
}
