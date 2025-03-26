#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

typedef struct dot{
  int x;
  int y;
} Dot;

void fill_arr(Dot *arr, int size);
void print_arr(Dot *arr, int size);
void write_arr(Dot *arr, int size, FILE *fp);
void read_arr(Dot *arr, int size, FILE *fp);

int main(int argc, char *argv[])
{
  srand(time(NULL));
  FILE  *bfp;
  Dot *DotArr = (Dot *)malloc(SIZE*sizeof(Dot));

  bfp = fopen("bfile", "rb");
  if (bfp == NULL) {
    puts("Error opening file");
  }
  
  //fill_arr(DotArr, SIZE);
  //write_arr(DotArr, SIZE, bfp);
  
 
  read_arr(DotArr,SIZE, bfp); 
  print_arr(DotArr, SIZE);
  
  

  
  fclose(bfp); 

  return EXIT_SUCCESS;
}


void fill_arr(Dot *arr, int size){
 for (int i = 0;i < size; i++) {
    arr[i].x = rand() % 100;
    arr[i].y = rand() % 100;
 } 
}


void print_arr(Dot *arr, int size){
  for (int i = 0; i < SIZE;i++) {
    printf("[%d]: %d, %d\n", i, arr[i].x, arr[i].y);
  }
}


void write_arr(Dot *arr, int size, FILE *fp){
  for (int i = 0; i < size;i++) {
    fwrite(&arr[i], sizeof(Dot), 1, fp);
  }
}

void read_arr(Dot *arr, int size, FILE *fp){
  for (int i = 0; i < SIZE && !feof(fp);i++) {
    fread(&arr[i], sizeof(Dot), 1, fp);
  }
}
