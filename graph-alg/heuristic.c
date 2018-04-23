// Simon Owens
// Algorithms

#include "heuristic.h"
#include "stdio.h"
#include "stdlib.h"


void connected_components(FILE* file, int num_vertices, int num_edges){
  // allocate space for your forest based on how many vertices you have
  struct node* forest;
  forest = malloc((num_vertices+1)*sizeof(struct node));
  
  // for each vertice, make a set
  for(int j=1;j<num_vertices;j++){
    forest[j].p = &forest[j];
    forest[j].rank = 0;
    forest[j].index = j;
  }

  int v1,v2;

  // find out how many edges you need to connect to the vertices
  for(int j=0;j<num_edges;j++){
    fscanf(file,"%d",&v1);
    fscanf(file,"%d",&v2);

    // if the neighbors aren't unioned, then union them 
    if(find_set(&forest[v1])->index != find_set(&forest[v2])->index){
        union_set(&forest[v1],&forest[v2]);
    }
  }

  // print out tree 
  printf("[ ");
  // print out the entire forest
  for(int i=1;i<num_vertices;i++){
    // there is another grouping of elemens in the forest  
    if(forest[i].p->index == forest[i].index){
      printf("[");
      // for each vertice
      for(int j=1;j<num_vertices;j++){
          // find each node in the vertice 
          if((find_set(&forest[j]))->index == forest[i].index)
            printf("%d ",j);
      }
      printf("]");
    }
  }

  // there is nothing left in the forest
  printf(" ]\n");

  // free up the memory you allocated
  free(forest);
}

// connect the next vertice to the forest 
void make_set(struct node * vertice){
  vertice->p = vertice;
  vertice->rank = 0;
}

void union_set(struct node *v1, struct node *v2){
  link(find_set(v1), find_set(v2));
}

// combine two sets together
void link(struct node* v1,struct node *v2){
  if (v1->rank > v2->rank) 
   v2->p = v2->p;
  else{
    v1->p = v2->p;
    if(v1->rank == v2->rank)
    v2->rank = v2->rank +1;
  }
}

// need to search for set to determine if we need to union them 
struct node * find_set(struct node* vertice){
  // path compression
  if (vertice->index != vertice->p->index)
    return vertice->p = find_set(vertice->p);
  return vertice->p;
}

