/********************************************************************************
 * Author: Ahsan Haleem
 * Assignment: 2 (COMP 2401)
 * Project Name: Inventory System
 * Purpose: This program will keep track of different products, their price, and the current
 *                number of units in stock. It will also allow the end user to print the entire
 *                inventory, add stock to the inventory, and buy products.
 * Source file: It has all the functions that run the inventory actions, like
 *                     initialize product, productArr and invertory, remove product.
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"

#define success 1   // for successful operation
#define fail 0      // for failed operation

/*
  Function:  Menu
  Purpose:   to print this beautiful menu for the user
       in/out: none
   return: none
*/
void menu()
{
  printf("\n");
  printf("\t ==========================================\n");
  printf("\t          PRODUCT INVENTORY SYSTEM\n");
  printf("\t ==========================================\n");

  printf("\n\nPress:");
  printf("\n 0.) Exit the program.");
  printf("\n 1.) Print the current inventory.");
  printf("\n 2.) Add stock of a product in the inventory.");
  printf("\n 3.) Buy a product from the inventory.");
  printf("\n\n Please enter your option: ");
}

/*
  Function:  initInventory
  Purpose:   initializing the inventory of a store
       in/out: inventory: Single pointer on product that is used and modified
   return:  a number for success or failure (0 or 1)
*/
int initInventory(Inventory *inventory)
{
  // Checking NULL pointer parameter
  if (inventory == NULL)
  {
      printf("\n  Error: parameter pointer is NULL!\n");
      return fail;
  }

    const char *storeName = "SCS STORE";
    strcpy(inventory->storeName, storeName);
    printf("\n\t ********** WELCOME TO %s **********\n", inventory->storeName);
    inventory->productArr = (ProductArr*) malloc(sizeof(ProductArr));

    // initializing all the values of productArr
    inventory->productArr->numProducts = 0;
    inventory->productArr->next_id = 1001;

    // Check if allocation was successful
    if (inventory->productArr == NULL)
    {
      printf("Error: could not allocate memory for productArr structure.\n");
      return fail;
    }
    return success;
}

/*
  Function:  initProduct
  Purpose:   initializing the product
       in/out: inventory:  Single pointer on product that is used and modified
       in: name: Single pointer on name that is used to get it's value
       in: price: Single pointer on name that is used to get it's value
       in: quantity: Single pointer on name that is used to point it's value
   return:  a number for success or failure (0 or 1)
*/
int initProductArr(Inventory *inventory, char *name, float price, int quantity)
{
  // Checking NULL pointer parameter
  if ((inventory == NULL) || (name == NULL))
  {
      printf("\n  Error: inventory or/and name parameter pointer is NULL!\n");
      return fail;
  }

    if(inventory->productArr->numProducts >= MAX_NUM)
    {
        printf("\nProducts' array is full!\n");
        return fail;
    }
    else
    {
      //dynamically allocate memory for a product
      inventory->productArr->products[inventory->productArr->numProducts] = malloc(sizeof(Product));
      // Check if allocation was successful
      if (inventory->productArr->products[inventory->productArr->numProducts] == NULL)
      {
        printf("Error: could not allocate memory for product structure.\n");
        return fail;
      }

      // Setting all the characteristics of the product
      inventory->productArr->products[inventory->productArr->numProducts]->id = inventory->productArr->next_id;
      strcpy(inventory->productArr->products[inventory->productArr->numProducts]->name, name);
      inventory->productArr->products[inventory->productArr->numProducts]->price = price;
      inventory->productArr->products[inventory->productArr->numProducts]->quantity = quantity;
      inventory->productArr->numProducts++;

      // Setting ID number for the next product
      inventory->productArr->next_id++;
      return success;
    }
}


/*
  Function:  populateProductTen
  Purpose: to dynamically allocate ten (10) different products, each with a different
                name, number of units, and price
    in/out: product: Single pointer on product array that is used and modified
    return:  a number for success or failure (0 or 1)
*/
int populateProductTen(Inventory *inventory)
{

  // Checking NULL pointer parameter
  if (inventory == NULL)
  {
      printf("\n  Error: parameter pointer is NULL!\n");
      return fail;
  }

    int numProducts = inventory->productArr->numProducts;

    char productName[10][30] = {"Coffee pack", "Tea pack", "Aluminum foil", "Potato Chip", "Soda drink", "All-purpose cleaner", "Cheese bottle", "Mix vegetable can", "Paper towel pack", "Candy bag"};
    float productPrice[10] = {14.99, 59.99, 12.97, 3.48, 12.47, 6.95, 6.48, 3.98, 19.88, 9.94};
    int productQuantity[10] = {433, 672, 209, 978, 591, 802, 980, 294, 319, 543};


    for(int i = numProducts; i < (numProducts + 10); i++)
    {
      //dynamically allocate memory for a product
      inventory->productArr->products[inventory->productArr->numProducts] = malloc(sizeof(Product));
      // Check if allocation was successful
      if (inventory->productArr->products[inventory->productArr->numProducts] == NULL)
      {
        printf("Error: could not allocate memory for product structure.\n");
        return fail;
      }

      // Setting all the characteristics of the product
      inventory->productArr->products[inventory->productArr->numProducts]->id = inventory->productArr->next_id;
      strcpy(inventory->productArr->products[inventory->productArr->numProducts]->name, productName[i-1]);
      inventory->productArr->products[inventory->productArr->numProducts]->price = productPrice[i-1];
      inventory->productArr->products[inventory->productArr->numProducts]->quantity = productQuantity[i-1];
      inventory->productArr->numProducts++;

      // Setting ID number for the next product
      inventory->productArr->next_id++;
    }
     return success;
}


/*
  Function:  Free
  Purpose: to free dynamically allocate memory after use from the inventory
    in/out: inventory: Single pointer on inventory that is used and modified
    return:  nothing
*/
void freeMemory (Inventory * inventory)
{
    for (int i = 0; i < inventory->productArr->numProducts; i++)
    {
      free(inventory->productArr->products[i]);
      inventory->productArr->products[i] = NULL;
    }
    free(inventory->productArr);
    inventory->productArr = NULL;
    free(inventory);
    inventory = NULL;
}
