// Simon Owens
// Algorithms

#include "connected-components.h"
#include "stdio.h"
#include "stdlib.h"


void connected_components(FILE* file, int num_vertices, int num_edges){
  // allocate space for your forest based on how many vertices you have
  struct node* forest = malloc(sizeof(struct node) * num_vertices);
  
  // for each vertice, make a set
  for(int j=0;j<num_vertices;j++){
    make_set(&forest[j]);
  }

  // find out how many edges you need to connect to the vertices
  for(int j=0;j<num_edges;j++){
    int v1,v2;
    fscanf(file,"%d",&v1);
    fscanf(file,"%d",&v2);

    // if the neighbors aren't unioned, then union them 
    if(find_set(&forest[v1-1]) != find_set(&forest[v2-1])){
      union_set(&forest[v1-1],&forest[v2-1]);
    }
  }

  // print out tree 
  printf("[ ");
  // print out the entire forest
  for(int i=0;i<num_vertices;i++){
    // there is another grouping of elemens in the forest  
    if(forest[i].p == &forest[i]){
      printf("[");
      // for each vertice
      for(int j=0;j<num_vertices;j++){
          // find each node in the vertice 
          if(find_set(&forest[j]) == &forest[i]){
            printf("%d",j+1);
	  if((j+1) != num_vertices)
	    printf(" ");
        }
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
}

// combine two sets together
void union_set(struct node* top,struct node *bot){
  struct node * p1 = find_set(top);
  struct node * p2 = find_set(bot);
  p2->p = p1;
}

// need to search for set to determine if we need to union them 
struct node * find_set(struct node* vertice){
  if(vertice->p == vertice){
    return vertice;
  }
  return find_set(vertice->p);
}

