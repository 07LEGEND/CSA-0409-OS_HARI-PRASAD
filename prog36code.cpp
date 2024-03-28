#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

typedef struct Block {
    int block_number;
    struct Block *next;
} Block;

typedef struct File {
    int file_number;
    Block *first_block;
    Block *last_block;
} File;

Block blocks[MAX_BLOCKS];
File files[MAX_BLOCKS];

int total_blocks = 0;
int total_files = 0;

void initialize() {
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        blocks[i].block_number = i;
        blocks[i].next = NULL;
    }
}

File* create_file() {
    if (total_files >= MAX_BLOCKS) {
        printf("Maximum number of files reached.\n");
        return NULL;
    }

    File *new_file = &files[total_files];
    new_file->file_number = total_files;
    new_file->first_block = NULL;
    new_file->last_block = NULL;
    total_files++;
    return new_file;
}

void allocate_block(File *file, int block_number) {
    if (total_blocks >= MAX_BLOCKS) {
        printf("Maximum number of blocks reached.\n");
        return;
    }

    Block *new_block = &blocks[total_blocks];
    new_block->block_number = block_number;
    new_block->next = NULL;

    if (file->first_block == NULL) {
        file->first_block = new_block;
        file->last_block = new_block;
    } else {
        file->last_block->next = new_block;
        file->last_block = new_block;
    }

    total_blocks++;
}

void display_file_allocation(File *file) {
    if (file == NULL) {
        printf("File not found.\n");
        return;
    }

    printf("File %d: ", file->file_number);
    Block *current_block = file->first_block;
    while (current_block != NULL) {
        printf("%d ", current_block->block_number);
        current_block = current_block->next;
    }
    printf("\n");
}

int main() {
    initialize();

    File *file1 = create_file();
    File *file2 = create_file();

    allocate_block(file1, 1);
    allocate_block(file1, 2);
    allocate_block(file1, 3);
    allocate_block(file2, 4);
    allocate_block(file2, 5);

    printf("File allocation details:\n");
    display_file_allocation(file1);
    display_file_allocation(file2);

    return 0;
}

