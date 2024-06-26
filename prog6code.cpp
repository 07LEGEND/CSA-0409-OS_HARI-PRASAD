#include<stdio.h>
struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
};

int findHighestPriority(struct Process processes[], int n, int current_time) {
    int highest_priority = -1;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
            if (highest_priority == -1 || processes[i].priority < highest_priority) {
                highest_priority = processes[i].priority;
                index = i;
            }
        }
    }

    return index;
}

void preemptivePriorityScheduling(struct Process processes[], int n) {
    int total_time = 0;
    int completed_processes = 0;

    printf("\nGantt Chart:\n");

    while (completed_processes < n) {
        int index = findHighestPriority(processes, n, total_time);

        if (index == -1) {
            printf("IDLE ");
            total_time++;
        } else {
            processes[index].remaining_time--;
            printf("P%d ", processes[index].process_id);
            total_time++;
            if (processes[index].remaining_time == 0) {
                completed_processes++;
            }
        }
    }

    printf("\n\n");
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];


    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter arrival time, burst time, and priority for process P%d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
    }

    preemptivePriorityScheduling(processes, n);

    return 0;
}
