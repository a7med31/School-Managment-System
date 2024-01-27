#include <stdio.h>
#include <stdlib.h>
#include "SMS.h"
#include <string.h>

Queue StudentsQueue;

   void initStudentsQueue(){
    StudentsQueue.front =NULL;
    StudentsQueue.rear =NULL;
   }




void MAIN_MENU (){
    printf("\n********************************************************\n");
    printf("\tWelcome to the School Management System\n");
    printf("********************************************************\n");
    printf("1. Create a new student\n");
    printf("2. Remove an existing student\n");
    printf("3. Check details of an existing student\n");
    printf("4. View student list\n");
    printf("5. Sort students Alphabetically\n");
    printf("6. Update information of an existing student\n");
    printf("7. Rank students\n");
    printf("8. Update student score\n");
    printf("9. Exit\n");


}


void NEW_STUDENT() {
    Node *newStudent = (Node *)malloc(sizeof(Node));

    if (newStudent != NULL) {
        printf("Please enter the Student Information\n");

        printf("Id: ");
        scanf("%d", &(newStudent->data.Id));
        while (getchar() != '\n'); // Clear the input buffer

        printf("Name: ");
        fgets(newStudent->data.Name, NAME_LENGTH, stdin);
        newStudent->data.Name[strcspn(newStudent->data.Name, "\n")] = '\0'; // Remove newline

        printf("Date of Birth(dd/mm/yyyy): ");
        fgets(newStudent->data.DateOfBirth, DateOfBirth_LENGTH, stdin);
        newStudent->data.DateOfBirth[strcspn(newStudent->data.DateOfBirth, "\n")] = '\0'; // Remove newline

        printf("Phone Number: ");
        fgets(newStudent->data.PhoneNumber, PhoneNumber_LENGTH, stdin);
        newStudent->data.PhoneNumber[strcspn(newStudent->data.PhoneNumber, "\n")] = '\0'; // Remove newline

        printf("Address: ");
        fgets(newStudent->data.Address, ADDRESS_LENGTH, stdin);
        newStudent->data.Address[strcspn(newStudent->data.Address, "\n")] = '\0'; // Remove newline

        printf("Computer Science Score: ");
        scanf("%d", &(newStudent->data.CS_score));
        while (getchar() != '\n'); // Clear the input buffer

        newStudent->next = NULL;

        if (StudentsQueue.rear == NULL) {
            StudentsQueue.front = newStudent;
            StudentsQueue.rear = newStudent;
        } else {
            StudentsQueue.rear->next = newStudent;
            StudentsQueue.rear = newStudent;
        }

        printf("Student added successfully.\n");
    } else {
        printf("Error in Memory Allocation: Student not added successfully\n");
    }
}

   

