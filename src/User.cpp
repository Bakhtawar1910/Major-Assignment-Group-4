#include "User.h"
#include <iostream>
using namespace std;

/**
 * User Constructor
 */
User::User(int id, string name, string email, string phone)
    : id(id), name(name), email(email), phone(phone) {}

User::User() {}

/**
 * displayUser()
 * ------------------------------------
 * Prints details of one user
 */
void User::displayUser() const {
    cout << "\n🧑 User ID: " << id
         << "\nName: "      << name
         << "\nEmail: "     << email
         << "\nPhone: "     << phone << "\n";
}