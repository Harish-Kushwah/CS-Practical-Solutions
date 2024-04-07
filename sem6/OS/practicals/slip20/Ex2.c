/*
Q.2 Write an MPI program to find the max number from randomly generated 1000
numbers (stored in array) on a cluster (Hint: Use MPI_Reduce) 
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

#define MAX 1000
int main(int argv , char *argc[])
{
    int rank,size;
    int local_max = -1;
    int global_max = -1;
    int arr[MAX];

    MPI_Init(&argv , &argc);
    MPI_Comm_rank(MPI_COMM_WORLD , &rank);
    MPI_Comm_size(MPI_COMM_WORLD , &size);

    srand(rank);
    for(int i =0; i<MAX; i++)
    {
        arr[i] = rand()%100;
        if(local_max < arr[i]){
            local_max = arr[i];
        }
    }

    MPI_Reduce(&local_max , &global_max , 1, MPI_INT , MPI_MAX , 0 ,MPI_COMM_WORLD);
    printf("Process %d local maximum %d " , rank , local_max);

    if(rank == 0 )
    {
        printf("Global Maximum %d" , global_max);
    }
    MPI_Finalize();

    return 0;

}