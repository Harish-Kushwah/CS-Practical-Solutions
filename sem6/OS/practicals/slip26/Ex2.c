/*
Q.2  Write  a  simulation  program  for  disk  scheduling  using  FCFS  algorithm.  Accept  total 
number  of  disk  blocks,  disk  request  string,  and  current  head  position  from  the  user. 
Display the list of request in the order in which it is served. Also display the total number 
of head moments.  
      56, 59, 40, 19, 91, 161, 151, 39, 185 
     Start Head Position: 48
*/

#include<stdio.h>
#include<math.h>

void FCFS(int arr[] , int size, int head)
{
    int curr_head,seek_count =0 ;

    printf("Seek Sequence :");
    for(int i = 0 ;i<size; i++)
    {
        curr_head = arr[0];
        seek_count += fabs(head - curr_head);
        head  = curr_head;
        printf("%d -> " , curr_head);
    }
    printf("\nTotal seek sequence :%d" , seek_count);

}

int main()
{
        int arr[] = {56, 59, 40, 19, 91, 161, 151, 39, 185 };
        int size = sizeof(arr)/sizeof(arr[0]);
        int head = 50;

        FCFS(arr,size,head);

        return 0;
}