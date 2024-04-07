/*
Q.2 Write a simulation program for disk scheduling using C-SCAN algorithm. Accept total
number of disk blocks, disk request string, and current head position from the user. Display
the list of request in the order in which it is served. Also display the total number of head
moments.. [15]
80, 150, 60,135, 40, 35, 170
Starting Head Position: 70
Direction: Right
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 199
#define MIN_SIZE 0
#define LEFT 0
#define RIGHT 1

void sort(int arr[] , int n)
{
    for(int i=0; i<n;i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[j]<arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}


int *insertIntoArray(int seq[] , int *size, int head)
{
    int *arr = (int *)malloc(sizeof(int)*MAX_SIZE);
    int found = 0;
    for(int i =0; i<*size; i++)
    {
        arr[i] = seq[i];
        if(seq[i] == head){
            found = 1; 
        }
    }
    if(!found)
    {
        arr[*size] = head;
        (*size)++;
    }

    return arr;
}

void cscan(int arr[] , int size, int head)
{
    int curr_index =0,seek_count=0;

    //find the head index
    for(int i =0; i<size; i++)
    {
        if(arr[i] == head){
            break;
        }
        else{
            curr_index++;
        }
    }

    printf("Seek Sequence :");
    //move towards the right
    for(int i = curr_index+1; i<size; i++)
    {
        seek_count += fabs(head - arr[i]);
        printf("%d -> ", arr[i]);
        head = arr[i];
    }
    
    for(int i = 0 ; i<curr_index; i++)
    {
        seek_count += fabs(head - arr[i]);
        printf("%d -> ", arr[i]);
        head = arr[i];
    }
    printf("\nTotal seek count %d " , seek_count);
}
int main()
{
    int seq[] = {80, 150, 60,135, 40, 35, 170};
    int size  = sizeof(seq)/sizeof(seq[0]);
    int head = 70;

    int *arr = NULL;
    arr = insertIntoArray(seq , &size, head);
    arr = insertIntoArray(arr, &size, MAX_SIZE);
    arr = insertIntoArray(arr,&size, MIN_SIZE);

    sort(arr, size);
    cscan(arr,size,head);
    return 0;


}