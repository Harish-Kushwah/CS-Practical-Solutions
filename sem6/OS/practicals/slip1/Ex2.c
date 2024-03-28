/*
Q.2 Write a simulation program for disk scheduling using FCFS algorithm. Accept
total number of disk blocks, disk request string, and current head position from the
user. Display the list of request in the order in which it is served. Also display the
total number of head moments.
 55, 58, 39, 18, 90, 160, 150, 38, 184
 Start Head Position: 50
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int disk_block,disk_head;
    int req[100];

    printf("Enter Disk Block size :");
    scanf("%d" , &disk_block);

    printf("Enter Disk head :");
    scanf("%d" , &disk_head);

    printf("Enter request string :");
    for(int i =0 ; i<disk_block; i++){
        scanf("%d" , &req[i]);
    }
    int  seek = 0;

    printf("Request Order :");
    printf("%d -> " ,disk_head);
    for(int i =0 ; i<disk_block; i++){
        int diff = abs(req[i] - disk_head);
        seek+= diff;
        disk_head = req[i];
        printf("%d -> " , req[i]);
    }

    printf("\nTotal Head position : %d" , seek);

}