/*
Q.2 Write a simulation program for disk scheduling using C-LOOK algorithm. Accept total
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

void sort(int arr[] , int size)
{
    for(int i =0 ; i<size; i++)
    {
        for(int j = i+1 ; j<size; j++)
        {
            if(arr[j]< arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int *insertIntoArray(int arr[] , int *size , int head)
{
    int *arr1 = (int *)malloc(sizeof(int)*MAX_SIZE);

    int found = 0;
    for(int i = 0 ; i<*size; i++)
    {
        arr1[i] = arr[i];
        if(arr[i] == head)
        {
            found = 1;
        }
    }
    if(!found)
    {
        arr1[*size] = head;
        (*size)++;
    }
    return arr1;
}

void clook(int arr[] , int size , int head , int direction)
{
    int curr_index = 0;
    int seek_count = 0;
    for(int i = 0; i<size; i++)
    {
        if(arr[i] == head)
        {
            break;
        }
        else{
            curr_index++;
        }
    }

    printf("Seek sequence : ");
    if(direction == LEFT)
    {
        // go to left 
          for(int i = curr_index-1; i>=0; i--){
            seek_count += fabs(head - arr[i]);
            printf("%d ->" , arr[i]);
            head = arr[i];
          }
        // got to right
        for(int i = size - 1 ; i>curr_index; i--){
            seek_count += fabs(head - arr[i]);
            printf("%d ->" , arr[i]);
            head = arr[i];
        }
    }
    else{

        // go right
        for(int i = curr_index + 1 ; i<size; i++){
            seek_count += fabs(head - arr[i]);
            printf("%d ->" , arr[i]);
            head = arr[i];
        }

        //go left
        for(int i = 0; i<curr_index; i++){
            seek_count += fabs(head - arr[i]);
            printf("%d ->" , arr[i]);
            head = arr[i];
        }

       
    }
    printf("\nTotal seek count %d " , seek_count);
}
int main()
{
    int seq[] = {80, 150, 60,135, 40, 35, 170};
    int size = sizeof(seq)/sizeof(seq[0]);
    int head = 70;
    int direction = LEFT;


    int *arr = NULL;
    arr = insertIntoArray(seq , &size , head);
    arr = insertIntoArray(arr, &size , MAX_SIZE);
    arr = insertIntoArray(arr, &size , MIN_SIZE);

    sort(arr , size);
    clook(arr,size,head,direction);
    return 0;
}