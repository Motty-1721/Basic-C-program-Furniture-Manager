#include <stdio.h>
#include <time.h>
#include <strings.h>
#include <windows.h>

#define MAX_FURNITURE 8
#define MAX_NAME_LENGTH 50
#define MAX_NAME 50

void intro()
{
    time_t now;
    time(&now);
    printf("\n");
    printf("\n\t\t\t    ================Tagalog Furniture================");
    printf("\n\n\t\t\t\t\t%s", ctime(&now));
}

void displayMainMenu()
{
    intro();
    printf("\n\n\n\t\t\t\t          1.Buy Furnitures");
    printf("\n\n\t\t\t\t          2.See Furnitures ");
    printf("\n\n\t\t\t\t          3.Exit");
    printf("\n\n\t\t\t\t          Your option:");
}

void getFullName(char custName[MAX_NAME])
{
    printf("\n\n\t\t\t\t          Enter your Full Name:\n\t\t\t\t           ");
    scanf(" %[^\n]s", custName);
    getchar();
}

void displayAvailableFurniture(char names[MAX_FURNITURE][MAX_NAME_LENGTH], float prices[MAX_FURNITURE])
{
    intro();
    printf("\n\n\t\t\t         These are the Available Furniture:\n");
    for (int i = 0; i < MAX_FURNITURE; i++)
    {
        printf("\n\t\t\t         %d. %s - $%.2f\n", i + 1, names[i], prices[i]);
    }
}

void displayPurchases(char purchases[MAX_FURNITURE][MAX_NAME_LENGTH], float purchasePrices[MAX_FURNITURE], int purchaseCount, float total)
{
    system("cls");
    intro();
    printf("\n\n\t\t\t\t        These are your purchases:\n\n");
    for (int i = 0; i < purchaseCount; i++)
    {
        printf("\t\t\t\t        Item: %s, Price: $%.2f\n", purchases[i], purchasePrices[i]);
    }
    printf("\n\n\t\t\t\t        Total Price: $%.2f\n", total);
}

int main()
{
    time_t now;
    time(&now);
    int cont = 1, option, selection, purchaseCount = 0;
    char purchaseOpt;
    char custName[MAX_NAME];
    char names[MAX_FURNITURE][MAX_NAME_LENGTH] = {"Chair", "Table", "Sofa", "Bed", "Desk", "Shelf", "Cabinet", "Dresser"};
    float prices[MAX_FURNITURE] = {29.99, 99.99, 399.99, 499.99, 79.99, 59.99, 149.99, 199.99};
    float total = 0.0;
    char purchases[MAX_FURNITURE][MAX_NAME_LENGTH];
    float purchasePrices[MAX_FURNITURE];
	
	intro();
	getFullName(custName);
    while (cont != 0)
    {
    	balik2:
        system("cls");
        displayMainMenu();
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            system("cls");
            {
                do
                {	
                	balik:
                    system("cls");
                    displayAvailableFurniture(names, prices);

                    printf("\n\t\t\t         Enter the number of the furniture you want to purchase: ");
                    scanf("%d", &selection);
                    getchar();

                    if (selection < 1 || selection > MAX_FURNITURE)
                    {
                    	system("cls");
                    	intro();
                        printf("\n\n\t\t\t        Invalid selection. Please try again.\n");
                        getchar();
                        goto balik;
                    }
                    strcpy(purchases[purchaseCount], names[selection - 1]);
                    purchasePrices[purchaseCount] = prices[selection - 1];
                    total += purchasePrices[purchaseCount];
                    purchaseCount++;

                    printf("\t\t\t\t          Do you want to add another purchase? (Y/N): ");
                    scanf(" %c", &purchaseOpt);
                    getchar();
                } while (purchaseOpt == 'Y' || purchaseOpt == 'y');

                FILE *file = fopen("purchases.txt", "a");
                if (file == NULL)
                {
                    printf("Error opening the file.\n");
                    return 1;
                }

                fprintf(file, "\nName: %s   Date: %s", custName, ctime(&now));
                for (int i = 0; i < purchaseCount; i++)
                {
                    fprintf(file, "Item: %s, Price: $%.2f\n", purchases[i], purchasePrices[i]);
                }
                fprintf(file, "\nTotal Price: $%.2f\n", total);

                displayPurchases(purchases, purchasePrices, purchaseCount, total);
                fclose(file);
            }
            break;

        case 2:
            system("cls");
            displayAvailableFurniture(names, prices);
            break;

        case 3:
            cont = 0;
            system("cls");
            printf("\n\t\t\t    ================Thank You for Patronizing================\n");
            break;

        default:
        	system("cls");
        	intro();
            printf("\n\n\t\t\t\t    Invalid Option!");
            getchar();
            goto balik2;
            break;
        }

        if (option != 3)
        {
            printf("\n\n\n\t\t\t\t     [0] if No\n\t\t\t\t     [1] if Yes");
            printf("\n\t\t\t\t     Do you want to perform another transaction?: ");
            scanf("%d", &cont);
        }
    }
    system("cls");
    printf("\n\t\t\t    ================Thank You for Patronizing================\n");
    return 0;
}