
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