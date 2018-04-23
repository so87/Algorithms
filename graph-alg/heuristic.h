#ifndef FOO_H_   /* Include guard */
#define FOO_H_

#include "stdlib.h"
#include "stdio.h"
typedef struct node node;
struct node {
  struct node* p;
  int rank;
  int index;
};

void connected_components(FILE* file, node* forest);
void make_set(struct node* forest, int index);
void link(struct node* vertice1, struct node* vertice2);
struct node* find_set(struct node* vertice);
void union_set(struct node* top, struct node* bot);
void print(struct node* forest, int vertices);
#endif // FOO_H_

