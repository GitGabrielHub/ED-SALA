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

	if (pilhaVazia(*pilha)){
		printf("Pilha vazia.\n");
	 	return 0;
	}
	Tpilha aux;
	aux = *pilha;
	*pilha = aux -> prox;
	printf("Elemento desempilhado com sucesso: %d\n", aux -> dado);
	free(aux);
	return 1;
}

int elementoTopo( Tpilha pilha, int *dado ){
	if (pilhaVazia(pilha)){
	printf("Não há elementos.\n"); 
	return 0;
	}

	*dado = pilha -> dado;
	return 1;
}

int imprimir (Tpilha pilha){
	if (pilhaVazia(pilha)){
		printf("Pilha vazia.\n");
	 	return 0;
	}
	Tpilha aux;
	aux = pilha;
	printf("Pilha = [ ");
	while (aux != NULL){
		printf("%d ", aux -> dado);
		aux = aux -> prox;
	}
	printf("]\n");
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

void esvaziar (Tpilha* pilha){
	if (pilhaVazia(*pilha)){
		printf("Pilha vazia.\n");
	 	
	}
	Tpilha aux,anterior;
	aux = *pilha;
	anterior = aux;

	while (aux != NULL){
		
		free(anterior);
		aux = aux -> prox;
		anterior = aux;
	}
	printf("Pilha esvaziada com sucesso.\n");
	*pilha = NULL;
}

int base (Tpilha pilha, int *dado){
	if (pilhaVazia(pilha)){
	printf("Não há elementos.\n"); 
	return 0;
	}
	while (pilha -> prox != NULL){

		pilha = pilha -> prox;
	}
	*dado = pilha -> dado;
	return 1;
}

int tamanhoPilha(Tpilha pilha,int* tamanho){
	if (pilhaVazia(pilha)){
		printf("Pilha vazia.\nTamanho: 0\n");
		return 0;
	}
	int contador = 0;
	while(pilha != NULL){
		contador++;
		pilha = pilha -> prox;
	}
	*tamanho = contador;
	return 1;
}

int desempilhar_quant (Tpilha* pilha, int quant){

	if (pilhaVazia(*pilha)){
		printf("Pilha vazia.\n");
	 	return 0;
	}
	int tam;
	tamanhoPilha(*pilha,&tam);
	if (quant > tam || quant < 1){
		printf("Não há essa quantidade de elementos na pilha.\n");
		return 0;
	}

	Tpilha aux;
	
	for (quant; quant != 0; quant--){
		
		aux = *pilha;
		printf("Elemento desempilhado com sucesso: %d\n", aux -> dado);
		free(aux);
		*pilha = aux -> prox;
	
	}

	return 1;
}

int sub_topo (Tpilha pilha, int *sub_t){
	int tam;
	tamanhoPilha(pilha,&tam);
	if (tam < 2){
		printf("Não há sub-topo.\n");
		return 0;
	}

	*sub_t = (pilha -> prox) -> dado;
	return 1;
}

void menu (){
	printf("\nEditor de pilha v2.0\n");
	printf("=====================\n\n");
	printf("1- Inicializar\n");
	printf("2- Empilhar\n");
	printf("3- Desempilhar\n");
	printf("4- Elemento topo\n");
	printf("5- Imprimir pilha\n");
	printf("6- Esvaziar a pilha\n");
	printf("7- Base da pilha\n");
	printf("8- Tamanho da pilha\n");
	printf("9- Desempilhar N elementos\n");
	printf("10- Mostrar sub-topo\n");
	printf("11- Mostar menu\n");
	printf("0- Sair do editor\n");
}

void concatena_pilhas (Tpilha* pilha, Tpilha* copia ){
	Tpilha aux_copia,novo,aux_anterior;
	int tam;
	tamanhoPilha(*copia, &tam);

	for (tam; tam != 0; tam--){
		aux_copia = *copia;
		while (aux_copia -> prox != NULL){
			aux_anterior = aux_copia;
			aux_copia = aux_copia -> prox;
		}
		novo = (no*) malloc (sizeof(no));
		novo -> dado = aux_copia -> dado;
		novo -> prox = *pilha;
		*pilha = novo;
		free(aux_copia);
		aux_anterior -> prox = NULL;

	}
}

void retira_impares (Tpilha* pilha){
	
	Tpilha aux = *pilha,cabeca = *pilha;
	while(aux != NULL){

		if ( (*pilha) -> dado % 2 == 0){
			aux = aux -> prox;
			while (aux != NULL){
				if ( aux -> dado % 2 == 0){
					(*pilha) -> prox = aux;
					(*pilha) = (*pilha) -> prox;
					aux = (*pilha) -> prox;
				}
				else{
					free((*pilha) -> prox);
					aux = aux -> prox;
			
				}
			}
		(*pilha) -> prox = NULL;
		*pilha = cabeca;
		break;
		}

		else {
			// printf("Retirei: %d\n", aux -> dado);
			*pilha = aux -> prox;
			free(aux);
			aux = *pilha;
			cabeca = *pilha;
		}
	
	}
}