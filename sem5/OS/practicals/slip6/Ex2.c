/*
Q.2 Write a programto implement the shell. It should display the command prompt  
     “myshell$”. Tokenize the command line and execute the given command by  
      creating the child      process. Additionally it should interpret the following  
      commands.  
       myshell$  search  f   filename   pattern  :- To display first occurrence of  
                                                                      pattern in the file. 
       myshell$  search a   filename  pattern  :- To search all the  occurrence of  
                                                                    pattern in the file.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

void search(char ch , char *file_name  , char *pattern)
{
    int file_open_status = open(file_name, O_RDONLY);
    if(file_open_status==-1)
    {
        printf("Unable to open file ");
        return ;
    }

    char temp_buff[1000];
    char file_char;
    int  buff_size =0;
    int  line_no =1;
    int  count =1;
    while(read(file_open_status , &file_char , 1) !=0)
    {
        if(file_char=='\n')
        {
            temp_buff[buff_size] = '\0';
            buff_size =0;

            if(ch=='f')
            {
                if(strstr(temp_buff , pattern)!=NULL)
                {
                    printf("Found at %d \n %s \n" ,line_no , temp_buff);
                    break;
                }
            }
            else if(ch=='a')
            {
                if(strstr(temp_buff , pattern)!=NULL)
                {
                    printf("%d th occurrence Found at %d\n %s \n" ,count , line_no , temp_buff);
                    count++;
                }
            }
            line_no++;
        }
        else{
            temp_buff[buff_size++] = file_char;
        }
        
    }
}
int main()
{
    char command[80];
    char t1[20] , t2[20],t3[20], t4[20];

    system("clear");

    while(1)
    {
        printf("myshell$");

        fflush(stdin);

        fgets(command , 80 , stdin);

        int n = sscanf(command ,"%s %s %s %s" , t1,t2,t3,t4);

        if(n==1)
        {
            if(!fork())
            {
                execlp(t1,t2,NULL);
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
        else
        if(n==4)
        {
            if(strcmp(t1,"search")==0)
            {
                search(t2[0] ,t3,t4);
            }
        }
    }

    return 0;
}