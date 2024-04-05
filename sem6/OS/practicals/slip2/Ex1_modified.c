/*
Q.1 Write a program to simulate Linked file allocation method. Assume disk with n
number of blocks. Give value of n as input. Randomly mark some block as allocated and
accordingly maintain the list of free blocks Write menu driver program with menu
options as mentioned below and implement each option.
• Show Bit Vector
• Create New File
• Show Directory
• Exit

*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_DIR_SIZE 20 //maximum directory size
#define MAX_NUM_OF_BLOCKS 30 //maximum number of disk blocks

typedef struct Block
{
    int blockNumber;
    struct Block *next;
}Block;

typedef struct File
{
    int file_id;
    Block *Blocks; // Linked list address 
}File;

int getValidRandomBlockNumber(int bitVector[] , int n){
    while(1){
        int num = rand()%n;
        if(bitVector[num]==0){
            bitVector[num] = 1;
            return num;
        }
    }
}

//Linked list insertion at head
Block *insertNewBlock(Block *head , int bitVector[] , int n)
{
    Block *newBlock  = (Block *)malloc(sizeof(Block));
    newBlock->blockNumber = getValidRandomBlockNumber(bitVector , n);
    newBlock->next = head;
    return newBlock;
}

void createNewFile(File directory[] , int *total_files , int bitVector[] , int n)
{
    int file_id , total_blocks;
    printf("Enter file id :");
    scanf("%d" , &file_id);

    printf("Enter Total blocks :");
    scanf("%d" , &total_blocks);
    
    if(total_blocks >=n){
        printf("Blocks are not sufficient,enter valid number of blocks");
        return;
    }


    directory[*total_files].file_id = file_id;
    directory[*total_files].Blocks = NULL;

   for(int i =0 ; i<total_blocks; i++){     
     Block *currentBlock = directory[*total_files].Blocks;
     directory[*total_files].Blocks = insertNewBlock(currentBlock, bitVector , n);    
    }

    (*total_files)++;

}

void showDirectory(File directory[], int *total_files)
{
    printf("Directory : \n");
    for(int i = 0; i<*total_files; i++)
    {
        printf("File %d - Blocks : ", directory[i].file_id );
        
        for(Block *currentBlock = directory[i].Blocks ; currentBlock!=NULL; currentBlock = currentBlock->next){
            printf("%d " , currentBlock->blockNumber);
        }
        printf("\n");
    }
}
void showBitVector(int bitVector[], int n){
    printf("Bit vector :");
    for(int i = 0; i<MAX_NUM_OF_BLOCKS; i++){
        printf("%d " , bitVector[i]);
    }
    printf("\n");
}
int main()
{
    File directory[MAX_DIR_SIZE];
    int total_files  =0 ;
    int n;
    int bitVector[MAX_NUM_OF_BLOCKS] = {0};

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
        case 5:
            exit(0);
        
        default:
            printf("Enter valid choice ");
            break;
        }
    }while (1);
}
