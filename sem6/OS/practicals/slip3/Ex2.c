/*
Q.2 Write an MPI program to calculate sum and average of randomly generated 1000
  numbers (stored in array) on a cluster 
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
#include<mpi.h> 
#include<stdlib.h>

#define  MAX_SIZE 1000
int  main(int argc , char *argv[])
{
    int rank , size;
    int local_array[MAX_SIZE];
    int global_sum = 0;
    int local_sum  = 0;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    //generate the random number
    srand(rank);
    for(int i =0; i<MAX_SIZE; i++){
        local_array[i] = rand()%100;
        local_sum += local_array[i];
    }

    MPI_Reduce(&local_sum , &global_sum ,1, MPI_INT, MPI_SUM,0,MPI_COMM_WORLD);
    printf("Process %d local sum : %d" , rank , local_sum);

    if(rank == 0){
        printf("\nTotal sum %d" , global_sum);
    }

    MPI_Finalize();

    return 0;

}
