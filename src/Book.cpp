/**
 * @file Book.cpp
 * @brief Implementation of the Book class.
 */

#include "Book.h"
#include <iostream>

using namespace std;

/**
 * @brief Default constructor for the Book class.
 */
Book::Book() {}

/**
 * @brief Parameterized constructor for the Book class.
 *
 * @param id Unique identifier for the book
 * @param title Title of the book
 * @param author Author of the book
 * @param genre Genre/category of the book
 */
Book::Book(int id, string title, string author, string genre)
    : id(id), title(title), author(author), genre(genre) {}

/**
 * @brief Displays book details to the console.
 *
 * Outputs the book ID, title, author, and genre in a readable format.
 */
void Book::displayBook() const {
    cout << "\n[Book ID: " << id << "] "
         << title << " by " << author
         << " (" << genre << ")\n";
}
