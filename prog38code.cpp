#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100
#define MAX_TRACKS 1000

// Function to sort the requests in ascending order
void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to simulate SCAN disk scheduling algorithm
void scan(int initial_head, int requests[], int total_requests, int max_tracks, int direction) {
    int current_head = initial_head;
    int total_movement = 0;
    int i;

    printf("Sequence of head movement:\n");
    printf("%d -> ", current_head);

    if (direction == 0) { // Towards lower numbered tracks
        // Service requests before the initial head position
        for (i = initial_head - 1; i >= 0; i--) {
            if (requests[i] != -1) {
                total_movement += abs(current_head - requests[i]);
                current_head = requests[i];
                requests[i] = -1; // Mark request as serviced
                printf("%d -> ", current_head);
            }
        }

        // Service requests after the initial head position
        for (i = initial_head; i < max_tracks; i++) {
            if (requests[i] != -1) {
                total_movement += abs(current_head - requests[i]);
                current_head = requests[i];
                requests[i] = -1; // Mark request as serviced
                printf("%d -> ", current_head);
            }
        }
    } else { // Towards higher numbered tracks
        // Service requests after the initial head position
        for (i = initial_head; i < max_tracks; i++) {
            if (requests[i] != -1) {
                total_movement += abs(current_head - requests[i]);
                current_head = requests[i];
                requests[i] = -1; // Mark request as serviced
                printf("%d -> ", current_head);
            }
        }

        // Service requests before the initial head position
        for (i = initial_head - 1; i >= 0; i--) {
            if (requests[i] != -1) {
                total_movement += abs(current_head - requests[i]);
                current_head = requests[i];
                requests[i] = -1; // Mark request as serviced
                printf("%d -> ", current_head);
            }
        }
    }

    printf("\nTotal head movement: %d\n", total_movement);
}

int main() {
    int initial_head;
    int total_requests;
    int requests[MAX_REQUESTS];
    int max_tracks;
    int direction;

    printf("Enter the initial position of the head: ");
    scanf("%d", &initial_head);

    printf("Enter the total number of requests: ");
    scanf("%d", &total_requests);

    printf("Enter the maximum number of tracks: ");
    scanf("%d", &max_tracks);

    printf("Enter the requests:\n");
    for (int i = 0; i < total_requests; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }

    printf("Enter the direction (0 for towards lower tracks, 1 for towards higher tracks): ");
    scanf("%d", &direction);

    sort(requests, total_requests); // Sort requests in ascending order

    scan(initial_head, requests, total_requests, max_tracks, direction);

    return 0;
}

