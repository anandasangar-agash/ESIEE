#include <stdio.h>

#include "sudoku.h"
#include "in_out.h"

int main(int argc, char* argv[]){
  Board B;

  fread_board(argv[1], B);

  printf("Grille initiale :\n");
  print_board(B);

  int n = count_solutions(B);
  printf("Nombre total de solutions : %d\n", n);
  
  printf("Solution :\n");
  if (!solve_board(B)) {
    printf("Pas de solution :(\n");
  }


  return 0;
}
