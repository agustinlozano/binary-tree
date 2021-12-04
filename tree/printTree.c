#include "tree.h"

void printPreorder(Node *n) {
  if (n == NULL) {
    return;
  }
  
  printf("\t%s", n->data);
  printPreorder(n->left);
  printPreorder(n->right);
}

void printInorder(Node *n) {
  if (n == NULL) {
    return;
  }

  printInorder(n->left);
  printf("\t%s", n->data);
  printInorder(n->right);
}

void printPostorder(Node *n) {
  if (n == NULL) {
    return;
  }

  printPostorder(n->left);
  printPostorder(n->right);
  printf("\t%s", n->data);
}