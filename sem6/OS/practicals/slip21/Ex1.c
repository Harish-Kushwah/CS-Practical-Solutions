/**
 * Q.1  Write  a  simulation  program  for  disk  scheduling  using  FCFS  algorithm.  Accept  total 
    number  of  disk  blocks,  disk  request  string,  and  current  head  position  from  the  user. 
    Display the list of request in the order in which it is served. Also display the total number 
    of head moments.  
      55, 58, 39, 18, 90, 160, 150, 38, 184 
     Start Head Position: 50
 * 
 */

#include<stdio.h>
#include<math.h>

void FCFS(int arr[] , int size, int head)
{
    int curr_head, seek_head = 0 ;

    printf("Sequence :");
    for(int i=0; i<size;i++){
        curr_head = arr[i];
        seek_head += fabs(head - curr_head);
        head = curr_head;
        printf("%d->" , curr_head);
    }

    printf("\nTotal seek head : %d" , seek_head);

    
}
int main()
{
    int arr[] = {55, 58, 39, 18, 90, 160, 150, 38, 184};
    int size = sizeof(arr)/sizeof(arr[0]);
    int head = 50;
    FCFS(arr,size,head);

}