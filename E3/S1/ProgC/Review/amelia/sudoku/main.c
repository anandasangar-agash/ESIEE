#include <stdio.h>
#include "interface.h"
#include "sudoku.h"
#include "in_out.h"

int main(int argc, char *argv[])
{
	Board B;
	int row, col, value, x, y;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s fichier\n", argv[0]);
		return 1;
	}

	fread_board(argv[1], B);

	init_window();

	while (!board_is_full(B))
	{
		draw_grid(B, -1, -1);
		wait_click_on_empty_cell(B, &row, &col);
		draw_grid(B, row, col);
		value = show_number_pad_and_get_choice(row, col);

		if (value != 0 && is_legal(B, row, col, value))
			B[row][col] = value;
	}

	draw_grid(B, -1, -1);
	MLV_wait_mouse(&x, &y);
	close_window();
	return 0;
}
