#define max 7

typedef struct fila
{
	int elementos[max];
	int ini;
	int fim;
	int tam;
	
}filaSeq;

void criarFila (filaSeq* fila);

int filaVazia (filaSeq *fila);

int filaCheia (filaSeq *fila);

int elementoFrente (filaSeq *fila, int *valor);

int enfileira (filaSeq *fila, int valor);

int desenfileira (filaSeq *fila);

void imprimir (filaSeq *fila);

void combina_filas (filaSeq *fila_1,filaSeq *fila_2,filaSeq *fila_3);