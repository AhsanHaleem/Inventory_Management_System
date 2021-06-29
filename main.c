/********************************************************************************
 * Author: Ahsan Haleem
 * Assignment: 2 (COMP 2401)
 * Project Name: Inventory System
 * Purpose: This program will keep track of different products, their price, and the current
 *               number of units in stock. It will also allow the end user to print the entire
 *               inventory, add stock to the inventory, and buy products.
 * Main source file: It has one function to run the whole program by calling all the other
 *                            functions from other files (user_interaction, inventory).
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"

#define success 1 // for successful operation
#define fail 0    // for failed operation

int main()
{

    int option = 0;
    float runningTotal = 0;

    Inventory *inventory = (Inventory*) malloc(sizeof(Inventory));
    // Check if allocation was successful
    if (inventory == NULL)
    {
        printf("Error: could not allocate memory for Inventory structure.\n");
        return fail;
    }
    strcpy(inventory->storeName,"\0");
    initInventory(inventory);
    initProductArr(inventory, "KitKat", 1.29, 9558);
    populateProductTen(inventory);

    do
    {
      menu();
      scanf("%d", &option);
      switch(option) {

        case 1 : // Print the current inventory
            displayInventory(inventory);
            break;
        case 2 : // Add stock of a product
            addStock(inventory);
            break;
        case 3 : // Buy a product
            runningTotal += buyProduct(inventory, runningTotal);
            break;
        default :
            if(option != 0){
                printf("Invalid option! Please select a valid option.\n");
            }
            break;
      }
    } while (option != 0);
    printTotal(runningTotal);

    freeMemory(inventory);

    return 0;
}
