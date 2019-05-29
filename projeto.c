#include "projeto.h"

void inicializar (TlistaEnc* l){
	l -> lista = NULL;
	l -> size = 0;
}

void add (TlistaEnc* l, int elemento){
	no* novo;
	novo = (no*) malloc (sizeof(no));
	novo -> dado = elemento;
	novo -> prox = NULL;


	if (l -> lista == NULL){
		l -> lista = novo;
		l -> size++;
		return;
	}
	no *aux;
	aux = l -> lista;
	while (aux -> prox != NULL){
		aux = aux -> prox;
	}
	aux -> prox = novo;
	l -> size++;
}

void imprimir (TlistaEnc l){
	while (l.lista != NULL){
		printf("%d ", l.lista -> dado);
		l.lista = l.lista -> prox;
	}

	printf("\nTamanho = %d\n", l.size);

}

void HeapSort(TlistaEnc* l, int tamanho){
	int i;
	for(i = tamanho/2 - 1 ;i >= 0 ; i--){
		ordenar(l, tamanho, i);
	}

	for(i = tamanho-1; i>=0; i--){
		trocarElementos(l, i, 0);
		ordenar(l, i, 0);
	}

}

void ordenar(TlistaEnc* l, int tamanho, int maiorElemento){

  int raiz = maiorElemento;
  int filhoEsquerdo = 2*maiorElemento + 1;
  int FilhoDireita = 2*maiorElemento + 2;

  if(filhoEsquerdo < tamanho && elementoPosicao(l,filhoEsquerdo) > elementoPosicao(l,raiz)) raiz = filhoEsquerdo;

  if(FilhoDireita < tamanho && elementoPosicao(l,FilhoDireita) > elementoPosicao(l,raiz)) raiz = FilhoDireita;

  if (raiz != maiorElemento){

    trocarElementos(l, raiz, maiorElemento);

    ordenar(l, tamanho, raiz);

  }

}

void trocarElementos(TlistaEnc* l, int posicaoMenor, int posicaoMaior){
  
  int aux = elementoPosicao(l, posicaoMaior);
  mexerNo(l,posicaoMaior,elementoPosicao(l,posicaoMenor));
  mexerNo(l,posicaoMenor,aux);
  //vet[posicaoMaior] = vet[posicaoMenor];
  //vet[posicaoMenor] = aux;

}


int elementoPosicao (TlistaEnc* l, int posicao){
	int i;
	no* aux;
	aux = l -> lista;
	for (i = 0; i < posicao; i++){
		aux = aux -> prox;
	}

	return aux -> dado;
}

void mexerNo (TlistaEnc* l,int pos, int elemento){
	no* aux;
	aux = l -> lista;

	for (pos; pos != 0; pos--){
		aux = aux -> prox;
	}

	aux -> dado = elemento;
}

int verificarOrdenacao(TlistaEnc l){
	
	while (l.lista->prox != NULL){
		if ( l.lista -> dado > l.lista -> prox -> dado) return 0;
		l.lista = l.lista-> prox;
	}

	return 1;
}

void Time (double T){
	if ( T / 1000000 < 1) printf("%.1f micro segundos\n",T);

	else if ( T / 1000000 < 60) printf("%.1f segundos\n",T / 1000000);

	else{
		int min,seg;
		min = (T / 1000000) / 60;
		seg =  (int)(T / 1000000) % 60;

		printf("%d minutos e %d segundos\n", min,seg);
	}


}