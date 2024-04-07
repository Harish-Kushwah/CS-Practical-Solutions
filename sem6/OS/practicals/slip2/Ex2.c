/*
Q.2 Write an MPI program to calculate sum of randomly generated 1000 numbers 
(stored in array) on a cluster 
*/

/**
 * Install the MSMPI for windows 
 * For compilation of program on windows
 * gcc Ex2.c -o Ex2.exe -I "C:\Program Files (x86)\Microsoft SDKs\MPI\Include" "C:\Program Files (x86)\Microsoft SDKs\MPI\Lib\x86\msmpi.lib"
 * 
 * run 
 * mpiexec -n 2 Ex2.exe
*/

/**
 * 
1. MPI_Init(&argc, &argv):
   - Purpose: Initializes the MPI environment.
   - Parameters:
     - `argc`: Pointer to the number of command line arguments.
     - `argv`: Pointer to the array of command line arguments.

2. MPI_Comm_rank(MPI_COMM_WORLD, &rank):
   - Purpose: Retrieves the rank of the calling process within the specified communicator.
   - Parameters:
     - `MPI_COMM_WORLD`: Predefined communicator that includes all processes.
     - `&rank`: Address of the variable where the rank of the calling process will be stored.

3. MPI_Comm_size(MPI_COMM_WORLD, &size):
   - Purpose: Retrieves the size of the communicator.
   - Parameters:
     - `MPI_COMM_WORLD`: Predefined communicator that includes all processes.
     - `&size`: Address of the variable where the size of the communicator will be stored.

4. MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD):
   - Purpose: Reduces values on all processes to a single value.
   - Parameters:
     - `&local_sum`: Address of the variable holding the local sum computed by each process.
     - `&global_sum`: Address of the variable where the result of the reduction operation will be stored.
     - `1`: Number of elements in the data to be reduced.
     - `MPI_INT`: Data type of the elements being reduced (integer).
     - `MPI_SUM`: Operation to be applied during the reduction (sum).
     - `0`: Rank of the process that will receive the result of the reduction operation (root process).
     - `MPI_COMM_WORLD`: Communicator over which the reduction operation will be performed.

5. MPI_Finalize():
   - Purpose: Finalizes the MPI environment and cleans up resources.
   - No parameters.

*/

#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

#define ARRAY_SIZE 1000
int main(int argc , char *argv[])
{
    int rank , size;
    int local_array[ARRAY_SIZE];

    int global_sum =0, local_sum =0 ;

    MPI_Init(&argc , &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    srand(rank);
    for(int i =0; i<ARRAY_SIZE; i++){
        local_array[i] = rand() %100;
        local_sum += local_array[i];
    }

    MPI_Reduce(&local_sum , &global_sum , 1 , MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    printf("Process %d local sum: %d\n" , rank , local_sum);

    if(rank == 0){
        printf("Total sum: %d\n" , global_sum);
    }

    MPI_Finalize();

    return 0;
}