/*
Q.1 Consider a system with ‘m’ processes and ‘n’ resource types. Accept number 
of instances for every resource type. For each process accept the allocation and 
maximum requirement matrices. Write a program to display the contents of need 
matrix and to check if the given request of a process can be granted immediately 
or not.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_RES 4
#define NOT_COMPLETED 0
#define COMPLETED 1

typedef struct Process
{
    int allocation[MAX_RES];
    int max[MAX_RES];
    int need[MAX_RES];
    int status;
}Process;

int isAllProcessCompleted(Process p[] , int m)
{
    for(int i= 0; i<m;i++){
        if(p[i].status == NOT_COMPLETED){
            return NOT_COMPLETED;
        }
    }
    return COMPLETED;
}
int isValidProcessNeed(int need[] , int available[],int n)
{
    for(int i =0; i<n;i++)
    {
        if(need[i]>available[i]){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int m,n;
    printf("Enter number of process :");
    scanf("%d" ,&m);

    printf("Enter number of resources :");
    scanf("%d" , &n);

    Process process[m];
    printf("Enter process details :\n");
    for(int i =0; i<m;i++)
    {
        printf("Enter Allocation of p-%d :" , i);
        for(int j =0; j<n;j++)
        {
            scanf("%d" ,&process[i].allocation[j]);
        }
    }
    for(int i =0; i<m;i++)
    {
        printf("Enter Max of p-%d :" , i);
        for(int j =0; j<n;j++)
        {
            scanf("%d" ,&process[i].max[j]);
        }
    }

    int available[n];
    printf("Enter available : ");
    for(int i =0; i<n;i++){
        scanf("%d" , &available[i]);
    }

    //calculate need matrix
    for(int i=0; i<m; i++)
    {
        for(int j =0; j<n; j++){
            process[i].need[j] = process[i].max[j] - process[i].allocation[j];
            process[i].status = NOT_COMPLETED;
        }
    }

    printf("Sequence is :");
    while(isAllProcessCompleted(process,m) == NOT_COMPLETED)
    {
        for(int i =0 ; i<m; i++)
        {
            if(isValidProcessNeed(process[i].need , available ,n)==1 && process[i].status == NOT_COMPLETED){
                
                for(int j =0; j<n;j++)
                {
                    available[j] += process[i].allocation[j];
                }
                process[i].status = COMPLETED;
                printf("p%d " , i);
    
            }

        }
    }

    printf("\nNeed Matrix :\n");
    for(int i =0; i<m;i++)
    {
        printf("P%d " , i);
        for(int j =0; j<n;j++)
        {
            printf("%d " , process[i].need[j]);
        }
        printf("\n");
    }

}