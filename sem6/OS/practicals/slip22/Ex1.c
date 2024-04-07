/*
Q.1 Write an MPI program to calculate sum of all odd randomly generated 1000 numbers(stored in array) on a cluster
*/

/**
 * For linux
 * compilation : mpicc Ex2.c
 * Run : mpiexec -n 4 ./Ex2
 * --------------------------------------------------
 * Install the MSMPI for windows 
 * 
 * For compilation of program on windows
 * gcc Ex1.c -o Ex1.exe -I "C:\Program Files (x86)\Microsoft SDKs\MPI\Include" "C:\Program Files (x86)\Microsoft SDKs\MPI\Lib\x86\msmpi.lib"
 * 
 * run 
 * mpiexec -n 2 Ex1.exe
*/

#include<stdio.h>
#include<mpi.h> 
#include<stdlib.h> 

#define MAX 1000
int main(int args , char *argv[])
{
    int rank , size;
    int sum = 0;
    int global_sum = 0;
    int arr[MAX];

    MPI_Init(&args , &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD , &size);

    srand(rank);

    for(int i =0 ; i<MAX; i++)
    {
        arr[i]  = rand()%100;
        if(arr[i] %2 != 0){
         sum += arr[i];
        }
    }

    MPI_Reduce(&sum , &global_sum , 1, MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    printf("Process %d Local sum %d\n" , rank , sum);

    if(rank == 0)
    {
        printf("Global Sum %d" , global_sum);
    }

    MPI_Finalize();
    return 0;
}