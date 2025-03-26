#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEfAULTSIZE 20

int
main(int argc, char **argv){

    long size;
    char *endptr;
    if(argc > 1){
        size = strtol(argv[1], &endptr, 10);
    }
    else size = DEfAULTSIZE;

    int *arr = (int*)malloc(size*sizeof(int));
    
    for (long i = 0; i < size; i++)
    {
        arr[i] = random() % 10;
    }
    
    for (long i = 0; i < size; i++)
    {
        printf("[%ld]:%d", i, arr[i]);
    }
    free(arr);

    return 0;
}