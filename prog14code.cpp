#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

// Structure to represent a file
struct File {
    char name[MAX_FILENAME_LENGTH];
};

int main() {
    struct File files[MAX_FILES]; // Array of file structures
    int numFiles = 0; // Number of files currently in the directory
    int choice;

    while (1) {
        printf("\n1. Add a file\n");
        printf("2. List all files\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numFiles >= MAX_FILES) {
                    printf("Directory is full!\n");
                } else {
                    printf("Enter file name: ");
                    scanf("%s", files[numFiles].name);
                    numFiles++;
                    printf("File added successfully.\n");
                }
                break;
            case 2:
                if (numFiles == 0) {
                    printf("Directory is empty!\n");
                } else {
                    printf("Files in directory:\n");
                    for (int i = 0; i < numFiles; i++) {
                        printf("%d. %s\n", i + 1, files[i].name);
                    }
                }
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

