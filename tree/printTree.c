#include "tree.h"

void preorder(Node *n) {
  Node *leftTree = (n -> left);

  printf("%s\n", n->data);

  if (n->left == NULL && n->right == NULL) {
    preorder(n -> right);
  } else if (leftTree != NULL) {
    preorder(leftTree);
  } else {
    printf("\nfin");
  }
}
