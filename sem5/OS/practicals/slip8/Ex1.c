/*
Q.1Write the simulation program to implement demand paging and show the 
page scheduling and total number of page faults according to the MRU page 
replacement algorithm. Assume the   memory of n frames.                        
Reference String : 7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6, 2 
*/

#include<stdio.h>

int search(int memory[] , int no_frame , int key)
{
    for(int i=0;i<no_frame;i++)
    {
        if(memory[i]==key)
        return 1;
    }
    return 0;
}
//logic 1 : find the most recently by count the the minimum distance length using count  
int getVictimPage1(int ref[] , int memory[] , int no_frame , int end)
{
    int min = 1000;
    int index = 0;
    for(int i=0;i<no_frame;i++)
    {
        int count = 0;
        for(int j=end ; j>=0; j--)
        {
            if(ref[j] == memory[i])
            {
                break;
            }
            count++;
        }
        if(count<min)
        {
          min = count;
          index = i;
        }
    }

    return index;

}
//logic 2 : find the most recently by count the the minimum distance length using index of elements
// in this case the element has max index is used most recently  
int getVictimPage(int ref[] , int memory[] , int no_frame , int end)
{
    int max = -1;
    int index = 0;
    for(int i=0;i<no_frame;i++)
    {
        int element_index = 0;
        for(int j=end ; j>=0; j--)
        {
            if(ref[j] == memory[i])
            {
               element_index = j;
               break;
            }
            
        }
        if(element_index>max)
        {
          max = element_index;
          index = i;
        }
    }

    return index;

}
int main()
{
    int ref[] = {7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6, 2};
    int n  = sizeof(ref)/sizeof(ref[0]);

    int no_frame;
    printf("Enter number of frame :");
    scanf("%d" , &no_frame);

    int memory[no_frame];
    int memory_size=0;
    int page_fault =0;

    for(int i=0;i<n;i++)
    {
        if(search(memory , no_frame  , ref[i])==0)
        {
            if(memory_size == no_frame)
            {
               int replace_index = getVictimPage(ref , memory , no_frame , i);
               memory[replace_index] = ref[i];
               page_fault++;
            }
            else{
                memory[memory_size++] = ref[i];
                page_fault++;
                
            }
        }
        
    }

    printf("Total number of page fault: %d " , page_fault);
    return 0;
}