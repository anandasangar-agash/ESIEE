#include <stdio.h>
#include <stdlib.>

typedef people {
    char* firstname;
    char* lastname;
    int age;
} People;

People[] all_people;
int nb_people;

typedef int(*Filter)(People* guy, int arg);

void filter_and_print(People* tab, int nmemb, Filter fct, int arg_filter){
    int i;

    for(i=0; i < nmemb; i++){
        if(fct(tab+i, arg_filter)){
            print_people(tab+1);
        }
    }
}

int filter_lastname_letter(People* guy, int arg){

    return (guy->lastname[0] == (char)arg);
}

filter_and_print(all_people, nb_people, filter_lastname_letter, 'D');

int filter_age(People* guy, int arg){

    return (guy->age >= arg);
}

filter_and_print(all_people, nb_people, filter_age, 18);

int filter_p_and_42(People* guy, int arg){
    void(arg);
    return (guy->lastname[0] == 'P' && guy->age >= 42);
}

filter_and_print(all_people, nb_people, filter_p_and_42, 0);

