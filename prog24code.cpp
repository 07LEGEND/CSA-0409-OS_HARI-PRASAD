#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // Creating a new file
    fd = creat("file.txt", 0666);
    if (fd == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    } else {
        printf("File created successfully.\n");
    }

    // Writing to the file
    write(fd, "Hello, this is a sample text.", 28);

    // Closing the file
    close(fd);

    // Opening the file for reading
    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Reading from the file
    printf("Content of the file:\n");
    ssize_t num_bytes_read;
    while ((num_bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, num_bytes_read);
    }
    if (num_bytes_read == -1) {
        perror("Error reading from file");
        exit(EXIT_FAILURE);
    }

    // Closing the file
    close(fd);

    return 0;
}

