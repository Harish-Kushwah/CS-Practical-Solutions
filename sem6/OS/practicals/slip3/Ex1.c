/*
Q.1 Write a C program to simulate Banker’s algorithm for the purpose of deadlock
avoidance. Consider the following snapshot of system, A, B, C and D is the
resource type

Process Allocation Max Available
A B C D A B C D A B C D
P0 0 0 1 2 0 0 1 2 1 5 2 0
P1 1 0 0 0 1 7 5 0
P2 1 3 5 4 2 3 5 6
P3 0 6 3 2 0 6 5 2
P4 0 0 1 4 0 6 5 6
a)Calculate and display the content of need matrix?
b)Is the system in safe state? If display the safe sequence

*/

#include<stdio.h>

#define MAX_RES 4
#define COMPLETED 1
#define NOT_COMPLETED 0

typedef struct  Process
{
    int allocation[MAX_RES];
    int max[MAX_RES];
    int need[MAX_RES];
    int status;
}Process;

int isAllProcessCompleted(Process process[] , int number_of_process)
{
    for(int i =0 ;i<number_of_process; i++){
        if(process[i].status == NOT_COMPLETED){
            return NOT_COMPLETED;
        }
    }
    return COMPLETED;
}

int isValidNeed(int need[] , int available[])
{
    for(int i=0; i<MAX_RES; i++){
        if(need[i]> available[i]){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int number_of_process = 5;
    printf("Enter total number of process :");
    scanf("%d" , &number_of_process);

    Process process[number_of_process];
   
    printf("Enter Process Details \n");
    for(int i=0;i<number_of_process;i++){
        printf("Enter allocations of p%d: " , i);
        for(int j=0;j<MAX_RES;j++){
            scanf("%d" , &process[i].allocation[j]);
        }
    }
    
    printf("\n");

    for(int i=0;i<number_of_process;i++){
        printf("Enter Max of p%d: " , i);
        for(int j=0;j<MAX_RES;j++){
            scanf("%d" , &process[i].max[j]);
        }
    }


    //calculate the need of each process
    for(int i=0; i<number_of_process;i++){
        for(int j=0; j<MAX_RES;j++){
            process[i].need[j] = process[i].max[j] - process[i].allocation[j];
        }
        process[i].status = NOT_COMPLETED;
    }


    int available[MAX_RES] ;
    printf("Enter available resources :");
    for(int i=0; i<MAX_RES; i++){
        scanf("%d" , &available[i]);
    }

    printf("Input set\n");
    while (isAllProcessCompleted(process , number_of_process) == NOT_COMPLETED)
    {
        for(int i=0 ; i<number_of_process; i++)
        {
            if(isValidNeed(process[i].need , available)==1 && process[i].status == NOT_COMPLETED){

                for(int j=0; j<MAX_RES; j++){
                    available[j] += process[i].allocation[j];
                    process[i].status =COMPLETED;
                  
                }
                 if(process[i].status == COMPLETED ){
                        printf("p%d " , i);
                    }

                
            }    
           
       }

    }

   printf("Need Matrix1\n");
    for(int i=0;i<number_of_process;i++){
        printf("p%d ", i);
        for(int j=0; j<MAX_RES; j++){
            printf("%d " , process[i].need[j]);
        }
        printf("\n");
    }
    

}