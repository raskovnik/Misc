#include <stdio.h>

typedef struct dob {
    int dd;
    int mm;
    int yyyy;
} DOB;

typedef struct User {
    char first_name[50];
    char last_name[50];
    DOB date_of_birth;
    char address[50];
    char contact[50];
    

} User;

void menu() {
    printf("Welcome to the main menu\n");
    printf("[1] Create a new account\n[2] Update information of existing account\n[3] Transactions\n[4] Check details of existing account\n[5] Removing existing account\n[6] View customer's list\n[7] Exit\n");
}

void create_account() {

}
void main() {
    menu();
    printf("\nEnter Your Choice: ");
}
