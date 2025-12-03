#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    string genre;

public:
    Book(); 
    Book(int id, string title, string author, string genre);

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }

    void displayBook() const;
};

#endif