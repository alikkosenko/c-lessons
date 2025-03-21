#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "text.txt"
#define MAXLEN 10000

/*
 * Read line from stdin and
 * write it to text.txt 
 */

int main(int argc, char *argv[]){

 FILE *fp;
 char buf[MAXLEN];

 fp = fopen(FILENAME, "a");

 printf("Enter your text:\n");

 fgets(buf, sizeof(buf), stdin);

 fputs(strcat(buf, "\n"), fp);

 fclose(fp);

 return 0;
}
