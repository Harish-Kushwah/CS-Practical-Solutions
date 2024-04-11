/*
Q.2 Write a simulation program for disk scheduling using SCAN algorithm. Accept total
number of disk blocks, disk request string, and current head position from the user. Display
the list of request in the order in which it is served. Also display the total number of head
moments.
82, 170, 43, 140, 24, 16, 190
 Starting Head Position: 50
 Direction: Left
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
    for(int i = 0 ; i<size; i++){
        for(int j = i+1; j<size; j++){
            if(arr[i]> arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int* insertIntoArray(int arr[] , int *size , int head)
{
    int *arr1 = (int*) malloc(sizeof(int)*MAX_SIZE);
    int found = 0;
    for(int i = 0; i<(*size) ; i++){
        arr1[i] = arr[i];

        if(arr[i] == head){
            found = 1;
            
        }
    }
    if(!found){
         arr1[*size] = head;
         (*size)++;
    }

    return arr1;

}
void scan(int arr[] , int size , int head, int direction)
{
    int curr_index = 0 ; 
    int seek_count = 0 ;
    
    //find the curr index of head 
    for(int i = 0 ; i<size; i++){
        if(arr[i] == head){
            break;
        }
        else{
            curr_index++;
        }
    }

    if(direction == LEFT){
        printf("Seek Sequence : %d -> ", head);
        // move towards the left up to 0
        for(int i = curr_index -1 ; i>=0; i--){
            seek_count += fabs(head - arr[i]);
            printf("%d -> ", arr[i]);
            head = arr[i];
        }

        //move towards the right from the next of current index
        for(int i = curr_index+1 ; i<size-1; i++){
            seek_count += fabs(head - arr[i]);
             printf("%d -> ", arr[i]);
            head = arr[i];
        }
    }
    else{
        printf("Seek Sequence : %d -> ", head);
        //move towards the right from the next of current index
        for(int i = curr_index+1 ; i<size; i++){
            seek_count += fabs(head - arr[i]);
             printf("%d -> ", arr[i]);
            head = arr[i];
        }

         // move towards the left up to first element
        for(int i = curr_index -1 ; i>0; i--){
            seek_count += fabs(head - arr[i]);
            printf("%d -> ", arr[i]);
            head = arr[i];
        }

    }
    printf("Total seek count : %d" , seek_count);
}
int main()
{
    int seq[] = {82, 170, 43, 140, 24, 16, 190};
    int size = sizeof(seq)/sizeof(seq[0]);
    int head = 50;
    int direction = RIGHT;

    int *arr = NULL;
    arr = insertIntoArray(seq , &size , head);
    arr = insertIntoArray(arr , &size , MAX_SIZE);
    arr = insertIntoArray(arr, &size , MIN_SIZE);

    sort(arr, size);

   

   scan(arr,size,head,direction);

}