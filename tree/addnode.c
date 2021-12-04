#include "tree.h"

/*  Documentation:
  Parametros:
    n     es cualquier nodo
    data  es el dato de un nodo que aun no existe

  La funcion es recursiva por tanto el codigo
    if n igual null es caso base
  Que seria cuando llego a una hoja en el arbol

  Por otra parte, si se da que
    n es distinto de null
  entonces la funcion se llama recursivamente

  En definitiva la funcion solo agrega un nodo
  en el brazo del arbol que corresponda.
*/

void addNewNode(Node **n, char *data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  Node *aux;
  int cmpValue;

  if (*n == NULL) {
    (*n) = newNode;
    setLeaves(*n);
    setData(*n, data);

  } else {
    //Comparar data contra el root
    if ((*n)->left == NULL && (*n)->right == NULL) {
      cmpValue = strcmp(data,(*n)->data);
      
      if (cmpValue <= 0) {
        addNewNode(&((*n)->left), data);

      } else {
        addNewNode(&((*n)->right), data);
      }

    //comparar data contra el contendido del nodo left
    } else if ((*n)->left != NULL && (*n)->right == NULL) {
      cmpValue = strcmp(data,(*n)->left->data);

      if (cmpValue <= 0) {
        aux = (*n)->left;
        (*n) -> left = NULL;

        addNewNode(&((*n)->left), data);
        addNewNode(&((*n)->right), aux->data);

      } else {
        addNewNode(&((*n)->right), data);
      }
    
    //comparar data contra el contendido del nodo right
    } else if ((*n)->left == NULL && (*n)->right != NULL) {
      cmpValue = strcmp(data,(*n)->right->data);

      if (cmpValue <= 0) {
        addNewNode(&((*n)->left), data);

      } else {
        aux = (*n)->right;
        (*n)->right = NULL;

        addNewNode(&((*n)->right), data);
        addNewNode(&((*n)->left), aux->data);
      }

    } else {
      printf("\nUps! Parece que hubo un error\n");
    }
  }
}

void setData(Node *n, char *data) {
  n -> data = data;
  printf("\tSe agrega un nodo con: %s", n->data);
}

void setLeaves(Node *n) {
  n -> left = NULL;
  n -> right = NULL;
}
