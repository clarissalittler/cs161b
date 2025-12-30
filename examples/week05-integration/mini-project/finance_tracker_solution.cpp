/*
 * Mini-Project: Personal Finance Tracker (Solution)
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
    double amount;
    string category;
};

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

int loadTransactions(Transaction trans[]) {
    ifstream inFile(FILENAME);
    if (!inFile) return 0;

    int count = 0;

    while (count < MAX_TRANSACTIONS) {
        if (!getline(inFile, trans[count].date, '|')) break;
        if (!getline(inFile, trans[count].description, '|')) break;
        if (!(inFile >> trans[count].amount)) break;
        if (inFile.peek() == '|') {
            inFile.ignore();
        }
        getline(inFile, trans[count].category);
        count++;
    }

    inFile.close();
    return count;
}

void saveTransactions(Transaction trans[], int count) {
    ofstream outFile(FILENAME);
    if (!outFile) {
        cerr << "Error saving transactions!" << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        outFile << trans[i].date << "|"
                << trans[i].description << "|"
                << trans[i].amount << "|"
                << trans[i].category << endl;
    }

    outFile.close();
}

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

void listTransactions(Transaction trans[], int count) {
    if (count == 0) {
        cout << "No transactions yet." << endl;
        return;
    }

    cout << "=== All Transactions ===" << endl;
    cout << left << setw(12) << "Date" << " | "
         << setw(20) << "Description" << " | "
         << right << setw(10) << "Amount" << " | "
         << left << "Category" << endl;
    cout << string(60, '-') << endl;

    for (int i = 0; i < count; i++) {
        cout << left << setw(12) << trans[i].date << " | "
             << setw(20) << trans[i].description << " | "
             << right << setw(10) << fixed << setprecision(2) << trans[i].amount << " | "
             << left << trans[i].category << endl;
    }
}

void categorySummary(Transaction trans[], int count) {
    if (count == 0) {
        cout << "No transactions to summarize." << endl;
        return;
    }

    cout << "=== Category Summary ===" << endl;

    string categories[50];
    double sums[50];
    int numCategories = 0;

    for (int i = 0; i < count; i++) {
        int foundIndex = -1;
        for (int j = 0; j < numCategories; j++) {
            if (categories[j] == trans[i].category) {
                foundIndex = j;
                break;
            }
        }

        if (foundIndex >= 0) {
            sums[foundIndex] += trans[i].amount;
        } else if (numCategories < 50) {
            categories[numCategories] = trans[i].category;
            sums[numCategories] = trans[i].amount;
            numCategories++;
        }
    }

    for (int i = 0; i < numCategories; i++) {
        cout << categories[i] << ": " << fixed << setprecision(2) << sums[i] << endl;
    }
}

void showBalance(Transaction trans[], int count) {
    double income = 0;
    double expenses = 0;

    for (int i = 0; i < count; i++) {
        if (trans[i].amount >= 0) {
            income += trans[i].amount;
        } else {
            expenses += trans[i].amount;
        }
    }

    cout << "=== Balance ===" << endl;
    cout << "Total income:   $" << fixed << setprecision(2) << income << endl;
    cout << "Total expenses: $" << fixed << setprecision(2) << (-expenses) << endl;
    cout << "-------------------" << endl;
    cout << "Net balance:    $" << fixed << setprecision(2) << (income + expenses) << endl;
}
