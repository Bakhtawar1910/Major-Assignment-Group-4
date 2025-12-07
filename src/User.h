#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

/**
 * User Class
 * ------------------------------------
 * Represents a user who can donate or
 * request books. Stores their:
 *  - Name
 *  - Email
 *  - Phone
 *  Used inside ExchangeSystem.
 */
class User {
private:
    int id;
    string name;
    string email;
    string phone;

public:
    User();
    User(int id, string name, string email, string phone);

    int getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }

    void displayUser() const; // Pretty print
};

#endif