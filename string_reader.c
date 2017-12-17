#include <stdio.h>
#include "vector.h"

int main (char *argc, char* argv[]){
    char const* const fname = argv[1];
    FILE* file = fopen(fname, "r");
    char line[256];
    char lines[1000][256];
    
    int count=0;


    Vector v;
    vector_init(&v);

    while(fgets(line,sizeof(line), file)){
        strcpy(lines[count], line);
        count++; 
    }
    while(count!=0){
        vector_push(&v, lines[count]);
        count--;
    }

    vector_push(&v, &line);
    
    while(vector_size(&v)){
        printf("%s", (char*) vector_pop(&v));
    }

    fclose(file);

    return 0;

}
