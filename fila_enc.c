#include <stdlib.h>
#include <stdio.h>
#include "fila_enc.h"


void criarFila(Tfila *fila ){
	fila -> inicio = fila -> final = NULL;
	fila -> tamanho = 0;
}

int filaVazia(Tfila fila){return (fila.tamanho == 0);}

int tamanhoFila( Tfila fila ){ return fila.tamanho;}

int elementoFrente (Tfila fila, int *valor){
	if (filaVazia(fila)) return 0;

	*valor = fila.inicio -> dado;
	return 1;
}

int enfileirar(Tfila *fila, int elemento ){
	no* novo;
	novo = (no*) malloc (sizeof(no));
	novo -> dado = elemento;
	novo -> prox = NULL;

	if (filaVazia(*fila)) fila -> inicio = novo;
	else (fila -> final) -> prox = novo;

	fila -> final = novo;
	fila -> tamanho++;
	return 1;
}

int desenfileirar(Tfila *fila){
	if (filaVazia(*fila)) return 0;

	if(tamanhoFila(*fila)  == 1){
		fila -> final = NULL;

	}

	no* aux = fila -> inicio;
	fila -> inicio = (fila -> inicio) -> prox;
	free(aux);
	fila -> tamanho --;
	return 1;
}

void imprimir( Tfila fila ){
	printf("Fila = [ ");
   	// varrendo todos os elementos
   	while ((fila.inicio) != NULL){
		printf( "%d ", (fila.inicio)->dado );
		fila.inicio = (fila.inicio) -> prox;
	}
   	printf("]\n");
}

void fila_alternada (Tfila fila_1, Tfila fila_2,Tfila* fila_3){

	int tam_1 = tamanhoFila(fila_1), tam_2 = tamanhoFila(fila_2);
	no *aux_1 = fila_1.inicio, *aux_2 = fila_2.inicio;
	
	while( tam_1 != 0 && tam_2 != 0){

		enfileirar(fila_3, aux_1 -> dado);
		enfileirar(fila_3, aux_2 -> dado);
		aux_1 = aux_1 -> prox;
		aux_2 = aux_2 -> prox;

		tam_1--;
		tam_2--;
		
	}

	if (tam_1 != 0){
		while( tam_1 != 0){
			enfileirar(fila_3, aux_1 -> dado);
			aux_1 = aux_1 -> prox;
			tam_1--;
		}
	}

	else if (tam_2 != 0){
		while( tam_2 != 0){
			enfileirar(fila_3, aux_2 -> dado);
			aux_2 = aux_2 -> prox;
			tam_2--;
		}
	}
}
