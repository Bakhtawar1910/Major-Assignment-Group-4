/**
 * @file User.cpp
 * @brief Implementation of the User class.
 */

#include "User.h"
#include <iostream>

using namespace std;

/**
 * @brief Parameterized constructor for the User class.
 *
 * @param id Unique identifier for the user
 * @param name Name of the user
 * @param email Email address of the user
 * @param phone Phone number of the user
 */
User::User(int id, string name, string email, string phone)
    : id(id), name(name), email(email), phone(phone) {}

/**
 * @brief Default constructor for the User class.
 */
User::User() {}

/**
 * @brief Displays user details.
 *
 * Prints the user's ID, name, email, and phone number
 * in a readable format.
 */
void User::displayUser() const {
    cout << "\nUser ID: " << id
         << "\nName: "    << name
         << "\nEmail: "   << email
         << "\nPhone: "   << phone << "\n";
}
