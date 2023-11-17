/*
Q.1 Write the simulation program to implement demand paging and show the page  
       scheduling and total number of page faults according to the LRU (using  
       counter method) page replacement algorithm. Assume the   memory of n  
       frames.  
   Reference String :   3,5,7,2,5,1,2,3,1,3,5,3,1,6,2  
*/

/*
Logic :
  In LRU we need to replace the page which is less recently used that is present at most of distance form the curent page
  or we used the their index for find the least used , page which is lest used recently has least index among the frames
*/

#include<stdio.h>
int hash[20];
int getVictimPage(int ref[] , int memory[] , int no_frame , int start )
{
   
    int min  =hash[memory[0]];
    int index = 0;
    for(int i=0;i<no_frame;i++)
    {
        int ind = hash[memory[i]];
        if(ind < min)
        {
            min = ind;
            index = i;
        }
    }
    return index;

}
int search(int memory[] , int no_frame , int key)
{
     for(int i=0;i<no_frame;i++)
     {
        if(memory[i]==key)
        {
            return 1;
        }

     }
     return 0;
}
int main()
{
    //initialize the page reference string
    // int ref[] = {1, 3, 3, 2, 5, 4, 5, 4, 1, 4, 2, 2, 5};
    int ref[] =  {8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2};
    int n = sizeof(ref)/sizeof(ref[0]);

    //initialize the number of frames
    int no_frame;
    printf("Enter number of frames :");
    scanf("%d" , &no_frame);

    //initialize the memory 
    int memory[no_frame];
    int memory_size =0;
    for(int i=0;i<no_frame;i++)
    {
        memory[i] = -1;
    }

    int page_fault =0;

    for(int i=0;i<n;i++)
    {
        hash[ref[i]] =i;
        //if page not present in memory 
        if(search(memory , no_frame , ref[i])==0)
        {
            if(memory_size == no_frame)
            {
                int replace_index = getVictimPage(ref,memory,no_frame , i);
                memory[replace_index] = ref[i];
                page_fault++;
            }
            else{
                memory[memory_size++] = ref[i];
                page_fault++;
            }
            
        }     
    }
    printf("Total page fault is %d ", page_fault);

}