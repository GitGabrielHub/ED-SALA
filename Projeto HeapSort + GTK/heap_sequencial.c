#include "heap_sequencial.h"

void trocarElementosSequencial(int vet[], int posicaoMenor, int posicaoMaior){
  
  int aux = vet[posicaoMaior];
  vet[posicaoMaior] = vet[posicaoMenor];
  vet[posicaoMenor] = aux;

}


void HeapSortSequencial(int vet[], int tamanho){

  for(int i = tamanho/2 - 1 ;i >= 0 ; i--){
    ordenarSequencial(vet, tamanho, i);
  }

  for(int i = tamanho-1; i>=0; i--){
    trocarElementosSequencial(vet, i, 0);
    ordenarSequencial(vet, i, 0);
  }

}

void ordenarSequencial(int vet[], int tamanho, int maiorElemento){

  int raiz = maiorElemento;
  int filhoEsquerdo = 2*maiorElemento + 1;
  int FilhoDireita = 2*maiorElemento + 2;

  if(filhoEsquerdo < tamanho && vet[filhoEsquerdo] > vet[raiz]) raiz = filhoEsquerdo;

  if(FilhoDireita < tamanho && vet[FilhoDireita] > vet[raiz]) raiz = FilhoDireita;

  if (raiz != maiorElemento){

    trocarElementosSequencial(vet, raiz, maiorElemento);

    ordenarSequencial(vet, tamanho, raiz);

  }

}

void imprimirSequencial(int vet[], int tamanho){

  printf("HEAPSORT ARRAY [ ");
  for(int i = 0; i < tamanho; i++){
    printf("%d ", vet[i]);
  }
  printf("]\n");
  printf("tamanho : %d\n", tamanho);
}

bool verificarOrdenacao_sequencial(int vet[], int tamanho){
  for(int i = 1; i < tamanho; i++){
    if(vet[i-1] > vet[i]) return false;
  }

  return true;
}

bool iniciarVetor(TVet *vet, int tamanho){
  
 if (vet->vetor == NULL){
  int *pI;
  if ((pI = (int*)malloc(tamanho*sizeof(int))) == NULL) return false;


  vet->vetor = pI;
  vet->tamanho = tamanho;


 }else if(tamanho != vet->tamanho){
   free(vet->vetor);
   vet->tamanho = tamanho;

   int *pI;
   if ((pI = (int*)malloc(tamanho*sizeof(int))) == NULL) return false;

  vet->vetor = pI;
 }
  
 return true;
   
}

void inicializarSequencial(TVet* vetor){
  vetor->vetor = NULL;
}

void adicionar_sequencial (TVet* vetor){
	unsigned long int i;
	 
	FILE *arquivo1;
	arquivo1 = fopen("aleatorios.txt","r");
	if (arquivo1 == NULL) {
		printf("Arquivo nao pode ser aberto.\n");
	    return;
	}
	int valor;
	for (i=0;i<vetor->tamanho;i++){
		fscanf(arquivo1,"%d",&valor);
		vetor->vetor[i] = valor;
	}

	fclose(arquivo1);

}

void adicionar_txt_sequencial(TVet* vetor){
	unsigned long int i;
	 
	FILE *arquivo1;
	arquivo1 = fopen("ordenado_sequencial.txt","w");
	if (arquivo1 == NULL) {
		printf("Arquivo nao pode ser aberto.\n");
	    return;
	}
	int valor;
	for (i=0;i<vetor->tamanho;i++){
		fprintf(arquivo1, "%d ", vetor->vetor[i]); 
	}

	fclose(arquivo1);
}

void calcular_tempo (int T,char auxiliar[40]){
  char nano[25];
  char us[20];
  strcpy(us," Microssegundos");
  if (T  / 1000000 < 1){
  	sprintf(nano, "%d", T);

  	int i;
  	for (i = 0; nano[i] != '\0'; i++){
  		auxiliar[i] = nano[i];
  	}
  	int j;
  	for(j = 0; us[j] != '\0'; j++,i++){
  		auxiliar[i] = us[j];
  	}
  	auxiliar[i] = '\0';
 
  	return;
  }
  char hms[20];
  strcpy(auxiliar,"H  : M  : S\n");

  T = T  / 1000000;

  int hor,min,seg,b;
  char h[10],m[10],s[10],t[10];

  hor =  T / 3600;
  b = T - ( hor * 3600);
  min =  b / 60;
  seg =  b - (min * 60);

  sprintf(h, "%i", hor);
  sprintf(m, "%i", min);
  sprintf(s, "%i", seg);

  if(hor < 10 || hor == 0){
  	auxiliar[12] ='0';
  	auxiliar[13] = h[0];
  }

  else{
  	auxiliar[12] = h[0];
  	auxiliar[13] = h[1];
  }

  auxiliar[14] = ' ';
  auxiliar[15] = ':';
  auxiliar[16] = ' ';

  if(min < 10){
    auxiliar[17] = '0';
    auxiliar[18] = m[0];
  }

  else {
    auxiliar[17] = m[0];
    auxiliar[18] = m[1];
  }

  auxiliar[19] = ' ';
  auxiliar[20] = ':';
  auxiliar[21] = ' ';

  if (seg < 10){
    auxiliar[22] = '0';
    auxiliar[23] = s[0];
  }

  else {
    auxiliar[22] = s[0];
    auxiliar[23] = s[1];
  }

  auxiliar[24] = '\0';

}