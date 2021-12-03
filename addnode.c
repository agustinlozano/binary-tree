#include "tree.h"

void addNewNode(Node **n, char *data) {
  Node *newNode = (Node *)malloc(sizeof(Node));

  if (*n == NULL) {
    printf("\nSe agrega una hoja del arbol");

    (*n) = newNode;
    setLeaves(*n);
    setData(*n, data);

  } else {
    int value = strcmp(data, (*n)->data);

    if (value <= 1) {
      addNewNode(&((*n)->left), data);

    } else if (value < 1) {
      addNewNode(&((*n)->right), data);

    } else {
      printf("\nError: algo salio mal!\n");
    }
  }
}

void setData(Node *n, char *data) {
  n -> data = data;
  printf("\nEl nodo ahora contiene: %s", n->data);
}

void setLeaves(Node *n) {
  n -> left = NULL;
  n -> right = NULL;
}
