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

#define MAX_DISK_SIZE 100
#define MAX_NUM_OF_BLOCK 20
int bitVector[MAX_NUM_OF_BLOCK] = {0};
int directory[MAX_NUM_OF_BLOCK][2] ={0}; //{start_block,total blocks}
int directory_size = 0;

void showBitVector(int n)
{
    printf("Bit vector :");
    for(int i =0; i<n; i++)
    {
        printf("%d " , bitVector[i]);
    }
    printf("\n");
}
int getFreeBlocks(int blocks_to_allocate)
{
    for(int i =0; i<= MAX_NUM_OF_BLOCK - blocks_to_allocate ; i++){
        if(!bitVector[i])
        return i;
    }
    return -1;
}
void createNewFile()
{
    int file_id,blocks_to_allocate;
    printf("Enter file Id :");
    scanf("%d" , &file_id);

    printf("Enter blocks to allocate :");
    scanf("%d" , &blocks_to_allocate);

    int start_block = getFreeBlocks(blocks_to_allocate);

    if(start_block == -1)
    {
        printf("Not enough space \n");
        return;
    }

    int total_blocks_required = start_block + blocks_to_allocate;
    for(int i = start_block ; i<total_blocks_required; i++)
    {
        bitVector[i] = 1;
    }
    
    directory[directory_size][0] = start_block;
    directory[directory_size][1] = blocks_to_allocate;
    
    printf("File %d is created successfully" , file_id);

}
void showDirectory()
{
    for(int i = 0; i<directory_size; i++)
    {
        printf("File :%d , start Block: %d , Blocks allocated %d\n" ,i+1 , directory[i][0] , directory[i][1]);
    }

}
int main()
{
    int n;
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
            showBitVector(n);
            break;
        case 2:
            createNewFile();
            break;
        case 3:
            showDirectory();
            break;
        case 4:
            exit(0);
        
        default:
            printf("Enter valid choice ");
            break;
        }
    }while (1);
}
