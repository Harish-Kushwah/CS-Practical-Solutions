/*
Q.2 Write  a  simulation  program  for  disk  scheduling  using  SCAN  algorithm.  Accept  total
number  of  disk  blocks,  disk  request  string,  and  current  head  position  from  the  user.
Display  the  list  of  request  in  the  order  in  which  it  is  served.  Also  display  the  total
number of head moments.
86, 147, 91, 170, 95, 130, 102, 70
Starting Head position= 125
Direction: Left

LOGIC:
 -> sort the give seek sequence 
 -> insert the head at the correct position
 -> if direction is left
      go towards the left up to 0 index(i.e up to minimum element)
      and then go towards the right up the last element except max size
    else 
      go towards the right up to max index(i.e up to maximum element)
      and then go towards the left up the last element except min size(i.e 0)
      
*/
#include <stdio.h>
#include <math.h>
#define LEFT 0
#define RIGHT 1

//bubble sort 
void sort(int arr[], int size)
{
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
//insertion of element into array at correct postion
int insertNumberIntoArray(int arr[], int *size, int head)
{
    int flag = 0;
    for (int i = 0; i < *size - 1; i++)
    {
        if (arr[i + 1] > head && arr[i] < head && flag == 0)
        {
            flag = 1;
            (*size)++;
        }
        if (flag == 1)
        {
            int temp = arr[i + 1];
            arr[i + 1] = head;
            head = temp;
        }
    }
    return flag;
}
//SCAN algorithm
void Scan(int arr[], int size, int head, int direction)
{
    int seek_time = 0 , curr_index = 0;

    // move  pointer to the head then start form that head to the left
    for (int i = 0; i < size; i++){
        if (arr[i] == head){
            break;
        }
        else{
            curr_index++;
        }
    }

    printf("Seek Sequence : %d->", head);
    if (direction == LEFT)
    {
        // move towards the left up to 0
        for (int i = curr_index - 1; i >= 0; i--)
        {
            seek_time += fabs(head - arr[i]);
            printf("%d->", arr[i]);
            head = arr[i];
        }

        // move towards the right up to last element of sequence
        for (int i = curr_index + 1; i < size - 1; i++)
        {
            seek_time += fabs(head - arr[i]);
            printf("%d->", arr[i]);
            head = arr[i];
        }
    }
    else
    {
         // move towards the right up to last element
        for (int i = curr_index + 1; i < size ; i++){
            seek_time += fabs(head - arr[i]);
            printf("%d->", arr[i]);
            head = arr[i];
        }

        // move towards the left up to first element 
        for (int i = curr_index - 1; i > 0; i--){
            seek_time += fabs(head - arr[i]);
            printf("%d->", arr[i]);
            head = arr[i];
        }
       
    }

    printf("\nTotal seek time : %d", seek_time);
}
int main()
{
    int MAX_SIZE = 199;
    int MIN_SIZE = 0;
    int arr[] = {MIN_SIZE, 86, 147, 91, 170, 95, 130, 102, 70, MAX_SIZE};
    int size = sizeof(arr) / sizeof(arr[0]);
    int head = 125;
    int direction = RIGHT;

    sort(arr, size);

    insertNumberIntoArray(arr, &size, head);

    Scan(arr, size, head, direction);
}