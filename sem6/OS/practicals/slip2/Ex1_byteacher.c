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

#define MAX_BLOCKS 50

typedef struct  Block
{
    int blockNumber;
    struct Block *next;
}Block;

typedef struct File
{
    int fileId;
    Block *blocks;
}File;


void showBitVector(int f[] , int n){
    printf("Bit vector :");
    for(int i = 0; i<n; i++){
        printf("%d " , f[i]);
    }
    printf("\n");
}

void showDirectory(File directory[] , int p)
{
    printf("Directory : \n");
    for(int i = 0; i<p; i++)
    {
        printf("File %d - Blocks : ", directory[i].fileId );
        
        for(Block *currentBlock = directory[i].blocks ; currentBlock!=NULL; currentBlock = currentBlock->next){
            printf("%d " , currentBlock->blockNumber);
        }
        printf("\n");
    }
}

void createNewFile(File directory[] , int *p , int n , int f[])
{
    int fileId, numBlocks;
    printf("Enter file ID: ");
    scanf("%d" , &fileId);

    printf("Enter number of blocks to allocate :");
    scanf("%d" , &numBlocks);

    if(*p >= n)
    {
        printf("No more space in the directory.\n");
        return;
    }

    directory[*p].fileId = fileId;
    directory[*p].blocks = NULL;

    for(int i = 0 ; i<numBlocks; i++)
    {
        int blockNumber = rand()%n; 

        if(blockNumber == 0){
            f[blockNumber] = 1;

            Block *newBlock = (Block *)malloc(sizeof(Block));

            newBlock ->blockNumber = blockNumber;
            newBlock ->next =  directory[*p].blocks;

            directory[*p].blocks = newBlock;
        }
        else{
            printf("%d block is already allocated\n", blockNumber);
            i--;
        }
    }
    (*p)++;
}

int main()
{
    File directory[MAX_BLOCKS];
    int p = 0,n,c;
    int bitVector[MAX_BLOCKS] = {0};

    printf("Enter the number of blocks on the disk: ");
    scanf("%d" , &n);

    do{
        printf("\nMenu\n");
        printf("1.Show bit vector\n");
        printf("2.Create new file\n");
        printf("3.Show Directory\n");
        printf("4.Exit \n");

        printf("Enter your choice :\n");
        scanf("%d" , &c);

        switch (c)
        {
        case 1:
            showBitVector(bitVector,n);
            break;
        case 2:
            createNewFile(directory,&p,n,bitVector);
            break;
        case 3:
            showDirectory(directory,p);
            break;
        case 4:
            exit(0);
        
        default:
            printf("Enter valid choice ");
            break;
        }
    }while (1);
}
