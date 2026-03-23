#include <stdio.h>
#include <stdlib.h>

int read_grid(int grid[9][9], char *filename)
{
    FILE *f;
    int i, j;
    int entry;

    f = fopen(filename, "r");
    if (f == NULL)
    {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", filename);
        return -1;
    }

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            fscanf(f, "%d", &entry);
            grid[i][j] = entry;
        }
    }

    fclose(f);
    return 0;
}
