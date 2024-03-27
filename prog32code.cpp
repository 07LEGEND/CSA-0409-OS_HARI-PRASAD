#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3 // Maximum number of frames in memory

// Node structure for doubly linked list to maintain page access history
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->prev = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to move a node to the front of the list
void moveToFront(struct Node** head, struct Node* node) {
    if (*head == node) {
        return;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    node->next = *head;
    node->prev = NULL;
    (*head)->prev = node;
    *head = node;
}

int main() {
    int reference_string[] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2}; // Reference string
    int num_pages = sizeof(reference_string) / sizeof(reference_string[0]);
    struct Node* frames[MAX_FRAMES] = {NULL}; // Array of pointers to the frames
    int page_faults = 0;

    // Simulate LRU page replacement algorithm
    for (int i = 0; i < num_pages; i++) {
        int page = reference_string[i];
        int page_found = 0;

        // Check if page is already in memory
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] != NULL && frames[j]->data == page) {
                page_found = 1;
                moveToFront(&frames[0], frames[j]); // Move the found page to the front of the list
                break;
            }
        }

        // If page is not in memory, replace the least recently used page
        if (!page_found) {
            page_faults++;
            if (frames[MAX_FRAMES - 1] != NULL) {
                struct Node* temp = frames[MAX_FRAMES - 1];
                frames[MAX_FRAMES - 1] = NULL;
                free(temp);
            }
            // Shift frames to the right
            for (int j = MAX_FRAMES - 2; j >= 0; j--) {
                frames[j + 1] = frames[j];
            }
            frames[0] = createNode(page); // Add new page to the front
        }

        // Print current state of frames after each page reference
        printf("Page reference %d: ", page);
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == NULL)
                printf(" - ");
            else
                printf("%d ", frames[j]->data);
        }
        printf("\n");
    }

    printf("\nTotal page faults: %d\n", page_faults);

    // Free memory allocated for frames
    for (int i = 0; i < MAX_FRAMES; i++) {
        struct Node* current = frames[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}

