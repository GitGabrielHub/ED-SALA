#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int main(void){

	int dado;

	Tpilha p,c;
	criarPilha(&p);

	if (pilhaVazia(p)){ 
		printf("Vazia\n");
	}

	if(empilhar(&p,500) && empilhar(&p,400) && empilhar(&p,300) && 
		empilhar(&p,200) && empilhar(&p,100)){
		printf("Empilhado\n");
	}

	desempilhar(&p);
	desempilhar(&p);

	printf("%d\n", p -> dado);

	printf("Impressão original:\n");
	imprimir(p);
	if(elementoTopo(p,&dado)) printf("elementoTopo = %d\n", dado);

	c = copiar(p);
	printf("\nImpressão copia:\n");
	imprimir(c);
	if(elementoTopo(c,&dado)) printf("elementoTopo = %d\n", dado);

	return 0;
}