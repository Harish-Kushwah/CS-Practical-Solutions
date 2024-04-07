/*
Q.1 ) Write a C Menu driven Program to implement following functionality
a) Accept Available
b) Display Allocation, Max
c) Display the contents of need matrix
d) Display Available

Process Allocation   Max     Available
        A B C       A B C     A B C
P0      2 3 2       9 7 5     3 3 2
P1      4 0 0       5 2 2
P2      5 0 4       11 0 4
P3      4 3 3       4 4 4
P4      2 2 4       6 5 5

*/

#include <stdio.h>

#define MAX 10
#define COMPLETED 1
#define NOT_COMPLETED 0

int MAX_RES;

typedef struct Process
{
    int allocation[MAX];
    int max[MAX];
    int need[MAX];
    int status;
} Process;

void printNeedMatrix(Process process[], int number_of_process)
{
    printf("Need Matrix\n");
    for (int i = 0; i < number_of_process; i++)
    {
        printf("p%d ", i);
        for (int j = 0; j < MAX_RES; j++)
        {
            printf("%d ", process[i].need[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printAllocationMatrix(Process process[], int number_of_process)
{
    printf("Allocation Matrix1\n");
    for (int i = 0; i < number_of_process; i++)
    {
        printf("p%d ", i);
        for (int j = 0; j < MAX_RES; j++)
        {
            printf("%d ", process[i].allocation[j]);
        }
        printf("\n");
    }
    printf("\n");
}
void printMaxMatrix(Process process[], int number_of_process)
{
    printf("Max Matrix\n");
    for (int i = 0; i < number_of_process; i++)
    {
        printf("p%d ", i);
        for (int j = 0; j < MAX_RES; j++)
        {
            printf("%d ", process[i].max[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printAvailable(int available[])
{
    for (int i = 0; i < MAX_RES; i++)
    {
        printf("%d ", available[i]);
    }
    printf("\n");
}
void menu()
{
    printf("\n1.Enter for accept available matrix\n");
    printf("2.Enter for Display Allocation, Max\n");
    printf("3.Enter for Display the contents of need matrix\n");
    printf("4.Enter for Display Available\n");
    printf("0.Enter for Exit\n");
}
int main()
{
    int number_of_process ;
    printf("Enter total number of process :");
    scanf("%d", &number_of_process);

    printf("Enter Max resources :");
    scanf("%d", &MAX_RES);

    Process process[number_of_process];

    printf("Enter Process Details \n");
    for (int i = 0; i < number_of_process; i++)
    {
        printf("Enter allocations of p%d: ", i);
        for (int j = 0; j < MAX_RES; j++)
        {
            scanf("%d", &process[i].allocation[j]);
        }
    }

    printf("\n");
    for (int i = 0; i < number_of_process; i++)
    {
        printf("Enter Max of p%d: ", i);
        for (int j = 0; j < MAX_RES; j++)
        {
            scanf("%d", &process[i].max[j]);
        }
    }

    // calculate the need of each process
    for (int i = 0; i < number_of_process; i++)
    {
        for (int j = 0; j < MAX_RES; j++)
        {
            process[i].need[j] = process[i].max[j] - process[i].allocation[j];
        }
        process[i].status = NOT_COMPLETED;
    }

    int available[MAX_RES];
    int choice;
    do
    {
        menu();

        printf("Enter choice :");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter available resources :");
            for (int i = 0; i < MAX_RES; i++)
            {
                scanf("%d", &available[i]);
            }
        }
        else if (choice == 2)
        {
            printAllocationMatrix(process, number_of_process);
            printMaxMatrix(process, number_of_process);
        }
        else if (choice == 3)
        {
            printNeedMatrix(process, number_of_process);
        }
        else if (choice == 4)
        {
            printAvailable(available);
        }

    } while (choice != 0);
}