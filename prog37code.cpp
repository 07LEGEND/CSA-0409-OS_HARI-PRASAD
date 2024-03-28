#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

void fcfs(int initial_head, int requests[], int total_requests) {
    int current_head = initial_head;
    int total_movement = 0;

    printf("Sequence of head movement:\n");
    printf("%d -> ", current_head);

    for (int i = 0; i < total_requests; i++) {
        total_movement += abs(current_head - requests[i]);
        current_head = requests[i];
        printf("%d -> ", current_head);
    }

    printf("\nTotal head movement: %d\n", total_movement);
}

int main() {
    int initial_head;
    int total_requests;
    int requests[MAX_REQUESTS];

    printf("Enter the initial position of the head: ");
    scanf("%d", &initial_head);

    printf("Enter the total number of requests: ");
    scanf("%d", &total_requests);

    printf("Enter the requests:\n");
    for (int i = 0; i < total_requests; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }

    fcfs(initial_head, requests, total_requests);

    return 0;
}

