/*
Q.1  Write a C program to implement the shell. It should display the command     
       prompt “myshell$”. Tokenize the command line and execute the given     
       command by creating the child process. Additionally it should interpret the     
       following ‘list’ commands as   
           myshell$ list  f dirname    :- To print names of all the files in current           
                                                        directory.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

void list(char ch , char *dir_name)
{
    DIR *dir = opendir(dir_name);

    if(dir==NULL)
    {
        printf("Unable to open a directory\n");
        return ;
    }
    struct dirent *entry;
    struct stat buff;
    if(ch=='f')
    {
        while ((entry=readdir(dir))!=NULL)
        {
            stat(entry->d_name , &buff);

            if(buff.st_mode)
            {
                printf("%s\n" , entry->d_name);
            }
        }
        
    }

}
int main()
{
    char command[80];
    char t1[20],t2[20],t3[20],t4[20];

    system("cls");

    while (1)
    {
        printf("myshell$");

        fflush(stdin);

        fgets(command , 80 , stdin);

        int n = sscanf(command ,"%s %s %s %s" , t1,t2,t3,t4);

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
            if(strcmp(t1,"list")==0)
            {
                list(t2[0] , t3);
            }
        }
    }
    
}