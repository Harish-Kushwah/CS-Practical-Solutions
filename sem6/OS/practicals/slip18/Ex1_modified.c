/*
Q.1 Write a program to simulate Indexed file allocation method. Assume disk 
with n number of blocks. Give value of n as input. Randomly mark some block 
as allocated and accordingly maintain the list of free blocks Write menu driver 
program with menu options as mentioned above and implement each option.  
• Show Bit Vector   
• Create New File   
• Show Directory   
• Delete File  
• Exit
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_NO_BLOCKS 100
#define MAX_NO_FILES 20

typedef struct File
{
    int file_id;
    int index_block;
}File;

void showBitVector(int bitVector[] , int n)
{
    printf("Bit vector is :");
    for(int i =0; i<n; i++)
    {
        printf("%d " , bitVector[i]);
    }
    printf("\n");
}

void showDirectory(File directory[] , int *total_files)
{
    printf("Directory is :");
    for(int i =0; i<*total_files; i++)
    {
        printf("\nFile ID : %d" , directory[i].file_id);
        printf("\nIndex block:%d" , directory[i].index_block);
    }
    printf("\n");
}
void createNewFile(File directory[], int *total_files, int n, int bitVector[])
{
    int file_id ,  index_block;
    printf("Enter file id :");
    scanf("%d" , &file_id);
    printf("Enter Index block :");
    scanf("%d" , &index_block);

    if(index_block <0 ||  index_block >=n)
    {
        printf("Enter valid index block");
        return;
    }
    else if(bitVector[index_block])
    {
        printf("index block already allocated");
        return;
    }

    bitVector[index_block] = 1;
    directory[*total_files].file_id = file_id;
    directory[*total_files].index_block = index_block;
    (*total_files)++;
    printf("Files created successfully"); 
}
void deleteFile(File directory[],int *total_files , int bitVector[])
{
    int file_id;
    printf("Enter file id");
    scanf("%d",&file_id);

    for(int i =0; i<*total_files; i++)
    {
        if(directory[i].file_id == file_id)
        {
            bitVector[directory[i].index_block] = 0;
            for(int j=i; j<*total_files; j++)
            {
                directory[j] = directory[j+1];
            }
            (*total_files)--;
            printf("File deleted successfully");
            return;
        }
    }
    printf("File not found");
}
int main()
{
    File directory[MAX_NO_FILES];
    int bitVector[MAX_NO_BLOCKS] = {0};
    int n;
    printf("Enter number of disk blocks :");
    scanf("%d" , &n);
    int total_files = 0,c;

    do {
        printf("\nMenu:\n");
        printf("1. Show Bit Vector\n");
        printf("2. Show Directory\n");
        printf("3. Create New File\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                showBitVector(bitVector, n);
                break;
            case 2:
                showDirectory(directory, &total_files);
                break;
            case 3:
                createNewFile(directory, &total_files, n, bitVector);
                break;
            case 4:
                deleteFile(directory, &total_files, bitVector);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (1);

    return 0;
}