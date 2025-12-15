/**
 * @file Request.h
 * @brief Defines the Request class, which manages book borrowing requests.
 */

#ifndef REQUEST_H
#define REQUEST_H

#include <string>
using namespace std;

/**
 * @class Request
 * @brief Represents a single book borrowing request in the system.
 *
 * This class stores all necessary information for a user requesting a book,
 * including unique identifiers for the request, book, and user, along with
 * the current status of the request (e.g., PENDING, APPROVED, REJECTED).
 */
class Request {
private:
    /** @brief The unique identifier for this request. */
    int id;
    /** @brief The ID of the book being requested. */
    int bookId;
    /** @brief The ID of the user making the request. */
    int userId;
    /** @brief The current status of the request (e.g., "PENDING"). */
    string status;

public:
    /**
     * @brief Default constructor.
     * Initializes a Request object with default or uninitialized values.
     */
    Request();

    /**
     * @brief Parameterized constructor.
     * @param id The unique identifier for the request.
     * @param bookId The ID of the book being requested.
     * @param userId The ID of the user making the request.
     */
    Request(int id, int bookId, int userId);

    /**
     * @brief Gets the unique identifier of the request.
     * @return The request ID.
     */
    int getId() const { return id; }

    /**
     * @brief Gets the ID of the requested book.
     * @return The book ID.
     */
    int getBookId() const { return bookId; }

    /**
     * @brief Gets the ID of the user who made the request.
     * @return The user ID.
     */
    int getUserId() const { return userId; }

    /**
     * @brief Gets the current status of the request.
     * @return The request status (e.g., "PENDING").
     */
    string getStatus() const { return status; }

    /**
     * @brief Prints the formatted details of the request to standard output.
     *
     * This method provides a user-friendly view of the request details.
     */
    void displayRequest() const;
};

#endif
