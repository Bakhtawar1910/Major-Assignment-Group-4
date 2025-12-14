/**
 * @file ExchangeSystem.h
 * @brief Declaration of the ExchangeSystem class.
 *
 * This class manages books, users, and exchange requests,
 * including menu handling and file persistence.
 */

#ifndef EXCHANGE_SYSTEM_H
#define EXCHANGE_SYSTEM_H

#include <vector>
#include "Book.h"
#include "User.h"
#include "Request.h"

using namespace std;

/**
 * @class ExchangeSystem
 * @brief Core controller class for the Old Book Exchange System.
 *
 * Handles all major system operations including menu navigation,
 * book management, user management, request handling, and
 * data persistence using files.
 */
class ExchangeSystem {
private:
    /**
     * @brief Collection of all books in the system.
     */
    vector<Book> books;

    /**
     * @brief Collection of all registered users.
     */
    vector<User> users;

    /**
     * @brief Collection of all exchange requests.
     */
    vector<Request> requests;

    /**
     * @brief Auto-incrementing ID for books.
     */
    int nextBookId = 1;

    /**
     * @brief Auto-incrementing ID for users.
     */
    int nextUserId = 1;

    /**
     * @brief Auto-incrementing ID for requests.
     */
    int nextRequestId = 1;

    // ----------- Menus -----------

    /**
     * @brief Displays the main menu.
     */
    void showMainMenu();

    /**
     * @brief Displays the books management menu.
     */
    void showBooksMenu();

    /**
     * @brief Displays the users management menu.
     */
    void showUsersMenu();

    /**
     * @brief Displays the requests management menu.
     */
    void showRequestsMenu();

    // ----------- Book Operations -----------

    /**
     * @brief Adds a new book to the system.
     */
    void addBook();

    /**
     * @brief Displays all books stored in the system.
     */
    void listBooks();

    /**
     * @brief Searches for a book by title.
     */
    void searchBook();

    /**
     * @brief Handles user interaction for the books menu.
     */
    void handleBooksMenu();

    // ----------- User Operations -----------

    /**
     * @brief Registers a new user.
     */
    void registerUser();

    /**
     * @brief Displays all registered users.
     */
    void listUsers();

    /**
     * @brief Handles user interaction for the users menu.
     */
    void handleUsersMenu();

    // ----------- Request Operations -----------

    /**
     * @brief Creates a new exchange request.
     */
    void createRequest();

    /**
     * @brief Displays all exchange requests.
     */
    void listRequests();

    /**
     * @brief Handles user interaction for the requests menu.
     */
    void handleRequestsMenu();

    // ----------- File Handling -----------

    /**
     * @brief Saves all book data to a file.
     */
    void saveBooks();

    /**
     * @brief Loads book data from a file.
     */
    void loadBooks();

    /**
     * @brief Saves all user data to a file.
     */
    void saveUsers();

    /**
     * @brief Loads user data from a file.
     */
    void loadUsers();

    /**
     * @brief Saves all request data to a file.
     */
    void saveRequests();

    /**
     * @brief Loads request data from a file.
     */
    void loadRequests();

    /**
     * @brief Saves all system data.
     */
    void saveAll();

public:
    /**
     * @brief Constructs the ExchangeSystem object.
     *
     * Loads existing books, users, and requests from files.
     */
    ExchangeSystem();

    /**
     * @brief Runs the main system loop.
     *
     * Displays menus and processes user input until exit.
     */
    void run();
};

#endif

