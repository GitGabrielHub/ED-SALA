#include <stdlib.h>
#include <stdio.h>
#include "fila_enc.h"

int main(void){
	int valor;
	Tfila fila,fila_2,fila_3;
	criarFila(&fila);
	criarFila(&fila_2);
	criarFila(&fila_3);

	if(filaVazia(fila)) printf("Vazia\n");

	enfileirar(&fila,100);
	enfileirar(&fila,200);
	enfileirar(&fila,300);
	
	enfileirar(&fila_2,400);
	enfileirar(&fila_2,500);
	enfileirar(&fila_2,600);
	enfileirar(&fila_2,700);
	enfileirar(&fila_2,800);

	fila_alternada (fila,fila_2,&fila_3);
	
	desenfileirar(&fila);

	elementoFrente(fila,&valor);
	printf("elementoFrente: %d\n", valor);

	printf("Tamanho da fila: %d\n", fila.tamanho);

	imprimir(fila_3);

	return 0;
}
