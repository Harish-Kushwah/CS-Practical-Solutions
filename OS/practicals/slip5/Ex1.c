/*
Q.1 Write the simulation program for demand paging and show the page
       scheduling and total number of page faults according the optimal page
       replacement algorithm. Assume the memory of n frames.
 Reference String :   8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2
*/

// for counting the frequency
#include <stdio.h>

// replace that page which is will come in future very late
//because keeping that page in memory is waste of memory because it will come in future 
int getVictimPage(int ref[], int memory[], int no_frame, int start, int n)
{
    int max = -1;
    int index = -1;

    for (int i = 0; i < no_frame; i++)
    {
        int count = 0;
        for (int j = start; j < n; j++)
        {
            if (ref[j] == memory[i])
            {
                break;
            }
            count++;
        }
        if (count >= max)
        {
            max = count;
            index = i;
        }
    }

    return index;
}
int search(int memory[], int no_frame, int key)
{
    for (int i = 0; i < no_frame; i++)
    {
        if (memory[i] == key)
            return 1;
    }
    return 0;
}
int main()
{
    // int ref[] = {8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2};
    int ref[] =  {7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6, 2};
    int n = sizeof(ref) / sizeof(ref[0]);

    int no_frame;
    printf("Enter number of frames :");
    scanf("%d", &no_frame);

    int page_fault = 0;

    int memory[no_frame];
    for (int i = 0; i < no_frame; i++)
    {
        memory[i] = -1;
    }
    int memory_size = 0;

    for (int i = 0; i < n; i++)
    {
        // when not found
        if (search(memory, no_frame, ref[i]) == 0)
        {
            //memory size if full then it need to replace the pages
            if (memory_size == no_frame)
            {
                int replace_index = getVictimPage(ref, memory, no_frame, i + 1, n);
                memory[replace_index] = ref[i];
                page_fault++;
            }
            else
            {
                //memory size is not full then insert into memory
                memory[memory_size++] = ref[i];
                page_fault++;
            }
        }
    }

    printf("Total page fault is %d ", page_fault);
}