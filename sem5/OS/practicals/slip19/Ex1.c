/*
Q.1 Write a C program to illustrate the concept of orphan process. Parent
process creates a child and terminates before child has finished its task. So
child process becomes orphan process. (Use fork(), sleep(), getpid(), getppid()).
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{

    pid_t pid = fork();

    if(pid==0)
    {
        printf("I am the child process %d" , getpid());
        sleep(10);
    }
    else if(pid >0)
    {
        printf("I am the parent process %d ",getppid());
    }
    else {
        printf("No process created");
    }
    return 0;
}