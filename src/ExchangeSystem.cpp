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
    showUsersMenu();
}
void ExchangeSystem::createRequest() {
    int userId, bookId;
    cout << "\nEnter User ID: ";
    cin >> userId;
    cout<<"\n"
    cout << "Enter Book ID: ";
    cin >> bookId;

    Request req(nextRequestId++, bookId, userId);
    requests.push_back(req);

    cout << "\n Request created successfully!\n";
}

void ExchangeSystem::handleRequestsMenu() {
    int option;
    cout << "\n--- Requests Menu ---\n";
    cout << "1. Create Request\n";
    cout << "0. Back\n";
    cout << "Select option: ";
    cin >> option;

    if(option == 1) createRequest();
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
