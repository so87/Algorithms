#ifndef FOO_H_   /* Include guard */
#define FOO_H_

#include "stdlib.h"
#include "stdio.h"

struct node {
  struct node* p;
  int rank;
};

void connected_components(FILE* file, int num_vertices, int num_edges);
void make_set(struct node* vertice);
struct node* find_set(struct node* vertice);
void union_set(struct node* top, struct node* bot);

#endif // FOO_H_

