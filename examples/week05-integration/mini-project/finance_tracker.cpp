/*
 * Mini-Project: Personal Finance Tracker
 *
 * Track income and expenses, categorize transactions,
 * and see where your money goes.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_TRANSACTIONS = 500;
const string FILENAME = "transactions.txt";

struct Transaction {
    string date;
    string description;
    double amount;      // Positive = income, negative = expense
    string category;
};

// Function prototypes
int loadTransactions(Transaction trans[]);
void saveTransactions(Transaction trans[], int count);
void printMenu();
void addTransaction(Transaction trans[], int& count);
void listTransactions(Transaction trans[], int count);
void categorySummary(Transaction trans[], int count);
void showBalance(Transaction trans[], int count);

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int count = loadTransactions(transactions);

    cout << "=== Personal Finance Tracker ===" << endl;
    cout << "Loaded " << count << " transactions." << endl;

    // Show current balance on startup
    double balance = 0;
    for (int i = 0; i < count; i++) {
        balance += transactions[i].amount;
    }
    cout << "Current balance: $" << fixed << setprecision(2) << balance << endl;
    cout << endl;

    int choice;
    do {
        printMenu();
        cin >> choice;
        cin.ignore();
        cout << endl;

        switch (choice) {
            case 1: addTransaction(transactions, count); break;
            case 2: listTransactions(transactions, count); break;
            case 3: categorySummary(transactions, count); break;
            case 4: showBalance(transactions, count); break;
            case 5:
                saveTransactions(transactions, count);
                cout << "Saved to " << FILENAME << endl;
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
        cout << endl;

    } while (choice != 5);

    return 0;
}

void printMenu() {
    cout << "1. Add transaction" << endl;
    cout << "2. List transactions" << endl;
    cout << "3. Category summary" << endl;
    cout << "4. Show balance" << endl;
    cout << "5. Save and quit" << endl;
    cout << "Choice: ";
}

// TODO: Implement file loading
// File format: date|description|amount|category
int loadTransactions(Transaction trans[]) {
    ifstream inFile(FILENAME);
    if (!inFile) return 0;

    int count = 0;
    string line;

    while (getline(inFile, line) && count < MAX_TRANSACTIONS) {
        // TODO: Parse the line into fields
        // Hint: Use find() and substr() to split on '|'
        // Or read field by field using getline with '|' delimiter

        // Example parsing approach:
        // size_t pos1 = line.find('|');
        // trans[count].date = line.substr(0, pos1);
        // ... continue parsing ...



        count++;
    }

    inFile.close();
    return count;
}

// TODO: Implement file saving
// Save in format: date|description|amount|category
void saveTransactions(Transaction trans[], int count) {
    ofstream outFile(FILENAME);
    if (!outFile) {
        cerr << "Error saving transactions!" << endl;
        return;
    }

    // TODO: Write each transaction
    // Format: date|description|amount|category


    outFile.close();
}

// TODO: Implement add transaction
void addTransaction(Transaction trans[], int& count) {
    if (count >= MAX_TRANSACTIONS) {
        cout << "Transaction list is full!" << endl;
        return;
    }

    cout << "Date (YYYY-MM-DD): ";
    getline(cin, trans[count].date);

    cout << "Description: ";
    getline(cin, trans[count].description);

    cout << "Amount (negative for expense): $";
    cin >> trans[count].amount;
    cin.ignore();

    cout << "Category: ";
    getline(cin, trans[count].category);

    count++;
    cout << "Transaction added!" << endl;
}

// TODO: Implement list transactions
void listTransactions(Transaction trans[], int count) {
    if (count == 0) {
        cout << "No transactions yet." << endl;
        return;
    }

    cout << "=== All Transactions ===" << endl;
    // TODO: Print each transaction nicely formatted


}

// TODO: Implement category summary
// Group transactions by category and show totals
void categorySummary(Transaction trans[], int count) {
    if (count == 0) {
        cout << "No transactions to summarize." << endl;
        return;
    }

    cout << "=== Category Summary ===" << endl;

    // Simple approach: keep track of unique categories and their sums
    // This is a bit tricky without more advanced data structures
    // One approach: for each transaction, search if we've seen its category

    string categories[50];
    double sums[50];
    int numCategories = 0;

    // TODO: Loop through transactions, accumulate by category


    // TODO: Print the summary

}

// TODO: Implement show balance
void showBalance(Transaction trans[], int count) {
    double income = 0;
    double expenses = 0;

    // TODO: Sum up income (positive) and expenses (negative) separately


    cout << "=== Balance ===" << endl;
    cout << "Total income:   $" << fixed << setprecision(2) << income << endl;
    cout << "Total expenses: $" << fixed << setprecision(2) << (-expenses) << endl;
    cout << "-------------------" << endl;
    cout << "Net balance:    $" << fixed << setprecision(2) << (income + expenses) << endl;
}

/*
 * Hints:
 *
 * Loading (parsing "|" delimited):
 *   getline(inFile, trans[count].date, '|');
 *   getline(inFile, trans[count].description, '|');
 *   inFile >> trans[count].amount;
 *   inFile.ignore();  // Skip the |
 *   getline(inFile, trans[count].category);
 *
 * Saving:
 *   outFile << trans[i].date << "|"
 *           << trans[i].description << "|"
 *           << trans[i].amount << "|"
 *           << trans[i].category << endl;
 *
 * Category summary approach:
 *   for each transaction:
 *     search categories[] for this category
 *     if found, add amount to corresponding sums[]
 *     if not found, add new category and initialize sum
 */
