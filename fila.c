#include <stdlib.h>
#include <stdio.h>
#include "fila.h"


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