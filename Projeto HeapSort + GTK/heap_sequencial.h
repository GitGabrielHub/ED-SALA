#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdbool.h>

typedef struct vetor{

  int *vetor;
  int tamanho;

}TVet;

void HeapSortSequencial(int vet[], int tamanho);
void ordenarSequencial(int vet[], int tamanho, int maiorElemento);
void trocarElementosSequencial(int vet[], int posicaoMenor, int posicaoMaior);
void imprimirSequencial(int vet[], int tamanho);
bool verificarOrdenacao_sequencial(int vet[], int tamanho);
bool iniciarVetor(TVet *vetor, int tamanho);
void inicializarSequencial(TVet* vetor);
void adicionar_txt_sequencial(TVet* vetor);
void adicionar_sequencial (TVet* vetor);
void calcular_tempo (int T,char auxiliar[40]);
