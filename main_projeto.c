#include "projeto.h"

int main(void){
	clock_t Inicio, Fim;

	TlistaEnc listaEnc ;
	inicializar(&listaEnc);

	int i = 1000; // Quantidade de números aleatórios para por na lista lista Encadeada
	int x = i;
	for (i; i != 0; i--){
		add(&listaEnc, rand() % x);
	}

	imprimir(listaEnc);

	Inicio = clock();
	HeapSort(&listaEnc,listaEnc.size);
	Fim = clock();
	double Total = ((Fim - Inicio));

	printf("-------------------------------\n");
	printf("Após o HeapSort\n");
	imprimir(listaEnc);

	printf("A ordenacao foi: %s\n", verificarOrdenacao(listaEnc) ? "Sucesso":"Fracasso");
	Time(Total);
	return 0;
}