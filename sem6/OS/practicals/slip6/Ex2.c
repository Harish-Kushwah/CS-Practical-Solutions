/*
Q.2 Write a simulation program for disk scheduling using C-SCAN algorithm. Accept total 
number of disk blocks, disk request string, and current head position from the user. Display 
the list of request in the order in which it is served. Also display the total number of head 
moments..      
80, 150, 60,135, 40, 35, 170 
Starting Head Position: 70 
Direction: Right 
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define LEFT 0 
#define RIGHT 1
#define MAX_SIZE 199
#define MIN_SIZE 0

void sort(int arr[] , int size)
{
    for(int i = 0 ; i<size; i++){
        for(int j = i+1; j<size; j++){
            if(arr[j]<arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
//insertion of element into array at correct postion
int* insertNumberIntoArray(int arr[], int *size, int head)
{
    int *arr1 = (int*) malloc(sizeof(int)*MAX_SIZE);
   
    int found = 0;
     for(int i =0 ; i<*size;i++){
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
void CScan(int *arr , int size , int head , int direction)
{
    int index = 0;
    int seek_time = 0;
    for(int i = 0 ; i<size; i++){ 
        if(arr[i] == head){
            break;
        }
        else{
            index++;
        }
    }
    printf("Seek sequence : ");
    //move toward the right
    for(int i = index+1 ; i<size; i++){
        seek_time += fabs(head - arr[i]);
        printf("%d -> " , arr[i]);
        head = arr[i];
    }
    // move from the left end up to the head index
    for(int i = 0; i< index; i++){
            seek_time += fabs(head - arr[i]);
            printf("%d -> " , arr[i]);
            head = arr[i];
    }

    printf("\nTotal seek time : %d " , seek_time);
}

int main()
{
    int arr1[] = {176, 79, 34, 60, 92, 11, 41, 114 };
    int size = sizeof(arr1)/sizeof(arr1[0]);
    int head = 50;
    int direction = RIGHT;

    int *arr = NULL;
    arr =  insertNumberIntoArray(arr1,&size,head);
    arr =  insertNumberIntoArray(arr,&size,MAX_SIZE);
    arr =  insertNumberIntoArray(arr,&size,MIN_SIZE);

    sort(arr,size);
       
    CScan(arr,size,head,direction);
}