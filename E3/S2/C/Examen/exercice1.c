#include <stdio.h>
#include <stdlib.>

typedef people {
    char* firstname;
    char* lastname;
    int age;
} People;

People* allocate_people(char* first_name, char* last_name, int age){

    People* p = malloc(sizeof(People));
    if(p == NULL) return NULL;

    p->firstname = malloc((strlen(first_name)+1)*sizeof(char));
    p->lastname = malloc((strlen(last_name)+1)*sizeof(char));

    if(p->firstanme == NULL || p->lastname == NULL){
        return NULL;
    }

    strcpy(p->firstname, first_name);
    strcpy(p->lastname, last_name);
    p->age = age;

    return p;
}

void fwrite_array_people(File* out, People* tab, int nb_people){
    int i;
    for (i = 0; i < nb_people; i++) {
        fprintf(out, "%s %s %d\n",
                tab[i].firstname,
                tab[i].lastname,
                tab[i].age);
    }
}