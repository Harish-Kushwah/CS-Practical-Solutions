/*
Q.2  Write  a  C  program  to  implement  the  shell  which  displays  the  command 
prompt  “myshell$”.  It  accepts  the  command,  tokenize  the  command  line  and 
execute  it  by  creating  the  child  process.  Also  implement  the  additional  command 
‘typeline’ as  
typeline +n   filename      :- To print first n lines in the file. 
typeline -a    filename      :- To print all  lines in the file
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void typeline(char *ch , char *file_name)
{
    int file_open_status= open(file_name ,O_RDONLY);

    if(file_open_status == -1)
    {
        printf("Unable to open  a file");
        return ;
    }

    char file_char;
    if(strcmp(ch,"a")==0){
        while (read(file_open_status , &file_char ,1)!=0)
        {
            printf("%c" , file_char);
        }
    }
    else {
        int num  = atoi(ch);
        int total_line =0;

        while (read(file_open_status , &file_char ,1)!=0)
        {
             
            if(file_char=='\n')
            {
                total_line++;
            }
            printf("%c" , file_char);
            
			if(total_line==num)
            break;
           
        }
        
    }
   
    
    
}
int fork()
{
    return 0;
}
int main()
{
    char command[80];
    char t1[20],t2[20],t3[20],t4[20];

    system("clear");

    while (1)
    {
        printf("Harish$");

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
        else 
        if(n==3)
        {
            if(strcmp(t1,"typeline")==0)
            {
                typeline(t2 , t3);
            }
        }

    }
    
    return 0;
}
