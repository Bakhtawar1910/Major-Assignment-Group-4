/**
 * @file Book.h
 * @brief Declaration of the Book class.
 *
 * Represents a book entity in the Old Book Exchange System.
 */

#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

/**
 * @class Book
 * @brief Represents a book available for exchange.
 *
 * Stores book details such as ID, title, author, and genre,
 * and provides methods to access and display this information.
 */
class Book {
private:
    /**
     * @brief Unique identifier for the book.
     */
    int id;

    /**
     * @brief Title of the book.
     */
    string title;

    /**
     * @brief Author of the book.
     */
    string author;

    /**
     * @brief Genre/category of the book.
     */
    string genre;

public:
    /**
     * @brief Default constructor.
     */
    Book();

    /**
     * @brief Parameterized constructor.
     *
     * @param id Unique identifier for the book
     * @param title Title of the book
     * @param author Author of the book
     * @param genre Genre/category of the book
     */
    Book(int id, string title, string author, string genre);

    /**
     * @brief Gets the book ID.
     * @return Book ID
     */
    int getId() const { return id; }

    /**
     * @brief Gets the book title.
     * @return Book title
     */
    string getTitle() const { return title; }

    /**
     * @brief Gets the book author.
     * @return Book author
     */
    string getAuthor() const { return author; }

    /**
     * @brief Gets the book genre.
     * @return Book genre
     */
    string getGenre() const { return genre; }

    /**
     * @brief Displays book details.
     */
    void displayBook() const;
};

#endif
