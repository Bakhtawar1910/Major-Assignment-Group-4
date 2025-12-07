#include "ExchangeSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

// Load data on startup
ExchangeSystem::ExchangeSystem() {
    loadBooks();
    loadUsers();
    loadRequests();
}

// ===================== MAIN MENU =====================

void ExchangeSystem::showMainMenu() {
    cout << "\n===== Old Book Exchange System =====\n";
    cout << "1. Manage Books\n";
    cout << "2. Manage Users\n";
    cout << "3. Manage Requests\n";
    cout << "4. Save All Data\n";
    cout << "0. Exit\n";
    cout << "-----------------------------------\n";
    cout << "Enter your choice: ";
}

// ===================== BOOKS =====================

void ExchangeSystem::showBooksMenu() {
    cout << "\n--- Books Menu ---\n";
    cout << "1. Add Book\n";
    cout << "2. List Books\n";
    cout << "3. Search Book\n";
    cout << "0. Back\n";
    cout << "Select option: ";
}

void ExchangeSystem::addBook() {
    string title, author, genre;
    cin.ignore();
    cout << "\nEnter book title: ";
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, author);
    cout << "Enter genre: ";
    getline(cin, genre);

    books.push_back(Book(nextBookId++, title, author, genre));
    cout << "\n📌 Book added successfully!\n";
}

void ExchangeSystem::listBooks() {
    if (books.empty()) {
        cout << "\n⚠ No books available.\n";
        return;
    }
    cout << "\n--- All Books ---\n";
    for (auto &b : books) b.displayBook();
}

void ExchangeSystem::searchBook() {
    string title;
    cin.ignore();
    cout << "\nEnter book title to search: ";
    getline(cin, title);

    bool found = false;
    for (auto &b : books) {
        if (b.getTitle() == title) {
            b.displayBook();
            found = true;
        }
    }
    if (!found)
        cout << "\n❌ Book not found!\n";
}

void ExchangeSystem::handleBooksMenu() {
    int option;
    showBooksMenu();
    cin >> option;

    switch (option) {
        case 1: addBook(); break;
        case 2: listBooks(); break;
        case 3: searchBook(); break;
    }
}

// ===================== USERS =====================

void ExchangeSystem::showUsersMenu() {
    cout << "\n--- Users Menu ---\n";
    cout << "1. Register User\n";
    cout << "2. List Users\n";
    cout << "0. Back\n";
    cout << "Select option: ";
}

void ExchangeSystem::registerUser() {
    string name, email, phone;
    cin.ignore();
    cout << "\nEnter name: ";
    getline(cin, name);
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter phone: ";
    getline(cin, phone);

    users.push_back(User(nextUserId++, name, email, phone));
    cout << "\n🎉 User registered successfully!\n";
}

void ExchangeSystem::listUsers() {
    if (users.empty()) {
        cout << "\n⚠ No users registered.\n";
        return;
    }
    cout << "\n--- All Users ---\n";
    for (auto &u : users) u.displayUser();
}

void ExchangeSystem::handleUsersMenu() {
    int option;
    showUsersMenu();
    cin >> option;

    switch (option) {
        case 1: registerUser(); break;
        case 2: listUsers(); break;
    }
}

// ===================== REQUESTS =====================

void ExchangeSystem::showRequestsMenu() {
    cout << "\n--- Requests Menu ---\n";
    cout << "1. Create Request\n";
    cout << "2. List Requests\n";
    cout << "0. Back\n";
    cout << "Select option: ";
}

void ExchangeSystem::createRequest() {
    int userId, bookId;
    cout << "\nEnter user ID: ";
    cin >> userId;
    cout << "Enter book ID: ";
    cin >> bookId;

    requests.push_back(Request(nextRequestId++, bookId, userId));
    cout << "\n📌 Request created successfully!\n";
}

void ExchangeSystem::listRequests() {
    if (requests.empty()) {
        cout << "\n⚠ No requests created.\n";
        return;
    }
    cout << "\n--- All Requests ---\n";
    for (auto &r : requests) r.displayRequest();
}

void ExchangeSystem::handleRequestsMenu() {
    int option;
    showRequestsMenu();
    cin >> option;

    switch (option) {
        case 1: createRequest(); break;
        case 2: listRequests(); break;
    }
}

// ===================== FILE HANDLING =====================

void ExchangeSystem::saveBooks() {
    ofstream file("data/books.txt");
    for (auto &b : books) {
        file << b.getId() << "|" << b.getTitle() << "|" << b.getAuthor() << "|" << b.getGenre() << "\n";
    }
}

void ExchangeSystem::loadBooks() {
    ifstream file("data/books.txt");
    if (!file) return;
    books.clear();

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, title, author, genre;
        getline(ss, idStr, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, genre, '|');
        int id = stoi(idStr);
        books.push_back(Book(id, title, author, genre));
        nextBookId = max(nextBookId, id + 1);
    }
}

void ExchangeSystem::saveUsers() {
    ofstream file("data/users.txt");
    for (auto &u : users) {
        file << u.getId() << "|" << u.getName() << "|" << u.getEmail() << "|" << u.getPhone() << "\n";
    }
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
}

void ExchangeSystem::saveRequests() {
    ofstream file("data/requests.txt");
    for (auto &r : requests) {
        file << r.getId() << "|" << r.getBookId() << "|" << r.getUserId() << "|" << r.getStatus() << "\n";
    }
}

void ExchangeSystem::loadRequests() {
    ifstream file("data/requests.txt");
    if (!file) return;
    requests.clear();

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, bookStr, userStr, status;
        getline(ss, idStr, '|');
        getline(ss, bookStr, '|');
        getline(ss, userStr, '|');
        getline(ss, status, '|');
        int id = stoi(idStr);
        int bookId = stoi(bookStr);
        int userId = stoi(userStr);
        Request r(id, bookId, userId);
        requests.push_back(r);
        nextRequestId = max(nextRequestId, id + 1);
    }
}

void ExchangeSystem::saveAll() {
    saveBooks();
    saveUsers();
    saveRequests();
    cout << "\n💾 All data saved successfully!\n";
}

// ===================== SYSTEM RUN LOOP =====================

void ExchangeSystem::run() {
    int choice;
    do {
        showMainMenu();
        cin >> choice;

        switch (choice) {
            case 1: handleBooksMenu();    break;
            case 2: handleUsersMenu();    break;
            case 3: handleRequestsMenu(); break;
            case 4: saveAll();            break;
            case 0: cout << "\nGoodbye!\n"; break;
            default: cout << "Invalid option, try again!\n";
        }

    } while (choice != 0);
}
