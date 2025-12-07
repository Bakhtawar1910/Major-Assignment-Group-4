#ifndef REQUEST_H
#define REQUEST_H

#include <string>
using namespace std;

/**
 * Request Class
 * -------------------------------------
 * Stores book borrowing request:
 *  - Book ID (requested)
 *  - User ID (who requested)
 *  - Status (default: PENDING)
 */
class Request {
private:
    int id;
    int bookId;
    int userId;
    string status;

public:
    Request();
    Request(int id, int bookId, int userId);

    int getId() const { return id; }
    int getBookId() const { return bookId; }
    int getUserId() const { return userId; }
    string getStatus() const { return status; }

    void displayRequest() const;
};

#endif