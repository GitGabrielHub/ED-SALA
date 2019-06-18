#include "heap_encadeado.h"

GtkWidget* time_sequencial,* time_encadeado,* number1;
TlistaEnc listaEnc ;
TVet vetor;
int num1;

void gerar_numeros (GtkWidget* boton1, gpointer data);
void ordenar_encadeado (GtkWidget* boton2, gpointer data);
void ordenar_sequencial (GtkWidget* boton3, gpointer data);