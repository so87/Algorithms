// Simon Owens
// Algorithms

#include "heuristic.h"
#include "stdio.h"
#include "stdlib.h"

void connected_components(FILE* graph){

  int vertices;
  fscanf(graph,"%d",&vertices);
  struct node* forest = malloc(sizeof(struct node) * vertices);
  for(int j=0;j<vertices;j++){
    make_set(&forest[j]);
  }
  int edges;
  fscanf(graph,"%d",&edges);
  for(int j=0;j<edges;j++){
    int v1,v2;
    fscanf(graph,"%d",&v1);
    fscanf(graph,"%d",&v2);

    if(find_set(&forest[v1-1]) != find_set(&forest[v2-1])){
      union_set(&forest[v1-1],&forest[v2-1]);
    }
  }
  print(forest,vertices);
  printf("\n");
  free(forest);
}

void make_set(struct node * v){
  v->p = v;
}

void union_set(struct node* v1,struct node *v2){
  struct node * pi = find_set(v1);
  struct node * p2 = find_set(v2);
  p2->p = pi;
}



struct node * find_set(struct node* v1){
  if(v1->p == v1){
    return v1;
  }
  return find_set(v1->p);
}

void print(struct node * sets,int len){
  printf("[ ");
  for(int i=0;i<len;i++){
    if(sets[i].p == &sets[i]){
      printf("[");
      for(int j=0;j<len;j++){
        if(find_set(&sets[j]) == &sets[i]){
          printf("%d ",j+1);
        }
      }
      printf("]");
    }
  }
  printf("]\n");
} 

