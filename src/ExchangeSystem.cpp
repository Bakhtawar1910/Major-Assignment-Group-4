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

void ExchangeSystem::addBook() {
    string title, author, genre;
    cout << "\nEnter book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, author);
    cout << "Enter genre: ";
    getline(cin, genre);

    Book newBook(nextBookId++, title, author, genre);
    books.push_back(newBook);

    cout << "\n📌 Book added successfully!\n";
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
    int option;
    cout << "\n--- Books Menu ---\n";
    cout << "1. Add Book\n";
    cout << "0. Back\n";
    cout << "Select option: ";
    cin >> option;

    if(option == 1) addBook();
}

// -------------------- USER FEATURE --------------------

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

// -------------------- REQUEST FEATURE --------------------

void ExchangeSystem::createRequest() {
    int userId, bookId;
    cout << "\nEnter User ID: ";
    cin >> userId;

    cout << "\nEnter Book ID: ";
    cin >> bookId;

    Request req(nextRequestId++, bookId, userId);
    requests.push_back(req);

    cout << "\n📌 Request created successfully!\n";
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
void ExchangeSystem::saveBooks() {
    ofstream file("data/books.txt");
    for (auto &b : books) {
        file << b.getId() << "|"
             << b.getTitle() << "|"
             << b.getAuthor() << "|"
             << b.getGenre() << "\n";
    }
    file.close();
}void ExchangeSystem::loadBooks() {
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
    file.close();
}
// -------------------- SYSTEM RUN LOOP --------------------

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
