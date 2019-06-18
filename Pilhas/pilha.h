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

void esvaziar (Tpilha* pilha);

int base (Tpilha pilha, int *dado);

int tamanhoPilha(Tpilha pilha,int* tamanho);

int desempilhar_quant (Tpilha* pilha, int quant);

int sub_topo (Tpilha pilha, int *sub_t);

void menu ();

void concatena_pilhas (Tpilha* pilha, Tpilha* copia );

void retira_impares (Tpilha* pilha);