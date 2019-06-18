#include "GtkWidget.h"

void gerar_numeros (GtkWidget* boton1, gpointer data){
  num1 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number1)));
  
  unsigned long int i;
  FILE *arquivo;
  arquivo = fopen("aleatorios.txt", "w");
  if(arquivo == NULL){
      printf("Arquivo nao pode ser aberto.\n");
      return;
  }

  if(listaEnc.lista != NULL){
    apagar_lista_encadeada(&listaEnc);
  }

  int valor;
  for(i=0; i<num1; i++){
    valor = 1 + rand() % (num1 * 3);
    fprintf(arquivo, "%d ", valor);   
  }
  
  fclose(arquivo);
}

void ordenar_encadeado (GtkWidget* boton2, gpointer data){
  
  clock_t Inicio, Fim;
  ler_txt(&listaEnc);

  Inicio = clock();
  HeapSort(&listaEnc, listaEnc.size);
  Fim = clock();

  adicionar_txt_encadeado(&listaEnc);

  float tempo_final = (Fim - Inicio);
  char buffer[40];
  char tempo_encadeado[40];
  calcular_tempo(tempo_final,tempo_encadeado);
  
  snprintf(buffer, sizeof(buffer), "%s",tempo_encadeado);
  gtk_label_set_text(GTK_LABEL(time_encadeado), buffer);

  printf("A ordenacao  foi: %s\n", verificarOrdenacao_encadeado(listaEnc) ? "Sucesso":"Fracasso");
}

void ordenar_sequencial (GtkWidget* boton3, gpointer data){
	if ( (iniciarVetor(&vetor,num1)) == true) printf("Iniciado com sucesso\n");
	adicionar_sequencial(&vetor);
	clock_t Inicio, Fim;
	
	Inicio = clock();
 	HeapSortSequencial(vetor.vetor,vetor.tamanho);
  	Fim = clock();

  	adicionar_txt_sequencial(&vetor);

	float tempo_final = (Fim - Inicio);
	char buffer[40];
	char tempo_sequencial[40];
	calcular_tempo(tempo_final,tempo_sequencial);
		  
	snprintf(buffer, sizeof(buffer), "%s",tempo_sequencial);
	gtk_label_set_text(GTK_LABEL(time_sequencial), buffer);
	
	printf("A ordenacao  foi: %s\n", verificarOrdenacao_sequencial(vetor.vetor,vetor.tamanho) ? "Sucesso":"Fracasso");
}