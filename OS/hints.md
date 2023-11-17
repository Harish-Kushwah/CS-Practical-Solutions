# OS Topics
### Operations on Processes
  - Fork() 
    fork() is used to create new processes

  - exec()
  The exec() family of functions replaces the current process image with a new process
image
  - execlp()
  execlp() system call is used after a fork() call by one of the two processes to replace the
processes memory space with a new program. This call loads a binary file into memory and
starts its execution

  - nice()
     Using nice() system call, we can change the priority of the process in multi-tasking
system
---
### What is Shell? 
Shell is an interface between user and operating system. It is the command interpreter, which
accept the command name (program name) from user and executes that command/program.
Shell mostly accepts the commands given by user from keyboard. Shell gets started
automatically when Operating system is successfully started
 
### How Shell Execute the command?
1. Accept the command from user.
2. Tokenize the different parts of command.
3. First part given on the given command line is always a command name.
4. Creates (Forks) a child process for executing the program associated with given command.
5. Once child process is created successfully then it loads (exec) the binary (executable) image
of given program in child process area.
6. Once the child process is loaded with given program it will start its execution while shell is
waiting (wait) for it (child) to complete the execution. Shell will wait until child finish its
execution.
7. Once child finish the execution then Shell wakeup, display the command prompt again and
accept the command and continue
---
##### Simple shell example of counting word,character and lines form the file 
##### Note:Read the code carefully and try to understand each lines meaning 

```c
/*
   Operating System (practical 2 , example 1)
   Q1] Making simple shell in linux ,add our own commands and also run system commands 
   by creating child process for them 
*/

//This is used for input output functions,and stream
#include<stdio.h>

//This is used for system call and standard library
#include<stdlib.h>

//This is used for performing strings operations 
#include<string.h>

//This is used for executing linux based system call 
#include<unistd.h>

//This is used for reading files 
#include<fcntl.h>

/*
 This function is counting total number of words,characters and line of the file
  How this function working?
 => 1.It takes the 'ch' as a character of choice for performing operations on file 
    2.Opens the file in read mode 
    3.Read the files charater by character 
    4.Apply logic of calculating the words,line and character
    5.print the respective count on the basis of choice 

    O_RDONLY =  Open or create a read-only file
*/
void count(char ch , char *file_name)
{
    int word_count = 0;
    int char_count = 0;
    int line_count = 0;

    int file_open_status = open(file_name , O_RDONLY); 

    if(file_open_status==-1)
    {
        printf("Unable to open a file\n");
        return ;
    }

    char file_char;
    while(read(file_open_status , &file_char , 1)!=0)
    {
        if(file_char==' ')
        {
            word_count++;
        }
        else if(file_char=='\n')
        {
            line_count++;
        }
        else{
            char_count++;
        }
    }

    if(ch=='c')
    {
        printf("Total number of character: %d\n" , char_count);

    }
    else if(ch=='w')
    {
        printf("Total number of words:%d\n" , word_count);
    }
    else if(ch=='l')
    {
        printf("Total number of line:%d\n" , line_count);
    }
}

/*
NOTE : remove this function if you are running this program on Linux
because window dose not support fork() function call
*/
int fork()
{
    return 0;
}
int main()
{
    //string for taking command from shell
    char command[80];

    //strings for dividing command into tokens(substring)
    char t1[20],t2[20],t3[20],t4[20];

    //clear the previous content from the shell
    //Note:use cls for windows
    system("clear");

    //Infinite loop for running shell
    while(1)
    {
        
        printf("Harish$");

        //To clear stdin buffer
        fflush(stdin);

        //take command from the stdin stream
        fgets(command , 80 , stdin);

        //make the tokens of commands
        //this will return number of tokens created 
        int n = sscanf(command,"%s %s %s %s" , t1,t2,t3,t4);

        /*
          if the command is of only one length
          ex. cls,clear,date
        */
        if(n==1)
        {   
            if(!fork())
            {
                /*
                  this function works on linux 
                  for windows use system() for system call
                */ 
                execlp(t1,t1,NULL);
                perror(t1);
            }
        }
         /*
          if the command is of only two length
          ex. cd dir_name,mkdir dir_name
        */
        else if(n==2)
        {
            if(!fork())
            {
                execlp(t1,t1,t2,NULL);
                perror(t1);
            }
        }
         /*
          if the command is of only three length
          ex. count c file_name
              count w file_name
              count l file_name
        */
        else if(n==3)
        {
            if(strcmp(t1,"count")==0)
            {
                count(t2[0] , t3);
            }
        }
         /*
          if the command is of only four length
        */
        else if(n==4)
        {
            if(!fork())
            {
                execlp(t1,t1,t2,t3,t4,NULL);
                perror(t1);
            }
        }
    }
}
```
----
### CPU Scheduling
  1) First Come First Serve (FCFS)
  2) Shortest Job First (SJF)
  3) Priority Scheduling
  4) Round Robin Scheduling (RR)
