#include <stdio.h>
#include "sudoku.h"
#include "graphic_module.h"

int main(int argc, char* argv[]){
  Board Grid;
  Second_board Second_grid;
  enum Result result = PLAYING;

  initialize_empty_board(Grid);
  fread_board(argv[1], Grid);
  initialize_game();
  wait_for_enter_keybord(MLV_KEYBOARD_RETURN);

  while(1){

    /* Vérification : Si victoire ou défaite, on sort */
    if(is_grid_complete(Grid)){
      result = WIN;
      goto ending;
    }

    /* Afficher la grille et les valeurs */
    print_grid(FIRST_X_MAIN_GRID, FIRST_Y_MAIN_GRID, LIM_OFFSET_X_MAIN_GRID, LIM_OFFSET_Y_MAIN_GRID, 1);
    print_values_grid(Grid, 0);

    /* Récupération des positions x et y */
    int x, y;

    MLV_wait_mouse(&x, &y);
    if(incorrect_clic_main_grid(Grid, &x, &y)) continue;

    /* On affiche les options possibles sur une autre grille
      + on met un ? dans la case séléctionnée
      + on met en surbrillance la case séléctionné */
    print_grid(FIRST_X_SECOND_GRID, FIRST_Y_SECOND_GRID, LIM_OFFSET_X_SECOND_GRID, LIM_OFFSET_Y_SECOND_GRID, 0);

    if(!print_possible_choices(Grid, Second_grid, x, y)){
      result = LOSE;
      goto ending;
    }
    print_string_value_into_cell("?", x, y, 1, 1);

    /* On récupère la valeur choisie dans la seconde grille */
    int x_second_grid, y_second_grid;
    MLV_wait_mouse(&x_second_grid, &y_second_grid);
    if(incorrect_clic_second_grid(Second_grid, &x_second_grid, &y_second_grid)) continue;
    int choosed_value = get_value_second_grid(Second_grid, &x_second_grid, &y_second_grid);

    /* On met la valeur dans la cellule choisie */
    put_value_into_grid(Grid, choosed_value, &x, &y);
  }

  ending:

  if(result){
    print_message("Vous avez gagné, félicitations ! "
      "Appuyer sur entrer pour quitter le sudoku ! ", 1);
  }
  else{
    print_message("Vous avez perdu, dommage ! "
      "Appuyer sur entrer pour quitter le sudoku ! ", 1);
  }
  wait_for_enter_keybord(MLV_KEYBOARD_RETURN);
  MLV_free_window();
  return 0;
}