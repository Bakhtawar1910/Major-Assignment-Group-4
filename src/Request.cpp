/**
 * @file Request.cpp
 * @brief Implements the Request class for managing book requests.
 */

#include "Request.h"
#include <iostream>

using namespace std;

/**
 * @brief Default Constructor for the Request class.
 *
 * This is a parameterless constructor, useful when creating an object that
 * will be initialized later, or for use in containers.
 */
Request::Request() {}

/**
 * @brief Parameterized Constructor for the Request class.
 *
 * Initializes a new Request object with specified IDs.
 * The default status is always set to "PENDING".
 *
 * @param id The unique identifier for the request.
 * @param bookId The ID of the book being requested.
 * @param userId The ID of the user making the request.
 */
Request::Request(int id, int bookId, int userId)
    : id(id), bookId(bookId), userId(userId), status("PENDING") {}

/**
 * @brief Displays the formatted details of the request.
 *
 * Prints the Request ID, Book ID, User ID, and the current Status to the console.
 * The function is marked `const` as it does not modify the object's state.
 */
void Request::displayRequest() const {
    cout << "\n📩 Request ID: " << id
         << "\nBook ID: "      << bookId
         << "\nUser ID: "      << userId
         << "\nStatus: "       << status << "\n";
}
