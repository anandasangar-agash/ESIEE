#include <MLV/MLV_all.h>
#include "graphic_module.h"

/* Initialisation du jeu */
void initialize_game(){
    MLV_create_window("Graphic Sudoku !", NULL, WIDTH_WINDOWS_PIX, HEIGHT_WINDOWS_PIX);
    print_message("Appuyer sur entrer pour lancer le sudoku.", 0);
    MLV_actualise_window();
}

void print_message(char* message, int clear_before){
    if(clear_before) MLV_draw_filled_rectangle(0, 0, WIDTH_WINDOWS_PIX, HEIGHT_WINDOWS_PIX, MLV_COLOR_BLACK);
    MLV_draw_text( 
        200, 250, 
        message, 
        MLV_COLOR_WHITE
    );
    MLV_actualise_window();
}

/* Affichage de la grille */
void print_grid(int first_x, int first_y, int lim_offest_x, int lim_offest_y, int clear_before){
    
    if(clear_before) MLV_draw_filled_rectangle(0, 0, WIDTH_WINDOWS_PIX, HEIGHT_WINDOWS_PIX, MLV_COLOR_BLACK);

    /* On veut 9 lignes et colonnes*/
    int offset_x = first_x;
    int offset_y;

    /* Traits Horizontaux */
    for(offset_y=first_y; offset_y < lim_offest_y; offset_y += CELL_SIZE){
        MLV_draw_line(offset_x, offset_y, lim_offest_x, offset_y, MLV_COLOR_WHITE);
    }
    /* Traits verticaux */
    offset_y = first_y;
    for(offset_x=first_x; offset_x < lim_offest_x; offset_x += CELL_SIZE){
        MLV_draw_line(offset_x, offset_y, offset_x, lim_offest_y, MLV_COLOR_WHITE);
    }
    offset_x = first_x;
    /* Dernier horizontal */
    MLV_draw_line(offset_x, lim_offest_y, lim_offest_x, lim_offest_y, MLV_COLOR_WHITE);
    /* Dernier vertical */
    MLV_draw_line(lim_offest_x, offset_y, lim_offest_x, lim_offest_y, MLV_COLOR_WHITE);

    MLV_actualise_window();
}

/* Affichage des valeurs dans la grille
On met des boites dans les cases, ça sera plus facile pour écrire dedans */
void print_values_grid(Board Grid, int clear_before){

    if(clear_before) MLV_draw_filled_rectangle(0, 0, WIDTH_WINDOWS_PIX, HEIGHT_WINDOWS_PIX, MLV_COLOR_BLACK);

    int i, j;
    int offset_x;
    int offset_y = FIRST_Y_MAIN_GRID;
    for(i=0; i < MAIN_GRID_LENGTH; i++){
        offset_x = FIRST_X_MAIN_GRID;
        for(j=0; j < MAIN_GRID_LENGTH; j++){
            unsigned short int number = Grid[i][j];
            print_int_value_into_cell(number, offset_x, offset_y, 0, 0);
            offset_x += CELL_SIZE;
        }
        offset_y += CELL_SIZE;
    }

    MLV_actualise_window();
}

void print_int_value_into_cell(unsigned short int value, int pos_x, int pos_y, int round_pos, int actualise_window){

    char string_number[6] = " "; /*6 pour un unsigned int*/
    if(value != 0) sprintf(string_number, "%hu", value);

    print_string_value_into_cell(string_number, pos_x, pos_y, round_pos, actualise_window);
}

void print_string_value_into_cell(char* value, int pos_x, int pos_y, int round_pos, int actualise_window){

    if(round_pos) round_position(&pos_x, &pos_y);

    MLV_draw_text_box(pos_x, pos_y, CELL_SIZE, CELL_SIZE, value, 1,
        MLV_COLOR_WHITE, MLV_COLOR_BLUE, MLV_COLOR_DARK_GREY, MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
    );

    if(actualise_window) MLV_actualise_window();
}

void round_position(int* pos_x, int* pos_y){
   *pos_x -= (*pos_x%CELL_SIZE);
   *pos_y -= (*pos_y%CELL_SIZE);
}

/* On trouve la cellule dans laquelle on clique. Si elle est déjà occupée, on retourne 1 */
int cell_already_complete(Board Grid, int* x, int* y){

    round_position(x, y);

    /* On récupère la valeur de cette case */
    int i, j;
    int offset_x;
    int offset_y = FIRST_Y_MAIN_GRID;
    for(i=0; i < MAIN_GRID_LENGTH; i++){
        offset_x = FIRST_X_MAIN_GRID;
        for(j=0; j < MAIN_GRID_LENGTH; j++){

            if(offset_x == *x && offset_y == *y){
                /* Déjà on sait qu'on a cliqué sur le tableau, c'est déjà ça :) */

                /* Maintenant, on regarde si la case est déjà prise */
                unsigned short int number = Grid[i][j];
                return number == 0 ? 0 : 1;
            }
            offset_x += CELL_SIZE;
        }
        offset_y += CELL_SIZE;
    }

    return 1;
}

