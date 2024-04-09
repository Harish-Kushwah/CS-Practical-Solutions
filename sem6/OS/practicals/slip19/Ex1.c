/*
Q.1 Write a C program to simulate Banker’s algorithm for the purpose 
of deadlock avoidance. Consider the following snapshot of system, A, 
B, C and D is the resource type.  
Proces 
s  
   Allocation       Max      Available   
    A  B  C  D | A  B  C  D  A  B  C  D  
P0  0  3  2  4 | 6  5  4  4  3  4  4  2  
P1  1  2  0  1 | 4  4  4  4          
P2  0  0  0  0 | 0  0  1  2          
P3  3  3  2  2 | 3  9  3  4          
P4  1  4  3  2 | 2  5  3  3          
P5  2  4  1  4 | 4  6  3  4          
a) Calculate and display the content of need matrix?  
b) Is the system in safe state? If display the safe sequence. 
*/
#include<stdio.h>

#define MAX_RES 4
#define MAX_NO_PROCESS 6
#define NOT_COMPLETE 0
#define COMPLETE 1
int MAX_ITR_NOT_REACHED  = 1000;  

int isAllProcessCompleted(int status[])
{
    for(int i = 0; i<MAX_NO_PROCESS; i++)
    {
        if(status[i] == NOT_COMPLETE){
            return NOT_COMPLETE;
        }
    }
    return COMPLETE;
}
int isValidNeed(int need[] , int available[])
{
    for(int i =0; i<MAX_NO_PROCESS; i++)
    {
        if(need[i]>available[i]){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int allocation[MAX_NO_PROCESS][MAX_RES] = {
        {0 ,3 , 2 , 4},
        {1 ,2 , 0 , 1},
        {0 ,0 , 0 , 0},
        {3 ,3 , 3 , 3},
        {1 ,4 , 3 , 2},
        {2 ,4 , 1 , 4}
    };
    int max[MAX_NO_PROCESS][MAX_RES] = {
        {6 ,5 , 4 , 4},
        {4 ,4 , 4 , 4},
        {0 ,0 , 1 , 2},
        {3 ,9 , 3 , 4},
        {2 ,5 , 3 , 3},
        {4 ,6 , 3 , 4}
    };

    int available[] = {3 , 4 , 4, 2};

    int process_status[MAX_NO_PROCESS] = {NOT_COMPLETE};
    int need[MAX_NO_PROCESS][MAX_RES];
    //calculate the need matrix and print
    printf("Need Matrix :\n");
    for(int i =0; i<MAX_NO_PROCESS; i++)
    {
        printf("p%d ",i);
        for(int j =0; j<MAX_RES; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d " , need[i][j]);
        }
        printf("\n");
    }


    printf("Safe sequence :");
    while (isAllProcessCompleted(process_status) == NOT_COMPLETE && MAX_ITR_NOT_REACHED)
    {
        for(int i =0; i<MAX_NO_PROCESS; i++)
        {
            if(isValidNeed(need[i] , available) && process_status[i]==NOT_COMPLETE)
            {
                for(int j =0; j<MAX_RES; j++)
                {
                    available[j] += allocation[i][j];
                }
                process_status[i] = COMPLETE;
                printf("p%d " , i );
            }
        }
        MAX_ITR_NOT_REACHED--;
    } 
}