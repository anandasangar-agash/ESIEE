#ifndef GRAPHIC_MODULE
#define GRAPHIC_MODULE

#include <MLV/MLV_all.h>
#include "sudoku.h"
#include <unistd.h>

#define WIDTH_WINDOWS_PIX 1200
#define HEIGHT_WINDOWS_PIX 800

#define FIRST_X_MAIN_GRID 100
#define FIRST_Y_MAIN_GRID 100
#define LIM_OFFSET_X_MAIN_GRID 500
#define LIM_OFFSET_Y_MAIN_GRID 500

#define FIRST_X_SECOND_GRID 600
#define FIRST_Y_SECOND_GRID 250
#define LIM_OFFSET_X_SECOND_GRID 750
#define LIM_OFFSET_Y_SECOND_GRID 400

#define MAIN_GRID_LENGTH 9
#define SECOND_GRID_LENGTH 3

#define MAIN_GRID_ID 1
#define SECOND_GRID_ID 2

#define CELL_SIZE 50

enum Result {LOSE, WIN, PLAYING};

void print_grid(int first_x, int first_y, int lim_offest_x, int lim_offest_y, int clear_before);
void print_values_grid(Board Grid, int clear_before);
void initialize_game();
void print_message(char* message, int clear_before);
int cell_already_complete(Board Grid, int* x, int* y);
int clic_out_of_grid(int* x, int* y, int id_grid);
int incorrect_clic_main_grid(Board Grid, int* x, int* y);
int incorrect_clic_second_grid(Second_board Grid, int* x, int* y);
void print_int_value_into_cell(unsigned short int value, int pos_x, int pos_y, int round_pos, int actualise_window);
void print_string_value_into_cell(char* value, int pos_x, int pos_y, int round_pos, int actualise_window);
int print_possible_choices(Board Grid, Second_board Second_grid, int x, int y);
void round_position(int* pos_x, int* pos_y);
int get_value_second_grid(Second_board Second_grid, int* x, int* y);
void put_value_into_grid(Board Grid, int choosed_value, int* x, int* y);
int is_grid_complete(Board Grid);
void wait_for_enter_keybord(MLV_Keyboard_button Key);

#endif