/* Pour savoir si le clic est dans la grid. Avec l'id on différencie 
la principale et la 2e */
int clic_out_of_grid(int* x, int* y, int id_grid){

    round_position(x, y);

    if(id_grid == 1){
        return (*x < FIRST_X_MAIN_GRID || *x > LIM_OFFSET_X_MAIN_GRID
        || *y < FIRST_Y_MAIN_GRID || *y > LIM_OFFSET_Y_MAIN_GRID);
    }
    else{
        return (*x < FIRST_X_SECOND_GRID || *x > LIM_OFFSET_X_SECOND_GRID
        || *y < FIRST_Y_SECOND_GRID || *y > LIM_OFFSET_Y_SECOND_GRID);
    }    
}

/* Le clic est incorrect si en dehors de la grille, ou si case déjà remplie */
int incorrect_clic_main_grid(Board Grid, int* x, int* y){

    if(clic_out_of_grid(x, y, MAIN_GRID_ID)){
      print_message("Le clic est en dehors de la grille", 1);
      sleep(2);
      return 1;
    }
    if(cell_already_complete(Grid, x, y)){
      print_message("La case n'est pas remplissable", 1);
      sleep(2);
      return 1;
    }
    return 0;
}

/* Le clic est incorrect si en dehors de la grille, ou si case vide */
int incorrect_clic_second_grid(Second_board Grid, int* x, int* y){

    if(clic_out_of_grid(x, y, SECOND_GRID_ID)){
      print_message("Le clic est en dehors de la grille", 1);
      sleep(2);
      return 1;
    }
    if( get_value_second_grid(Grid, x, y) == 0){
      print_message("Aucune valeur choisie", 1);
      sleep(2);
      return 1;
    }

    return 0;
}

/* Pour récupérer une valeur sur la 2e grid,
on regarde sur quelle case on est car la grid est ordonnée */
int get_value_second_grid(Second_board Grid, int* x, int* y){

    round_position(x, y);

    /* On récupère la valeur de cette case */
    int val = 1;
    int i, j;
    int offset_x;
    int offset_y = FIRST_Y_SECOND_GRID;
    for(i=0; i < SECOND_GRID_LENGTH; i++){
        offset_x = FIRST_X_SECOND_GRID;
        for(j=0; j < SECOND_GRID_LENGTH; j++){

            if(offset_x == *x && offset_y == *y){
                /* Maintenant, on récupère la val de la case */
                return Grid[i][j];
            }
            val +=1;
            offset_x += CELL_SIZE;
        }
        offset_y += CELL_SIZE;
    }

    return 0;
}

/* Affiche les valeurs possibles. Si aucune, return 0 */
int print_possible_choices(Board Grid, Second_board Second_grid,
        int x, int y){

    unsigned short int at_least_one_possible_value = 0;
    unsigned short int val = 1;

    /* Attention, x devient les colonnes (j)
    et y devient les lignes ()i */
    unsigned int index_i = (x - FIRST_X_MAIN_GRID) / CELL_SIZE;
    unsigned int index_j = (y - FIRST_Y_MAIN_GRID) / CELL_SIZE;

    /* On bloucle sur les cellules du tab */
    int i, j;
    int offset_x;
    int offset_y = FIRST_Y_SECOND_GRID;
    for(i=0; i < SECOND_GRID_LENGTH; i++){
        offset_x = FIRST_X_SECOND_GRID;
        for(j=0; j < SECOND_GRID_LENGTH; j++){

        if(insertion_possible(Grid, index_j, index_i, val, MAIN_GRID_LENGTH)){
            print_int_value_into_cell(val, offset_x, offset_y, 0, 0);
            Second_grid[i][j] = val;
            at_least_one_possible_value ++;
        }
        else{
            Second_grid[i][j] = 0;
        }

        offset_x += CELL_SIZE;
        val += 1;
        }
        offset_y += CELL_SIZE;
    }
    MLV_actualise_window();

    return at_least_one_possible_value;
}

/* On met une valeur dans la grille principale */
void put_value_into_grid(Board Grid, int choosed_value, int* x, int* y){
    round_position(x, y);

    /* On récupère la valeur de cette case */
    int i, j;
    int offset_x;
    int offset_y = FIRST_Y_MAIN_GRID;
    for(i=0; i < MAIN_GRID_LENGTH; i++){
        offset_x = FIRST_X_MAIN_GRID;
        for(j=0; j < MAIN_GRID_LENGTH; j++){

            if(offset_x == *x && offset_y == *y){
                Grid[i][j] = choosed_value;
            }
            offset_x += CELL_SIZE;
        }
        offset_y += CELL_SIZE;
    }
}

int is_grid_complete(Board Grid){
    int i, j;
    for(i=0; i<MAIN_GRID_LENGTH; i++){
        for(j=0; j<MAIN_GRID_LENGTH; j++){
            if(Grid[i][j] == 0){
                printf("pas fini \n");
                return 0;
            }
        }
    }
    return 1;
}

void wait_for_enter_keybord(MLV_Keyboard_button Key){
    MLV_Keyboard_button touche = MLV_KEYBOARD_NONE;
    while( touche != MLV_KEYBOARD_RETURN ){
        MLV_wait_keyboard( &touche, NULL, NULL);
    }
}