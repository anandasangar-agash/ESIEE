#ifndef FOO.H
#define FOO.H

#include <stdio.h>

typedef struct plop{
    int foobar;
    char* barfoo;
} Plop;


int bla(FILE*, int nb_entries);
void bar(int pouet, int pouetpouet);
int barbar(Plop* tab, int nb_plop);

#endif 