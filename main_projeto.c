#include "projeto.h"

int main(void){
	clock_t Inicio, Fim;

	TlistaEnc listaEnc ;
	inicializar(&listaEnc);
	
	//if (listaEnc.lista == NULL && listaEnc.size == 0) printf("Tudo certo\n");
	//printf("%d\n", rand() % 100);

	int i;
	for (i = 100; i != 0; i--){
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