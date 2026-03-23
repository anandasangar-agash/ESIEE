#include "sudoku.h"

int check_row(Board B, int r, int v)
{
	int c;
	for (c = 0; c < 9; c++)
		if (B[r][c] == v)
			return 0;
	return 1;
}

int check_col(Board B, int c, int v)
{
	int r;
	for (r = 0; r < 9; r++)
		if (B[r][c] == v)
			return 0;
	return 1;
}

int check_block(Board B, int r, int c, int v)
{
	int i, j;
	int br = (r / 3) * 3, bc = (c / 3) * 3;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (B[br + i][bc + j] == v)
				return 0;
	return 1;
}

int is_legal(Board B, int r, int c, int v)
{
	return check_row(B, r, v) && check_col(B, c, v) && check_block(B, r, c, v);
}

int board_is_full(Board B)
{
	int r, c;
	for (r = 0; r < 9; r++)
		for (c = 0; c < 9; c++)
			if (B[r][c] == 0)
				return 0;
	return 1;
}
