/*
Q.2 Write a program to implement  shell. It should display the command prompt  
     “myshell$”. Tokenize the command line and execute the given command by  
      creating the child      process. Additionally it should interpret the following  
      commands.  
       myshell$  search a   filename  pattern  :- To search all the  occurrence of  
                                                                    pattern in the file.         
       myshell$ search c  filename  pattern    :- To count the number of occurrence     
                                                                     of  pattern in  the  file
*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>

void search(char ch , char *file_name , char *pattern)
{
    int file_open_status = open(file_name , O_RDONLY);

    if(file_open_status==-1)
    {
        printf("Unable to open a file");
        return ;
    }

    char temp_buff[1000];
    char file_char;
    char buff_size =0;
    int line_no=1;
    int count =0;
    while(read(file_open_status , &file_char , 1)!=0)
    {
        if(file_char=='\n')
        {
            temp_buff[buff_size++] = '\0';
            buff_size =0;

            if(ch=='a')
            {
                if(strstr(temp_buff , pattern)!=NULL)
                {
                    count++;
                    printf("%dth occurrence found in line %d \n %s \n" , count , line_no, temp_buff);
                   
                }
            }
            else if(ch=='c'){
                if(strstr(temp_buff , pattern)!=NULL)
                {
                    count++;
                }
            }

            line_no++;
        }
        else{
            temp_buff[buff_size++] = file_char;      
        }
    }

    if(ch=='c')
    {
        printf("Total occurrence is %d \n" , count);
    }
}
int main()
{
    char command[80];
    char t1[20],t2[20],t3[30] ,t4[20];

    system("cls");

    while(1)
    {
        printf("myshell$");

        fflush(stdin);

        fgets(command ,80 , stdin);

        int n =sscanf(command , "%s %s %s %s" , t1,t2,t3,t4);

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
        else if(n==3)
        {
            if(!fork())
            {
                execlp(t1,t1,t2,t3,NULL);
                perror(t1);
            }
        }
        if(n==4)
        {
            if(strcmp(t1,"search")==0)
            {
                search(t2[0],t3,t4);
            }
        }
    }

    return 0;
}