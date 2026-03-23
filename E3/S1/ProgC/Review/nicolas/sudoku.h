#ifndef __SUDOKU__
#define __SUDOKU__

typedef int Board[9][9];
typedef int Second_board[3][3];

void initialize_empty_board(Board grid);
void print_board(Board grid);
void recurs_remplir_grille(Board grid, unsigned int max);
int fread_board(const char* file, Board board);
int insertion_possible(Board grid, unsigned int index_i, unsigned int index_j,
    unsigned int val, unsigned int max);
void print_second_board(Second_board grid);

#define MAIN_GRID_LENGTH 9
#define SECOND_GRID_LENGTH 3


#endif