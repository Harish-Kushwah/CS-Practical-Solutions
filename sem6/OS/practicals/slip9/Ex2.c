/*
Q.2 Write a simulation program for disk scheduling using LOOK algorithm. Accept total
number of disk blocks, disk request string, and current head position from the user. Display
the list of request in the order in which it is served. Also display the total number of head
moments. [15]
 176, 79, 34, 60, 92, 11, 41, 114
 Starting Head Position: 65
Direction: Left
*/
/*
 LOOK ALGORITHM:

 seq ={1,2,3,4,5,6,7,8}
 head = 5
 direction = RIGHT
                       H
 |--|----|----|---|----|----|----|----|----|
 0  1    2    3   4    5    6    7    8    9
    |                   ----->        | 
    |                        ---->    |
    |                             --->|
    |               <-----------------|
    |           <----
    |      <----
    |<----

seek sequence :- 5 -> 6 -> 7 -> 8 -> 4 -> 3 -> 2 -> 1    

*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LEFT 0 
#define RIGHT 1
#define MAX_SIZE 199
#define MIN_SIZE 0

void sort(int arr[] , int size)
{
    for(int i = 0;i<size; i++){
        for(int j =i+1; j<size; j++){
            if(arr[j]< arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int* insertIntoArray(int arr[] , int *size, int head)
{
    int *arr1 = (int*)malloc(sizeof(int)*MAX_SIZE);
    int found = 0;
    for(int i =0; i<*size; i++){
        arr1[i] = arr[i];
        if(arr[i] == head){
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
void look(int arr[], int size , int head,int direction)
{
    int curr_index = 0;
    int seek_count = 0;

    //find the current index of head
    for(int i = 0 ; i<size; i++)
    {
       if(arr[i] == head){
         break;
       }
       else{
         curr_index++;
       }
    }

    printf("Seek Sequence :");
    if(direction == LEFT)
    {
        //go towards the left 
        for(int i = curr_index - 1; i>0 ;i--){
            seek_count += fabs(head - arr[i]);
            printf("%d -> " , arr[i]);
            head = arr[i];
        }

        //go towards the right
        for(int i = curr_index + 1; i<size-1; i++){
            seek_count += fabs(head - arr[i]);
            printf("%d -> " , arr[i]);
            head = arr[i];
        }
    }
    else{

        //go towards the right
        for(int i = curr_index + 1; i<size-1; i++){
            seek_count += fabs(head - arr[i]);
            printf("%d -> " , arr[i]);
            head = arr[i];
        }
        //go towards the left
        for(int i = curr_index - 1; i>0; i--){
            seek_count += fabs(head - arr[i]);
            printf("%d -> " , arr[i]);
            head = arr[i];
        }
    }

    printf("\nTotal seek count : %d " , seek_count);
}
int main()
{
    int seq[] = {176,79,34,60,92,11,41,114};
    int size = sizeof(seq)/sizeof(seq[0]);
    int head = 50;
    int direction = LEFT;

    int *arr = NULL;
    arr = insertIntoArray(seq , &size , head);
    arr = insertIntoArray(arr, &size , MAX_SIZE);
    arr = insertIntoArray(arr, &size , MIN_SIZE);

    sort(arr, size);

    look(arr, size, head, direction);

    return 0;
}