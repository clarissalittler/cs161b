/*
 * Mini-Project: Contact Book
 *
 * A simple contact manager using an array of structs.
 *
 * This is great practice for:
 * - Defining and using structs
 * - Managing an array of structs
 * - Menu-driven program structure
 * - Search and delete operations
 */

#include <iostream>
#include <string>
using namespace std;

// Define the Contact struct
struct Contact {
    string name;
    string phone;
    string email;
};

const int MAX_CONTACTS = 100;

// Function prototypes
void addContact(Contact contacts[], int& count);
void listContacts(Contact contacts[], int count);
int searchContact(Contact contacts[], int count, const string& searchName);
void deleteContact(Contact contacts[], int& count, int index);
void printMenu();

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;  // How many contacts we actually have
    int choice;

    cout << "=== Contact Book ===" << endl;

    do {
        printMenu();
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();  // Clear the newline left by cin >>

        switch (choice) {
            case 1:
                if (count < MAX_CONTACTS) {
                    addContact(contacts, count);
                } else {
                    cout << "Contact book is full!" << endl;
                }
                break;

            case 2:
                listContacts(contacts, count);
                break;

            case 3: {
                string searchName;
                cout << "Search for: ";
                getline(cin, searchName);
                int idx = searchContact(contacts, count, searchName);
                if (idx >= 0) {
                    cout << "Found: " << contacts[idx].name;
                    cout << " - " << contacts[idx].phone;
                    cout << " - " << contacts[idx].email << endl;
                } else {
                    cout << "Contact not found." << endl;
                }
                break;
            }

            case 4: {
                string deleteName;
                cout << "Delete contact named: ";
                getline(cin, deleteName);
                int idx = searchContact(contacts, count, deleteName);
                if (idx >= 0) {
                    deleteContact(contacts, count, idx);
                    cout << "Contact deleted." << endl;
                } else {
                    cout << "Contact not found." << endl;
                }
                break;
            }

            case 5:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
        cout << endl;

    } while (choice != 5);

    return 0;
}

void printMenu() {
    cout << "1. Add contact" << endl;
    cout << "2. List all contacts" << endl;
    cout << "3. Search by name" << endl;
    cout << "4. Delete contact" << endl;
    cout << "5. Quit" << endl;
}

// TODO: Implement this function
// Read name, phone, email from the user and add to the array
// Don't forget to increment count!
void addContact(Contact contacts[], int& count) {
    cout << "Name: ";
    // TODO: Read the name using getline

    cout << "Phone: ";
    // TODO: Read the phone

    cout << "Email: ";
    // TODO: Read the email

    // TODO: Add the contact to the array and increment count

    cout << "Contact added!" << endl;
}

// TODO: Implement this function
// Print all contacts with their index
void listContacts(Contact contacts[], int count) {
    if (count == 0) {
        cout << "No contacts yet." << endl;
        return;
    }

    // TODO: Loop through and print each contact
    // Format: "1. Name - Phone - Email"

}

// TODO: Implement this function
// Search for a contact by name (case-sensitive for simplicity)
// Return the index if found, -1 if not found
int searchContact(Contact contacts[], int count, const string& searchName) {
    // TODO: Loop through contacts looking for a matching name
    // Return the index when found

    return -1;  // Not found
}

// TODO: Implement this function
// Delete the contact at the given index by shifting all later contacts down
// Don't forget to decrement count!
void deleteContact(Contact contacts[], int& count, int index) {
    // TODO: Shift contacts[index+1] to contacts[index], etc.
    // Then decrement count

}

/*
 * Hints:
 *
 * addContact:
 *   getline(cin, contacts[count].name);
 *   count++;
 *
 * listContacts:
 *   for (int i = 0; i < count; i++) {
 *       cout << (i+1) << ". " << contacts[i].name << ...
 *   }
 *
 * searchContact:
 *   if (contacts[i].name == searchName) return i;
 *
 * deleteContact:
 *   for (int i = index; i < count - 1; i++) {
 *       contacts[i] = contacts[i + 1];
 *   }
 *   count--;
 *
 * Test your program:
 * - Add 3 contacts
 * - List them
 * - Search for one
 * - Delete the middle one
 * - List again (should show 2 contacts)
 */
