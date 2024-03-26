#include <stdio.h>
#include <stdlib.h>

#define FILENAME "employee_details.dat"
#define MAX_EMPLOYEES 100

// Structure to represent an employee
struct Employee {
    int empId;
    char name[50];
    float salary;
};

// Function to add employee details to the file
void addEmployee() {
    struct Employee emp;
    FILE *fp;

    // Open the file in append mode
    fp = fopen(FILENAME, "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Input employee details
    printf("Enter employee ID: ");
    scanf("%d", &emp.empId);
    printf("Enter employee name: ");
    scanf("%s", emp.name);
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);

    // Write employee details to file
    fwrite(&emp, sizeof(struct Employee), 1, fp);

    // Close the file
    fclose(fp);

    printf("Employee details added successfully.\n");
}

// Function to display employee details from the file
void displayEmployees() {
    struct Employee emp;
    FILE *fp;
    int count = 0;

    // Open the file in read mode
    fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read and display employee details
    printf("\nEmployee Details:\n");
    printf("-------------------------------------------------\n");
    printf("ID\tName\t\tSalary\n");
    printf("-------------------------------------------------\n");
    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        printf("%d\t%s\t\t%.2f\n", emp.empId, emp.name, emp.salary);
        count++;
    }
    if (count == 0) {
        printf("No employees found.\n");
    }

    // Close the file
    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

