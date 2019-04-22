typedef struct nofila{
	int dado;
	struct nofila* prox;
}no;

typedef struct controle{
	no* inicio;
	no* final;
	int tamanho;
}Tfila;

void criarFila(Tfila *fila );

int filaVazia (Tfila fila);

int elementoFrente (Tfila fila, int *valor);

int tamanhoFila( Tfila fila );

int enfileirar(Tfila *fila, int elemento );

int desenfileirar(Tfila *fila );

void imprimir(Tfila fila);