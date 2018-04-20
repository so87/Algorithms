// Simon Owens
// Dr. Morse Algorithms and Data Structures
// Extra Credit Algorithm
#include "stdio.h"
#include "stdlib.h"
#include "heuristic.h"

int main(int argc, char **argv){
  

  FILE * file;
  if(argc == 2){
    file = fopen(argv[1], "r");
    unsigned int touples = 0;
    fscanf(file, "%d", &touples);

    for (unsigned int i = 0; i < touples; i++){
      // call Connected components
     
 
      // print out the answer


    }
   }
  else{
   printf("Usage: ./driver <input file>\n");
   printf("your input file should tell how many tuples it contains\n");
   return 1; 
  }

  // FIN
  printf("--------------\n");
  printf("End of program\n");

  if(argc == 2)
    free(file);


  return 0;
}
