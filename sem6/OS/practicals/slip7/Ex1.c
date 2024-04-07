/*
Q.1 Consider the following snapshot of the system.
Proces
s
Allocation Max Available
A B C D A B C D A B C D
P0 2 0 0 1 4 2 1 2 3 3 2 1
P1 3 1 2 1 5 2 5 2
P2 2 1 0 3 2 3 1 6
P3 1 3 1 2 1 4 2 4
P4 1 4 3 2 3 6 6 5
Using Resource –Request algorithm to Check whether the current system is in safe
state or not 
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_RES 4
#define COMPLETED 1
#define NOT_COMPLETED 0

typedef struct Process 
{
    int allocation[MAX_RES];
    int max[MAX_RES];
    int need[MAX_RES];
    int status;
}Process;

int isAllProcessCompleted(Process process[] , int number_of_process)
{
    for(int i = 0; i<number_of_process; i++)
    {
        if(process[i].status == NOT_COMPLETED){
          
            return NOT_COMPLETED;
        }
    }

    return COMPLETED;
}

int isValidNeed(int need[] , int available[])
{
    // need 123  a 234  : 1 <2 valid
    //      321   123   : in valid

    for(int i =0; i<MAX_RES; i++)
    {
        if(need[i] > available[i]){
            return 0;
        }
    }
    return 1;

}
int main()
{
    int number_of_process;
    printf("Enter number of process :");
    scanf("%d" , &number_of_process);

    Process process[number_of_process];

    printf("Enter process details :");
    for(int i =0; i<number_of_process; i++)
    {
        printf("Enter allocation of p%d : " , i);
        for(int j = 0; j<MAX_RES; j++)
        {
           scanf("%d"  , &process[i].allocation[j]);
         
        }

    }

      for(int i =0; i<number_of_process; i++)
    {
        printf("Enter max of p%d : " , i);
        for(int j = 0; j<MAX_RES; j++)
        {
           scanf("%d"  , &process[i].max[j]);
        }

    }

    int available[MAX_RES];
    printf("Enter available :");
    for(int i = 0; i<MAX_RES; i++)
    {
        scanf("%d" , &available[i]);
    }

    //calculate need matrix
    // max - allocation

    for(int i =0; i<number_of_process; i++)
    {
        for(int j = 0; j<MAX_RES; j++)
        {
           process[i].need[j] =  process[i].max[j] -  process[i].allocation[j];
        }
        process[i].status = NOT_COMPLETED;

    }


    while(isAllProcessCompleted(process , number_of_process) != COMPLETED)
    {
           for(int i =0; i<number_of_process; i++)
           {
              if( isValidNeed(process[i].need, available)==1  && process[i].status != COMPLETED  ){

                    for(int j = 0; j<MAX_RES; j++)
                    {
                        available[j] += process[i].allocation[j];
                        process[i].status = COMPLETED;         
                    }

                    if(process[i].status == COMPLETED ){
                        printf("p%d " , i);
                    }
              }
           }

       
    }


printf("\nNeed Matrix1\n");
    for(int i=0;i<number_of_process;i++){
        printf("p%d ", i);
        for(int j=0; j<MAX_RES; j++){
            printf("%d " , process[i].need[j]);
        }
        printf("\n");
    }

}
