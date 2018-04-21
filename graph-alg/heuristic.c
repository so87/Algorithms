// Simon Owens
// Algorithms

#include "heuristic.h"
#include "stdio.h"
#include "stdlib.h"


void connected_components(FILE* graph){
  // find all of the vertices
  int vertices;
  fscanf(graph,"%d",&vertices);

  // allocate space for your forest based on how many vertices you have
  struct node* forest = malloc(sizeof(struct node) * vertices);
  
  // for each vertice, make a set
  for(int j=0;j<vertices;j++){
    make_set(&forest[j]);
  }

  // find out how many edges you need to connect to the vertices
  int edges;
  fscanf(graph,"%d",&edges);
  for(int j=0;j<edges;j++){
    int v1,v2;
    fscanf(graph,"%d",&v1);
    fscanf(graph,"%d",&v2);

    // 
    if(find_set(&forest[v1-1]) != find_set(&forest[v2-1])){
      union_set(&forest[v1-1],&forest[v2-1]);
    }
  }

  // print out the entire forest
  print(forest,vertices);
  printf("\n");

  // free up the memory you allocated
  free(forest);
}

// 
void make_set(struct node * v){
  v->p = v;
}

// combine two sets together
void union_set(struct node* v1,struct node *v2){
  struct node * pi = find_set(v1);
  struct node * p2 = find_set(v2);
  p2->p = pi;
}

// need to search for set to determine if we need to union them 
struct node * find_set(struct node* v1){
  if(v1->p == v1){
    return v1;
  }
  return find_set(v1->p);
}

// print out the entire forest
void print(struct node * sets,int len){
  printf("[ ");
  // print out the entire forest
  for(int i=0;i<len;i++){
    // 
    if(sets[i].p == &sets[i]){
      printf("[");
      // 
      for(int j=0;j<len;j++){
          //  
          if(find_set(&sets[j]) == &sets[i]){
          printf("%d ",j+1);
        }
      }
      printf("]");
    }
  }
  printf("]\n");
} 

