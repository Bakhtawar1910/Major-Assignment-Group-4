#include "Request.h"
#include <iostream>
using namespace std;

Request::Request() {}

Request::Request(int id, int bookId, int userId)
    : id(id), bookId(bookId), userId(userId), status("PENDING") {}

void Request::displayRequest() const {
    cout << "\n[Request ID: " << id << "] "
         << "Book: " << bookId 
         << " | User: " << userId 
         << " | Status: " << status << "\n";
}