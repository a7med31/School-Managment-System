#ifndef SMS_H
#define SMS_H

#include "STD_TYPES.h"
#define NAME_LENGTH        30
#define ADDRESS_LENGTH     30
#define PhoneNumber_LENGTH 15
#define DateOfBirth_LENGTH 15


typedef struct{
    uint8 Id;
    uint8 Name[NAME_LENGTH];
    uint8 DateOfBirth[DateOfBirth_LENGTH];
    uint8 PhoneNumber[PhoneNumber_LENGTH];
    uint8 Address[ADDRESS_LENGTH];
    uint8 CS_score;
}Student;

typedef struct Node{
    Student data;
    struct Node* next;
}Node;



typedef struct 
{
     Node* front;
     Node* rear;
}Queue;


void MAIN_MENU ();
void NEW_STUDENT();
void initStudentsQueue( );
void DELETE_STUDENT();
void swap(Node* node1, Node* node2);
void SORT_ALPHABETICALLY();
void STUDENT_LIST();
void STUDENT_EDIT();
void RANK_STUDENT();
void SEARCH_STUDENT();
void STUDENT_SCORE();

#endif



