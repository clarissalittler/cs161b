/*
 * inventory_manager.cpp
 * A complete inventory management system.
 *
 * This program demonstrates integration of:
 * - Structs (Product)
 * - Arrays (product inventory)
 * - Functions (modular design)
 * - File I/O (persistence)
 *
 * Study the structure: how it's organized, how pieces connect.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  // For formatting output
using namespace std;

// =============== DATA STRUCTURES ===============

struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

const int MAX_PRODUCTS = 100;
const string FILENAME = "inventory.dat";

// =============== FUNCTION PROTOTYPES ===============

// File operations
int loadInventory(Product products[]);
void saveInventory(Product products[], int count);

// Display operations
void printMenu();
void listProducts(Product products[], int count);
void showProduct(const Product& p);

// CRUD operations
void addProduct(Product products[], int& count);
int findProduct(Product products[], int count, int id);
void updateQuantity(Product products[], int count);
void searchByName(Product products[], int count);

// Reports
void showInventoryValue(Product products[], int count);

// =============== MAIN ===============

int main() {
    Product inventory[MAX_PRODUCTS];
    int productCount = loadInventory(inventory);

    cout << "=== Inventory Manager ===" << endl;
    cout << "Loaded " << productCount << " products." << endl << endl;

    int choice;
    do {
        printMenu();
        cin >> choice;
        cin.ignore();
        cout << endl;

        switch (choice) {
            case 1: listProducts(inventory, productCount); break;
            case 2: addProduct(inventory, productCount); break;
            case 3: updateQuantity(inventory, productCount); break;
            case 4: searchByName(inventory, productCount); break;
            case 5: showInventoryValue(inventory, productCount); break;
            case 6:
                saveInventory(inventory, productCount);
                cout << "Inventory saved. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
        cout << endl;

    } while (choice != 6);

    return 0;
}

// =============== MENU ===============

void printMenu() {
    cout << "1. List all products" << endl;
    cout << "2. Add product" << endl;
    cout << "3. Update quantity" << endl;
    cout << "4. Search by name" << endl;
    cout << "5. Inventory value report" << endl;
    cout << "6. Save and quit" << endl;
    cout << "Choice: ";
}

// =============== FILE I/O ===============

int loadInventory(Product products[]) {
    ifstream inFile(FILENAME);
    if (!inFile) return 0;

    int count = 0;
    while (count < MAX_PRODUCTS &&
           inFile >> products[count].id
                  >> products[count].quantity
                  >> products[count].price) {
        inFile.ignore();  // Skip space
        getline(inFile, products[count].name);
        count++;
    }

    inFile.close();
    return count;
}

void saveInventory(Product products[], int count) {
    ofstream outFile(FILENAME);
    if (!outFile) {
        cerr << "Error: Could not save inventory." << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        // Format: id quantity price name
        outFile << products[i].id << " "
                << products[i].quantity << " "
                << products[i].price << " "
                << products[i].name << endl;
    }

    outFile.close();
}

// =============== DISPLAY ===============

void showProduct(const Product& p) {
    cout << setw(5) << p.id << " | "
         << setw(20) << left << p.name << right << " | "
         << setw(5) << p.quantity << " | $"
         << fixed << setprecision(2) << setw(8) << p.price << endl;
}

void listProducts(Product products[], int count) {
    if (count == 0) {
        cout << "No products in inventory." << endl;
        return;
    }

    cout << "  ID  | Name                 |   Qty | Price" << endl;
    cout << "------+----------------------+-------+-----------" << endl;

    for (int i = 0; i < count; i++) {
        showProduct(products[i]);
    }
}

// =============== CRUD OPERATIONS ===============

void addProduct(Product products[], int& count) {
    if (count >= MAX_PRODUCTS) {
        cout << "Inventory is full!" << endl;
        return;
    }

    Product& p = products[count];  // Reference for convenience

    cout << "Enter product ID: ";
    cin >> p.id;
    cin.ignore();

    // Check if ID already exists
    if (findProduct(products, count, p.id) != -1) {
        cout << "Error: Product ID already exists." << endl;
        return;
    }

    cout << "Enter product name: ";
    getline(cin, p.name);

    cout << "Enter quantity: ";
    cin >> p.quantity;

    cout << "Enter price: $";
    cin >> p.price;

    count++;
    cout << "Product added!" << endl;
}

int findProduct(Product products[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            return i;
        }
    }
    return -1;  // Not found
}

void updateQuantity(Product products[], int count) {
    int id;
    cout << "Enter product ID to update: ";
    cin >> id;

    int index = findProduct(products, count, id);
    if (index == -1) {
        cout << "Product not found." << endl;
        return;
    }

    cout << "Current quantity: " << products[index].quantity << endl;
    cout << "Enter change (+/- amount): ";

    int change;
    cin >> change;

    products[index].quantity += change;
    if (products[index].quantity < 0) {
        products[index].quantity = 0;
    }

    cout << "Updated. New quantity: " << products[index].quantity << endl;
}

void searchByName(Product products[], int count) {
    string searchTerm;
    cout << "Search for: ";
    getline(cin, searchTerm);

    cout << endl << "Results:" << endl;
    bool found = false;

    for (int i = 0; i < count; i++) {
        // Simple substring search
        if (products[i].name.find(searchTerm) != string::npos) {
            showProduct(products[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "No products found matching '" << searchTerm << "'" << endl;
    }
}

// =============== REPORTS ===============

void showInventoryValue(Product products[], int count) {
    double totalValue = 0;
    int totalItems = 0;

    cout << "=== Inventory Value Report ===" << endl << endl;

    for (int i = 0; i < count; i++) {
        double value = products[i].quantity * products[i].price;
        totalValue += value;
        totalItems += products[i].quantity;

        cout << products[i].name << ": "
             << products[i].quantity << " x $" << products[i].price
             << " = $" << fixed << setprecision(2) << value << endl;
    }

    cout << endl;
    cout << "Total items: " << totalItems << endl;
    cout << "Total value: $" << fixed << setprecision(2) << totalValue << endl;
}
