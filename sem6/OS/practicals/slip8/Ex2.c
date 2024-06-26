/*
Q.2 Write a simulation program for disk scheduling using SSTF algorithm. Accept total
number of disk blocks, disk request string, and current head position from the user. Display
the list of request in the order in which it is served. Also display the total number of head
moments.
 186, 89, 44, 70, 102, 22, 51, 124
 Start Head Position: 70 
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
    for(int i = 0; i<size; i++){
        for(int j =i+1; j<size; j++){
            if(arr[j]<arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
int* insertIntoArray(int arr[] , int *size , int head)
{
    int *arr1 = (int*)malloc(sizeof(int)*MAX_SIZE);
    int found = 0;
    for(int i =0; i<*size; i++){
        arr1[i] = arr[i];

        if(arr[i] == head){
            found = 0;
        }
    }

    if(!found){
        arr1[*size] = head;
        (*size)++;
    }
    return arr1;
}

void sstf(int arr[] , int size, int head)
{
    int curr_time = 0;
    int seek_time = 0;
    for(int i =0 ;i<size; i++){
        if(arr[i] == head){
            break;
        }
        else{
            curr_time++;
        }
    }

    printf("seek sequence :");
    //go towards the left
    for(int i = curr_time -1; i>0; i--){
        seek_time+= fabs(head - arr[i]);
        printf("%d -> ", arr[i]);
        head = arr[i];
    }

    //go towards the right
    for(int i = curr_time + 1; i<size-1; i++){
         seek_time+= fabs(head - arr[i]);
         printf("%d -> ", arr[i]);
         head = arr[i];
    }
    printf("\nseek time %d\n" , seek_time);

}
int main()
{
    int seq[] = {186, 89, 44, 70, 102, 22, 51, 124};
    int size = sizeof(seq)/sizeof(seq[0]);
    int head = 50;

    int *arr = NULL;
    arr = insertIntoArray(seq , &size , head);
    arr = insertIntoArray(arr , &size , MAX_SIZE);
    arr = insertIntoArray(arr,&size, MIN_SIZE);

    sort(arr , size );
    sstf(arr , size , head);
    
    return 0;
}