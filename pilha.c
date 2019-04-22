#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

void criarPilha (Tpilha* pilha){
	*pilha = NULL;
}

int pilhaVazia (Tpilha pilha){return pilha == NULL;}

int empilhar (Tpilha* pilha, int valor){

	Tpilha novo;
	novo = (no*) malloc (sizeof(no));
	
	novo -> dado = valor;
	novo -> prox = *pilha;
	*pilha = novo;
	return 1;
}

int desempilhar (Tpilha* pilha){

	if (pilhaVazia(*pilha)) return 0;

	Tpilha aux;
	aux = *pilha;
	*pilha = aux -> prox;
	printf("Elemento desempilhado com sucesso: %d\n", aux -> dado);
	free(aux);
	return 1;
}

int elementoTopo( Tpilha pilha, int *dado ){
	if (pilhaVazia(pilha)) return 0;

	*dado = pilha -> dado;
	return 1;
}

int imprimir (Tpilha pilha){
	if (pilhaVazia(pilha)) return 0;

	Tpilha aux;
	aux = pilha;
	while (aux != NULL){
		printf("Dado : %d\n", aux -> dado);
		aux = aux -> prox;
	}

	return 1;
}

Tpilha copiar (Tpilha pilha){
	if (pilhaVazia(pilha)) return NULL;

	Tpilha copia = NULL, aux, novo;
	
	while (pilha != NULL){

		
		novo = (no*) malloc (sizeof(no));
		novo -> dado = pilha -> dado;

		if (pilhaVazia(copia)){
			
			novo -> prox = NULL;
			copia = novo;
			aux = copia;
		}
		else{
				
			aux -> prox = novo;
			novo -> prox = NULL;
			aux = aux -> prox;	

		}
		
		pilha = pilha -> prox;
	}
	return copia;
}