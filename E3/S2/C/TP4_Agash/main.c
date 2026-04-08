#define  _DEFAULT_SOURCE 1

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "sys/stat.h"
#include <ftw.h>

struct file_info {
    char *name;
    long size;
} array[11];


void init_array(){
    for(int i = 0; i < 10; i++){
        array[i].name = NULL;
        array[i].size = 0;
    }
}

void swap(struct file_info *a, struct file_info *b){
    struct file_info temp = *a;
    *a = *b;
    *b = temp;
}

void insert_array(char *name, long size){

    array[10].name = strdup(name);
    array[10].size = size;
    for(int i = 10; i > 0; i--){
        if(array[i].size > array[i-1].size){
            swap(&array[i], &array[i-1]);
        } else {
            break;
        }
    }
}

void print_array(){
    for(int i = 0; i < 10; i++){
        if(array[i].name == NULL) break;
        printf("%s : %ld octets\n", array[i].name, array[i].size);
    }
}

int fn(const char *fpath, const struct stat *sb, int tflag){

    printf("%s", fpath);

    insert_array((char*)fpath, sb->st_size);
    return 0;
}

int main(int argc, char* argv[]){
    
    if(argc < 2){
        printf("Directory is missing !! \n");
        return 1;
    }

    init_array();

    ftw(argv[1], fn, 2);
    print_array();

    return 0;
}