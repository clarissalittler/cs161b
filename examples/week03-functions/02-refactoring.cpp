/*
 * 02-refactoring.cpp
 * Before and after: making code cleaner through refactoring.
 *
 * This file shows a messy "before" version and a cleaned-up "after" version
 * of the same program. Both do the exact same thing, but one is much
 * easier to read and maintain.
 */

#include <iostream>
#include <string>
using namespace std;

/*
 * ================================================================
 * THE "BEFORE" VERSION
 * This works, but it's hard to read and maintain
 * (Commented out so it doesn't conflict with the "after" version)
 * ================================================================

int main() {
    double p[100];
    int n = 0;
    int c;

    cout << "1. Add 2. View 3. Stats 4. Quit\n";
    cin >> c;

    while (c != 4) {
        if (c == 1) {
            cout << "Price: ";
            cin >> p[n];
            n++;
        } else if (c == 2) {
            for (int i = 0; i < n; i++) {
                cout << i+1 << ". $" << p[i] << endl;
            }
        } else if (c == 3) {
            if (n > 0) {
                double s = 0;
                for (int i = 0; i < n; i++) s += p[i];
                double avg = s / n;
                double hi = p[0], lo = p[0];
                for (int i = 1; i < n; i++) {
                    if (p[i] > hi) hi = p[i];
                    if (p[i] < lo) lo = p[i];
                }
                cout << "Avg: $" << avg << " Hi: $" << hi << " Lo: $" << lo << endl;
            }
        }
        cout << "1. Add 2. View 3. Stats 4. Quit\n";
        cin >> c;
    }
    return 0;
}

 *
 * Problems with this version:
 * - Single-letter variable names (p, n, c, s)
 * - Everything crammed into main()
 * - Repeated code (printing the menu)
 * - Hard to follow the logic
 * - No comments
 */

/*
 * ================================================================
 * THE "AFTER" VERSION
 * Same functionality, but cleaner and more maintainable
 * ================================================================
 */

const int MAX_PRICES = 100;

// Clear, focused helper functions
void printMenu();
void addPrice(double prices[], int& count);
void viewPrices(const double prices[], int count);
void showStatistics(const double prices[], int count);

// Statistics helpers
double calculateSum(const double arr[], int count);
double findHighest(const double arr[], int count);
double findLowest(const double arr[], int count);

int main() {
    double prices[MAX_PRICES];
    int priceCount = 0;
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addPrice(prices, priceCount);
                break;
            case 2:
                viewPrices(prices, priceCount);
                break;
            case 3:
                showStatistics(prices, priceCount);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
        cout << endl;

    } while (choice != 4);

    return 0;
}

void printMenu() {
    cout << "=== Price Tracker ===" << endl;
    cout << "1. Add price" << endl;
    cout << "2. View all prices" << endl;
    cout << "3. Show statistics" << endl;
    cout << "4. Quit" << endl;
    cout << "Choice: ";
}

void addPrice(double prices[], int& count) {
    if (count >= MAX_PRICES) {
        cout << "Price list is full!" << endl;
        return;
    }

    cout << "Enter price: $";
    cin >> prices[count];
    count++;
    cout << "Price added." << endl;
}

void viewPrices(const double prices[], int count) {
    if (count == 0) {
        cout << "No prices recorded yet." << endl;
        return;
    }

    cout << "Recorded prices:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "  " << (i + 1) << ". $" << prices[i] << endl;
    }
}

void showStatistics(const double prices[], int count) {
    if (count == 0) {
        cout << "No prices to analyze." << endl;
        return;
    }

    double sum = calculateSum(prices, count);
    double average = sum / count;
    double highest = findHighest(prices, count);
    double lowest = findLowest(prices, count);

    cout << "Statistics:" << endl;
    cout << "  Count: " << count << endl;
    cout << "  Total: $" << sum << endl;
    cout << "  Average: $" << average << endl;
    cout << "  Highest: $" << highest << endl;
    cout << "  Lowest: $" << lowest << endl;
}

double calculateSum(const double arr[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }
    return sum;
}

double findHighest(const double arr[], int count) {
    double highest = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }
    return highest;
}

double findLowest(const double arr[], int count) {
    double lowest = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }
    return lowest;
}

/*
 * What changed:
 *
 * 1. MEANINGFUL NAMES
 *    - p, n, c, s → prices, priceCount, choice, sum
 *    - Names describe purpose, not just type
 *
 * 2. EXTRACTED FUNCTIONS
 *    - printMenu(), addPrice(), viewPrices(), showStatistics()
 *    - Each function has one clear job
 *
 * 3. REUSABLE HELPERS
 *    - calculateSum(), findHighest(), findLowest()
 *    - Could be used in other programs
 *
 * 4. EDGE CASE HANDLING
 *    - Empty list checks
 *    - Full list check
 *    - Invalid menu choice
 *
 * 5. CLEAR STRUCTURE
 *    - main() is now a simple loop that dispatches to handlers
 *    - Easy to add new menu options
 *
 * 6. CONST CORRECTNESS
 *    - Functions that don't modify use const
 *    - Documents intent and prevents accidents
 *
 * The "after" version has more lines, but each line is simpler.
 * The logic is easier to follow, test, and modify.
 */
