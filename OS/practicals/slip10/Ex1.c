/*
Q.1 Write the simulation program for demand paging and show the page    
        scheduling and total number of page faults according the FIFO page  
        replacement algorithm. Assume the memory of n frames. 
   Reference String :   2, 4, 5, 6, 9, 4, 7, 3, 4, 5, 6, 7, 2, 4, 7, 1
*/
#include<stdio.h>
#define FOUND 1
#define NOT_FOUND 0

int search(int memory[] , int no_frame , int key)
{
    for(int i=0;i<no_frame;i++)
    {
        if(memory[i]==key)
        {
            return FOUND;
        }
    }
    return NOT_FOUND;
}
int main()
{
    int ref[] = {2, 4, 5, 6, 9, 4, 7, 3, 4, 5, 6, 7, 2, 4, 7, 1};
    int n = sizeof(ref)/sizeof(ref[0]);

    int no_frame = 3;

    int memory[no_frame];
    int memory_size = 0;
    int page_fault =0;
    for(int i=0;i<n;i++)
    {
        if(search(memory , no_frame ,ref[i])==NOT_FOUND)
        {
            memory[memory_size] = ref[i];
            page_fault++;
            memory_size = (memory_size+1)%no_frame;
            
        }
    }
    printf("Total number of page fault %d" , page_fault);
    return 0;
}