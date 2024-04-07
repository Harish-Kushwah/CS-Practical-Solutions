/*
Q.2 Write an MPI program to find the max number from randomly generated
1000 numbers (stored in array) on a cluster (Hint: Use MPI_Reduce) 
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
   int global_max = -1;
  

   MPI_Init(&argc , &argv);
   MPI_Comm_rank(MPI_COMM_WORLD , &rank);
   MPI_Comm_size(MPI_COMM_WORLD, &size);

   srand(rank);
   for(int i =0; i<MAX_SIZE; i++)
   {
        int num = rand()%100;
        if(local_max < num){
            local_max = num;
        }
   }

   MPI_Reduce(&local_max , &global_max , 1 , MPI_INT,MPI_MAX, 0 , MPI_COMM_WORLD);
   printf("Process : %d Local max %d" ,rank, local_max );

   if(rank == 0)
   {
     printf("\nGlobal maximum %d ",global_max);
   }

   MPI_Finalize();
   return 0;


}

