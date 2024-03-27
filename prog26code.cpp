#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "example.txt";
    char buffer[100];

    // Create a new file and open for writing
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    printf("File created and opened successfully for writing.\n");

    // Write to the file
    fputs("This is a test.\n", file);
    fputs("This is another line.\n", file);

    // Close the file
    fclose(file);
    printf("File closed successfully.\n");

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    printf("File opened successfully for reading.\n");

    // Read from the file
    printf("Content of the file:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);
    printf("File closed successfully.\n");

    return 0;
}

