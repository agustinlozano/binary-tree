#include "tree.h"

void storePreorder(Node *n, FILE *fpointer){
  if (n == NULL) {
    return;
  }
  
  fprintf(fpointer, "%s", n->data);
  storePreorder(n->left, fpointer);
  storePreorder(n->right, fpointer);
}

void storeInorder(Node *n, FILE *fpointer) {
  if (n == NULL) {
    return;
  }

  storeInorder(n->left, fpointer);
  fprintf(fpointer, "%s", n->data);
  storeInorder(n->right, fpointer);
}

void storePostorder(Node *n, FILE *fpointer) {
  if (n == NULL) {
    return;
  }

  storePostorder(n->left, fpointer);
  storePostorder(n->right, fpointer);
  fprintf(fpointer, "%s", n->data);
}

void storeMessagePre(FILE *fptr) {
  char *message = "\nAlmacenado en preorder\n";
  fprintf(fptr, "%s", message);
}

void storeMessageIn(FILE *fptr) {
  char *message = "\nAlmacenado en inorder\n";
  fprintf(fptr, "%s", message);
}

void storeMessagePost(FILE *fptr) {
  char *message = "\nAlmacenado en postorder\n";
  fprintf(fptr, "%s", message);
}
