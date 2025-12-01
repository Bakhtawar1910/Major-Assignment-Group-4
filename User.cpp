#include "User.h"
#include <iostream>
using namespace std;

User::User() {}

User::User(int id, string name, string email, string phone)
    : id(id), name(name), email(email), phone(phone) {}

void User::displayUser() const {
    cout << "\n[User ID: " << id << "] "
         << name << " | " << email << " | " << phone << "\n";
}