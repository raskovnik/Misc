#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Contact {
    char name[20];
    char number[14];
    char address[20];
    char email[30];
} Contact;

void printMenu() {
    printf("[1] Add a new contact\n");
    printf("[2] List all contacts\n");
    printf("[3] Search for contact\n");
    printf("[4] Edit a contact\n");
    printf("[5] Delete a contact\n");
    printf("[0] Exit\n");
}

void displayContact(Contact contact) {
    printf("Contact Name: %s", contact.name);
    printf("Contact Number: %s", contact.number);
    printf("Contact Address: %s", contact.address);
    printf("Contact Email: %s", contact.email);
    printf("\n");
}

void addContact(Contact contact) {
    FILE *fp;
    char save_choice;
    printf("Enter contact name: ");
    fgets(contact.name, 20, stdin);
    printf("Enter phone number: ");
    fgets(contact.number, 14, stdin);
    printf("Enter contact address: ");
    fgets(contact.address, 20, stdin);
    printf("Enter contact email address: ");
    fgets(contact.email, 30, stdin);
    printf("\n");

    displayContact(contact);
    printf("Do you want to save this contact?[y/n] ");
    scanf("%c", &save_choice);
    if (save_choice == 'y') {
        fp = fopen("Contacts.txt", "a+");
        fwrite(&contact, sizeof(Contact), 1, fp);
        if (fwrite != 0) {
            printf("\nSuccessfully saved contact\n");
        }
        else {
            printf("\nError saving contact.\n");
        }
        fclose(fp);
    }
    else { system("clear");}
}

void searchContact(char *contactName) {
    Contact query;
    FILE *fp;
    fp  = fopen("Contacts.txt", "r");
    if (fp == NULL) {
        printf("You do not have any saved contacts yet!\n");
    }
    if (contactName == "ALL") {
        while(fread(&query, sizeof(query), 1, fp)) {
            displayContact(query);
        }
    }

    else{
        while(fread(&query, sizeof(query), 1, fp)) {
            if (strcmp(query.name, contactName) != 0) {
                displayContact(query);
                fclose(fp);
                break;
            }
        }
        printf("Sorry, couldn't find a match\n");
    }
    fclose(fp);
}


void main() {
    int choice;
    char *contactName;
    Contact contact, query;
    while (true) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fgetc(stdin);

        switch (choice) {
            case 1:
                system("clear");
                addContact(contact);
                break;

            case 2:
                system("clear");
                contactName = "ALL";
                searchContact(contactName);
                break;

            case 3:
                system("clear");
                printf("Enter the name of the contact to search: ");
                scanf("%s", contactName);
                printf("%s", contactName);
                searchContact(contactName);
                break;

            default:
                printf("Invalid Option\n");
                system("clear");
                break;
        }
    }
}