#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct User {
    int account_number;
    char first_name[50];
    char last_name[50];
    char date_of_birth[20];
    char address[50];
    char contact[50];
    

} User;
int accNo = 1;

void menu() {
    printf("Welcome to the main menu\n");
    printf("[1] Create a new account\n[2] Update information of existing account\n[3] Transactions\n[4] Check details of existing account\n[5] Removing existing account\n[6] View customer's list\n[7] Exit\n");
}

void display_user(User user) {
    printf("\nAccount Number: %d\n", user.account_number);
    printf("First Name: %s", user.first_name);
    printf("Last Name: %s", user.last_name);
    printf("Date Of Birth: %s", user.date_of_birth);
    printf("Address: %s", user.address);
    printf("Contact: %s", user.contact);
}

void create_account(int accNo, User user, FILE *fp) {
            user.account_number = accNo;
            accNo+=1;
            printf("Enter your details below\n");
            fgetc(stdin);
            printf("Enter your first_name: ");
            fgets(user.first_name, 50, stdin);
            printf("Enter your last name: ");
            fgets(user.last_name, 50, stdin);
            printf("Enter date of birth: ");
            fgets(user.date_of_birth, 20, stdin);
            printf("Enter address: ");
            fgets(user.address,50, stdin);
            printf("Enter your contact: ");
            fgets(user.contact,50, stdin);

            fp = fopen("Users.txt", "a+");
            fwrite(&user, sizeof(user), 1, fp);
            if (fwrite != 0) {
                printf("\nSuccessfully created account\n");
                display_user(user);
            }
            else {
                printf("\nError creating account\n");
                fclose(fp);
            }
}

void edit() {

}

void main() {
    menu();
    int choice, query_id, notFound = 0;
    User user, query;
    FILE *fp, *bd;
    printf("\nEnter Your Choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            system("clear");
            create_account(accNo, user, fp);
            break;

        case 2:
            system("clear");
            printf("Enter the account number: ");
            scanf("%d", &query_id);
            fp = fopen("Users.txt", "r");
            while(fread(&query, sizeof(user), 1, fp)) {
                if (query.account_number == query_id) {
                    display_user(query);
                    notFound = 1;
                    break;
                }
                if (!notFound) {
                    printf("Sorry, the account number does not exist\n");
                 }
            }
            fclose(fp);
            break;

    }
}