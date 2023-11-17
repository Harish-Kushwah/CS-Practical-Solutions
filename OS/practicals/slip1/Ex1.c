/*
Q.1 Write the simulation program to implement demand paging and show the
page  scheduling  and  total  number  of  page  faults  according  to  the  LFU  page
replacement algorithm. Assume the   memory of n frames.
 Reference String : 3,4,5,4,3,4,7,2,4,5,6,7,2,4,6

Step-1 : Initialize total_page_fault as 0.
Step-2 : Create a vector / array of size equal to memory capacity.
            Create a map to store frequency of pages
Step-3 : Traverse elements of pages[]
Step-4 : In each traversal:
       if(element is present in memory):
            remove the element and push the element at the end
            increase its frequency
       else:
            if(memory is full)
                 remove the first element and decrease frequency of 1st element
            Increment total_page_fault
            push the element at the end and increase its frequency
      Compare frequency with other pages starting from the 2nd last page
      Sort the pages based on their frequency and time at which they arrive
      if frequency is same, then, the page arriving first must be placed first

Logic:
 Least Frequent Used :- In this case we assume that page is not using i.e page hit not occurring
  therefore their frequency is increasing , hence such page needs to replace 
  if pages having same frequency replace those page which came first 

  calculate the frequency each time 
  if page hit occurs then reset the their frequency

  replace the page which is used min no of times

*/
#include <stdio.h>

typedef struct Memory
{
    int page;
    int arrival_time;

}Memory;
int hash[20];

int search(Memory memory[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (memory[i].page == key)
        {
            return key;
        }
    }
    return -1;
} 

int getMinFreqElementIndex(int ref[] , Memory memory[], int no_frame ,int end)
{
    int min =  hash[memory[0].page];
    int index = -1;
    int same =0;
    for (int i = 0; i<no_frame; i++)
    {
        //get minimum frequent page
        int count = hash[memory[i].page];
        printf("\npage  = %d  used =  %d\n" , memory[i] , count);
        if (count < min)
        {
            min = count;   
            index  = i;
            same++;
        } 
    }
    printf("Same :%d\n" , same);
    if(same==0){

   
       //apply fifo
        int min_arrival = 100;
            for(int j =0; j<no_frame;j++)
            {
                int t = memory[j].arrival_time;
                if(t<min_arrival)
                {
                    min_arrival = t;
                    index = j;
                }
            }
    }
    return index;
}
void printFrq(int ref[] , int n)
{
    for(int i=0;i<n;i++)
    {
       printf("%d => %d \n " , ref[i] , hash[ref[i]]);
    }
}
int main()
{
    // int ref[] ={3,4,5,4,3,4,7,2,4,5,6,7,2,4,6};
    // int ref[] ={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2};
    // int ref[] ={ 5, 0, 1, 3, 2, 4, 1, 0, 5};
    // int ref[] ={ 1,2,0,3,0,4,2,3,0,3,2};
    int ref[] ={ 1,2,3,4,1,2,5,1,2,3,4,5};
    int n = sizeof(ref) / sizeof(ref[0]);
    
    for(int i=0;i<n;i++)
    {
      
    }
    int no_frame;
    printf("Enter total number of frame :");
    scanf("%d" , &no_frame);

    int total_page_fault = 0;
    Memory memory[no_frame];
    for (int i = 0; i < no_frame; i++)
    {
        memory[i].page = -1;
        memory[i].arrival_time =0;
    }

    int memory_size = 0;
    for (int i = 0; i < n; i++)
    {
        hash[ref[i]]++;
        // when page not found in the memory then add in the memory   
        if (search(memory, no_frame, ref[i]) == -1)
        {
            //if memory is full then replace the page on the basis of frequency
            if (memory_size == no_frame )
            {
            
                int replace_index = getMinFreqElementIndex(ref , memory, no_frame , i);    
                printf("%d to %d" ,memory[replace_index].page , ref[i] );
                memory[replace_index].page = ref[i];
                memory[replace_index].arrival_time  = i;

                total_page_fault++;
            }
            else
            {
                memory[memory_size].page = ref[i];
                memory[memory_size].arrival_time  = i;
                memory_size++;
                
                total_page_fault++;  
            }
            
        }
        
        // printFrq(ref,n);
        
    }

    printf("Page fault :%d", total_page_fault);
    return 0;
}