/*
Q.2 Write a simulation program for disk scheduling using SSTF algorithm. Accept total
number of disk blocks, disk request string, and current head position from the user. Display
the list of request in the order in which it is served. Also display the total number of head
moments.
55, 58, 39, 18, 90, 160, 150, 38, 184
Start Head Position: 50
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 199
#define MIN_SIZE 0


void sort(int arr[] , int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j = i +1; j<n; j++){
            if(arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int *insertIntoArray(int seq[] , int *size , int head)
{
    int *arr = (int *)malloc(sizeof(int)*MAX_SIZE);
    int found = 0;
    for(int i =0 ;i<*size; i++)
    {
        arr[i]  = seq[i];

        if(seq[i] == head){
            found = 1;
        } 
    }
    if(!found){
        arr[*size] = head;
        (*size)++;
    }
    return arr;
}
void sstf(int arr[], int size , int head)
{
    int curr_index = 0;
    int seek_count = 0;

    //find index of head
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

    printf("Seek Sequence :");
    //go to left
    for(int i = curr_index-1; i>0; i--){
        seek_count += fabs(head-arr[i]);
        printf("%d -> ",arr[i]);
        head = arr[i];
    }

    //go to right 
    for(int i = curr_index + 1 ; i<size-1; i++){
        seek_count += fabs(head-arr[i]);
        printf("%d -> ",arr[i]);
        head = arr[i];
    }

    printf("\nTotal seek count : %d" , seek_count);


}
int main()
{
    int seq[] = {55, 58, 39, 18, 90, 160, 150, 38, 184};
    int size  = sizeof(seq)/sizeof(seq[0]);
    int head = 70;

    int *arr = NULL;
    arr = insertIntoArray(seq, &size, head);
    arr = insertIntoArray(arr, &size, MAX_SIZE);
    arr = insertIntoArray(arr, &size, MIN_SIZE);

    sort(arr,size);

    sstf(arr,size,head);
    return 0;

}