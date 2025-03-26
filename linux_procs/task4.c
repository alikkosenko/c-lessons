
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


int main(int argc, char *argv[])
{

  pid_t pid = fork();

  if (pid < 0) {
    perror("fork() error");
    exit(EXIT_FAILURE);
  }
  
  if(pid == 0){
    printf("I'm child process of PID %d, my PID is %d\n", getppid(), getpid());
    sleep(10);
    printf("Child process ended its work on his own\n");
  }
  else {
    sleep(11);
    printf("Killing PID %d\n", pid);
    kill(pid, SIGKILL);
  }


  return EXIT_SUCCESS;
}
