#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct items {
    char item[20];
    float price;
    int qty;
} items;

typedef struct orders{
    char customer[50];
    char date[50];
    int numOfItems;
    items itm[50];
} orders;

void generateBillHeader(char name[50], char date[30]) {
    printf("\n\n");
    printf("-----------------Restaurant---------------|");
    printf("\nDate:%s", date);
    printf("\nInvoice to: %s", name);
    printf("\n");
    printf("------------------------------------------|\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t\n");
    printf("------------------------------------------|");
    printf("\n\n");
}

void generateBillBody(char item[30], int qty, float price) {
    printf("%s\t\t", item);
    printf("%d\t\t", qty);
    printf("%.2f\t\t", qty * price);
    printf("\n");
}

void generateBillFooter(float total) {
    printf("\n");
    float dis = 0.1 * total;
    float netTotal = total - dis;
    float cgst = 0.09 * netTotal, grandTotal = netTotal + 2 * cgst;
    printf("------------------------------------------|\n");
    printf("Sub Total%s\t\t\t%.2f", "%", total);
    printf("\nDiscount @10%s\t\t\t%.2f","%", dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total \t\t\t%.2f", netTotal);
    printf("\nCGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\nSGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\n------------------------------------------|");
    printf("\nGrand Total\t\t\t%.2f", grandTotal);
    printf("\n------------------------------------------|\n");
}

void main() {
    int option, noItems;
    char customer[50];
    orders order, ord;
    char saveBill = 'y', contFlag = 'y';
    FILE *fp;
    while (contFlag == 'y') {
        system("clear");
        float Total; 
        int notFound = 0;
        printf("---------Restaurant----------");
        printf("\n[1].Generate Invoice\n[2].Show all invoices\n[3].Search invoice\n[4].Exit\n");
        
        printf("\nSelect Your Option: ");
        scanf("%d", &option);
        fgetc(stdin);

        switch(option) {
            case 1:
                system("clear");
                printf("\nEnter the name of the customer: ");
                fgets(order.customer, 50, stdin);
                order.customer[strlen(order.customer) - 1] = 0;
                strcpy(order.date, __DATE__);
                printf("\nEnter the number of items: ");
                scanf("%d", &noItems);
                order.numOfItems = noItems;

                for (int i=0; i < noItems; i++) {
                    fgetc(stdin);
                    printf("\nEnter item %d: ", i + 1);
                    fgets(order.itm[i].item, 20, stdin);
                    order.itm[i].item[strlen(order.itm[i].item) - 1] = 0;
                    printf("\nEnter the quantity: ");
                    scanf("%d", &order.itm[i].qty);
                    printf("\nEnter the unit price: ");
                    scanf("%f", &order.itm[i].price);
                    Total += order.itm[i].qty * order.itm[i].price; 
                }

                generateBillHeader(order.customer, order.date);
                for (int i = 0; i < order.numOfItems; i++) {
                    generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                }
                generateBillFooter(Total);

                printf("Do you want to save the invoice[y/n]: ");
                scanf("%s", &saveBill);

                if (saveBill == 'y') {
                    fp = fopen("RestaurantBill.txt", "a+");
                    fwrite(&order, sizeof(orders), 1, fp);
                    if (fwrite != 0) {
                        printf("\nSuccessfully saved\n");
                    }
                    else {
                        printf("\nError saving\n");
                        fclose(fp);
                        }
                }

                break;

            case 2:
                system("clear");
                fp = fopen("RestaurantBill.txt", "r");
                printf("\n-----------Previous Invoices--------------|\n");
                while (fread(&ord, sizeof(orders), 1, fp)) {
                    float total = 0;
                    generateBillHeader(ord.customer, ord.date);
                    for (int i = 0; i < ord.numOfItems; i++) {
                        generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
                        total += ord.itm[i].qty * ord.itm[i].price;
                    }
                    generateBillFooter(total);
                }
                fclose(fp);
                break;

            case 3:
                system("clear");
                printf("Enter the name of the customer: ");
                fgets(customer, 50, stdin);
                customer[strlen(customer) - 1] = 0;
                fp = fopen("RestaurantBill.txt", "r");
                printf("\n-----------Invoice for %s--------------|\n", customer);
                while (fread(&ord, sizeof(orders), 1, fp)) {
                    if (!strcmp(ord.customer, customer)) {
                        float total = 0;
                        generateBillHeader(ord.customer, ord.date);
                        for (int i = 0; i < ord.numOfItems; i++) {
                            generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
                            total += ord.itm[i].qty * ord.itm[i].price;
                        }
                        generateBillFooter(total);
                        notFound = 1;
                    }
                    if (!notFound) {
                        printf("Sorry, the invoice for %s does not exist\n", customer);
                    }
                }
                fclose(fp);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Sorry, invalid option");
                break;

        }
        printf("Do you want to continue[y/n]: ");
        scanf("%c", &contFlag);
    }
}
