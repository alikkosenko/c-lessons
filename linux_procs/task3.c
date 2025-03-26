
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{

  pid_t c1 = fork();

  if (c1 < 0) {
    perror("fork() error");
  }

  if(c1 == 0){
    printf("I'm child process of PID %d and my PID is %d\n", getppid(), getpid());
    sleep(3);
    exit(0);
  }

  wait(NULL);


  pid_t c2 = fork();

  if (c2 < 0) {
    perror("fork() error");
  }

  if(c2 == 0){
    printf("I'm child process of PID %d and my PID is %d\n", getppid(), getpid());
    sleep(5);
    exit(0);
  }

  wait(NULL);


  pid_t c3 = fork();

  if (c3 < 0) {
    perror("fork() error");
  }

  if(c3 == 0){
    printf("I'm child process of PID %d and my PID is %d\n", getppid(), getpid);
    sleep(7);
    exit(0);
  }

  wait(NULL);

  return EXIT_SUCCESS;
}
