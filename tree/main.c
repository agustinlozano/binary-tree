#include "tree.h"

int main(void) {
  Node *root = NULL;

  printf("\tBinary Tree\n");

  FILE *fpointer;
  char dataToBeRead[50];

  fpointer = fopen("input.txt", "r");

  if (fpointer == NULL) {
    printf("\nError: fallo la apertura del archivo.");
    
  } else {
    printf("\nExito: el archivo fue accedido corretamente:\n");

    //Por cada linea de texto en input.txt hago:
    while (fgets(dataToBeRead, 50, fpointer) != NULL) {
      char *nodeData = dataToBeRead;
      addNewNode(&root, nodeData);
    }
    printf("\n");
  }
  
  return EXIT_SUCCESS;
}
