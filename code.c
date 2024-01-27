#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char dob[MAX_NAME_LENGTH];
    char id[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Student;

Student students[MAX_STUDENTS];
int numStudents = 0;
int scores[MAX_STUDENTS];

void MAIN_MENU();
void NEW_STUDENT();
void DELETE_STUDENT();
void STUDENT_LIST();
void STUDENT_EDIT();
void RANK_STUDENT();
void STUDENT_SCORE();

void MAIN_MENU() {
    printf("Welcome to the School Management System\n");
    printf("1. Create a new student\n");
    printf("2. Update information of an existing student\n");
    printf("3. View and manage scores\n");
    printf("4. Check details of an existing student\n");
    printf("5. Remove an existing student\n");
    printf("6. View student list\n");
    printf("7. Rank students\n");
    printf("8. Exit\n");
}

void NEW_STUDENT() {
    if (numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    printf("Enter student's name: ");
    fgets(students[numStudents].name, MAX_NAME_LENGTH, stdin);
    printf("Enter student's date of birth: ");
    fgets(students[numStudents].dob, MAX_NAME_LENGTH, stdin);
    printf("Enter student's ID: ");
    fgets(students[numStudents].id, MAX_NAME_LENGTH, stdin);
    printf("Enter student's address: ");
    fgets(students[numStudents].address, MAX_ADDRESS_LENGTH, stdin);
    printf("Enter student's phone number: ");
    fgets(students[numStudents].phone, MAX_PHONE_LENGTH, stdin);

    scores[numStudents] = 0;  // Initialize score to 0 for the new student

    numStudents++;

    printf("New student created successfully.\n");
}

void DELETE_STUDENT() {
    char id[MAX_NAME_LENGTH];
    printf("Enter student's ID to delete: ");
    fgets(id, MAX_NAME_LENGTH, stdin);

    int i;
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].id, id) == 0) {
            int j;
            for (j = i; j < numStudents - 1; j++) {
                strcpy(students[j].name, students[j + 1].name);
                strcpy(students[j].dob, students[j + 1].dob);
                strcpy(students[j].id, students[j + 1].id);
                strcpy(students[j].address, students[j + 1].address);
                strcpy(students[j].phone, students[j + 1].phone);
                scores[j] = scores[j + 1];
            }

            numStudents--;

            printf("Student deleted successfully.\n");
            return;
        }
    }

    printf("Student not found.\n");
}

void STUDENT_LIST() {
    int i, j;
    Student temp;

    for (i = 0; i < numStudents - 1; i++) {
        for (j = 0; j < numStudents - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("Student List:\n");
    printf("%-20s %-15s %-10s %-20s %-15s\n", "Name", "Date of Birth", "ID", "Address", "Phone Number");
    for (i = 0; i < numStudents; i++) {
        printf("%-20s %-15s %-10s %-20s %-15s\n", students[i].name, students[i].dob, students[i].id, students[i].address, students[i].phone);
    }
}

void STUDENT_EDIT() {
    char id[MAX_NAME_LENGTH];
    printf("Enter student's ID to edit: ");
    fgets(id, MAX_NAME_LENGTH, stdin);

    int i;
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("Student found. Enter new details.\n");
            printf("Enter student's name: ");
            fgets(students[i].name, MAX_NAME_LENGTH, stdin);
            printf("Enter student's date of birth: ");
            fgets(students[i].dob, MAX_NAME_LENGTH, std

            printf("Enter student's address: ");
            fgets(students[i].address, MAX_ADDRESS_LENGTH, stdin);
            printf("Enter student's phone number: ");
            fgets(students[i].phone, MAX_PHONE_LENGTH, stdin);

            printf("Student details updated successfully.\n");
            return;
        }
    }

    printf("Student not found.\n");
}

void RANK_STUDENT() {
    int i, j;
    Student temp;
    int tempScore;

    for (i = 0; i < numStudents - 1; i++) {
        for (j = 0; j < numStudents - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;

                tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;
            }
        }
    }

    printf("Student Rankings (by Computer Science score):\n");
    printf("%-10s %-20s %-10s %-20s %-15s\n", "ID", "Name", "Score", "Date of Birth", "Phone Number");
    for (i = 0; i < numStudents; i++) {
        printf("%-10s %-20s %-10d %-20s %-15s\n", students[i].id, students[i].name, scores[i], students[i].dob, students[i].phone);
    }
}

void STUDENT_SCORE() {
    char id[MAX_NAME_LENGTH];
    printf("Enter student's ID to update score: ");
    fgets(id, MAX_NAME_LENGTH, stdin);

    int i;
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("Enter student's new score: ");
            scanf("%d", &scores[i]);
            getchar();  // Consume newline character

            printf("Student score updated successfully.\n");
            return;
        }
    }

    printf("Student not found.\n");
}

int main() {
    int choice;

    do {
        MAIN_MENU();
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                NEW_STUDENT();
                break;
            case 2:
                STUDENT_EDIT();
                break;
            case 3:
                STUDENT_SCORE();
                break;
            case 4:
                // Function to check details of an existing student
                break;
            case 5:
                DELETE_STUDENT();
                break;
            case 6:
                STUDENT_LIST();
                break;
            case 7:
                RANK_STUDENT();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}