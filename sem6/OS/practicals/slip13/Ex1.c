/*
Q.1 Write a C program to simulate Banker’s algorithm for the purpose of deadlock 
avoidance. The following snapshot of system, A, B, C and D are the resource type.  
Process

   Allocation Need     Available  
    A  B  C | A  B  C  | A  B  C  
P0  0  1  0 | 0  0  0  | 0  0  0  
P1  2  0  0 | 2  0  2        
P2  3  0  3 | 0  0  0        
P3  2  1  1 | 1  0  0        
P4  0  0  2 | 0  0  2    

a) Calculate and display the content of need matrix?  
b) Is the system in safe state? If display the safe sequence.

NOTE:IN THE GIVEN QUESTION THE MAX MATRIX IS WRONG IT SHOULD BE NEED MATRIX(REF. TEXTBOOK PAGE NO. 1.22)
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_RES 3
#define NUM_PROCESS 5
#define NOT_COMPLETE 0
#define COMPLETE 1

int MAX_ITR_NOT_REACHED  = 1000;
int isAllProcessCompleted(int status[])
{
    for(int i=0; i<NUM_PROCESS; i++)
    {
        if(status[i]==0){
            return 0;
        }
    }
    return 1;
}
int isValidNeed(int need[] , int available[])
{
    for(int i=0; i<MAX_RES; i++)
    {
        if(need[i]>available[i])
        { 
            return 0;
        }
    }
    return 1;
}
int main()
{
    int allocation[NUM_PROCESS][MAX_RES] = {
        {0,1,0},
        {2,0,0},
        {3,0,3},
        {2,1,1},
        {0,0,2}
    };

    int max[NUM_PROCESS][MAX_RES] = {
        {0,1,0},
        {4,0,2},
        {3,0,4},
        {3,1,1},
        {0,0,4}
    };

    int available[] ={0,0,0};
    int process_status[NUM_PROCESS]={NOT_COMPLETE};

    //calculate the need matrix
    int need[NUM_PROCESS][MAX_RES];
    for(int i =0; i<NUM_PROCESS; i++)
    {
        for(int j =0; j<MAX_RES; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("need matrix : \n");
    for(int i=0; i<NUM_PROCESS; i++)
    {
        printf("p%d " ,i);
        for(int j =0; j<MAX_RES; j++)
        {
            printf("%d " ,need[i][j]);
        }
        printf("\n");
    }


    while(isAllProcessCompleted(process_status) == NOT_COMPLETE && MAX_ITR_NOT_REACHED)
    {
        for(int i=0;i<NUM_PROCESS; i++)
        {
            if(isValidNeed(need[i],available)==1 && process_status[i] == NOT_COMPLETE)
            {
                for(int j=0; j<MAX_RES; j++)
                {
                    available[j] += allocation[i][j];
                }
                process_status[i] = COMPLETE;
                printf("p%d \n",i);
            }
        }
        MAX_ITR_NOT_REACHED--;
    }
    
    for(int i=0;i<NUM_PROCESS;i++)
    {
        if(process_status[i]==NOT_COMPLETE){
            printf("process in deadlock : p%d\n" , i);
        }
    }

  
}