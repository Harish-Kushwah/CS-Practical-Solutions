/*
Q.1 Write a program to simulate Sequential (Contiguous) file allocation method.
Assume disk with n number of blocks. Give value of n as input. Randomly mark some
block as allocated and accordingly maintain the list of free blocks Write menu driver
program with menu options as mentioned below and implement each option.
• Show Bit Vector
• Show Directory
• Delete File
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

void showBitVector(int bitVector[] , int n)
{
    printf("Bit Vector :");
    for(int i =0 ; i<n; i++)
    {
        printf("%d " ,bitVector[i]);
    }
    printf("\n");
}
void showDirectory(File directory[] , int *total_files)
{
    for(int i=0; i<*total_files; i++)
    {
        printf("File ID :%d\n" , directory[i].file_id);
        printf("Start block :%d\n" , directory[i].start_block);
        printf("Total block :%d\n\n" , directory[i].total_block);
    }
}

int getFreeBlocks(int bitVector[] , int total_req_blocks)
{
    for(int i=0; i<MAX_BLOCK -total_req_blocks; i++)
    {
        if(bitVector[i] == 0){
            return i;
        }
    }
    return -1;
}

void createNewFile(File directory[] , int *total_files , int bitVector[], int n)
{
    int file_id,total_req_blocks;
    printf("Enter file id :");
    scanf("%d" , &file_id);

    printf("Enter total required blocks :");
    scanf("%d" , &total_req_blocks);

   
    int start_block = getFreeBlocks(bitVector , total_req_blocks);

    int remaining_blocks = n - start_block;

    if(total_req_blocks > remaining_blocks )
    {
        printf("Sufficient Number of blocks are no available");
        return;
    }

    int total_blocks = start_block + total_req_blocks;
    for(int i = start_block; i<total_blocks; i++)
    {
         bitVector[i] = 1;
    }
    directory[*total_files].file_id = file_id;
    directory[*total_files].start_block = start_block;
    directory[*total_files].total_block = total_req_blocks;
    (*total_files)++;

    printf("File added success fully \n");
    printf("Total number of remaining blocks %d" , remaining_blocks);
}
void deleteFile(File directory[] , int *total_files , int bitVector[], int file_id)
{
    for(int i =0; i<*total_files; i++){

        if(directory[i].file_id == file_id)
        {
            int start_block = directory[i].start_block;
            int total_block = directory[i].total_block;
            
            for(int i =start_block ; i<=start_block+total_block; i++){
                bitVector[i] = 0;
            }
            printf("File Deleted successfully");
            //move the remaining files
            for(int j = i; j<*total_files-1; j++)
            {
                directory[j] =directory[j+1]; 
            }
            (*total_files)--;
            
        }

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
        printf("3.Delete  file\n");
        printf("4.Show Directory\n");
        printf("5.Exit \n");

        int c;
        printf("Enter your choice :\n");
        scanf("%d" , &c);

        switch (c)
        {
             int file_id;
        case 1:
            showBitVector(bitVector ,n);
            break;
        case 2:
            createNewFile(directory,&total_files,bitVector , n);
            break;
        case 3:
           
            printf("Enter file id :");
            scanf("%d" , &file_id);
            deleteFile(directory,&total_files,bitVector,file_id);
            break;
        case 4:
            showDirectory(directory,&total_files);
            break;
        case 5:
            exit(0);
        
        default:
            printf("Enter valid choice ");
            break;
        }
    }while (1);
}
