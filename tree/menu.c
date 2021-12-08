
#include "tree.h"

int runMenu(void) {
  int choice;

  printf("\n\t1. Mostra en preorder");
  printf("\n\t2. Mostra en inorder");
  printf("\n\t3. Mostra en postorder");
  printf("\n\t0. Salir");
  printf("\nSu eleccion: ");
  scanf(" %d", &choice);

  return choice;
}

int runDataStorageMenu(void) {
  int choice;
  printf("\nDesea almacenar los datos en el archivo de salida?");
  printf("\n1. Almacenar");
  printf("\n2. Salir");
  printf("\nSu respuesta: ");
  scanf(" %d", &choice);
  
  return choice;
}

void breakup(void) {
  char respuesta;
  printf("\nPara continuar presione una tecla.");
  printf("\nSu respuesta: ");
  scanf(" %c", &respuesta);
}