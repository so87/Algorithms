#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "heuristic.h"

void connected_components(FILE* file, node* forest){

  int num_vertices;; 
  fscanf(file, "%d", &num_vertices);
  int num_edges; 
  fscanf(file, "%d", &num_edges);    
  
  // allocate for the forest     
  forest = malloc((num_vertices + 1) * sizeof(node));            

  for (int i = 1; i <= num_vertices; i++)
  {
    make_set(forest, i); 
  }
  
  // make sure to cover each edge 
  int e1,e2;
  for (int i = 0; i < num_edges; i++){ 
     // read in the edges from the file 
     fscanf(file, "%d", &e1);
     fscanf(file, "%d", &e2); 
     
    // this checks if they aren't the same
    if( (find_set(&forest[e1]))->index != (find_set(&forest[e2]))->index)
        {
          // this unions by rank 
          union_set(&forest[e1],&forest[e2]);         
        }              
      
    }
    // print out that forest
    print(forest, num_vertices);
}    
    

node * find_set(node * v){
  // this is path compression
  if (v->index != v->p->index){
    return v->p = find_set(v->p);      
  }  
  return v->p;  
}
void make_set(node * forest, int i){
  forest[i].index = i;
  forest[i].p = &forest[i];
  forest[i].rank = 0; 
}

// union by rank is in link 
void union_set(node * v1, node * v2){
  link(find_set(v1), find_set(v2));
}

void link(node * v1, node * v2){
  // if the first forest has a bigger rank. attach the second to it
  if (v1->rank > v2->rank){
    v2->p = v1->p;
  }
  else{
    // otherwise, attach the first to the second
    v1->p = v2->p;
    if(v1->rank == v2->rank){
      v2->rank = v2->rank +1; // update the rank
    }
  }
}

void print(node * forest,int num_vertices){
  // print out, morse format annoying
  printf("[ "); 
  
  // this is a forest
  for (int i = 1; i <= num_vertices; i++){   
    // this is a tree 
    if(forest[i].p->index == forest[i].index){
      printf("[ ");
      for (int j = 1; j <= num_vertices; j++){
        if ((find_set(&forest[j]))->index == forest[i].index){
          // printing out value in tree 
          printf("%d ",j);
        }
      }
      printf("]");
    }
  }    
  // forest is done 
  printf("]");   
  printf("\n");
}


