typedef struct nopilha{
	int dado;
	struct nopilha* prox;
}no;

typedef no* Tpilha;

void criarPilha( Tpilha* pilha );

int pilhaVazia (Tpilha pilha);

int empilhar (Tpilha* pilha, int valor);

int desempilhar (Tpilha* pilha);

int elementoTopo( Tpilha pilha, int *dado );

int imprimir (Tpilha pilha);

Tpilha copiar (Tpilha pilha);