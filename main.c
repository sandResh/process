#include <stdio.h> 
#include <stdlib.h> 
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main(void) 
{
  srandom(time(NULL));
  for (int i = 0; i < 2; i++)
  {

    int pid = fork();
    pid_t pid1;
    if (pid > 0)
    {
        //wait(NULL);
        
        pid1 = wait(NULL);
        printf ("Child Pid: (%d) has completed \n", pid1);
    }
    else if (pid == 0)
    {
        printf("Child Pid: (%d) is going to sleep!\n", getpid());
        sleep(random() % 10);

        printf("Child Pid: is awake!\nWhere is my Parent: (%d)? \n", getppid());
        exit (0);
    }
    else if (pid < 0)
    {
        printf("Unable to fork() child process! \n");
    }    
  }
  
  
  

}