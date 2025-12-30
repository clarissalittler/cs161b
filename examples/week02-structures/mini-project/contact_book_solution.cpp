/*
 * Mini-Project: Contact Book (Solution)
 */

#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

const int MAX_CONTACTS = 100;

void addContact(Contact contacts[], int& count);
void listContacts(Contact contacts[], int count);
int searchContact(Contact contacts[], int count, const string& searchName);
void deleteContact(Contact contacts[], int& count, int index);
void printMenu();

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    cout << "=== Contact Book ===" << endl;

    do {
        printMenu();
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

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

void addContact(Contact contacts[], int& count) {
    cout << "Name: ";
    getline(cin, contacts[count].name);

    cout << "Phone: ";
    getline(cin, contacts[count].phone);

    cout << "Email: ";
    getline(cin, contacts[count].email);

    count++;
    cout << "Contact added!" << endl;
}

void listContacts(Contact contacts[], int count) {
    if (count == 0) {
        cout << "No contacts yet." << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << (i + 1) << ". " << contacts[i].name;
        cout << " - " << contacts[i].phone;
        cout << " - " << contacts[i].email << endl;
    }
}

int searchContact(Contact contacts[], int count, const string& searchName) {
    for (int i = 0; i < count; i++) {
        if (contacts[i].name == searchName) {
            return i;
        }
    }
    return -1;
}

void deleteContact(Contact contacts[], int& count, int index) {
    if (index < 0 || index >= count) {
        return;
    }
    for (int i = index; i < count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    count--;
}
