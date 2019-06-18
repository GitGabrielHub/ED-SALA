#include <stdio.h>
#include <stdlib.h>
#include "fila_seq.h"

int main(void){
	filaSeq fila,fila_2,fila_3;
	criarFila(&fila);
	criarFila(&fila_2);
	criarFila(&fila_3);

	enfileira(&fila, 110);
	enfileira(&fila, 120);

	enfileira(&fila_2, 140);
	enfileira(&fila_2, 150);
	enfileira(&fila_2, 160);
	enfileira(&fila_2, 170);
	enfileira(&fila_2, 180);

	imprimir(&fila);


	imprimir(&fila);

	combina_filas (&fila, &fila_2, &fila_3);

	imprimir(&fila_3);

	return 0;

}