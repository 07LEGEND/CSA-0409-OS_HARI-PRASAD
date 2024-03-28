#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    // Create a file with some content
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }
    fprintf(file, "This is a test file.\n");
    fclose(file);

    // Change file permissions to read-only for owner, group, and others
    if (chmod("example.txt", S_IRUSR | S_IRGRP | S_IROTH) != 0) {
        perror("Error changing file permissions");
        return 1;
    }

    // Print file permissions
    struct stat file_stat;
    if (stat("example.txt", &file_stat) != 0) {
        perror("Error getting file stat");
        return 1;
    }
    printf("File Permissions: %o\n", file_stat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));

    // Try to read the file
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        perror("Error reading file");
        return 1;
    }
    printf("Content of the file: %s", buffer);
    fclose(file);

    // Try to write to the file (should fail due to read-only permissions)
    file = fopen("example.txt", "a");
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }
    if (fprintf(file, "This line should not be written.\n") < 0) {
        perror("Error writing to file");
        return 1;
    }
    fclose(file);

    return 0;
}

