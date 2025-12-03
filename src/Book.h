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
    Book(); // Constructor (implementation will come later)
};

#endif