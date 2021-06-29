/********************************************************************************
 * Author: Ahsan Haleem
 * Assignment: 2 (COMP 2401)
 * Project Name: Inventory System
 * Purpose: This program will keep track of different products, their price, and the current
 *                number of units in stock. It will also allow the end user to print the entire
 *                inventory, add stock to the inventory, and buy products.
 * Source file: It has all the functions that run the user interaction actions, like printing
 *                     inventory, printing user's cart, add stock, buy product.
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"

#define success 1 // for successful operation
#define fail 0    // for failed operation

/*
    Function:  displayInventory
    Purpose:   displaying the inventory of a store
       in: inventory: Single pointer on inventory that is used to print
    return:  a number for success or failure (0 or 1)
*/
int displayInventory(Inventory *inventory)
{
  // Checking NULL pointer parameter
  if (inventory == NULL)
  {
      printf("\n  Error: parameter pointer is NULL!\n");
      return fail;
  }

    if ((inventory == NULL) || (inventory->productArr == NULL))
    {
        return fail;
    }
    printf("\n\n\t\t ****** INVENTORY ******\n");
    printf("----------------------------------------------------------------------\n");
    printf(" | PRODUCT ID |      PRODUCT NAME      |   QUANTITY   |    PRICE    | \n");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < inventory->productArr->numProducts; i++)
    {
        printf("   #%-5d       %-20s       %-5dunits      %-3.2f each   \n", inventory->productArr->products[i]->id, inventory->productArr->products[i]->name, inventory->productArr->products[i]->quantity, inventory->productArr->products[i]->price);
    }

    return success;
}

/*
    Function:  addStock
    Purpose:   adding stock of an existing product in the inventory of a store
       in/out: inventory: Single pointer on inventory that is used to modify the quantity of
                            existing product in it.
    return:  a number for success or failure (0 or 1)
*/
int addStock(Inventory *inventory)
{
  // Checking NULL pointer parameter
  if (inventory == NULL)
  {
      printf("\n  Error: parameter pointer is NULL!\n");
      return fail;
  }

    int id = 0, quantity = 0;

    // Prompting user for id and number of units
    printf("\nEnter an existing product id: ");
    scanf("%d", &id);
    printf("\nEnter the product's quantity to be add: ");
    scanf("%d", &quantity);
    printf("\n");

    // Finding the corresponding product in the product array
    for (int i = 0; i < inventory->productArr->numProducts; i++)
    {
        if ((inventory->productArr->products[i]->id != id) && (i == (inventory->productArr->numProducts - 1)))
        {
            printf("\n  Error: invalid ID of a non-existing product.\n");
            return fail;
        }
        else if(inventory->productArr->products[i]->id == id)
        {
          inventory->productArr->products[i]->quantity += quantity;
          break;
        }
    }

    return success;
}


/*
    Function:  buyProduct
    Purpose:   to allow user to buy an existing product from the inventory of a store
       in/out: inventory: Single pointer on product that is used to print
       in/out: runningTotal: value for total amount after buying a product
    return:  a number for success or failure (0 or 1)
*/
int buyProduct(Inventory *inventory, float running_total)
{
  // Checking NULL pointer parameter
  if (inventory == NULL)
  {
      printf("\n  Error: parameter pointer is NULL!\n");
      return fail;
  }

    int id = 0;

    // Prompting user for id and number of units
    printf("\nEnter an existing product id: ");
    scanf("%d", &id);
    printf("\n");
    // Finding the corresponding product in the product array
    for (int i = 0; i < inventory->productArr->numProducts; i++)
    {
        if ((inventory->productArr->products[i]->id != id) && (i == (inventory->productArr->numProducts - 1)))
        {
            printf("\n  Error: invalid ID of a non-existing product that was added!\n");
            return fail;
        }
        else if (inventory->productArr->products[i]->id == id)
        {
            inventory->productArr->products[i]->quantity--;
            running_total += inventory->productArr->products[i]->price;
            printCart(running_total, inventory->productArr->products[i]->name);
            break;
        }
    }
    return running_total;
}

/*
    Function:  printCart
    Purpose:   This function prints the cart for the user to see his/her total cost
       in: total: the total cost of all the items in the cart
       in: name: single pointer to name to point to it's value
    return:  nothing
*/
void printCart(float total, char *name)
{
  // Checking NULL pointer parameter
  if (name == NULL)
  {
      printf("\n  Error: name parameter pointer is NULL!\n");
  }

    if (total > 0.0) {
        printf("\n  After adding %s in the cart, your total is $%.2f \n",  name, total);
    }
}

/*
    Function:  printTotal
    Purpose:   This function prints the cart for the user to see his/her total cost
       in: total: the total cost of all the items in the cart
    return:  nothing
*/
void printTotal(float total)
{
    if (total > 0.0) {
        printf("\n  Thank you for shopping, your total is $%.2f \n", total);
    }
}
