#include <stdio.h>

#define MEMORY_SIZE 100

struct MemoryBlock {
    int size;
    int allocated;
};

void initializeMemory(struct MemoryBlock memory[], int size);
void displayMemory(struct MemoryBlock memory[], int size);
void firstFit(struct MemoryBlock memory[], int size, int processSize);
void bestFit(struct MemoryBlock memory[], int size, int processSize);
void worstFit(struct MemoryBlock memory[], int size, int processSize);

int main() {
    struct MemoryBlock memory[MEMORY_SIZE];
    int processSize;

    initializeMemory(memory, MEMORY_SIZE);

    printf("Initial Memory State:\n");
    displayMemory(memory, MEMORY_SIZE);

    printf("Enter the size of the process: ");
    scanf("%d", &processSize);
    printf("\nFirst Fit:\n");
    firstFit(memory, MEMORY_SIZE, processSize);
    displayMemory(memory, MEMORY_SIZE);

    initializeMemory(memory, MEMORY_SIZE);

    printf("\nBest Fit:\n");
    bestFit(memory, MEMORY_SIZE, processSize);
    displayMemory(memory, MEMORY_SIZE);

    initializeMemory(memory, MEMORY_SIZE);

    printf("\nWorst Fit:\n");
    worstFit(memory, MEMORY_SIZE, processSize);
    displayMemory(memory, MEMORY_SIZE);

    return 0;
}

void initializeMemory(struct MemoryBlock memory[], int size) {
    for (int i = 0; i < size; i++) {
        memory[i].size = 0;
        memory[i].allocated = 0;
    }
}

void displayMemory(struct MemoryBlock memory[], int size) {
    printf("Memory: ");
    for (int i = 0; i < size; i++) {
        printf("[%d:%d] ", memory[i].size, memory[i].allocated);
    }
    printf("\n");
}

void firstFit(struct MemoryBlock memory[], int size, int processSize) {
    for (int i = 0; i < size; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            memory[i].allocated = 1;
            break;
        }
    }
}

void bestFit(struct MemoryBlock memory[], int size, int processSize) {
    int bestFitIndex = -1;
    int bestFitSize = MEMORY_SIZE + 1;

    for (int i = 0; i < size; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            if (memory[i].size < bestFitSize) {
                bestFitSize = memory[i].size;
                bestFitIndex = i;
            }
        }
    }

    if (bestFitIndex != -1) {
        memory[bestFitIndex].allocated = 1;
    }
}

void worstFit(struct MemoryBlock memory[], int size, int processSize) {
    int worstFitIndex = -1;
    int worstFitSize = -1;

    for (int i = 0; i < size; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            if (memory[i].size > worstFitSize) {
                worstFitSize = memory[i].size;
                worstFitIndex = i;
            }
        }
    }

    if (worstFitIndex != -1) {
        memory[worstFitIndex].allocated = 1;
    }
}
