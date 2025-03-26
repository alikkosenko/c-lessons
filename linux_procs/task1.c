#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  pid_t c1, c2;
  c1 = fork();
  sleep(3);
  
  if (c1 < 0) {
    exit(EXIT_FAILURE);
  }

  if (c1 > 0) {
    printf("Main program(PID %d) executed child process (PID %d)\n", getpid(), c1);
    c2 = fork();
    if (c1 < 0) {
      exit(EXIT_FAILURE);
    }
    sleep(3);
    if (c2 > 0) {
      printf("Main program(PID %d) executed child process (PID %d)\n", getpid(), c2);
    }
    else {
      printf("I am child process with pid %d, my parent pid is %d\n", getpid(), getppid());
    }
  }
  else {
    printf("I am child process with pid %d, my parent pid is %d\n", getpid(), getppid());
  }
  

  


  return EXIT_SUCCESS;


}
