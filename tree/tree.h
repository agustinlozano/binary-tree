#ifndef TREE
#define TREE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *data;
  struct node *left;
  struct node *right;
} Node;


int runMenu(void);

void addNewNode(Node **root, char *data);
  void setData(Node *n, char *data);
  void setLeaves(Node *n);

#endif