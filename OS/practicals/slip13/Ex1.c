/*
Q.1 Write a C program to implement the shell which displays the command   
      prompt “myshell$”. It accepts the command, tokenize the command line and  
      execute it by creating the child process. Also implement the additional   
      command ‘typeline’ as  
         typeline -a    filename :- To print all  lines in the file.
*/
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>


void typeline(char ch , char *file_name)
{
    int file_open_status  = open(file_name , O_RDONLY);

    if(file_open_status==-1)
    {
        printf("Unable to open file ");
        return;
    }

    if(ch=='a')
    {
        char file_char;
        while(read(file_open_status , &file_char , 1)!=0)
        {
            printf("%c" , file_char);
        }
    }

}

int main()
{
    char command[80];
    char t1[20] , t2[20],t3[20] ,t4[20];

    system("cls");

    while(1)
    {
        printf("myshell$");

        fflush(stdin);

        fgets(command , 80 , stdin);

        int n = sscanf(command , "%s %s %s %s" , t1,t2,t3,t4);

        if(n==1)
        {
            if(!fork())
            {
                execlp(t1,t1,NULL);
                perror(t1);
            }
        }
        else if(n==2)
        {
            if(!fork())
            {
                execlp(t1,t1,t2,NULL);
                perror(t1);
            }
        }
        if(n==3)
        {
            if(strcmp(t1,"typeline")==0)
            {
                typeline(t2[0] , t3);
            }
        }

    }
    return 0;
}