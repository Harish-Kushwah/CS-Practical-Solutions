/*
Q.2 Write a simulation program for disk scheduling using FCFS algorithm. Accept
total number of disk blocks, disk request string, and current head position from the
user. Display the list of request in the order in which it is served. Also display the
total number of head moments.
 55, 58, 39, 18, 90, 160, 150, 38, 184
 Start Head Position: 50
*/

#include<stdio.h>
#include<math.h>

void FCFS(int arr[], int size , int head)
{
    int seek_count = 0;
    int curr_track, distance;
   
    for(int i = 0 ; i<size; i++)
    {
        curr_track = arr[i];
        distance = fabs(head - curr_track);
        seek_count += distance;
        head = curr_track;
    }
    printf("Total number of seek operations : %d\n",seek_count);

    printf("Seek sequence is \n");
    for(int i = 0 ; i<size; i++)
    {
        printf("%d->", arr[i]);
    }
}
int main()
{
   // request array
    int arr[] = { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head = 50;
    int size = sizeof(arr)/sizeof(int);
    FCFS(arr,size,head);
    return 0;
}