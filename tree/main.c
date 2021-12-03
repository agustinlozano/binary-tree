#include "tree.h"

/*  Output tree

           Agustin
            /   \
           /     \
      Celeste    Vicente
        /  \        /  \ 
       /    \      /    \
    Ninito  null  null  null
     /  \
    /    \
Carlos  Julieta

*/

int main(void) {
  Node *root = NULL;

  printf("\tBinary Tree\n");

  FILE *fpointer;
  char data[MEMBERS][MAX_CHARS];

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

  //Armamos el arbol
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

      //imprimir manualmente
  printf("\n\nnivel cero: %sleft: %sright: %s\n",
    root->data, root->left->data, root->right->data);

  printf("\n\nnivel uno: %sderecha: %s",
    root->left->data, root->left->right->data);
  
  // printf("\n\nnivel dos: %sleft: %sright: %s\n",
  // root->left->left->data, root->left->left->left->data, root->left->left->right->data);

  /* Nivel 3 */
  addNewNode(&root->left->right, data[4]);
  addNewNode(&root->left->right, data[5]);

  printf("\n\nMostramos el arbol en preorder\n");
  preorder(root);

  return EXIT_SUCCESS;
}
