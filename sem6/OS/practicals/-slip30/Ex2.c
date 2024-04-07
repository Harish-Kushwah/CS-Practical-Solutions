/*
Q.2  Write  a  simulation  program  for  disk  scheduling  using  FCFS  algorithm.  Accept  total 
number of disk blocks, disk request string, and current head position from the user. Display 
the list of request in the order in which it is served. Also display the total number of head 
moments.  
      65, 95, 30, 91, 18, 116, 142, 44, 168 
     Start Head Position: 52

*/

#include<stdio.h>
#include<math.h>

void FCFS(int arr[], int size , int head)
{
    int curr_head,seek_time = 0;

    printf("Seek Sequence :");
    for(int i = 0; i<size; i++)
    {
        curr_head = arr[i];
        seek_time+= fabs(head - curr_head);
        head = curr_head;
        printf("%d->" , curr_head);
    }

    printf("\nTotal seek time : %d" , seek_time);
}
int main()
{
    int arr[] = {65, 95, 30, 91, 18, 116, 142, 44, 168};
    int size  = sizeof(arr)/sizeof(arr[0]);
    int head = 50;

    FCFS(arr,size, head);
    return 0;
}