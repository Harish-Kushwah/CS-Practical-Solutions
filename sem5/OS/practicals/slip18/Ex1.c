/*
Q.1 Write a C program that demonstrates the use of nice() system call. After a
child Process is started using fork (), assign higher priority to the child using
 nice () system call. 
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    pid_t pid  = fork();

    if(pid==0)
    {
        printf("I am the child process with id : %d\n" , getpid());
        nice(-19);
    }
    else if(pid>0)
    {
        printf("I am the parent process with id : %d\n" , getpid());

    }
    return 0;
}