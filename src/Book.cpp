#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() {}

Book::Book(int id, string title, string author, string genre)
    : id(id), title(title), author(author), genre(genre) {}

void Book::displayBook() const {
    cout << "\n[Book ID: " << id << "] "
         << title << " by " << author 
         << " (" << genre << ")\n";
}