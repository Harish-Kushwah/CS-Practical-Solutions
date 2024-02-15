/*
Q.1 Write the simulation program for demand paging and show the page    
        scheduling and total number of page faults according the FIFO page  
        replacement algorithm. Assume the memory of n frames. 
   Reference String :   3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6
 */

#include<stdio.h>
int search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return 0;
        }
    }
    return -1;
}
int main()
{
   int ref[] = {3,4,5,4,3,4,7,2,4,5,6,7,2,4,6 };

   int n = sizeof(ref)/sizeof(ref[0]);

   int no_frame ;
   printf("Enter number of frames :");
   scanf("%d" ,&no_frame);

   int memory_index=0;
   int memory[no_frame];
   int total_page_fault = 0;
   for(int i=0;i<n;i++)
   { 
      if(search(memory , no_frame , ref[i])==-1)
      {
        memory[memory_index] = ref[i];
        total_page_fault++;
        memory_index = (memory_index+1)%no_frame;
      }
   }
   printf("Total page fault %d" , total_page_fault);
}