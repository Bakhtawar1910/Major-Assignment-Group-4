#include "Request.h"
#include <iostream>
using namespace std;

/**
 * Request Constructor
 * --------------------------------
 * Default status is always "PENDING"
 */
Request::Request(int id, int bookId, int userId)
    : id(id), bookId(bookId), userId(userId), status("PENDING") {}

Request::Request() {}

/**
 * displayRequest()
 * --------------------------------
 * Prints formatted request details
 */
void Request::displayRequest() const {
    cout << "\n📩 Request ID: " << id
         << "\nBook ID: "      << bookId
         << "\nUser ID: "      << userId
         << "\nStatus: "       << status << "\n";
}