#include <string.h>
#include <stdio.h>

void min_max(int tab[], int size, int *min, int *max) {
    int i;
    int local_min, local_max;

    if (tab[0] < tab[1]) {
        *min = tab[0];
        *max = tab[1];
    } else {
        *min = tab[1];
        *max = tab[0];
    }

    for (i = 2; i < size; i += 2) {
        if (tab[i] < tab[i + 1]) {
            local_min = tab[i];
            local_max = tab[i + 1];
        } else {
            local_min = tab[i + 1];
            local_max = tab[i];
        }

        if (local_min < *min)
            *min = local_min;
        if (local_max > *max)
            *max = local_max;
    }
}

void min_max_general(int tab[], int size, int *min, int *max) {
    int i;
    int local_min, local_max;

    if (size % 2 == 0) {
        if (tab[0] < tab[1]) {
            *min = tab[0];
            *max = tab[1];
        } else {
            *min = tab[1];
            *max = tab[0];
        }
        i = 2;
    } else {
        *min = *max = tab[0];
        i = 1;
    }

    for (; i < size; i += 2) {
        if (tab[i] < tab[i + 1]) {
            local_min = tab[i];
            local_max = tab[i + 1];
        } else {
            local_min = tab[i + 1];
            local_max = tab[i];
        }

        if (local_min < *min)
            *min = local_min;
        if (local_max > *max)
            *max = local_max;
    }
}


int est_voyelle(char c) {
    return (c == 'A' || c == 'E' || c == 'I' ||
            c == 'O' || c == 'U' || c == 'Y');
}

int mot_valide(char *mot) {
    int i, j;

    if (strlen(mot) != 6)
        return 0;

    for (i = 0; i < 6; i++) {
        if (mot[i] < 'A' || mot[i] > 'Z')
            return 0;
    }

    /* chercher deux voyelles non adjacentes */
    for (i = 0; i < 6; i++) {
        if (est_voyelle(mot[i])) {
            for (j = i + 2; j < 6; j++) {
                if (est_voyelle(mot[j]))
                    return 1;
            }
        }
    }

    return 0;
}

int combat(int a, int b) {
    if (a == b)
        return a;

    if ((a == 0 && b == 1) || (a == 1 && b == 2) || (a == 2 && b == 0))
        return a;
    else
        return b;
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage : %s MOT\n", argv[0]);
        return 1;
    }

    if (mot_valide(argv[1]))
        printf("1\n");
    else
        printf("0\n");

    int i;
    int len;

    len = strlen(argv[1]);
    for (i = len - 1; i >= 0; i--) {
        putchar(argv[1][i]);
    }
    putchar('\n');

    return 0;
}
