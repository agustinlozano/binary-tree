#include "tree.h"

/* Built tree - Lines: 57-70

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
  FILE *fpointer1;
  char data[MEMBERS][MAX_CHARS];

  printf("\nAcceder archivo...\n");

  fpointer = fopen("input.txt", "r");
  fpointer1 = fopen("output.txt", "w");

  breakup();

  if (fpointer == NULL || fpointer1 == NULL) {
    printf("\nError: fallo la apertura del archivo.");
    
  } else {
    printf("\nExito: el archivo fue accedido corretamente\n");

    //Guardo cada miembro en la estructura data
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

  breakup();

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
  
  breakup();

  int choice, storeOption;
  do {
    printf("\nImprimir el arbol");

    choice = runMenu();
    switch (choice) {
      case 1:
        printf("\n\nMostramos el arbol en preorder\n");
        printPreorder(root);
        storeOption = runDataStorageMenu();

        if (storeOption == 1) {
          storeMessagePre(fpointer1);
          storePreorder(root, fpointer1);
        }
        break;

      case 2:
        printf("\n\nMostramos el arbol en inorder\n");
        printInorder(root);
        storeOption = runDataStorageMenu();

        if (storeOption == 1) {
          storeMessageIn(fpointer1);
          storeInorder(root, fpointer1);
        }
        break;

      case 3:
        printf("\n\nMostramos el arbol en postorder\n");
        printPostorder(root);
        storeOption = runDataStorageMenu();

        if (storeOption == 1) {
          storeMessagePost(fpointer1);
          storePostorder(root, fpointer1);
        }
        break;

      case 0:
        printf("\n\nSalir del programa\n\n");
        break;

      default:
        printf("\nError: opcion incorrecta\n\n");
        break;
    }
  } while (choice != 0);

  printf("\nFin del programa.\n");
  
  fclose(fpointer);
  fclose(fpointer1);

  return EXIT_SUCCESS;
}
