/********************************************************************************
 * Author: Ahsan Haleem
 * Assignment: 2 (COMP 2401)
 * Project Name: Inventory System
 * Purpose: This program will keep track of different products, their price, and the current
 *                number of units in stock. It will also allow the end user to print the entire
 *                inventory, add stock to the inventory, and buy products.
 * Header file: It has all the function prototypes and data type definitions.
 *******************************************************************************/
#define MAX_NUM 100 // Maximum number of projects
#define MAX_STR 32  // Maximum length of a string

typedef struct ProductType
{
  int   id;                       // Product identification number
  char  name[MAX_STR];            // Name of the product
  float price;                    // Price of the product
  int   quantity;                 // Number of units of the product (currently in inventory)
} Product;

typedef struct ProductArrType
{
  Product *products[MAX_NUM];       // Products array
  int     numProducts;             // Number of products in a product array
  int     next_id;                 // Product ID for the next product
} ProductArr;

typedef struct InventoryType
{
  char       storeName[MAX_STR];    // Store name
  ProductArr *productArr;           // Producct array's pointer
} Inventory;

// External functions used my the main program
extern void menu();
extern int initProductArr(Inventory *, char *, float, int);
extern int initInventory(Inventory *);
extern int populateProductTen(Inventory *);
extern int displayInventory(Inventory *);
extern int addStock(Inventory *);
extern int buyProduct(Inventory *, float);
extern void printCart(float total, char*);
extern void printTotal(float total);
extern void freeMemory (Inventory *);
