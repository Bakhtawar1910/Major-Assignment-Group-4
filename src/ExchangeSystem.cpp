#include "ExchangeSystem.h"
#include <iostream>
using namespace std;

void ExchangeSystem::showMainMenu() {
    cout << "\n===== Old Book Exchange System =====\n";
    cout << "1. Manage Books\n";
    cout << "2. Manage Users\n";
    cout << "3. Manage Requests\n";
    cout << "0. Exit\n";
    cout << "-----------------------------------\n";
    cout << "Enter your choice: ";
}

void ExchangeSystem::showBooksMenu() {
    cout << "\n--- Books Menu (Feature coming soon) ---\n";
}

void ExchangeSystem::showUsersMenu() {
    cout << "\n--- Users Menu (Feature coming soon) ---\n";
}

void ExchangeSystem::showRequestsMenu() {
    cout << "\n--- Requests Menu (Feature coming soon) ---\n";
}

void ExchangeSystem::handleBooksMenu() {
    showBooksMenu();
}

void ExchangeSystem::handleUsersMenu() {
    int option;
    cout << "\n--- Users Menu ---\n";
    cout << "1. Register User\n";
    cout << "0. Back\n";
    cout << "Select option: ";
    cin >> option;

    if(option == 1) registerUser();
}

void ExchangeSystem::registerUser() {
    string name, email, phone;
    cout << "\nEnter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter phone: ";
    getline(cin, phone);

    User newUser(nextUserId++, name, email, phone);
    users.push_back(newUser);

    cout << "\n🎉 User registered successfully!\n";
}
 exchangeSystem.cpp me ye function add krna hai


void ExchangeSystem::handleRequestsMenu() {
    showRequestsMenu();
}


void ExchangeSystem::saveUsers() {
    ofstream file("data/users.txt");
    for (auto &u : users) {
        file << u.getId() << "|"
             << u.getName() << "|"
             << u.getEmail() << "|"
             << u.getPhone() << "\n";
    }
    file.close();
}


void ExchangeSystem::loadUsers() {
    ifstream file("data/users.txt");
    if (!file) return;

    users.clear();
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, email, phone;

        getline(ss, idStr, '|');
        getline(ss, name, '|');
        getline(ss, email, '|');
        getline(ss, phone, '|');

        int id = stoi(idStr);
        users.push_back(User(id, name, email, phone));

        nextUserId = max(nextUserId, id + 1);
    }
    file.close();
}

void ExchangeSystem::run() {
    int choice;
    do {
        showMainMenu();
        cin >> choice;

        switch (choice) {
            case 1: handleBooksMenu(); break;
            case 2: handleUsersMenu(); break;
            case 3: handleRequestsMenu(); break;
            case 0: cout << "Exiting... Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);
}
