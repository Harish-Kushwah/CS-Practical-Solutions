/*
Q.2 Write an MPI program to find the min number from randomly generated 1000 numbers
 (stored in array) on a cluster (Hint: Use MPI_Reduce) 
*/

/**
 * For linux
 * compilation : mpicc Ex2.c
 * Run : mpiexec -n 4 ./Ex2
 * --------------------------------------------------
 * Install the MSMPI for windows 
 * 
 * For compilation of program on windows
 * gcc Ex2.c -o Ex2.exe -I "C:\Program Files (x86)\Microsoft SDKs\MPI\Include" "C:\Program Files (x86)\Microsoft SDKs\MPI\Lib\x86\msmpi.lib"
 * 
 * run 
 * mpiexec -n 2 Ex2.exe
*/


#include<stdio.h>
#include<stdlib.h> 
#include<mpi.h> 

#define MAX_SIZE 1000

int main(int argc , char *argv[])
{
    int rank,size;
    int local_max = -1;
    int local_min = MAX_SIZE;
    int global_min = MAX_SIZE;
    int arr[MAX_SIZE];

    MPI_Init(&argc , &argv);
    MPI_Comm_rank(MPI_COMM_WORLD , &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    //generate random number
    srand(rank);

    for(int i =0; i<MAX_SIZE; i++)
    {
        arr[i] = rand()%10;      

        if(local_min > arr[i]){
            local_min = arr[i];
        }
        printf("%d " , arr[i]);
    }

    MPI_Reduce(&local_min , &global_min , 1 , MPI_INT , MPI_MIN, 0 , MPI_COMM_WORLD);

    
    printf("process :%d local max : %d\n" , rank , local_min);

    if(rank == 0){
        printf("Global maximum %d " , global_min);
    }

    MPI_Finalize();

    return 0;
}