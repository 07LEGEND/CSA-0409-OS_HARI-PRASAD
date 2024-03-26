#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES_PER_DIR 100
#define MAX_DIRS 100
#define MAX_FILENAME_LENGTH 50
#define MAX_DIRNAME_LENGTH 50

// Structure to represent a file
struct File {
    char name[MAX_FILENAME_LENGTH];
};

// Structure to represent a directory
struct Directory {
    char name[MAX_DIRNAME_LENGTH];
    struct File files[MAX_FILES_PER_DIR];
    int numFiles;
};

// Array of directories
struct Directory directories[MAX_DIRS];
int numDirs = 0;

// Function to create a new directory
void createDirectory(char *name) {
    if (numDirs >= MAX_DIRS) {
        printf("Maximum directories reached!\n");
        return;
    }
    strcpy(directories[numDirs].name, name);
    directories[numDirs].numFiles = 0;
    numDirs++;
    printf("Directory '%s' created successfully.\n", name);
}

// Function to add a file to a directory
void addFileToDirectory(char *dirName, char *fileName) {
    int i;
    for (i = 0; i < numDirs; i++) {
        if (strcmp(directories[i].name, dirName) == 0) {
            if (directories[i].numFiles >= MAX_FILES_PER_DIR) {
                printf("Maximum files reached in directory '%s'!\n", dirName);
                return;
            }
            strcpy(directories[i].files[directories[i].numFiles].name, fileName);
            directories[i].numFiles++;
            printf("File '%s' added to directory '%s'.\n", fileName, dirName);
            return;
        }
    }
    printf("Directory '%s' not found!\n", dirName);
}

// Function to list all files in a directory
void listFilesInDirectory(char *dirName) {
    int i;
    for (i = 0; i < numDirs; i++) {
        if (strcmp(directories[i].name, dirName) == 0) {
            printf("Files in directory '%s':\n", dirName);
            for (int j = 0; j < directories[i].numFiles; j++) {
                printf("%d. %s\n", j + 1, directories[i].files[j].name);
            }
            return;
        }
    }
    printf("Directory '%s' not found!\n", dirName);
}

int main() {
    int choice;
    char dirName[MAX_DIRNAME_LENGTH], fileName[MAX_FILENAME_LENGTH];

    while (1) {
        printf("\n1. Create Directory\n");
        printf("2. Add File to Directory\n");
        printf("3. List Files in Directory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter directory name: ");
                scanf("%s", dirName);
                createDirectory(dirName);
                break;
            case 2:
                printf("Enter directory name: ");
                scanf("%s", dirName);
                printf("Enter file name: ");
                scanf("%s", fileName);
                addFileToDirectory(dirName, fileName);
                break;
            case 3:
                printf("Enter directory name: ");
                scanf("%s", dirName);
                listFilesInDirectory(dirName);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