void DELETE_STUDENT(){
    uint8 id;
    Node* current = StudentsQueue.front;
    Node* previous = NULL;

    printf("Enter the ID of the student to delete: ");
    scanf("%d", &id);
   
    

    while (current != NULL) {
        if (current->data.Id == id) {
            if (current == StudentsQueue.front) {
                StudentsQueue.front = current->next;
                free(current);
            } else if (current == StudentsQueue.rear) {
                StudentsQueue.rear = previous;
                previous->next = NULL;
                free(current);
            } else {
                previous->next = current->next;
                free(current);
            }
            printf("Student with Id %d deleted successfully.\n", id);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Student with ID %d not found.\n", id);

}

void swap(Node* node1, Node* node2) {
    Student temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void SORT_ALPHABETICALLY() {
    int flag;
    Node* last = NULL;

    do {
        flag = 0;
        Node* current = StudentsQueue.front;
        while (current->next != last) {
            if (strcmp(current->data.Name, current->next->data.Name) > 0) {
                swap(current, current->next);
                flag = 1;
            }
            current = current->next;
        }
        last = current;
    } while (flag);
}


void STUDENT_LIST() {
    Node* current = StudentsQueue.front;

    if (current == NULL) {
        printf("No students found.\n");
        return;
    }

    printf("\n");
    printf("%-10s%-20s%-20s%-20s%-20s%-20s\n", "ID", "Name", "Date of Birth","Address","Phone","Score");
    printf("------------------------------------------------------------------------------------------------------\n");

    while (current != NULL) {
        printf("%-10d%-20s%-20s%-20s%-20s%-20d\n",
               current->data.Id,
               current->data.Name,
               current->data.DateOfBirth,
               current->data.Address,
               current->data.PhoneNumber,
               current->data.CS_score);

        // Move to the next node
        current = current->next;

        // Check if there are more nodes, and if so, print empty lines
        if (current != NULL) {
            printf("\t\t\t\t\t\n");
        }
    }
}


void STUDENT_EDIT() {
    int id;
    Node* current = StudentsQueue.front;

    printf("Enter Student Id to Edit: ");
    scanf("%d", &id);
    while (getchar() != '\n'); 


    while (current != NULL) {
        if (current->data.Id == id) {
            printf("Enter Student Name: ");
            fgets(current->data.Name, sizeof(current->data.Name), stdin);
            current->data.Name[strcspn(current->data.Name, "\n")] = '\0'; 

            printf("Enter Date of Birth (dd/mm/yyyy): ");
            fgets(current->data.DateOfBirth, DateOfBirth_LENGTH, stdin);
            current->data.DateOfBirth[strcspn(current->data.DateOfBirth, "\n")] = '\0'; // Remove newline


            printf("Enter Address: ");
            fgets(current->data.Address, sizeof(current->data.Address), stdin);
            current->data.Address[strcspn(current->data.Address, "\n")] = '\0';

            printf("Enter Phone Number: ");
            fgets(current->data.PhoneNumber, PhoneNumber_LENGTH, stdin);
            current->data.PhoneNumber[strcspn(current->data.PhoneNumber, "\n")] = '\0';

            printf("Enter Computer Science Score: ");
            scanf("%d", &(current->data.CS_score));
            while (getchar() != '\n'); 

            printf("Student details updated successfully.\n");
            return;
        }

        current = current->next;
    }

    printf("Student with ID %d not found.\n", id);
}

void RANK_STUDENT(){

    int flag;
    Node* last = NULL;

    do {
        flag = 0;
        Node* current = StudentsQueue.front;
        while (current->next != last) {
            if (current->data.CS_score < current->next->data.CS_score) {
                swap(current, current->next);
                flag = 1;
            }
            current = current->next;
        }
        last = current;
    } while (flag);
}

void SEARCH_STUDENT() {
    int id;
    printf("Enter the Id of the student to find: ");
    scanf("%d", &id);
    Node* current = StudentsQueue.front;

    while (current != NULL) {
        if (current->data.Id == id) {
            printf("\n");
            printf("%-10s%-20s%-20s%-20s%-20s%-20s\n", "ID", "Name", "Date of Birth","Address","Phone","Score");
            printf("-------------------------------------------------------------------------------------------------\n");
            printf("%-10d%-20s%-20s%-20s%-20s%-20d\n",
                   current->data.Id,
                   current->data.Name,
                   current->data.DateOfBirth,
                   current->data.Address,
                   current->data.PhoneNumber,
                   current->data.CS_score);
            return;
        }

        current = current->next;
    }

    printf("Student with Id %d not found.\n", id);
}

void STUDENT_SCORE() {
     Node* current = StudentsQueue.front;
     int id;
     printf("Enter the Id of the student: ");
     scanf("%d", &id);

    while (current != NULL) {
        if (current->data.Id == id) {
            printf("Enter Computer Science Score for Student Id %d: ", id);
            scanf("%d", &current->data.CS_score);
            printf("Computer Science Score for Student Id %d updated successfully.\n", id);
            return;
        }

        current = current->next;
    }

    printf("Student with ID %d not found.\n", id);
}











