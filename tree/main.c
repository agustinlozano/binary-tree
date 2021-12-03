#include "tree.h"

/*  Output tree

                Agustin                       Nivel 0       
                /     \
               /       \
              /         \
        Celeste         Vicente               Nivel 1
         /  \             /   \
        /    \           /     \
      null  Ninito    Carlos  Julieta         Nivel 2
             /  \      /  \     /  \
            /    \    /    \   /    \
          null  null null null null null      Nivel 3
*/

int main(void) {
  Node *root = NULL;

  printf("\tBinary Tree\n");

  FILE *fpointer;
  char data[MEMBERS][MAX_CHARS];

  printf("\nAcceder archivo:");

  fpointer = fopen("input.txt", "r");

  if (fpointer == NULL) {
    printf("\nError: fallo la apertura del archivo.");
    
  } else {
    printf("\nExito: el archivo fue accedido corretamente\n");

    //Guardo cada miembro en la estructura dataToBeRead
    int index = 0;
    while (fgets(data[index], 10, fpointer) != NULL) {
      index++;
    }
    
    printf("\nLos datos leidos desde el archivo son:\n");
    for(int i = 0; i<MEMBERS; i++){
      printf("\tMiembro n%d: %s", i+1, data[i]);
    }
    printf("\n");
  }

  printf("\nLlenamos el arbol con los datos\n");
  /* Setear el root - Nivel 0 */
  root = (Node *)malloc(sizeof(Node));
  root -> data = data[0];
  root -> left = NULL;
  root -> right = NULL;


  /* Nivel 1 */
  addNewNode(&root, data[1]);
  addNewNode(&root, data[2]);

  /* Nivel 2 */
  addNewNode(&root->left, data[3]);
  addNewNode(&root->right, data[4]);
  addNewNode(&root->right, data[5]);
  
  int choice;
  do {
    printf("\nImprimir el arbol");

    choice = runMenu();
    switch (choice) {
      case 1:
        printf("\n\nMostramos el arbol en preorder\n");
        printPreorder(root);
        break;

      case 2:
        printf("\n\nMostramos el arbol en inorder\n");
        printInorder(root);
        break;

      case 3:
        printf("\n\nMostramos el arbol en postorder\n");
        printPostorder(root);
        break;

      default:
        break;
    }
  } while (choice != 0);

  printf("\nFin del programa.\n");

  return EXIT_SUCCESS;
}
