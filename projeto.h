#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no
{
	int dado;
	struct no* prox;

}no;

typedef struct listaEnc
{
	struct no* lista;
	int size;

}TlistaEnc;

void inicializar (TlistaEnc* l);

void add (TlistaEnc* l, int elemento);

void imprimir (TlistaEnc l);

void mecherNo (TlistaEnc* l,int pos, int elemento);

int elementoPosicao (TlistaEnc* l, int posicao);

void trocarElementos(TlistaEnc* l, int posicaoMenor, int posicaoMaior);

void ordenar(TlistaEnc* l, int tamanho, int maiorElemento);

void HeapSort(TlistaEnc* l, int tamanho);

int verificarOrdenacao(TlistaEnc l);

void Time(int T);