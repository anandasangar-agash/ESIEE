#include <stdio.h>


int suite_u(int index){
    if (index == 0){
        return 8;
    }
    return suite_u(index-1) + 7*index - 7;
}

int comptage_string(char* mot){

    int str1 = 0, str2 = 0, str3 = 0;
    int i;
    for(i=0; mot[i] != '\0'; i++){
        if((mot[i] >= 'A' && mot[i] <= 'Z') || (mot[i] >= 'a' && mot[i] <= 'z')){
            str1++;
        }
        if(mot[i] == 'A' || mot[i] == 'E' || mot[i] == 'I' || mot[i] == 'O' || mot[i] == 'U' || mot[i] == 'Y'){
            str2++;
        }
        if(mot[i] == 'a'){
            str3++;
        }
    }
    return 2*str1 + 5*str2 + 8*str3;
}

unsigned long int most_present(unsigned long int* tab){

    int i, index = 0;
    unsigned long int occurences[1001];
    for(i=0; i < 1001; i++){
        occurences[i] = 0;
    }
    for(i=0; tab[i]!=0; i++){
        occurences[tab[i]]++;
    }
    for(i=1; i<1001; i++){
        if(occurences[i] > occurences[index]){
            index = i;
        }
    }

    return index;
}

int main(int argc, char* argv[]){
    int i, nb = 0;
    for(i=0; i < 9; i++){
        printf("%d ", suite_u(nb));
        nb += 4;
    }

    if(argc < 1){
        printf("entrer un nom !\n");
        return 1;
    }

    printf("\n");
    printf("nombre de caractères : %d\n", comptage_string(argv[1]));

    return 0;
}