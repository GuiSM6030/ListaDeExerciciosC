#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
	int valor;
	struct Vertice* esq;
	struct Vertice* dir;
	struct Vertice* pai;
} Vertice;

typedef struct Arvore{
	Vertice* raiz;
	int qtde;
} Arvore;

void in_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        in_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        in_ordem(raiz->dir);
    }
}

void pre_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

Vertice *cria_vertice(int valor){
	Vertice* novo = malloc(sizeof(Vertice));
	novo->dir = NULL;
	novo->esq = NULL;
	novo->pai = NULL;
	novo->valor = valor;
	
	return novo;
}

Arvore *cria_arvore(){
	Arvore* arvore = malloc(sizeof(Arvore));
	arvore->raiz = NULL;
	arvore->qtde = 0;

	return arvore;
}

void inserir(Arvore* arvore, int valor){
	Vertice* novo = cria_vertice(valor);

	Vertice* anterior = NULL;
	Vertice* atual = arvore->raiz;

	while(atual != NULL){
		anterior = atual;
		if(valor <= anterior->valor){
			atual = atual->esq;
		}else{
			atual = atual->dir;
		}
	}

	novo->pai = anterior;
	if(anterior != NULL){
		if(valor <= anterior->valor){
			anterior->esq = novo;
		}else{
			anterior->dir = novo;
		}
	}else{
		arvore->raiz = novo;
	}
	arvore->qtde++;
}

int remover_vertice(Arvore* arvore, Vertice* vertice) {
    // implementar

    //veirificar se não tem filhos
    if(vertice->esq == NULL && vertice->dir == NULL){
        
       //se não tiver verificar se é raiz ou filho esquerdo ou direito de seu pai, faça NULL na posição correspondente
        //sem filhos
        if(arvore->raiz==vertice){
            arvore->raiz=NULL;
        }
            
        else if(vertice->pai->dir==vertice){
            vertice->pai->dir=NULL;
        }
        else
            vertice->pai->esq=NULL;

    }

        //Se o vértice tiver um filho, faça esse filho ser filho de seu pai considerando se o vértice é filho esquerdo ou direito;
        //sem filho esquero
        if(vertice->esq == NULL || vertice->dir == NULL){
        Vertice* filho;


            if(vertice->dir!=NULL){
                filho = vertice->dir;
            }
            else
            filho = vertice->esq;
        

        if(vertice->pai == NULL){
            arvore->raiz = filho;
            filho->pai = NULL;
        }
        else {
            if(vertice->pai->esq == vertice){
                vertice->pai->esq = filho;
            }
            else {
                vertice->pai->dir = filho;
            }
            filho->pai = vertice->pai;

        }
        free(vertice);
}

    //Se o vértice tiver dois filhos, encontre o vértice mais a direita do filho esquerdo, troque os valores do vértice a ser removido 
    //com o vértice encontrado, chame a função de remoção passando a referência do vértice encontrado.

    else{
        Vertice* maior = vertice->esq;
        while(maior->dir != NULL){
            maior = maior -> dir;
        }

        vertice->valor = maior->valor;
        remover_vertice(arvore, maior);
    }

    
    arvore->qtde--;
    return 1;


}

    

Vertice *buscar_valor(Arvore* arvore, int valor){
	Vertice* atual = arvore->raiz;
	while(atual != NULL){
		if(valor < atual->valor){
			atual = atual->esq;
		}else if(valor > atual->valor){
			atual = atual->dir;
		}else{
			return atual;
		}
	}
	return NULL;
}


int main(void) {
	int dados[] = {5, 3, 8, 2, 4, 7, 9, 1, 6, 10};
  	Arvore *arvore = cria_arvore();
  	
	for(int i = 0; i < 10; i++){
		inserir(arvore, dados[i]);
		printf("Inseriu %d mostra em ordem -> ", dados[i]);
		in_ordem(arvore->raiz);
		printf("\n");
		printf("Inseriu %d mostra em pré-ordem -> ", dados[i]);
		pre_ordem(arvore->raiz);
		printf("\n");
		printf("Inseriu %d mostra em pós-ordem -> ", dados[i]);
		pos_ordem(arvore->raiz);
		printf("\n");
	}

	for(int i = 0; i < 10; i++){
		Vertice *vertice = buscar_valor(arvore, dados[i]);
		if(vertice != NULL){
			remover_vertice(arvore, vertice);
		}
		printf("Removeu %d mostra em ordem -> ", dados[i]);
		in_ordem(arvore->raiz);
		printf("\n");
		printf("Removeu %d mostra em pré-ordem -> ", dados[i]);
		pre_ordem(arvore->raiz);
		printf("\n");
		printf("Removeu %d mostra em pós-ordem -> ", dados[i]);
		pos_ordem(arvore->raiz);
		printf("\n");
	}

	free(arvore);
		
    return 0;
}
