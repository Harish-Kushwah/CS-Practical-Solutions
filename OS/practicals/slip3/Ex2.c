/*
Q.2 Write a programto implement the toy shell. It should display the command  
        prompt “myshell$”. Tokenize the command line and execute the given   
        command by creating the child process. Additionally it should interpret the  
        following commands.  
            count c   filename      :- To print number of characters in the file. 
            count w  filename      :- To print number of words in the file. 
            count l    filename     :- To print number of lines in the file.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

void count(char ch , char *file_name)
{
    int file_open_status = open(file_name , O_RDONLY);

    if(file_open_status==-1)
    {
        printf("Unable to open a file\n");
        return;
    }

    char file_char;
    int total_word =0;
    int total_lines =1;
    int total_char =0;
    while(read(file_open_status , &file_char , 1)!=0)
    {
        if(file_char==' ')
        {
            total_word++;
        }
        else if(file_char=='\n')
        {
            total_lines++;
        }
        else {
            total_char++;
        }
    }

    if(ch=='c')
    {
        printf("Total character is %d\n" , total_char);
    }
    else  if(ch=='w')
    {
        printf("Total words is %d\n" , total_word);
    }
    else  if(ch=='l')
    {
        printf("Total lines is %d\n" , total_lines);
    }
    
}
int main()
{
    char command[80];
    char t1[20] , t2[20],t3[20],t4[20];
    system("cls");

    while(1)
    {
        printf("Harish$");

        fflush(stdin);

        fgets(command , 80,stdin);

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
        else
        if(n==3)
        {
            if(strcmp(t1,"count")==0)
            {
                count(t2[0] , t3);
            }
        }


    }

    return 0;
}