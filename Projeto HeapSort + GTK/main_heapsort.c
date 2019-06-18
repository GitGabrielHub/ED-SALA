#include "GtkWidget.h"

int main(int argc, char **argv){

  inicializarEncadeado(&listaEnc);
  inicializarSequencial(&vetor);

  GtkWidget * window,* grid,* boton1,* boton2,* boton3, * conteudo;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);
  gtk_window_set_title (GTK_WINDOW (window), "Programa");

  grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(window), grid);
  gtk_grid_set_row_spacing(GTK_GRID(grid),2.5);
  gtk_grid_set_column_spacing (GTK_GRID(grid),2.5);

  number1 = gtk_entry_new();
  gtk_grid_attach(GTK_GRID(grid), number1, 0, 0, 1, 1);

  boton1 = gtk_button_new_with_label("Gerar números aleatórios");
  g_signal_connect(boton1, "clicked", G_CALLBACK(gerar_numeros), NULL);
  gtk_grid_attach(GTK_GRID(grid), boton1, 1, 0, 1, 1);

  boton2 = gtk_button_new_with_label("Ordenar com lista encadeada");
  g_signal_connect(boton2, "clicked", G_CALLBACK(ordenar_encadeado), NULL);
  gtk_grid_attach(GTK_GRID(grid), boton2, 0, 1, 1, 1);

  boton3 = gtk_button_new_with_label("Ordenar com lista sequencial");
  g_signal_connect(boton3, "clicked", G_CALLBACK(ordenar_sequencial), NULL);
  gtk_grid_attach(GTK_GRID(grid), boton3, 1, 1, 1, 1);

  time_encadeado = gtk_label_new("TEMPO ENCADEADO");
  gtk_grid_attach(GTK_GRID(grid), time_encadeado, 0, 2, 1, 1);

  time_sequencial = gtk_label_new("TEMPO SEQUENCIAL");
  gtk_grid_attach(GTK_GRID(grid), time_sequencial, 1, 2, 1, 1);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;

}