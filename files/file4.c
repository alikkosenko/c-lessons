#include <stdio.h>


int main(int argc, char *argv[])
{
  FILE *from, *to, *log;
  
  log = fopen("logfile.log", "w");

  if(log == NULL){
    puts("[Error] Cannot open log file");
  }

  if(argc != 3){
    fprintf(log,"[Error]\nUsage: %s from to", argv[0]);
    return 1;
  }

  
  from = fopen(argv[1], "r");
  to = fopen(argv[2], "w");
  
  if(from == NULL || to == NULL){
    fprintf(log, "[Error]Cannot open one of files\n");
  }

  while (!feof(from)) {
    fputc(fgetc(from), to);
  }


  fclose(from);
  fclose(to);
  fclose(log);

  return 0;
}
