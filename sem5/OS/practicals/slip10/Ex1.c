/*
Q.1 Write the simulation program for demand paging and show the page  
       scheduling and total number of page faults according the LRU page  
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
          return FOUND;
    }
    return NOT_FOUND;
}

int getVictimPage(int ref[] , int memory[] , int no_frame , int end)
{
    int max = -1;
    int index =0;
    for(int i=0;i<no_frame ; i++)
    {
        int count =0;
        for(int j = end ; j>=0;j--)
        {
            if(ref[j]==memory[i])
            {
                break;
            }
            count++;
        }

        if(count>max)
        {
            max = count;
            index = i;
        }
    }
    return index;
}
int main()
{
    int ref[] = {8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2};
    int n = sizeof(ref)/sizeof(ref[0]);

    int no_frame = 4;
    printf("Enter number of frames :");
    scanf("%d" ,  &no_frame);

    int memory[no_frame];
    int memory_size =0;

    int page_fault=0;

    for(int i=0;i<n;i++)
    {
        if(search(memory , no_frame , ref[i])==NOT_FOUND)
        {
           if(memory_size == no_frame)
           {
             int replace_index = getVictimPage(ref , memory, no_frame , i);
             memory[replace_index] = ref[i];
             page_fault++;
           }
           else{
                memory[memory_size++] = ref[i];
                page_fault++;
           }
        }
    }
    printf("Total page fault : %d" , page_fault);

    return 0;
}