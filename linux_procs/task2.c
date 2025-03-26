#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{

  pid_t pid = fork();

  if (pid < 0) {
    perror("fork() error");
  }

  if (pid == 0) {
    execlp("ps", "ps", "aux", NULL);
  }

  wait(NULL);

  return EXIT_SUCCESS;
}
