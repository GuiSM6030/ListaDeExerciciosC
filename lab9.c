#include <stdio.h>
#include <stdlib.h>

#define tam_hash 11

typedef struct Celula{
  int valor;
  struct Celula* proximo;
}Celula;

typedef struct {
  Celula* inicio;
}Lista;

typedef struct {
  Lista* table[tam_hash];
}Hash;

Hash* start_hash(){
  Hash* hash = malloc(sizeof(Hash));
  for(int i = 0; i < tam_hash; i++){
    Lista* lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    hash->table[i] = lista;
  }
  return hash;
}

void inserir_hash(Hash* hash, int valor){
  // implementar
  int indice = valor % tam_hash;

  Celula* novo = malloc(sizeof(Celula));

  novo->valor = valor;

  novo->proximo = hash->table[indice]->inicio;

  hash->table[indice]->inicio = novo;


}

void remover_hash(Hash* hash, int valor){
  // implementar
  int indice = valor % tam_hash;
  
  Celula *anterior = NULL;
  Celula *atual = hash->table[indice]->inicio;

  while(atual != NULL && atual->valor != valor){
      anterior = atual;
      atual = atual->proximo;
   
  }
  if(atual == NULL){
      return;
  }
  if (anterior == NULL) {
    hash->table[indice]->inicio = atual->proximo;
  } else{
      anterior->proximo = atual->proximo;
  }
  
free(atual);
}

void imprimir(Hash* hash){
  printf("---------------------\n");
  for(int i = 0; i < tam_hash; i++){
    Celula* atual = hash->table[i]->inicio;
    printf("%d -> ", i);
    while(atual != NULL){
      printf("%d ", atual->valor);
      atual = atual->proximo;
    }
    printf("\n");
  }
  printf("---------------------\n");
}

int main(void) {
  Hash* hash = start_hash();
  int valor;
  while(1){
    scanf("%d", &valor);
    if(valor == 0)
      break;
    inserir_hash(hash, valor);
  }
  imprimir(hash);
  while(1){
    scanf("%d", &valor);
    if(valor == 0)
      break;
    remover_hash(hash, valor);
  }
  imprimir(hash);
  return 0;
}