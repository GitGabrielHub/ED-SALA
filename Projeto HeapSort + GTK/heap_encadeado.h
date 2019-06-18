#include "heap_sequencial.h"

typedef struct no
{
	int dado;
	struct no* prox;

}no;

typedef struct listaEnc
{
	struct no* lista;
	struct no* final_lista;
	int size;

}TlistaEnc;

void inicializarEncadeado(TlistaEnc* l);
void add (TlistaEnc* l, int elemento);
void imprimir (TlistaEnc l);
void mexerNo (TlistaEnc* l,int pos, int elemento);
int elementoPosicao (TlistaEnc* l, int posicao);
void trocarElementos(TlistaEnc* l, int posicaoMenor, int posicaoMaior);
void ordenar(TlistaEnc* l, int tamanho, int maiorElemento);
void HeapSort(TlistaEnc* l, int tamanho);
void apagar_lista_encadeada (TlistaEnc* l);
void adicionar_txt_encadeado(TlistaEnc* l);
void ler_txt(TlistaEnc* l);
bool verificarOrdenacao_encadeado(TlistaEnc l);