#ifndef REQUEST_H
#define REQUEST_H

#include <string>
using namespace std;

class Request {
private:
    int requestId;
    int bookId;
    int userId;
    string status; // PENDING, APPROVED, REJECTED

public:
    Request(); // Constructor (implementation later)
};

#endif