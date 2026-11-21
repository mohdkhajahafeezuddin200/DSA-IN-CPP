
#include <stdio.h>
#include <string.h>

#define MAX 100
#define LOW_STOCK 5

struct Product {
    int product_id;
    char name[50];
    float price;
    int quantity;
    char category[30];
};

struct Product products[MAX];
int count = 0;

// Function declarations
void addProduct();
void displayInventory();
void searchProduct();
void updateStock();
void sellProduct();
void lowStockAlert();
void calculateInventoryValue();
void sortProducts();
void saveInventory();
void loadInventory();

// Add product
void addProduct() {
    if (count >= MAX) {
        printf("\nInventory is full!\n");
        return;
    }

    struct Product p;
    int duplicate = 0;

    printf("\nEnter Product ID: ");
    scanf("%d", &p.product_id);

    for (int i = 0; i < count; i++) {
        if (products[i].product_id == p.product_id) {
            duplicate = 1;
            break;
        }
    }

    if (duplicate) {
        printf("\nProduct ID already exists!\n");
        return;
    }

    printf("Enter Product Name: ");
    scanf(" %49[^\n]", p.name);

    printf("Enter Category: ");
    scanf(" %29[^\n]", p.category);

    printf("Enter Price: ");
    scanf("%f", &p.price);

    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);

    if (p.price < 0 || p.quantity < 0) {
        printf("\nInvalid price or quantity!\n");
        return;
    }

    products[count++] = p;

    printf("\nProduct added successfully!\n");

    saveInventory();
}

// Display inventory
void displayInventory() {
    if (count == 0) {
        printf("\nInventory is empty!\n");
        return;
    }

    printf("\n========== INVENTORY DETAILS ==========\n");

    printf("%-10s %-20s %-15s %-10s %-10s\n",
           "ID", "Name", "Category", "Price", "Quantity");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-15s %-10.2f %-10d\n",
               products[i].product_id,
               products[i].name,
               products[i].category,
               products[i].price,
               products[i].quantity);
    }
}

// Search product by ID or name
void searchProduct() {
    int choice, id, found = 0;
    char name[50];

    printf("\n1. Search by Product ID");
    printf("\n2. Search by Product Name");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Product ID: ");
        scanf("%d", &id);

        for (int i = 0; i < count; i++) {
            if (products[i].product_id == id) {
                printf("\nProduct Found!\n");
                printf("ID: %d\n", products[i].product_id);
                printf("Name: %s\n", products[i].name);
                printf("Category: %s\n", products[i].category);
                printf("Price: %.2f\n", products[i].price);
                printf("Quantity: %d\n", products[i].quantity);
                found = 1;
                break;
            }
        }
    }
    else if (choice == 2) {
        printf("Enter Product Name: ");
        scanf(" %49[^\n]", name);

        for (int i = 0; i < count; i++) {
            if (strcmp(products[i].name, name) == 0) {
                printf("\nProduct Found!\n");
                printf("ID: %d\n", products[i].product_id);
                printf("Name: %s\n", products[i].name);
                printf("Category: %s\n", products[i].category);
                printf("Price: %.2f\n", products[i].price);
                printf("Quantity: %d\n", products[i].quantity);
                found = 1;
                break;
            }
        }
    }
    else {
        printf("\nInvalid choice!\n");
        return;
    }

    if (!found) {
        printf("\nProduct not found!\n");
    }
}

// Update stock after purchase
void updateStock() {
    int id, quantity, found = 0;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (products[i].product_id == id) {
            printf("Enter quantity to add: ");
            scanf("%d", &quantity);

            if (quantity <= 0) {
                printf("\nInvalid quantity!\n");
                return;
            }

            products[i].quantity += quantity;

            printf("\nStock updated successfully!\n");
            found = 1;
            saveInventory();
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found!\n");
    }
}

// Sell product
void sellProduct() {
    int id, quantity, found = 0;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (products[i].product_id == id) {
            printf("Available Quantity: %d\n",
                   products[i].quantity);

            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);

            if (quantity <= 0) {
                printf("\nInvalid quantity!\n");
                return;
            }

            if (quantity > products[i].quantity) {
                printf("\nInsufficient stock!\n");
                return;
            }

            products[i].quantity -= quantity;

            printf("\nSale successful!\n");
            printf("Total Amount: Rs. %.2f\n",
                   products[i].price * quantity);

            found = 1;
            saveInventory();

            if (products[i].quantity < LOW_STOCK) {
                printf("\nWARNING: Low Stock!\n");
            }

            break;
        }
    }

    if (!found) {
        printf("\nProduct not found!\n");
    }
}

// Low stock alert
void lowStockAlert() {
    int found = 0;

    printf("\n========== LOW STOCK PRODUCTS ==========\n");

    for (int i = 0; i < count; i++) {
        if (products[i].quantity < LOW_STOCK) {
            printf("\nProduct ID: %d", products[i].product_id);
            printf("\nProduct Name: %s", products[i].name);
            printf("\nAvailable Quantity: %d\n",
                   products[i].quantity);

            found = 1;
        }
    }

    if (!found) {
        printf("\nNo low-stock products!\n");
    }
}

// Calculate total inventory value
void calculateInventoryValue() {
    float total = 0;

    for (int i = 0; i < count; i++) {
        total += products[i].price * products[i].quantity;
    }

    printf("\nTotal Inventory Value: Rs. %.2f\n", total);
}

// Sort products
void sortProducts() {
    int choice;
    struct Product temp;

    printf("\n1. Sort by Quantity");
    printf("\n2. Sort by Price");
    printf("\n3. Sort by Name");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("\nInvalid choice!\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            int swap = 0;

            if (choice == 1 &&
                products[j].quantity > products[j + 1].quantity)
                swap = 1;

            else if (choice == 2 &&
                     products[j].price > products[j + 1].price)
                swap = 1;

            else if (choice == 3 &&
                     strcmp(products[j].name,
                            products[j + 1].name) > 0)
                swap = 1;

            if (swap) {
                temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }

    printf("\nProducts sorted successfully!\n");
    displayInventory();

    saveInventory();
}

// Save inventory to binary file
void saveInventory() {
    FILE *fp = fopen("inventory.dat", "wb");

    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    fwrite(products, sizeof(struct Product), count, fp);

    fclose(fp);

    printf("\nInventory saved successfully!\n");
}

// Load inventory from binary file
void loadInventory() {
    FILE *fp = fopen("inventory.dat", "rb");

    if (fp == NULL) {
        return;
    }

    count = 0;

    while (count < MAX &&
           fread(&products[count],
                 sizeof(struct Product), 1, fp) == 1) {
        count++;
    }

    fclose(fp);
}

// Main function
int main() {
    int choice;

    loadInventory();

    do {
        printf("\n\n====== INVENTORY MANAGEMENT SYSTEM ======\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Search Product\n");
        printf("4. Update Stock\n");
        printf("5. Sell Product\n");
        printf("6. Low Stock Alert\n");
        printf("7. Calculate Inventory Value\n");
        printf("8. Sort Products\n");
        printf("9. Save Inventory\n");
        printf("10. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;

            case 2:
                displayInventory();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateStock();
                break;

            case 5:
                sellProduct();
                break;

            case 6:
                lowStockAlert();
                break;

            case 7:
                calculateInventoryValue();
                break;

            case 8:
                sortProducts();
                break;

            case 9:
                saveInventory();
                break;

            case 10:
                saveInventory();
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 10);

    return 0;
}
