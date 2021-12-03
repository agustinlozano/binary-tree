
#include "tree.h"

int runMenu(void) {
  int choice;

  printf("\n\t1. Agregar un nodo");
  printf("\n\t2. Eliminar un nodo");
  printf("\n\t3. Imprimir la arbol");
  printf("\n\t0. Salir");
  printf("\nSu eleccion: ");
  scanf(" %d", &choice);

  return choice;
}