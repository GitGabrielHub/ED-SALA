#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int main(void){
	int escolha,valor,elemento_topo,tamanho,q_elementos,sub;
	char esvaziar_p = 's';
	Tpilha pilha,copia;
	menu ();
	printf ("\nDigite um valor de 1 a 11: ");
	scanf("%d", &escolha);
	printf("\n");

	while(escolha != 0){
		
		switch (escolha){
			case 1:
			if (pilha == NULL){
				printf("Já foi inicializada.\n");
			}
			else{
				criarPilha(&pilha);
				printf("Pilha criada.\n");
			}
			break;

			case 2:
			printf("Digite o valor para ser empilhado: ");
			scanf("%d", &valor);
			empilhar(&pilha,valor);
			printf("Empilhado.\n");
			break;

			case 3:
			desempilhar(&pilha);
			break;

			case 4:
			if(elementoTopo (pilha,&elemento_topo)){
				printf("Elemento do topo: %d\n",elemento_topo);
			}
			break;

			case 5:
			//copia = copiar (pilha);
			printf("Original: ");
			imprimir(pilha);
			//printf("Cópia: ");
			//imprimir(copia);
			break;

			case 6:
			getchar();
			printf("Tem certeza que quer esvaziar a pilha? s/n: ");
			scanf("%c", &esvaziar_p);
			if (esvaziar_p == 's') esvaziar(&pilha);
			else printf("Esvaziamento cancelado.\n");
			break;

			case 7:
			if (base (pilha,&elemento_topo)){
				printf("Elemento do topo: %d\n",elemento_topo);
			}
			break;

			case 8:
			if (tamanhoPilha(pilha,&tamanho)){
				printf("Tamanho: %d\n",tamanho);
			}
			break;

			case 9:
			printf("Digite a quantidade de elementos: ");
			scanf("%d", &q_elementos);
			desempilhar_quant (&pilha, q_elementos);
			break;

			case 10:
			if (sub_topo(pilha,&sub)) printf("Sub-topo: %d\n", sub);
			break;

			case 11:
			menu ();
			break;

			case 12:
			concatena_pilhas(&pilha,&copia);
			printf("Concatenado com sucesso");
			break;

			case 13:
			retira_impares (&pilha);
			printf("Ímpares retirados com sucesso");
			break;

			default:
			printf("Opção inválida.\n");
			break;

		}
		getchar();
		printf ("\nDigite um valor de 1 a 11: ");
		scanf("%d", &escolha);
		printf("\n");

	}
	printf("Obrigado por usar o EDITOR DE PILHA v2.0");
	return 0;
}