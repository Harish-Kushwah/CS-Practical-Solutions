// *Indexed File Allocation*

#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 50
#define MAX_FILES 10

typedef struct File {
    int fileId;
    int indexBlock;
} File;

void showBitVector(int f[], int n) {
    printf("Bit Vector: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", f[i]);
    }
    printf("\n");
}

void showDirectory(File directory[], int p) {
    printf("Directory:\n");
    for (int i = 0; i < p; i++) {
        printf("File %d - Index Block: %d\n", directory[i].fileId, directory[i].indexBlock);
    }
}

void createNewFile(File directory[], int *p, int n, int f[]) {
    int fileId, indexBlock;
    char buffer[50];  // Buffer for input

    printf("Enter file ID: ");
    if (scanf("%s", buffer) == 1 && sscanf(buffer, "%d", &fileId) == 1) {
        printf("Enter index block: ");
        scanf("%d", &indexBlock);

        if (indexBlock >= 0 && indexBlock < n) {
            if (f[indexBlock] == 0) {
                f[indexBlock] = 1;
                directory[*p].fileId = fileId;
                directory[*p].indexBlock = indexBlock;
                (*p)++;
                printf("File %d created successfully.\n", fileId);
            } else {
                printf("Index block %d is already allocated.\n", indexBlock);
            }
        } else {
            printf("Invalid index block.\n");
        }
    } else {
        printf("Invalid file ID. Please enter a valid integer.\n");
    }
}

void deleteFile(File directory[], int *p, int f[]) {
    int fileId;
    printf("Enter the file ID to delete: ");
    scanf("%d", &fileId);

    int fileIndex = -1;
    for (int i = 0; i < *p; i++) {
        if (directory[i].fileId == fileId) {
            fileIndex = i;
            break;
        }
    }

    if (fileIndex != -1) {
        int indexBlock = directory[fileIndex].indexBlock;
        f[indexBlock] = 0;
        printf("File %d deleted successfully.\n", fileId);

        for (int i = fileIndex; i < *p - 1; i++) {
            directory[i] = directory[i + 1];
        }

        (*p)--;
    } else {
        printf("File not found.\n");
    }
}

int main() {
    File directory[MAX_FILES];
    int p = 0, n, c;
    int bitVector[MAX_BLOCKS] = {0};

    printf("Enter the number of blocks on the disk: ");
    scanf("%d", &n);

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
                showDirectory(directory, p);
                break;
            case 3:
                createNewFile(directory, &p, n, bitVector);
                break;
            case 4:
                deleteFile(directory, &p, bitVector);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (1);

    return 0;
}