/*
Q.1 Implement the Menu driven Banker's algorithm for accepting Allocation, Max
from user.
a) Accept Available
b) Display Allocation, Max
c) Find Need and display It,
d) Display Available
Consider the system with 3 resources types A,B, and C with 7,2,6        instances respectively.
Consider the following snapshot:
Process Allocation Request
 A B C A B C
P0 0 1 0 0 0 0
P1 4 0 0 5 2 2
P2 5 0 4 1 0 4
P3 4 3 3 4 4 4
P4 2 2 4 6 5 5
*/
#include <stdio.h>

#define number_of_process 5
#define MAX_RES 3

void menu()
{
    printf("\n_______________________[OS]____________________\n");
    printf("1.Enter for accept available matrix\n");
    printf("2.Enter for Display Allocation, Max\n");
    printf("3.Enter for Display the contents of need matrix\n");
    printf("4.Enter for Display Available\n");
    printf("0.Enter for Exit\n");
    printf("\n");
}
int main()
{
    int allocation[number_of_process][MAX_RES] = {
        {0, 1, 0},
        {4, 0, 0},
        {5, 0, 4},
        {4, 3, 3},
        {2, 2, 4},
    };
    int max[number_of_process][MAX_RES] = {
        {0, 0, 0},
        {5, 2, 2},
        {1, 0, 4},
        {4, 4, 4},
        {6, 5, 5},
    };

    int choice;
    int available[MAX_RES];

    do
    {
        menu();
        printf("Enter choice :");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter available resources :\n");
            for (int i = 0; i < MAX_RES; i++)
            {
                scanf("%d", &available[i]);
            }
            printf("Available resources saved successfully.\n");
        }
        else if (choice == 2)
        {
            printf("Allocation Matrix is:\n");
            for (int i = 0; i < number_of_process; i++)
            {
                for (int j = 0; j < MAX_RES; j++)
                {
                    printf("%d ", allocation[i][j]);
                }
                printf("\n");
            }

            printf("\nMax Matrix is:\n");
            for (int i = 0; i < number_of_process; i++)
            {
                for (int j = 0; j < MAX_RES; j++)
                {
                    printf("%d ", max[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
        else if (choice == 3)
        {
            int need[number_of_process][MAX_RES];
            for (int i = 0; i < number_of_process; i++)
            {
                for (int j = 0; j < MAX_RES; j++)
                {
                    need[i][j] = max[i][j] - allocation[i][j];
                }
            }

            printf("Need Matrix is:\n");
            for (int i = 0; i < number_of_process; i++)
            {
                for (int j = 0; j < MAX_RES; j++)
                {
                    printf("%d ", need[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
        else if (choice == 4)
        {
            printf("Available resources :");
            for (int i = 0; i < MAX_RES; i++)
            {
                printf("%d ", available[i]);
            }
            printf("\n");
        }
    } while (choice != 0);
}