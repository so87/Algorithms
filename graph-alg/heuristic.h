#ifndef FOO_H_   /* Include guard */
#define FOO_H_

#include "stdlib.h"
#include "stdio.h"

struct node {
  struct node* p;
  struct node* children;
};

void connected_components(FILE* file);
void make_set(struct node* v);
struct node* find_set(struct node* v1);
void print (struct node* sets, int length);
void union_set(struct node* v1, struct node*v2);

#endif // FOO_H_

