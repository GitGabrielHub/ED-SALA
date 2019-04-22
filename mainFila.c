#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

int main(void){
	int valor;
	Tfila fila;
	criarFila(&fila);

	if(filaVazia(fila)) printf("Vazia\n");

	enfileirar(&fila,100);
	enfileirar(&fila,200);
	enfileirar(&fila,300);
	enfileirar(&fila,400);
	enfileirar(&fila,500);
	desenfileirar(&fila);

	elementoFrente(fila,&valor);
	printf("elementoFrente: %d\n", valor);

	printf("Tamanho da fila: %d\n", fila.tamanho);

	imprimir(fila);

	return 0;
}