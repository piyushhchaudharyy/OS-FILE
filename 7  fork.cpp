// fork() creates a new process by duplicating the calling process
// The new process is referred as the child process. The calling process is called as the parent process

// The child and parent processes run in separate memory spaces. At the time of fork() both have
// the same content. Memory writing file mapping and unmapping of one process won't affect the
// other one

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t p;
    printf("before fork\n");
    p = fork();
    if(p < 0) printf("error");
    if (p == 0) // chid process
    {
        printf("I am child having id %d\n", getpid());
        printf("My parent's id is %d\n", getppid());
    }
    else // p > 0 (parent process)
    {
        // wait(NULL); // it makes parent wait for the child process to complete
        printf("My child's id is %d\n", p);
        printf("I am parent having id %d\n", getpid());
    }
    printf("Common\n");
}

