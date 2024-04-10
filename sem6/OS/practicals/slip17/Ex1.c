/*
Q.1 Write a program to simulate Linked file allocation method. Assume disk with 
n number of blocks. Give value of n as input. Randomly mark some block as 
allocated and accordingly maintain the list of free blocks Write menu driver 
program with menu options as mentioned above and implement each option.  
• Show Bit Vector   
• Show Directory   
• Delete Already File  
• Exit 
*/
#include<stdio.h>
#include<stdlib.h>
  
#define MAX_NO_FILES 20
#define MAX_NO_BLOCKS 100
typedef struct Block
{
    int block_number;
    struct Block *next;
}Block;

typedef struct File
{
    int file_id;
    Block *blocks;
}File;

void showBitVector(int bitVector[] , int n)
{
    printf("Bit vector : ");
    for(int i=0;i<n;i++)
    {
        printf("%d " , bitVector[i]);
    }
    printf("\n");
}
void showDirectory(File directory[] , int *total_files)
{
    printf("\nDirectory is :");
    for(int i =0; i<*total_files; i++)
    {
        printf("\nFile id : %d\n" , directory[i].file_id);
        printf("Block number : ");
        for(Block *temp = directory[i].blocks; temp!=NULL; temp = temp->next){
            printf("%d " , temp->block_number);
        }
    }
    printf("\n");
}

int getRandomeBlockNumber(int bitVector[] , int n)
{
    while(1)
    {
        int num = rand()%n;
        if(bitVector[num]==0){
            bitVector[num] = 1;
            return num;
        }
    }
}
int getRemainingBlocks(int bitVector[],int n)
{
    int count =0;
    for(int i =0; i<n;i++){
        if(bitVector[i]==0)
        count++;
    }
    return count;
}
Block *insetBlock(Block *head , int block_number)
{
    Block *newBlock = (Block*)malloc(sizeof(Block));
    newBlock->block_number = block_number;
    newBlock->next = head;
    return newBlock;
}
void createNewFile(File directory[] , int *total_file , int bitVector[] , int n)
{
    int file_id , total_blocks;
    printf("Enter file id :");
    scanf("%d" , &file_id);

    printf("Enter total blocks :");
    scanf("%d" , &total_blocks);

    if(total_blocks > getRemainingBlocks(bitVector,n)){
        printf("Sufficient bocks are not avilable\n");
        return;
    }

    directory[*total_file].file_id = file_id;
    directory[*total_file].blocks = NULL;

    for(int i =0; i<total_blocks; i++){
       int block_number = getRandomeBlockNumber(bitVector,n);
       directory[*total_file].blocks = insetBlock(directory[*total_file].blocks , block_number); 
    }
    (*total_file)++;
    printf("File created succssfully");
}
void deleteFile(File directory[], int *total_file, int file_id ,int bitVector[])
{
    for(int i=0;i<*total_file; i++)
    {
        File file = directory[i];
        if(file.file_id == file_id)
        {
            //free the alloted blocks
            for(Block *temp = file.blocks; temp!=NULL; temp=temp->next)
            {
                bitVector[temp->block_number]=0;
            }

            //remove the file
            for(int j=i; j<(*total_file); j++)
            {
                directory[j] = directory[j+1];
            }
            (*total_file)--;

            printf("File deleted successfully");
            return;
        }
    }
    printf("File not found\n");
}
void menu()
{   
    printf("\n____________________[MENU]_________________\n");
    printf("1.Show Bit Vector\n");   
    printf("2.Show Directory\n"); 
    printf("3.Delete Already File\n");
    printf("4.Create new file\n");
    printf("5.Exit\n");

}
int main()
{
    File directory[MAX_NO_FILES];
     int bitVector[MAX_NO_BLOCKS] = {0};

    int n;
    printf("Enter number of blocks :");
    scanf("%d" , &n);
    int total_files = 0,file_id;
   
   do{
        menu();
        int ch;
        printf("Enter choice :");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1:
            showBitVector(bitVector,n);
            break;
        case 2:
            showDirectory(directory,&total_files);
            break;
        case 3:
            printf("Enter file id to delete:");
            scanf("%d" , &file_id);
            deleteFile(directory,&total_files,file_id,bitVector);
            break;
        case 4:
            createNewFile(directory,&total_files,bitVector,n);
            break;
        case 5:
            exit(0);

        default:
            printf("Enter valid case");
        }
   }while(1);
    
}