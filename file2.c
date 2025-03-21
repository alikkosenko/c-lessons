#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILENAME "text.txt"
#define MAXLEN 10000

/*
 * Read file contents and print it
 */

int main(int argc, char *argv[]){

 FILE *fp;
 char buf[MAXLEN];

 fp = fopen(FILENAME, "r");


 
 


 fclose(fp);

 return 0;
}
