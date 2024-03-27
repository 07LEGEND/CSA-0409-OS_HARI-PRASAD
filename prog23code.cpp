#include <stdio.h>

#define MAX_BLOCKS 50

int main() {
    int memory[MAX_BLOCKS];
    int num_blocks, num_processes, i, j;
    
    printf("Enter the number of memory blocks: ");
    scanf("%d", &num_blocks);
    
    printf("Enter the size of each memory block:\n");
    for (i = 0; i < num_blocks; i++) {
        scanf("%d", &memory[i]);
    }
    
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    
    int process[num_processes];
    int allocation[num_processes];
    
    printf("Enter the size of each process:\n");
    for (i = 0; i < num_processes; i++) {
        scanf("%d", &process[i]);
        allocation[i] = -1; // Initialize allocation array to -1 indicating not allocated
    }
    
    // First Fit Algorithm
    for (i = 0; i < num_processes; i++) {
        for (j = 0; j < num_blocks; j++) {
            if (memory[j] >= process[i]) {
                allocation[i] = j;
                memory[j] -= process[i];
                break;
            }
        }
    }
    
    printf("\nProcess\t   Process Size\tBlock No.\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t", i+1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    
    return 0;
}

