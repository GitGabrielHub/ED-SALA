#include <stdio.h>
#include <stdlib.h>
#include "fila_seq.h"

void criarFila (filaSeq* fila){
	fila -> ini = 0;
	fila -> fim = -1;
	fila -> tam = 0;

}

int filaVazia (filaSeq *fila) {return fila -> tam;}

int filaCheia (filaSeq *fila) {return fila -> tam == max;}

int elementoFrente (filaSeq *fila, int *valor){
	if(filaVazia (fila) == 0) return 0;

	*valor = fila -> elementos [ fila -> ini ];
	return 1;
}

int enfileira (filaSeq *fila, int valor){
	if (filaCheia (fila)) return 0;

	fila -> tam++;

	fila -> fim = (fila -> fim + 1) % max;
	fila -> elementos [ fila -> fim ] = valor;
	return 1;

}

int desenfileira (filaSeq *fila){
	if(filaVazia (fila) == 0) return 0;

	fila -> tam--;
	fila -> ini = ( fila -> ini + 1) % max;

	return 1;
}

void imprimir (filaSeq *fila){
	int aux = fila -> ini,i;
	printf("Fila = [ ");

	for ( i = 0, aux; i < fila -> tam; i++, aux = (aux + 1) % max) {
		printf("%d ", fila -> elementos [ aux ] );
	}
	printf(" ]\n");
}

void combina_filas (filaSeq *fila_1,filaSeq *fila_2,filaSeq *fila_3){

	if (filaVazia(fila_1) + filaVazia(fila_2) > max){
		printf("Grande demais\n");
	}

	else{
		int tam_1 = filaVazia(fila_1), tam_2 = filaVazia(fila_2);
		for (; tam_1 != 0 && tam_2 != 0; ){
			enfileira(fila_3, fila_1 -> elementos [ fila_1 -> ini]);
			enfileira(fila_3, fila_2 -> elementos [ fila_2 -> ini]);
			fila_1 -> ini = (fila_1 -> ini + 1) % max;
			fila_2 -> ini = (fila_2 -> ini + 1) % max;
			tam_1--;
			tam_2--;
		}

		if ( tam_1 != 0){
			for (tam_1; tam_1 != 0; tam_1 --){
				enfileira(fila_3, fila_1 -> elementos [ fila_1 -> ini]);
				fila_1 -> ini = (fila_1 -> ini + 1) % max;
			}
		}

		else if ( tam_2 != 0){
			for (tam_2; tam_2 != 0; tam_2 --){
				enfileira(fila_3, fila_2 -> elementos [ fila_2 -> ini]);
				fila_2 -> ini = (fila_2 -> ini + 1) % max;
			}
		}
	}


}

