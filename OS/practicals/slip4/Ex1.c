/*
Q.1 Write the simulation program for demand paging and show the page  
       scheduling and total number of page faults according the MFU page  
       replacement algorithm. Assume the memory of n frames. 
 Reference String :   8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2 

 */
#include <stdio.h>

int hash[20];

int search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return key;
        }
    }
    return -1;
} 
int getMaxFreqElementIndex(int ref[] , int memory[], int no_frame ,int end)
{
    int max = -1;
    int index = 0;
    for (int i = 0; i<no_frame; i++)
    {
        int count =0;
        for(int j = 0; j<end;j++)
        {
            if(ref[j] == memory[i])
            {
                count++;
            }
        }
       
        if (count > max)
        {
            max = count;
            index = i;
        }
    }
    return index;
}
int main()
{
    // int ref[] ={3,4,5,4,3,4,7,2,4,5,6,7,2,4,6};
    // int ref[] ={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2};
    // int ref[] ={ 5, 0, 1, 3, 2, 4, 1, 0, 5};
    int ref[] ={ 1,2,0,3,0,4,2,3,0,3,2};
//     int ref[] ={ 1,2,3,4,1,2,5,1,2,3,4,5};
    int n = sizeof(ref) / sizeof(ref[0]);
    
    int no_frame;
    printf("Enter total number of frame :");
    scanf("%d" , &no_frame);

    int total_page_fault = 0;
    int memory[no_frame];
    for (int i = 0; i < no_frame; i++)
    {
        memory[i] = -1;
    }

    int memory_size = 0;
    for (int i = 0; i < n; i++)
    {
        // when page not found in the memory then add in the memory   
        if (search(memory, no_frame, ref[i]) == -1)
        {
            //if memory is full then replace the page on the basis of frequency
            if (memory_size == no_frame )
            {
            
                int replace_index = getMaxFreqElementIndex(ref , memory, no_frame , i);    
                memory[replace_index] = ref[i];
                total_page_fault++;
            }
            else
            {
                memory[memory_size++] = ref[i];
                total_page_fault++;  
            }
        }
        
    }

    printf("Page fault :%d", total_page_fault);
    return 0;
}