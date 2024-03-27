#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3 // Maximum number of frames in memory

int main() {
    int reference_string[] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2}; // Reference string
    int num_pages = sizeof(reference_string) / sizeof(reference_string[0]);
    int frames[MAX_FRAMES];
    int page_faults = 0;
    int oldest_frame = 0; // Index to track the oldest frame

    // Initialize frames to -1, indicating empty frames
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    // Simulate FIFO page replacement algorithm
    for (int i = 0; i < num_pages; i++) {
        int page = reference_string[i];
        int page_found = 0;

        // Check if page is already in memory
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                page_found = 1;
                break;
            }
        }

        // If page is not in memory, replace the oldest page
        if (!page_found) {
            frames[oldest_frame] = page;
            oldest_frame = (oldest_frame + 1) % MAX_FRAMES; // Update index of oldest frame
            page_faults++;
        }

        // Print current state of frames after each page reference
        printf("Page reference %d: ", page);
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == -1)
                printf(" - ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal page faults: %d\n", page_faults);

    return 0;
}

