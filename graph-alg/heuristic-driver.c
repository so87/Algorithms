// Simon Owens
// Dr. Morse Algorithms and Data Structures
// Extra Credit Algorithm
#include "stdio.h"
#include "stdlib.h"
#include "heuristic.h"

int main(int argc, char **argv){
  
  printf("-------------\n\n");

  FILE * file;
  if(argc == 2){
    file = fopen(argv[1], "r");
    unsigned int touples = 0;
    fscanf(file, "%d", &touples);

    for (unsigned int i = 0; i < touples; i++){
      // get how many vertices 
      int num_vertices; 
      fscanf(file, "%d", &num_vertices); 

      // get how many edges
      int num_edges;
      fscanf(file, "%d", &num_edges);

      // call Connected componenta
      connected_components(file, num_vertices, num_edges);     
    }
   }
  else{
   printf("Usage: ./driver <input file>\n");
   printf("your input file should tell how many tuples it contains\n");
   return 1; 
  }

  // FIN
  printf("\n--------------\n");
  printf("End of program\n");

  if(argc == 2)
    free(file);


  return 0;
}
