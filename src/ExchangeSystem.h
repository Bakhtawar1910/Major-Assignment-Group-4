#ifndef EXCHANGE_SYSTEM_H
#define EXCHANGE_SYSTEM_H

#include <vector>
#include "Book.h"
#include "User.h"
#include "Request.h"
using namespace std;

/*
 * ExchangeSystem Class
 * ------------------------------------------
 * This class handles the complete logic of:
 *  - Managing Books
 *  - Managing Users
 *  - Managing Requests
 *  - File Handling for Data Persistence
 *  - Main System Navigation (Menus)
 *
 * All data is stored in vectors and also saved
 * in text files inside the /data folder.
 */

class ExchangeSystem {
private:
    // Data storage containers
    vector<Book> books;
    vector<User> users;
    vector<Request> requests;

    // Auto-increment IDs for new entries
    int nextBookId = 1;
    int nextUserId = 1;
    int nextRequestId = 1;

    // Menu display functions
    void showMainMenu();
    void showBooksMenu();
    void showUsersMenu();
    void showRequestsMenu();

    // Book module functions
    void addBook();
    void listBooks();
    void searchBook();
    void handleBooksMenu();

    // User module functions
    void registerUser();
    void listUsers();
    void handleUsersMenu();

    // Request module functions
    void createRequest();
    void listRequests();
    void handleRequestsMenu();

    // File Management
    void saveBooks();
    void loadBooks();
    void saveUsers();
    void loadUsers();
    void saveRequests();
    void loadRequests();
    void saveAll();

public:
    ExchangeSystem(); // Loads stored data automatically from files
    void run();       // Main infinite loop of the system
};

#endif
