#ifndef EXCHANGE_SYSTEM_H
#define EXCHANGE_SYSTEM_H

#include <vector>
#include "Book.h"
#include "User.h"
#include "Request.h"
using namespace std;

class ExchangeSystem {
private:
    // Data storage
    vector<Book> books;
    vector<User> users;
    vector<Request> requests;

    // Auto-increment IDs
    int nextBookId = 1;
    int nextUserId = 1;
    int nextRequestId = 1;

    // ----------- Menus -----------
    void showMainMenu();
    void showBooksMenu();
    void showUsersMenu();
    void showRequestsMenu();

    // ----------- Book Operations -----------
    void addBook();
    void listBooks();
    void searchBook();
    void handleBooksMenu();

    // ----------- User Operations -----------
    void registerUser();
    void listUsers();
    void handleUsersMenu();

    // ----------- Request Operations -----------
    void createRequest();
    void listRequests();
    void handleRequestsMenu();

    // ----------- File Handling -----------
    void saveBooks();
    void loadBooks();

    void saveUsers();
    void loadUsers();

    void saveRequests();
    void loadRequests();

    void saveAll();   // Save everything

public:
    ExchangeSystem(); // Loads existing data on startup
    void run();       // Main system loop
};

#endif
