#include <stdio.h>
#include <stdlib.h>
#include "SMS.h"

int main(){
  
    initStudentsQueue( );
    int choice;


    while (1) 
	{
        MAIN_MENU();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) 
		{
           
            case 1:
                NEW_STUDENT();
                break;

            case 2:
                DELETE_STUDENT();
                break;


            case 3:
                SEARCH_STUDENT();
                break;
    

            case 4:
                STUDENT_LIST();
                break;

            case 5:
                SORT_ALPHABETICALLY();
                break;

            case 6:
                STUDENT_EDIT();
                break;

            case 7:
                RANK_STUDENT();
                break;

            case 8:
                STUDENT_SCORE();
                break;    

            case 9:
                printf("Exiting the program. Goodbye!\n");
                return 0;
    

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}


 
