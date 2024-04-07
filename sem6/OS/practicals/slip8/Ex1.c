/*
Q.1 Write a program to simulate Contiguous file allocation method. Assume disk with n
number of blocks. Give value of n as input. Randomly mark some block as allocated and
accordingly maintain the list of free blocks Write menu driver program with menu
options as mentioned above and implement each option.
• Show Bit Vector
• Create New File
• Show Directory
• Exit
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_BLOCK 20
#define MAX_DIR_SIZE 20
typedef struct File 
{
    int file_id;
    int start_block;
    int total_block;
}File;

int getFreeStartBlockIndex(int bitVector[] , int total_req_blocks)
{
    for(int i =0; i<MAX_BLOCK - total_req_blocks; i++)
    {
        if(bitVector[i]==0){
            return i;
        }
    }
    return -1;
}
void createNewFile(File directory[] , int *total_files ,int bitVector[], int n)
{
    int file_id, total_req_blocks;
    printf("Enter file ID :");
    scanf("%d" , &file_id);

    printf("Enter total blocks :");
    scanf("%d" , &total_req_blocks);

    if(total_req_blocks>n){
        printf("Enter valid number of blocks");
        return;
    }

    int start_block = getFreeStartBlockIndex(bitVector, total_req_blocks);
    int total_blocks = start_block + total_req_blocks;
    
    for(int i=start_block; i<total_blocks; i++)
    {
        bitVector[i] = 1;
    }

    directory[*total_files].file_id = file_id;
    directory[*total_files].start_block = start_block;
    directory[*total_files].total_block = total_req_blocks;
    (*total_files)++; 
}
void showBitVector(int bitVector[], int n)
{
    printf("Bit Vector :");
    for(int i = 0; i<n;i++)
    {
        printf("%d " , bitVector[i]);
    }
    printf("\n");
}
void showDirectory(File directory[] , int *total_files)
{
    for(int i=0; i<*total_files; i++)
    {
        printf("File ID : %d \n" , directory[i].file_id);
        printf("Start Block : %d \n" , directory[i].start_block);
        printf("Total Block :%d\n\n",directory[i].total_block);
    }
}
int main()
{
    File directory[MAX_DIR_SIZE];
    int total_files  =0 ;
    int n;
    int bitVector[MAX_BLOCK] = {0};

    printf("Enter the number of blocks on the disk: ");
    scanf("%d" , &n);

    do{
        printf("\nMenu\n");
        printf("1.Show bit vector\n");
        printf("2.Create new file\n");
        printf("3.Show Directory\n");
        printf("4.Exit \n");

        int c;
        printf("Enter your choice :\n");
        scanf("%d" , &c);

        switch (c)
        {
        case 1:
            showBitVector(bitVector ,n);
            break;
        case 2:
            createNewFile(directory,&total_files,bitVector , n);
            break;
        case 3:
            showDirectory(directory,&total_files);
            break;
        case 4:
            exit(0);
        
        default:
            printf("Enter valid choice ");
            break;
        }
    }while (1);
}
