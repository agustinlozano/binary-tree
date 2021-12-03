#ifndef TREE
#define TREE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMBERS 6
#define MAX_CHARS 10

typedef struct node {
  char *data;
  struct node *left;
  struct node *right;
} Node;


int runMenu(void);

void addNewNode(Node **n, char *data);
  void setData(Node *n, char *data);
  void setLeaves(Node *n);

void printPreorder(Node *n);
void printInorder(Node *n);
void printPostorder(Node *n);

#endif