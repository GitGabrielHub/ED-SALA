#include "heap_encadeado.h"

void inicializarEncadeado (TlistaEnc* l){
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
		l -> final_lista = novo;
		l -> size++;
		return;
	}

	l -> final_lista -> prox = novo;
	l -> final_lista = l -> final_lista -> prox;
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
	register int i;
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

}


int elementoPosicao (TlistaEnc* l, int posicao){
	register int i;
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

void apagar_lista_encadeada (TlistaEnc* l){
  no* aux;
  while(l -> lista != NULL){
    aux = l -> lista;
    l -> lista = l -> lista -> prox;
    free(aux); 
  }
  l -> size = 0;
}

void ler_txt(TlistaEnc* l){
  int valor;
 
  FILE *arquivo1;
  arquivo1 = fopen("aleatorios.txt","r");
  int cp;
  if (arquivo1 == NULL) {
      printf("Arquivo nao pode ser aberto.\n");
      return;
  }
  while (true) {
    cp = fscanf(arquivo1,"%d",&valor);
    if (cp != 1) break;
    add(l,valor);
  }
  
  fclose(arquivo1);
  //imprimir(listaEnc);
}

void adicionar_txt_encadeado(TlistaEnc* l){
  	FILE *arquivo;
  	arquivo = fopen("ordenado_encadeado.txt", "w");
  	if(arquivo == NULL){
  		printf("Arquivo nao pode ser aberto.\n");
      	return;
  	}
  	no* aux = l->lista;
  	while(aux != NULL){
    	fprintf(arquivo, "%d ", aux -> dado); 
    	aux = aux -> prox;
  	}
  	fclose(arquivo);
}

bool verificarOrdenacao_encadeado(TlistaEnc l){
	no* frente,* anterior;
	anterior = l.lista;
	frente = anterior -> prox;
	while (frente != NULL){
		if (anterior -> dado > frente -> dado) return false;
		anterior = anterior -> prox;
		frente = frente->prox;
	}
	
	return true;
}
