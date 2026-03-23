#include <stdio.h>
#include <stdbool.h>

void wc(){
     int c;
    int n_chars = 0;
    int n_words = 0;
    int n_lines = 0;
    bool in_word = false;

    while ((c = getchar()) != EOF) {
        n_chars++;

        if (c == '\n') {
            n_lines++;
        }

        if (c == ' ' || c == '\t' || c == '\n') {
            in_word = false;
        } else if (!in_word) {
            in_word = true;
            n_words++;
        }
    }

    printf("Lignes : %d\n", n_lines);
    printf("Mots   : %d\n", n_words);
    printf("Caractères : %d\n", n_chars);
}

int main(int argc, char* argv[]){
    printf("Entrez du texte (Ctrl+D pour terminer) :\n");
    wc();
    return 0;
}