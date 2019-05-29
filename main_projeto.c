#include "projeto.h"

int main(void){
	clock_t Inicio, Fim;

	TlistaEnc listaEnc ;
	inicializar(&listaEnc);

	int i = 100; // Quantidade de números aleatórios no lista Encadeada
	for (i; i != 0; i--){
		add(&listaEnc, rand() % 100);
	}

	imprimir(listaEnc);

	Inicio = clock();
	HeapSort(&listaEnc,listaEnc.size);
	Fim = clock();
	float Total = ((Fim - Inicio));

	printf("-------------------------------\n");
	printf("Após o HeapSort\n");
	imprimir(listaEnc);

	printf("A ordenacao foi: %s\n", verificarOrdenacao(listaEnc) ? "Sucesso":"Fracasso");
	printf("Tempo de execucao = (%.2f ms)",Total);
	return 0;
}